#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            throw runtime_error("Queue is empty");
        }

        int value = stack2.top();
        stack2.pop();
        return value;
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    int size() {
        return stack1.size() + stack2.size();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    queue.enqueue(4);

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    if (queue.isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
