#include <iostream>
#include <cstring>
using namespace std;

class Document {
private:
    char* content;

public:
    Document(const char* initialContent) {
        content = new char[strlen(initialContent) + 1];
        strcpy(content, initialContent);
    }

    ~Document() {
        delete[] content;
    }

    Document(const Document& other) {
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
    }

    Document& operator=(const Document& other) {
        if (this == &other) {
            return *this;
        }

        delete[] content;

        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);

        return *this;
    }

    void setContent(const char* newContent) {
        delete[] content;
        content = new char[strlen(newContent) + 1];
        strcpy(content, newContent);
    }

    void display() const {
        cout << "Document content: " << content << endl;
    }
};

int main() {
    Document doc1("Original Document Content");
    cout << "Original Document (doc1):" << endl;
    doc1.display();

    Document doc2 = doc1;
    cout << "\nCopied Document (doc2) using copy constructor:" << endl;
    doc2.display();

    doc1.setContent("Modified Document Content");
    cout << "\nModified Original Document (doc1):" << endl;
    doc1.display();

    cout << "\nCopied Document (doc2) after modifying original document:" << endl;
    doc2.display();

    Document doc3("Temporary Content");
    doc3 = doc1;
    cout << "\nCopied Document (doc3) using copy assignment operator:" << endl;
    doc3.display();
}

