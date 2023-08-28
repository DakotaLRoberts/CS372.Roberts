#pragma once

#pragma once
#include <iostream>
#include "vector.hpp"
using namespace std;
template <typename Thing>
class Bagwithreceipt {
public:
    void insert(Thing aThing) {
        bagContents.push_back(aThing);
        bagsize++;
        //receiptnum = bagsize * rand() % 10 +2;
        bagnum.push_back(receiptnum);
    }
    void retreive() {
        bagnum.traverse();



    }
    Thing& pop(Thing ) {
        Thing aThing;
        if (bagContents.size() > 0) {
            aThing = bagContents[bagSize];
            bagSize--;
        }
        else {
            std::cerr << "Can't pop out of an empty bag" << std::endl;
        }
        return aThing;
    }
    int size() {
        return bagSize;
    }
    int count(Thing aThing) {
        int bagCount = 0;
        for (int i = 0; i < bagSize; i++) {
            if (bagContents[i] == aThing) {
                bagCount++;
            }
        }
        return bagCount;
    }
private:
    vector<Thing> bagContents;
    vector<Thing> bagnum;
    int bagsize = 0;
    string receiptnum = "0";
};
int main() {
    Bagwithreceipt<string> bag;
    Bagwithreceipt<string> itemnum;
    string item;
    
    int many;
    int number;
    cout << "How many items do you wish to add to the bag?" << endl;
    cin >> many;
    do{
        cout << "Please enter the items name you want to add to the bag" << endl;
        cin >> item;
        bag.insert(item);
        
        many--;
    } while (many != 0);
    itemnum.retreive();
    cout << "How many items do you wish to remove from the bag?" << endl;
    cin >> many;
    do {
        cout << "Please enter the items recepit number you want to remove" << endl;
        cin >> number;
        itemnum.retreive();

        many--;
    } while (many != 0);
    

    return 0;
}
