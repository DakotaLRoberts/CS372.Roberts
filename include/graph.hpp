#include <iostream>
#include <vector>
#include <list>
#include <utility>

template <class N>
class Graph {
public:
    Graph() {}
    Graph(std::vector<N> nodes, std::vector<std::pair<N, N>> edges) {
        // Initialize the graph with nodes and edges.
        for (const N& node : nodes) {
            addNode(node);
        }
        for (const auto& edge : edges) {
            addEdge(edge.first, edge.second);
        }
    }

    virtual ~Graph() {}

    virtual bool adjacent(N x, N y) const = 0;
    virtual std::vector<N> neighbors(N x) const = 0;
    virtual void addNode(N x) = 0;
    virtual void addEdge(N x, N y) = 0;
    virtual void deleteEdge(N x, N y) = 0;
};

template <class N>
class AdjListGraph : public Graph<N> {
private:
    std::vector<N> nodeVector;
    std::vector<std::list<N>> edgesVector;

public:
    AdjListGraph() : Graph<N>() {}

    AdjListGraph(const AdjListGraph& other) : Graph<N>() {
        // Copy contents of 'other' into this graph.
        nodeVector = other.nodeVector;
        edgesVector = other.edgesVector;
    }

    AdjListGraph& operator=(const AdjListGraph& source) {
        if (this != &source) {
            // Implement copy assignment.
            nodeVector = source.nodeVector;
            edgesVector = source.edgesVector;
        }
        return *this;
    }

    AdjListGraph(std::vector<N> newNodes, std::vector<std::pair<N, N>> newEdges)
        : Graph<N>(newNodes, newEdges) {
        // Populate the graph with newNodes and newEdges.
        for (const N& node : newNodes) {
            nodeVector.push_back(node);
            edgesVector.push_back(std::list<N>());
        }
        for (const auto& edge : newEdges) {
            addEdge(edge.first, edge.second);
        }
    }

    virtual bool adjacent(N x, N y) const {
        // Check if there is an edge between nodes x and y.
        int xIndex = getNodeIndex(x);
        return std::find(edgesVector[xIndex].begin(), edgesVector[xIndex].end(), y) != edgesVector[xIndex].end();
    }

    virtual std::vector<N> neighbors(N x) const {
        // Find neighbors of node x.
        int xIndex = getNodeIndex(x);
        std::vector<N> result;
        for (N neighbor : edgesVector[xIndex]) {
            result.push_back(neighbor);
        }
        return result;
    }

    virtual void addNode(N node) {
        // Add a node to the graph.
        if (!containsNode(node)) {
            nodeVector.push_back(node);
            edgesVector.push_back(std::list<N>());
        }
    }

    virtual void addEdge(N x, N y) {
        // Add an edge between nodes x and y.
        int xIndex = getNodeIndex(x);
        int yIndex = getNodeIndex(y);
        if (xIndex != -1 && yIndex != -1) {
            edgesVector[xIndex].push_back(y);
            edgesVector[yIndex].push_back(x);
        }
    }

    virtual void deleteEdge(N x, N y) {
        // Remove the edge between nodes x and y.
        int xIndex = getNodeIndex(x);
        int yIndex = getNodeIndex(y);
        if (xIndex != -1 && yIndex != -1) {
            edgesVector[xIndex].remove(y);
            edgesVector[yIndex].remove(x);
        }
    }

private:
    int getNodeIndex(N node) const {
        // Get the index of a node in the nodeVector.
        for (size_t i = 0; i < nodeVector.size(); ++i) {
            if (nodeVector[i] == node) {
                return static_cast<int>(i);
            }
        }
        return -1; // Node not found.
    }

    bool containsNode(N node) const {
        // Check if the node is already in the graph.
        return getNodeIndex(node) != -1;
    }
};

