#include <iostream>
#include"vector.hpp"
using namespace std;
int main() {
    vector<int> myVector;
    int choice = 1;
    size_t find;
    int display;
    int input;
    do {
        cout << "Please enter the number you wish to enter into the vector" << endl;
        cin >> input;
        myVector.push_back(input);
        cout << "are you finished with entering numbers (1) NO or (0) Yes" << endl;
        cin >> choice;
    } while (choice != 0);
    for (size_t i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    cout << "Please enter the number you wish to search for in the vector" << endl;
    cin >> find;
    display=myVector.T&(find);
    cout << display;
    return 0;
}