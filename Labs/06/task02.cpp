#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

class Stack {
    int top;
    int size;
    char *arr;
public:
    Stack(int size) : top(-1), size(size) {
        arr = new char[size];
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(char x) {
        if (top < size - 1) {
            arr[++top] = x;
        } else {
            cout << "Stack overflow" << endl;
        }
    }
    char peek() const {
        if (top >= 0) return arr[top];
        return 0;
    }
    char pop() {
        if (top >= 0) return arr[top--];
        else {
            cout << "Stack underflow" << endl;
            return 0;
        }
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infix_to_postfix(string &infix) {
    string output = "";
    Stack s(infix.size());
    for (char c : infix) {
        if (isalnum(c)) { 
            output += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                output += s.pop();
            }
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                output += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        output += s.pop();
    }
    return output;
}

string infix_to_prefix(string &infix) {

    reverse(infix.begin(), infix.end());

    for (size_t i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string postfix = infix_to_postfix(infix);

    reverse(postfix.begin(), postfix.end());
    return postfix;
}
int main() {
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";   
    cout << "Infix Expression: " << infix << endl;

    string postfix = infix_to_postfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    string prefix = infix_to_prefix(infix);
    cout << "Prefix Expression: " << prefix << endl;
    return 0;
}