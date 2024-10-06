// Implementation using circular queue
#include <iostream>
using namespace std;

class TicketQueue {
private:
    int front, rear, size;
    int queue[10];
    const int max_size = 10;

public:
    TicketQueue() {
        front = 0;
        rear = 0;
        size = 0;
    }

    bool isFull() {
        return size == max_size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int passenger_id) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more passengers." << endl;
        } else {
            queue[rear] = passenger_id;
            rear = (rear + 1) % max_size;
            size++;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No passengers to remove." << endl;
        } else {
            cout << "Passenger " << queue[front] << " has been removed from the queue." << endl;
            front = (front + 1) % max_size;
            size--;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Current queue: ";
            for (int i = 0; i < size; i++) {
                cout << queue[(front + i) % max_size] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TicketQueue tq;

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
