
#include <iostream>
#include<string>
#include"bag.hpp"
using namespace std;
int main() {
    Bag<string> myBag;
    int receipt;
    int numitem = 0;
    string doom;
    cout << "Please enter how many items you want in the bag." << endl;
    cin >> numitem;
    do {
        receipt = 0;
        cout << "Please enter the item name you want to enter." << endl;
        cin >> doom;
        receipt = myBag.insert(doom);
        cout << "Here is the receipt numberv for this object " << receipt << endl;
        numitem--;
    } while (numitem >= 0);
    myBag.displayItemsWithIds();

    myBag.removeItemWithUserInput();

    std::cout << "After removing an item:\n";
    myBag.displayItemsWithIds();

    return 0;
}