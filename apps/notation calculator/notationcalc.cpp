#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
#include <string>

using namespace std;



void evaluateStackTops(stack<double>& numbers, stack<char>& operations) {
    double op1, op2;
    op2 = numbers.top();
    numbers.pop();
    op1 = numbers.top();
    numbers.pop();
    switch (operations.top()) {
    case '+': numbers.push(op1 + op2);
        break;
    case '-': numbers.push(op1 - op2);
        break;
    case '*': numbers.push(op1 * op2);
        break;
    case '/': numbers.push(op1 / op2);
        break;
    }
    operations.pop();
}
double readAndEvaluate(istream& ins) {
    const char DECIMAL = '.';
    const char RIGHTPAREN = ')';
    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;
    while (ins && ins.peek() != '\n') {
        if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
            ins >> number;
            numbers.push(number);
        }
        else if (strchr("+-*/", ins.peek()) != NULL) {
            ins >> symbol;
            operations.push(symbol);
        }
        else if (ins.peek() == RIGHTPAREN) {
            ins.ignore();
            evaluateStackTops(numbers, operations);
        }
        else {
            ins.ignore();
        }
    }
    return numbers.top();
}
int operatordetector(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
string Prefix(const string& expression) {
    stack<char> operators;
    stack<string> prenotation;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;
        if (isdigit(expression [i]) || (expression[i] == '.')) {
            string operand;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                operand += expression[i];
                i++;
            }
            prenotation.push(operand);
            i--; 
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string op1 = prenotation.top();
                prenotation.pop();
                string op2 = prenotation.top();
                prenotation.pop();
                char op = operators.top();
                operators.pop();
                string newOp = op + op1 + op2;
                prenotation.push(newOp);
            }
            operators.pop(); 
        }
        else {
            while (!operators.empty() && operatordetector(operators.top()) >= operatordetector(expression[i])) {
                string op2 = prenotation.top();
                prenotation.pop();
                string op1 = prenotation.top();
                prenotation.pop();
                char op = operators.top();
                operators.pop();
                string newOperand = op + op1 + op2;
                prenotation.push(newOperand);
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        string op2 = prenotation.top();
        prenotation.pop();
        string op1 = prenotation.top();
        prenotation.pop();
        char op = operators.top();
        operators.pop();
        string newOperand = op + op1 + op2;
        prenotation.push(newOperand);
    }

    return prenotation.top();
}
string Postfix(const string& expression) {
    stack<char> operators;
    string postnotation;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;
        if (isdigit(expression[i]) || (expression[i] == '.')) {
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                postnotation += expression[i];
                i++;
            }
            postnotation += ' ';
            i--; 
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postnotation += operators.top();
                postnotation += ' ';
                operators.pop();
            }
            operators.pop(); 
        }
        else {
            while (!operators.empty() && operatordetector(operators.top()) >= operatordetector(expression [i])) {
                postnotation += operators.top();
                postnotation += ' ';
                operators.pop();
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        postnotation += operators.top();
        postnotation += ' ';
        operators.pop();
    }

    return postnotation;
}
int main() {
    string expression;
    cout << "Type a fully parenthesized expression: ";
    cin >> expression;

    string prefix = Prefix(expression);
    string postfix = Postfix(expression);

    cout << "Here is the prefix notation: " << prefix << endl;
    cout << "Here is the postfix notation: " << postfix << endl;

    return 0;
}



