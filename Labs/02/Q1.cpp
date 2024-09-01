#include <iostream>
using namespace std;



int main(){
    int ** arr = new int*[3];
    int size[3];
    for (int i = 0; i < 3; i++){
        size[i]=5;
        arr[i] = new int [size[i]];
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < size[i]; j++){
            cout << "Enter the "<< j <<" element of row "<< i;
            cin >> arr[i][j];
        }
        cout << endl;
    }
   int  newsize = 10;
    for (int i = 0; i < 3; i++){
        int * newrow = new int[newsize];
        int j;
        for (j = 0; j < size[i]; j++){
            newrow[j] = arr[i][j];
        }
        for ( j = size[i]; j < newsize; j++) {
            cout << "enter the "<< j <<" element of row "<< i; 
            cin >> newrow[j];
        }
        cout << endl;
    
    
    
    delete[] arr[i]; 
        arr[i] = newrow; 
        size[i] = newsize;
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < size[i]; j++){
            cout << "Element " << j << " of row " << i << " is" << arr[i][j] << endl;
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++){
        delete [] arr[i];
    }
    delete [] arr;
    
    return 0;
}
