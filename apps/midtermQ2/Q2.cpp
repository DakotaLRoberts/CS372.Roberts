#include <iostream>
#include <stack>
#include <string>
using namespace std;
int Matching(const string& input) {
   stack<char> checker;// named checker as the stack is used to check  for matching paranthesis
   for (size_t i = 0; i < input.size(); ++i) {
       char string = input[i];
       if (string == '(') {
           checker.push(string);
       }
       else if (string == ')' && !checker.empty()) {
           checker.pop();
       }
       else if (string == ')') {
           return 1;
       }
   }
    return checker.empty(); 
}

int main() {
   string input;
    cout << "Enter a string: ";
    cin >> input;
    if (Matching(input)) {
        cout << "The string has matching parentheses." << std::endl;
    }
    else {
        cout << "The string has mismatched parentheses." << std::endl;
    }
    return 0;
}