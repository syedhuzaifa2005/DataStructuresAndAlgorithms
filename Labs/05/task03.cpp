#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(value);
    }

    void printList() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        head = reverseRecursively(head);
    }

private:
    Node* reverseRecursively(Node* node) {
        if (!node || !node->next) {
            return node;
        }

        Node* newHead = reverseRecursively(node->next);

        node->next->next = node;
        node->next = nullptr;

        return newHead;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    
    cout << "Original list: ";
    list.printList();
    
    list.reverse();
    
    cout << "Reversed list: ";
    list.printList();
    
    return 0;
}
