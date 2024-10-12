#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void separateEvenOdd(Stack& original, Stack& evenStack, Stack& oddStack) {
    while (!original.isEmpty()) {
        int value = original.pop();
        if (value % 2 == 0) {
            evenStack.push(value);
        } else {
            oddStack.push(value);
        }
    }
}

int main() {
    Stack original, evenStack, oddStack;

    original.push(10);
    original.push(15);
    original.push(20);
    original.push(25);
    original.push(30);
    separateEvenOdd(original, evenStack, oddStack);

    cout << "Even stack: ";
    evenStack.display();

    cout << "Odd stack: ";
    oddStack.display();

    return 0;
}
