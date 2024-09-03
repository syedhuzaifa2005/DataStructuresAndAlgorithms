#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    
    Node(int val){
        value = val;
        next = NULL;
    }
};

// Insert a Value at the Head
void insertAtHead(Node* &head, int value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

// Insert a Value at the Tail
void insertAtTail(Node* &head, int value){
    Node* new_node = new Node(value);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert at an arbitrary Position
void insertAtGivenPosition(Node* &head, int value, int position){
    if(position == 0){
        insertAtHead(head, value);
        return;
    }
    Node* new_node = new Node(value);
    Node* temp = head;
    int curr = 0;
    while(curr != position-1){
        temp = temp->next;
        curr++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Updating Value at given Position
void updateValue(Node* &head, int value, int position){
    Node* temp = head;
    int curr = 0;
    while(curr != position){
        temp = temp->next;
        curr++;
    }
    temp->value = value;
}

// Deleting the Value at Head
void deleteHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Deleting the Value at Tail
void deleteTail(Node* &head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// Deleting the Value at an Arbitrary Position
void deleteAtGivenPosition(Node* &head, int position){
    if(position == 0){
        deleteHead(head);
        return;
    }
    int curr = 0;
    Node* prev = head;
    while(curr != position-1){
        prev = prev->next;
        curr++;
    }
    Node* temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
}

// Count the Number of Nodes
int countNodes(Node* &head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// Displaying the List
void displayList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
// Insertion at Head
    insertAtHead(head, 4);
    displayList(head);
    insertAtHead(head, 9);
    displayList(head);
// Insertion at Tail
    insertAtTail(head, 3);
    displayList(head);
    insertAtTail(head, 2);
    displayList(head);
// Insertion at Position
    insertAtGivenPosition(head, 1, 2);
    displayList(head);
// Updating value at position
    updateValue(head, 10, 2);
    displayList(head);
// Deleting at Head
    deleteHead(head);
    displayList(head);
// Deleting at Tail
    deleteTail(head);
    displayList(head);
// Deleting at Position
    deleteAtGivenPosition(head, 1);
    displayList(head);
// Number of Nodes
    cout << "The Number of Nodes in the Linked List are " << countNodes(head) << endl;
    return 0;
}
