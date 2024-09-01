#include <iostream>
using namespace std;

void checkfriendship(bool **array, int checkfriend1, int checkfriend2){
	for (int i=0; i<5; i++){
    	if (array[checkfriend1][i]==true){
    		if(array[checkfriend2][i]==true){
				cout<<checkfriend1<<"and"<<checkfriend2<<"have a mutual friend"<<i<<endl;
            }
		}
		else{
			continue;
		}
	}
}
	
int main() {
    bool **array = new bool*[5];
    for (int i = 0; i < 5; i++) {
        array[i] = new bool[5];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 1 && j == 1) ||
                (i == 1 && j == 3) || (i == 2 && j == 0) || (i == 2 && j == 2) ||
                (i == 2 && j == 3) || (i == 2 && j == 4) || (i == 3 && j == 1) ||
                (i == 3 && j == 2) || (i == 3 && j == 3) || (i == 4 && j == 2) ||
                (i == 4 && j == 4)) {
                array[i][j] = false;
            } else {
                array[i][j] = true;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (array[i][j] == true) {
                cout << "* ";
            } else {
                cout << "  ";  
            }
        }
        cout << endl;
    }
    
    int checkfriend1;
    int checkfriend2;
    
    cout << "enter the friend 1"<<endl;
    cin >> checkfriend1;
    cout << "enter the friend 2"<<endl;
    cin >> checkfriend2;
    
	checkfriendship(array, checkfriend1, checkfriend2);

    for (int i = 0; i < 5; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}