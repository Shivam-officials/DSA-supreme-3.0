#include <iostream>
#include <iterator>

using namespace std;


//idea:tail bhul jao ye khi ni milta Linked List me leetcode wagerah pe to bhul jao

class Node {
public:
  int data;
  Node *next;

  Node(int _value) : data(_value) { next = nullptr; }

  ~Node(){
    delete next;
  }
};

// return the ptr advanceThePtr from specific position to specific steps simply
// return 0 based index..doesnot modify original pointer
Node *advanceThePtr(Node *itr, int steps) {
  for (int i = 0; i < steps; i++) {
    itr = itr->next;
  }
  return itr;
}

//length of sinly LL
int getLengthOfLL(Node* &head){
    Node* temp = head;
    int lengthOfLL = 0;
    while(temp !=nullptr){
        lengthOfLL++;
        temp = temp->next;
    }
    return lengthOfLL;
}

//*delete in LL
void deleteNode(int position, Node *&head, Node *&tail) {

  int lengthOfLL = getLengthOfLL(head) ;
  // CASE 1: when LL is empty
  if (head == nullptr && tail == nullptr) {

    cout << "LL is empty \n";
    return;

  } else 
  
  if (head == tail) //CASE 2:  when there is only one node
  {

    Node *temp = head;
    head = nullptr;
    tail = nullptr;
    delete temp;
    cout << "only 1 done left was deleted\n";
    return;

  } else 
  
  if (position == 1) { //CASE 3:  deleting the head in LL

    Node *temp = head;
    head = head->next;
    temp->next = nullptr; //*ISOLATING THE NODE BEFORE DELETING works without it bt sometimes show unusual behaviour so its IMP
    delete temp;
    cout << "head has been deleted\n";
    return;

  } else {  //CASE 4:deleting at specific case 

    Node *previous = advanceThePtr(head, position - 2); // position -2 bcz of this function works on zero based index and LL need 1 based indexs
    Node *currentNode = previous->next;
    previous->next = currentNode->next; // or
    // temp->next = temp->next->next;
    currentNode->next = nullptr; //*ISOLATING THE NODE BEFORE DELETING
    delete currentNode;

    // Print a message indicating the specific node has been deleted
    cout << "specific node has been deleted at position no: " << position << endl;

    // If the deleted node was the last node, update the tail pointer
    if(position == lengthOfLL){
      tail = previous;
    }

    return;

  }
}

// passing head and tail is imp to insert for knowing linkedlist state
Node *insertAtHead(int _value, Node *&head, Node *&tail) {
  // if linked list is empty then both taill and head will be poiting at null
  Node *newNode = new Node(_value);
  if (head == nullptr && tail == nullptr) {

    head = newNode; // after one value both head and tail will be poiting
                    // towards same node
    tail = newNode;
  } else {

    newNode->next = head;
    head = newNode;
  }
  return head;
}

Node *insertAtTail(int _value, Node *&head, Node *&tail) {
  // if linked list is empty then both taill and head will be poiting at null
  Node *newNode = new Node(_value);
  if (head == nullptr && tail == nullptr) {

    head = newNode; // after one value both head and tail will be poiting
                    // towards same node
    tail = newNode;
  } else {

    tail->next = newNode;
    tail = newNode;
  }
  return tail;
}

// deost not change original head bcz of pass by copy
void printLinkedList(Node *head) {
  while (head != nullptr) {
    cout << head->data << "->";
    // head = advanceThePtr(head,1); // both works
    head = head->next;
  }
  cout << "nullptr\n" << endl;
}

int main(int argc, char const *argv[]) {

  // //dynamic memory object creation
  // Node* first = new Node(5);
  // cout << first->data<<" "<<first->next;

  Node *head = nullptr;
  Node *tail = nullptr;

  // LL is empty
  head = insertAtHead(10, head, tail);
  // 10->nullptr
  printLinkedList(head);

  head = insertAtHead(20, head, tail);
  // 20 -> 10->nullptr
  printLinkedList(head);

  head = insertAtHead(30, head, tail);
  // 30 -> 20 -> 10->nullptr
  printLinkedList(head);

  head = insertAtHead(40, head, tail);
  // 40 -> 30 -> 20 -> 10->nullptr
  printLinkedList(head);

  head = insertAtHead(50, head, tail);
  // 50 -> 40 -> 30 -> 20 -> 10->nullptr
  printLinkedList(head);

  deleteNode(3, head, tail);
  printLinkedList(head);

  return 0;
}
