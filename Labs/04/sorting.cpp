#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(v[i], v[minIndex]);
        }
    }
}

void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0  &&  v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}

void shellSort(vector<int>& v) {
    int n = v.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            
            v[j] = temp;
        }
    }
}


int main() {
    vector<int> v1 = {6, 2, 1, 8, 9, 3};
    bubbleSort(v1);
    cout << "Sorted array using BubbleSort: ";
    for(int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;


	vector<int> v2 = {7, 1, 4, 2, 3};
	selectionSort(v2);
	cout << "Sorted array using Selection Sort: ";
	for(int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
    
    
    vector<int> v3 = {4, 3, 2, 10, 12, 1, 5, 6};
	insertionSort(v3);
	cout << "Sorted array using Insertion Sort: ";
	for(int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;


	vector<int> v4 = {23, 29, 15, 19, 31, 7, 9, 5, 2};
	shellSort(v4);
	cout << "Sorted array using Shell Sort: ";
	for(int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

    return 0;
}
