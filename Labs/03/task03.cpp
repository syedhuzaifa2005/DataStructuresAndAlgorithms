#include <iostream>
using namespace std;

class LinkedList;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
    friend class LinkedList;
};

class LinkedList {
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void segregateEvenOdd(){
        if(head == NULL  ||  head->next == NULL){
            return;
        }
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* curr = head;
        while(curr != NULL){
            int value = curr->data;

            if(value % 2 == 0){
                if(evenStart == NULL){
                    evenStart = curr;
                    evenEnd = evenStart;
                } else{
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
            } else{
                if(oddStart == NULL){
                    oddStart = curr;
                    oddEnd = oddStart;
                } else{
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }
            curr = curr->next;
        }
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        head = evenStart;
    }
};


int main(){
    LinkedList list;
    list.append(3);
    list.append(7);
    list.append(2);
    list.append(9);
    list.append(10);
    list.append(6);
    list.append(5);
    list.printList();
    list.segregateEvenOdd();
    list.printList();
}