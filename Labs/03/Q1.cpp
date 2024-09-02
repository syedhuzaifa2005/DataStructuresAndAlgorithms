#include<iostream>

using namespace std;

class Node{
    private:
        int data;
        Node* next;

    public:
        Node() {
            data = 0;
            next = NULL;
        }
        Node(const int val) {
            data = val;
            next = NULL;
        }
        friend class testLinkList;

};

class testLinkList{
    private:
        Node* head;

    public:
        testLinkList() {
            head = NULL;
        }
        testLinkList(Node* n) {
            head = n;
        }

        void insert_start(const int val){
            Node* n = new Node(val);
            if(head == NULL) {
                head = n;
            } else {
                n->next = head;
                head = n;
            }
        }

        void insert_end(const int val) {
            Node* n = new Node(val);
            if(head == NULL) {
                head == n;
            } else {
                Node* current = head;
                while(current->next != NULL){
                    current = current->next;
                }
                current->next = n;
                n->next = NULL;
            }
        }

        void insert_After(const int value, const int insertingVal) {
            if(head != NULL){
                Node* n = new Node(insertingVal);
                Node* currentptr = head;
                while(currentptr->data != value) {
                    currentptr = currentptr -> next;
                } 
                n-> next = currentptr->next;
                currentptr->next = n;
            } else {
                cout<<"no node with this value"<<endl;
            }
        }

        void insert_Before(const int value, const int insertingVal) {
            if(head != NULL) {
                Node* n = new Node(insertingVal);
                Node* currentptr = head;
                while(currentptr->next->data != value) {
                    currentptr = currentptr -> next;
                }
                n-> next = currentptr->next;
                currentptr->next = n;
            } else {
                cout<<"the value doesnt exist in the LL"<<endl;
            }
        }

        void delete_Head() {
            if(head != NULL) {
                Node* currentptr = head;
                head = currentptr-> next;
                delete currentptr;
                currentptr = NULL;
            } else {
                cout<<"List has no nodes to delete at head"<<endl;
            }
        }

        void delete_Tail() {
            if(head != NULL) {
                Node* currentptr = head;
                while(currentptr->next->next != NULL){
                    currentptr = currentptr-> next;
                }
                Node* temp = currentptr-> next;
                currentptr->next = NULL;
                delete temp;
                temp = NULL;
            } else{
                cout<<"\nthe list is already empty"<<endl;
            }
        }

        void delete_at_val(const int val) {
            if(head != NULL) {
                Node* currentptr = head;
                while(currentptr->data != val) {
                    currentptr = currentptr -> next;
                }
                Node* temp = currentptr->next;
                currentptr->next = temp->next;
                delete temp;
            }
        }

        void count_Nodes() {
            int sum = 0;
            Node* currentptr = head;
            if(head != NULL) {
                while(currentptr->next != NULL) {
                    sum = sum + 1;
                    currentptr = currentptr->next;
                }
                cout<<"the number of node in the linked list are "<<sum+1<<endl;
            } else {
                cout<<"number of nodes is 0"<<endl;
            }
        }

        void display_List() {
            Node* currentptr = head;
            while(currentptr != NULL) {
                cout<<currentptr->data<<"->";
                currentptr = currentptr->next;
            }
            cout<<"END OF LIST"<<endl;
            
        }
};

int main () {
    testLinkList test_list;
    test_list.insert_start(5);
    test_list.insert_start(6);
    test_list.insert_start(7);
    test_list.insert_start(8);
    test_list.insert_start(9);
    test_list.display_List();

    test_list.insert_end(10);
    test_list.insert_end(11);
    test_list.insert_end(12);
    test_list.insert_end(13);
    test_list.insert_end(14);
    test_list.display_List();
    test_list.insert_After(8,50);
    test_list.insert_Before(8,40);
    test_list.display_List();

    test_list.delete_Head();
    test_list.delete_Tail();
    test_list.delete_at_val(12);
    test_list.display_List();
    test_list.count_Nodes();
}