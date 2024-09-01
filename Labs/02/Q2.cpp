#include <iostream>
#include "matrixmultiply.h"

using namespace std;


int main(){
	int rowsa =2;
	int rowsb =2;
	int colsa =2;
	int colsb =2;
	int **a = new int*[rowsa];
	for (int i = 0; i < rowsa; i++){
		a[i] = new int[colsa];
	}
	int **b = new int*[rowsb];
	for (int i = 0; i < rowsb; i++){
		b[i] = new int[colsb];
	}
	int **c = new int*[rowsa];
	for (int i = 0; i < rowsa; i++){
		c[i] = new int[colsb];
	}
	for (int i = 0; i < rowsa; i++){
		for (int j = 0; j < colsa; j++){
			cout << "Enter the value of element " << j << " of row " << i << endl;
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < rowsb; i++){
		for (int j = 0; j < colsb; j++){
			cout << "Enter the value of element "<< j << " of row " << i << endl;
			cin >> b[i][j];
		}
	}
	multiplymatrix(a, b, c, rowsa, colsa, colsb);
	
	
	for (int i = 0; i < rowsa; i++){
		for (int j = 0; j < colsb; j++){
			cout << "The element " << j << " of row "<< i << " is" << c[i][j] << endl;
		}
	}
	
	for (int i = 0; i < rowsa; i++) delete[] a[i];
    delete[] a;

    for (int i = 0; i < rowsb; i++) delete[] b[i];
    delete[] b;

    for (int i = 0; i < rowsa; i++) delete[] c[i];
    delete[] c;
	
	return 0;
}
