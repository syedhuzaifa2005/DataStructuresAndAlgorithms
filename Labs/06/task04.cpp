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

    int peek() {
        if (!isEmpty()) {
            return top->data;
        }
        return -1;
    }
};

class Queue {
    Stack stack1, stack2;

public:

    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (stack1.isEmpty() && stack2.isEmpty()) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                int value = stack1.pop();
                stack2.push(value);
            }
        }
        return stack2.pop();
    }

    bool isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    q.enqueue(50);
    q.enqueue(60);

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    return 0;
}
