#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void separateEvenOdd(const stack<int>& inputStack, stack<int>& evenStack, stack<int>& oddStack) {
    stack<int> tempStack = inputStack;

    while (!tempStack.empty()) {
        int value = tempStack.top();
        tempStack.pop();
        
        if (value % 2 == 0) {
            evenStack.push(value);
        } else {
            oddStack.push(value);
        }
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> inputStack;
    vector<int> inputValues = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int value : inputValues) {
        inputStack.push(value);
    }

    stack<int> evenStack;
    stack<int> oddStack;

    separateEvenOdd(inputStack, evenStack, oddStack);

    cout << "Even Stack: ";
    printStack(evenStack);

    cout << "Odd Stack: ";
    printStack(oddStack);

    return 0;
}