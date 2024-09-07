#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int val){
        value = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int value){
    Node* new_node = new Node(value);
    if(head == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

void insertAtTail(Node* &head, Node* &tail, int value){
    Node* new_node = new Node(value);
    if(tail == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}

void insertAfterGivenPosition(Node* &head, int value, int position){
    Node* temp = head;
    int curr = 0;
    while(curr != position - 1){
        temp = temp->next;
        curr++;
    }
    Node* new_node = new Node(value);
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next->prev = new_node;
}

void insertBeforeGivenPosition(Node* &head, int value, int position){
    Node* temp = head;
    int curr = 0;
    while(curr != position - 2){
        temp = temp->next;
        curr++;
    }
    Node* new_node = new Node(value);
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next->prev = new_node;
}

void deleteAtHead(Node* &head, Node* &tail){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    if(head == NULL){
        tail = NULL;
    } else{
        head->prev = NULL;
    }
    delete temp;
}

void deleteAtTail(Node* &head, Node* &tail){
    if(tail == NULL){
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    if(tail == NULL){
        head = NULL;
    } else{
        tail->next = NULL;
    }
    delete temp;
}

void deleteFromGivenPosition(Node* &head, Node* &tail, int position){
    if(position == 1){
        deleteAtHead(head, tail);
        return;
    }
    Node* previous = head;
    int curr = 1;
    while(curr != position - 1){
        previous = previous->next;
        curr++;
    }
    Node* temp = previous->next;
    previous->next = previous->next->next;
    previous->next->next->prev = previous->next;
    delete temp;

}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->value << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
// Insert At head
    insertAtHead(head, tail, 6);
    display(head);
    insertAtHead(head, tail, 3);
    display(head);
// Insert At tail
    insertAtTail(head, tail, 7);
    display(head);
    insertAtTail(head, tail, 5);
    display(head);
// Insert Before a position
    insertBeforeGivenPosition(head, 9, 2);
    display(head);
// Insert After a position
    insertAfterGivenPosition(head, 8, 3);
    display(head);
// Delete head
    deleteAtHead(head, tail);
    display(head);
// Delete tail
    deleteAtTail(head, tail);
    display(head);
// Delete at a certain position
    deleteFromGivenPosition(head, tail, 2);
    display(head);
}