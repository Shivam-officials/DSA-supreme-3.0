#include <iostream>
using namespace std;

#include <iostream>

class Node {
    public: // this was missing
    int data;
    Node* next;
    
};

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    // Node* head = nullptr;
    // Node* second = nullptr;
    // Node* third = nullptr;
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    printList(head);

    return 0;
}