#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    friend class TicktQueueLinkedList;
};

class TicketQueueLinkedList {
private:
    Node* front;
    Node* rear;
    int size;

public:
    TicketQueueLinkedList() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int passenger_id) {
        Node* temp = new Node();
        temp->data = passenger_id;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No passengers to remove." << endl;
        } else {
            Node* temp = front;
            cout << "Passenger " << front->data << " has been removed from the queue." << endl;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* temp = front;
            cout << "Current queue: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    TicketQueueLinkedList tq;

    cout << "Adding 10 passengers to the queue:" << endl;
    for (int i = 1; i <= 10; i++) {
        tq.enqueue(i);
    }
    tq.displayQueue();

    cout << "\nRemoving the first 5 passengers:" << endl;
    for (int i = 1; i <= 5; i++) {
        tq.dequeue();
    }
    tq.displayQueue();

    cout << "\nAttempting to add 5 more passengers to the queue:" << endl;
    for (int i = 11; i <= 15; i++) {
        tq.enqueue(i);
    }
    tq.displayQueue();

    return 0;
}
