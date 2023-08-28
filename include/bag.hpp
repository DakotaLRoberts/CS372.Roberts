#include <iostream>
#include<string>
#include"vector.hpp"
using namespace std;

template <typename Thing>
class Bag {
public:
    int insert(string aThing) {
        bagContents.push_back(aThing);
        bagSize++;
        itemIdstorage(nextitemid);
        return nextitemid;
    }

    void itemIdstorage(int aThing) {
        itemIds.push_back(aThing);
        nextitemid++;
    }

    void removeItemById(int itemId) {
        for (size_t i = 0; i < itemIds.size(); i++) {
            if (itemIds[i] == itemId) {
                bagContents.erase(i);
                itemIds.erase(i);
                break;  // Stop once the item ID is found and removed
            }
        }
    }

    void removeItemWithUserInput() {
        int itemId;
        displayItemsWithIds();
        std::cout << "Enter the ID of the item you want to remove: ";
        std::cin >> itemId;
        removeItemById(itemId);
        displayItemsWithIds();
    }
    void displayItemsWithIds() {
        std::cout << "Items and their IDs in the bag:\n";
        for (size_t i = 0; i < bagContents.size(); i++) {
            std::cout << "Item: " << bagContents[i] << " (ID: " << itemIds[i] << ")\n";
        }
    }
    Thing pop() {
        if (bagContents.empty()) {
            std::cerr << "Can't pop out of an empty bag" << std::endl;
            return Thing(); // Return a default-constructed Thing or throw an exception here
        }

        Thing aThing = bagContents.back();
        bagContents.pop_back();
        bagSize--;
        return aThing;
    }

    size_t size() const {
        return bagSize;
    }

    size_t count(const Thing& aThing) const {
        size_t bagCount = 0;
        for (const auto& item : bagContents) {
            if (item == aThing) {
                bagCount++;
            }
        }
        return bagCount;
    }
private:
    vector<Thing> bagContents;
    vector<int> itemIds;
    size_t bagSize = 0;
    int nextitemid = 1;


};


