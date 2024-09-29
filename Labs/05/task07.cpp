#include <iostream>
#include <climits>
using namespace std;

class Stack{
private:
    int capacity;
    int* arr;
    int top;
public:
    Stack(int c){
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int value){
        if(this->top == (this->capacity - 1)){
            cout << "OVERFLOW" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = value;
    }

    int pop(){
        if(this->top == -1){
            cout << "UNDERFLOW" << endl;
            return INT_MIN;
        }
        this->top--;
    }

    int getTop(){
        if(this->top == -1){
            cout << "UNDERFLOW" << endl;
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    bool isEmpty(){
        return this->top == -1;
    }

    int size(){
        return this->top + 1;
    }

    bool isFull(){
        return this->top == (this->capacity - 1);
    }
};

int main(){
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
}
