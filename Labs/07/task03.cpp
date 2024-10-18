#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student* next;

    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};

void insertStudent(Student*& head, string name, int score) {
    Student* newStudent = new Student(name, score);
    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

int getDigit(int number, int place) {
    return (number / place) % 10;
}

void radixSort(Student*& head) {
    const int RADIX = 10;
    vector<Student*> buckets[RADIX];

    for (int place = 1; place <= 100; place *= 10) {
        // Clear the buckets
        for (int i = 0; i < RADIX; i++) {
            buckets[i].clear();
        }

        Student* current = head;
        while (current) {
            int digit = getDigit(current->score, place);
            buckets[digit].push_back(current);
            current = current->next;
        }

        head = nullptr;
        Student* tail = nullptr;
        for (int i = 0; i < RADIX; i++) {
            for (Student* student : buckets[i]) {
                if (!head) {
                    head = student;
                    tail = student;
                } else {
                    tail->next = student;
                    tail = tail->next;
                }
            }
        }

        if (tail) {
            tail->next = nullptr;
        }
    }
}

void displayStudents(Student* head) {
    cout << "Sorted student records:\n";
    while (head) {
        cout << head->name << " - " << head->score << endl;
        head = head->next;
    }
}

int main() {
    Student* students = nullptr;

    int n;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score of " << name << ": ";
        cin >> score;
        insertStudent(students, name, score);
    }

    radixSort(students);

    displayStudents(students);
}

