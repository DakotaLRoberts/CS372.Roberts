#include<iostream>
#include"graph.hpp"
int main() {
    AdjListGraph<int> adjListGraph;
    adjListGraph.addNode(1);
    adjListGraph.addNode(2);
    adjListGraph.addNode(3);
    adjListGraph.addNode(4);
    adjListGraph.addEdge(1, 2);
    adjListGraph.addEdge(2, 3);
    adjListGraph.addEdge(3, 4);
    adjListGraph.addEdge(4, 1);
    std::cout << "AdjListGraph Operations:" << std::endl;
    std::cout << "Is 1 adjacent to 2? " << (adjListGraph.adjacent(1, 2) ? "Yes" : "No") << std::endl;
    std::cout << "Neighbors of 2: ";
    for (int neighbor : adjListGraph.neighbors(2)) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;
    adjListGraph.deleteEdge(3, 4);
    std::cout << "Is 3 adjacent to 4? " << (adjListGraph.adjacent(3, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Neighbors of 3: ";
    for (int neighbor : adjListGraph.neighbors(3)) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    AdjMatrixGraph<int> adjMatrixGraph;
    adjMatrixGraph.addNode(1);
    adjMatrixGraph.addNode(2);
    adjMatrixGraph.addNode(3);
    adjMatrixGraph.addNode(4);
    adjMatrixGraph.addEdge(1, 2);
    adjMatrixGraph.addEdge(2, 3);
    adjMatrixGraph.addEdge(3, 4);
    adjMatrixGraph.addEdge(4, 1);
    std::cout << "\nAdjMatrixGraph Operations:" << std::endl;
    std::cout << "Is 1 adjacent to 2? " << (adjMatrixGraph.adjacent(1, 2) ? "Yes" : "No") << std::endl;
    std::cout << "Neighbors of 2: ";
    for (int neighbor : adjMatrixGraph.neighbors(2)) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;
    adjMatrixGraph.deleteEdge(3, 4);
    std::cout << "Is 3 adjacent to 4? " << (adjMatrixGraph.adjacent(3, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Neighbors of 3: ";
    for (int neighbor : adjMatrixGraph.neighbors(3)) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    return 0;
}





