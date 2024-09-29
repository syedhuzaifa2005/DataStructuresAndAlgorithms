#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

class Stack {
private:
    Node* head;;
    int capacity;
    int currsize;
public:
    Stack(int c){
        this->capacity = c;
        this->currsize = 0;
        head = NULL;
    }

    bool isEmpty(){
        return this->head == NULL;
    }

    bool isFull(){
        return this->currsize == this->capacity;
    }

    void push(int d){
        if(this->currsize == this->capacity){
            cout << "OVERFLOW" << endl;
            return;
        }
        Node* new_node = new Node(d);
        new_node->next = this->head;
        this->head = new_node;
        this->currsize++;
    }

    int pop(){
        if(this->head == NULL){
            cout << "UNDERFLOW" << endl;
            return INT_MIN;
        }
        Node* new_head = this->head->next;
        this->head->next = NULL;
        Node* toBeRemoved = this->head;
        int result = toBeRemoved->data;
        delete this->head;
        this->head = new_head;
        return result;
    }

    int getTop(){
        if(this->head == NULL){
            cout << "UNDERFLOW" << endl;
            return INT_MIN;
        }
        return this->head->data;
    }

    int size(){
        return this->currsize;
    }
};

int main() {
    Stack s1(5);
    s1.push(2);
    s1.push(3);
    s1.push(5);
    cout << s1.getTop() << endl;
    s1.push(7);
    s1.push(9);
    cout << s1.getTop() << endl;
    s1.push(10);

    s1.pop();
    s1.pop();
    s1.pop();
    cout << s1.getTop() << endl;

    return 0;
}
