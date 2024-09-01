#include <iostream>
using namespace std;

int main(){
	int departments = 4;
	int courses[departments] = {3, 4, 2, 1};
	float **gpa = new float *[departments];
	for(int i=0; i<departments; i++){
		gpa[i] = new float [courses[i]];
	}
	
	for(int i=0; i<departments; i++){
	    if (i == 0){
            cout << "Software Engineering";
        } else if(i == 1){
            cout << "Artificial Intelligence";
        } else if(i == 2){
            cout << "Computer Science";   
        } else if(i == 3){
            cout << "Data Science";
        } 
		for(int j=0; j<courses[i]; j++){
			cout << "Enter the gpa of the course " << j << endl;
			cin >> gpa[i][j];
		}
	}
	
	for(int i=0; i<departments; i++){
	    if (i == 0){
            cout << "Software Engineering";
        } else if(i == 1){
            cout << "Artificial Intelligence";
        } else if(i == 2){
            cout << "Computer Science";   
        } else if(i == 3){
            cout << "Data Science";
        } 
		for (int j = 0; j < courses[i]; j++){
			cout << "The gpa of course " << j << " is " << gpa[i][j] << endl;
		}
	}
	
	for(int i=0; i<departments; i++){
		delete [] gpa[i];
	}
	delete [] gpa;
	return 0;
}