template <class N>
class AdjMatrixGraph : public Graph<N> {
private:
    static const int MaxSize = 100;
    std::vector<N> nodeVector;
    bool adjMatrix[MaxSize][MaxSize];
    unsigned int numNodes = 0;

public:
    AdjMatrixGraph() : Graph<N>() {
        // Initialize the adjacency matrix.
        for (int i = 0; i < MaxSize; ++i) {
            for (int j = 0; j < MaxSize; ++j) {
                adjMatrix[i][j] = false;
            }
        }
    }

    AdjMatrixGraph(const AdjMatrixGraph& other) : Graph<N>() {
        // Copy contents of 'other' into this graph.
        nodeVector = other.nodeVector;
        numNodes = other.numNodes;
        for (int i = 0; i < numNodes; ++i) {
            for (int j = 0; j < numNodes; ++j) {
                adjMatrix[i][j] = other.adjMatrix[i][j];
            }
        }
    }

    AdjMatrixGraph& operator=(const AdjMatrixGraph& source) {
        if (this != &source) {
            // Implement copy assignment.
            nodeVector = source.nodeVector;
            numNodes = source.numNodes;
            for (int i = 0; i < numNodes; ++i) {
                for (int j = 0; j < numNodes; ++j) {
                    adjMatrix[i][j] = source.adjMatrix[i][j];
                }
            }
        }
        return *this;
    }

    AdjMatrixGraph(std::vector<N> newNodes, std::vector<std::pair<N, N>> newEdges)
        : Graph<N>(newNodes, newEdges) {
        // Populate the adjacency matrix with newNodes and newEdges.
        for (const N& node : newNodes) {
            addNode(node);
        }
        for (const auto& edge : newEdges) {
            addEdge(edge.first, edge.second);
        }
    }

    virtual bool adjacent(N x, N y) const {
        // Check if there is an edge between nodes x and y.
        int xIndex = getNodeIndex(x);
        int yIndex = getNodeIndex(y);
        if (xIndex != -1 && yIndex != -1) {
            return adjMatrix[xIndex][yIndex];
        }
        return false;
    }

    virtual std::vector<N> neighbors(N x) const {
        // Find neighbors of node x.
        int xIndex = getNodeIndex(x);
        std::vector<N> result;
        if (xIndex != -1) {
            for (int i = 0; i < numNodes; ++i) {
                if (adjMatrix[xIndex][i]) {
                    result.push_back(nodeVector[i]);
                }
            }
        }
        return result;
    }

    virtual void addNode(N node) {
        // Add a node to the graph.
        if (!containsNode(node) && numNodes < MaxSize) {
            nodeVector.push_back(node);
            numNodes++;
        }
    }

    virtual void addEdge(N x, N y) {
        // Add an edge between nodes x and y.
        int xIndex = getNodeIndex(x);
        int yIndex = getNodeIndex(y);
        if (xIndex != -1 && yIndex != -1) {
            adjMatrix[xIndex][yIndex] = true;
            adjMatrix[yIndex][xIndex] = true;
        }
    }

    virtual void deleteEdge(N x, N y) {
        // Remove the edge between nodes x and y.
        int xIndex = getNodeIndex(x);
        int yIndex = getNodeIndex(y);
        if (xIndex != -1 && yIndex != -1) {
            adjMatrix[xIndex][yIndex] = false;
            adjMatrix[yIndex][xIndex] = false;
        }
    }

private:
    int getNodeIndex(N node) const {
        // Get the index of a node in the nodeVector.
        for (size_t i = 0; i < nodeVector.size(); ++i) {
            if (nodeVector[i] == node) {
                return static_cast<int>(i);
            }
        }
        return -1; // Node not found.
    }

    bool containsNode(N node) const {
        // Check if the node is already in the graph.
        return getNodeIndex(node) != -1;
    }
};

int main() {
    // Example usage of AdjMatrixGraph
    AdjMatrixGraph<int> graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 3);

    // Test graph operations
    std::cout << "Are 1 and 2 adjacent? " << (graph.adjacent(1, 2) ? "Yes" : "No") << std::endl;
    std::cout << "Neighbors of 1: ";
    for (int neighbor : graph.neighbors(1)) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    return 0;
}

