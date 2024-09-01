#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName; 
    char* examDate;     
    int score;

public:
    Exam(const char* name, const char* date, int score) {
        studentName = strdup(name);
        examDate = strdup(date);
        this->score = score;
    }
    void setDetails(const char* name, const char* date, int score) {
        delete[] studentName;
        delete[] examDate;
        studentName = strdup(name);
        examDate = strdup(date);
        this->score = score;
    }
    void display() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }
    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }
};

int main() {
    Exam exam1("Student 1", "19-08-2024", 87);
    cout << "Exam 1 details:" << endl;
    exam1.display();

    Exam exam2 = exam1;
    cout << "\nExam 2 details (after shallow copy):" << endl;
    exam2.display();

    exam2.setDetails("Student 2", "21-08-2024", 79);

    cout << "\nExam 1 details (after modifying Exam 2):" << endl;
    exam1.display();
    cout << "\nExam 2 details (after modification):" << endl;
    exam2.display();
}

