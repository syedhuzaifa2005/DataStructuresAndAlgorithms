#include <iostream>
using namespace std;

// Write a program to sort a doubly linked list and remove duplicates from the sorted list.

class Node{
public:
    int value;
    Node* prev;
    Node* next;

    Node(int val){
        value = val;
        prev= NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void append(int value){
        Node* new_node = new Node(value);
        if(tail == NULL){
            head = new_node;
            tail = new_node;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void sortList(Node* &head, Node* &tail){
    if(!head){
        return;
    }

    bool swapped;
    Node* curr;
    do{
        curr = head;
        swapped = false;
    
        while(curr->next != NULL){
            if(curr->value > curr->next->value){
                swap(curr->value, curr->next->value);
                swapped = true;
            }
            curr = curr->next;
        }
    } while(swapped);
}

void removeDuplicates(Node* &head, Node* &tail){
    if(!head){
        return;
    }
    Node* curr = head;
    while(curr != NULL  &&  curr->next != NULL){
        if(curr->value == curr->next->value){
            Node* temp = curr->next;
            curr->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = curr;
            } else{
                curr = tail;
            }
            delete temp;
        } else{
            curr = curr->next;
        }
    }
}

int main(){
    DoublyLinkedList dll1;
    dll1.append(4);
    dll1.append(2);
    dll1.append(4);
    dll1.append(8);
    dll1.append(3);
    dll1.append(4);
    dll1.append(8);
    cout << "Doubly Linked List:" << endl;
    dll1.display();
    sortList(dll1.head, dll1.tail);
    cout << "Sorted List:" << endl;
    dll1.display();
    removeDuplicates(dll1.head, dll1.tail);
    cout << "Sorted List with NO Duplicates:" << endl;
    dll1.display();

}