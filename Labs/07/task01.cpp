#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int data){
        value = data;
        next = NULL;
    }
    friend class LinkedList;
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void append(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int countNodes(){
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

Node* getTail(Node* cur) {
    while(cur != NULL && cur->next != NULL) {
        cur = cur->next;
    }
    return cur;
}

Node* PartitionLinkedList(Node* head, Node* end, Node** newHead, Node** newEnd){
    Node* pivot = end;
    Node* prev = NULL;
    Node* cur = head;
    Node* tail = pivot;
    while(cur != pivot) {
        if(cur->value < pivot->value) {
            if(*newHead == NULL) {
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else {
            if(prev) {
                prev->next = cur->next;
            }
            Node* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if(*newHead == NULL) {
        *newHead = pivot;
    }

    *newEnd = tail;

    return pivot;
}

Node* QuickSortRecur(Node* head, Node* end){
    if(!head || head == end) {
        return head;
    }
    Node* newHead = NULL;
    Node* newEnd = NULL;
    Node* pivot = PartitionLinkedList(head, end, &newHead, &newEnd);
    if(newHead != pivot){
        Node* temp = newHead;
        while(temp->next != pivot){
            temp = temp->next;
        }
        temp->next = NULL;
        newHead = QuickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    pivot->next = QuickSortRecur(pivot->next, newEnd);
    return newHead;
}

Node* QuickSortLinkedList(Node* head) {
    return QuickSortRecur(head, getTail(head));
}


int main(){
    cout << "Sorting an Array using QUICK Sort:" << endl;
    int arr[] = {7, 6, 10, 9, 35, 2, 18, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    QuickSortArray(arr, 0, n - 1);
    cout << "Sorted Array using Quick Sort:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Sorting a Linked List using QUICK Sort:" << endl;
    LinkedList LL1;
    LL1.append(10);
    LL1.append(7);
    LL1.append(8);
    LL1.append(9);
    LL1.append(1);
    LL1.append(5);
    LL1.append(3);
    cout << "Unsorted Linked List:" << endl;
    LL1.display();
    LL1.head = QuickSortLinkedList(LL1.head);
    cout << "Sorted Linked List using Quick Sort:" << endl;
    LL1.display();
}
