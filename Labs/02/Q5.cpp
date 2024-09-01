#include <iostream>
#include <string>
using namespace std;

void bookseat(string ** conference, int flag){
	int row; 
	int col;
	string name;

	cout << "Enter the row you want to book " << endl;
	cin >> row;
	cout << "Enter the column you want to book " << endl;
	cin >> col;
	cout << "Enter your name" << endl;
	cin >> name;
	
	conference[row][col] = name;
	flag = 1;
}

int main(){
	int rows = 2;
	int cols = 2;
	int flag = 0;
	
	string **conference = new string *[rows];
	for(int i = 0; i < rows; i++){
		conference[i] = new string[cols];
	}
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(flag == 0){
			conference[i][j] = "not booked";
		    }
	    }
	}
	
	bookseat(conference, flag);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
		    cout << conference[i][j];
		}
		cout<<endl;
	}
return 0;
}