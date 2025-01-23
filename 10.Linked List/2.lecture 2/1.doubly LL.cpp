#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int _value):data(_value),next(nullptr),prev(nullptr){};

    //dtor
    ~Node(){
        delete next;
        delete prev;
    }
};

// returns a advanced ptr from head to specified steps without changing original head ptr
Node* advanceThePtr(Node* &head,int steps){
    Node* temp = head;
    for(int i = 0;i<steps;i++){
        temp = temp->next;
    }
    return temp;
}

Node* insertAtHead(int _value,Node* &head, Node* &tail){
    //creating new node
    Node* newNode = new Node(_value);

    //if doubly LL is empty
    if(head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
    }else //if LL is not empty
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* insertAtTail(int _value,Node* &head, Node* &tail){
    //creating new node
    Node* newNode = new Node(_value);

    //if doubly LL is empty
    if(head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
    }else // if LL is not empty
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return tail;
}

int getLengthOfLL(Node* &head){
    Node* temp = head;
    int lengthOfLL = 0;
    while(temp !=nullptr){
        lengthOfLL++;
        temp = temp->next;
    }
    return lengthOfLL;
}

// enters the value at specific position withiin valid range(1 to n+1 [n == length of LL])
void insertAtPosition(int _value,int position, Node* &head, Node* &tail){

    //creating new node
    Node* newNode = new Node(_value);

    int lengthOfLL = getLengthOfLL(head);

    //if doubly LL is empty
    if(position == 1){
        insertAtHead(_value, head, tail);
    }else if (position == lengthOfLL+1) {
        insertAtTail(_value, head, tail);
    }else 
    {   
        //addressign requried nodes
        Node* prevNode = advanceThePtr(head, position-2);
        Node* forwardNode = prevNode->next;

        //making back link
        prevNode->next = newNode;
        newNode->prev = prevNode;

        //making forward link
        newNode->next = forwardNode;
        forwardNode->prev = newNode;
       

    }


}

void printLinkedList(Node* &head){
    Node* temp = head;
    cout << "nullptr ";
    while(temp != nullptr){
        cout<<" "<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

void printLinkedListReverse(Node* &tail){
    Node* temp = tail;
    cout << "\nLL in reverse order \nnullptr ";
    while(temp != nullptr){
        cout<<"<-"<<temp->data<<" ";
        temp = temp->prev;
    }
    cout << "nullptr\n";
}


int searchingInLL(int _value,Node* &head){

    Node* itr = head;
    int position = 0;
    while(itr != nullptr){
        position++;
        if(itr->data == _value){
            return position; // returns the 1 based index as ans
        }

        itr = itr->next;
    }
    return -1;
}



void deleteAtSpecificPoint(int _position, Node* &head, Node* &tail){


    int lengthOfLL =  getLengthOfLL(head);

    if(head == nullptr && tail == nullptr) { //CASE 1 : LL EMPTY

        cout << "Linked is empty \n";
        return;

    }else if (head == tail)  { //CASE 2 : LL have only 1 one node

        delete head;
        head = nullptr;
        tail = nullptr;
        
    }else if (_position == 1) { //CASE 3 : when we have to head node

        Node* itr = head;

        head = head->next;
        head->prev = nullptr;

        //isolating the to be deleting node
        itr->next = nullptr;

        //deleting the node 
        delete itr;

    }else if ( _position == lengthOfLL){ //CASE 4: when we have to delete tail
    
        Node* temp = tail->prev;

        Node* nodeToBeDeleted = tail;

        //isolating the tail node
        temp->next = nullptr;
        nodeToBeDeleted->prev = nullptr;
         
        //deleting the node 
        delete nodeToBeDeleted;

        //updating the tail
        tail = temp;
        
    } else{ // CASE 5: when deleting in between
     
        
        //adressing the node
        Node* prevNode = advanceThePtr(head, _position-2);
        Node* nodeToBeDeleted = prevNode->next;
        Node* forwardNode = nodeToBeDeleted->next;

        // making link
        prevNode->next = forwardNode;
        forwardNode->prev = prevNode;

        //isolating the nodeToBeDeleted
        nodeToBeDeleted->next = nullptr;
        nodeToBeDeleted->prev = nullptr;

        //deleting the node 
        delete nodeToBeDeleted;
    }

}


int main(int argc, char const *argv[])
{

    
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtHead(5, head, tail);
    printLinkedList(head); // Output: nullptr  5  nullptr

    insertAtHead(4, head, tail);
    printLinkedList(head); // Output: nullptr  4  5  nullptr

    insertAtHead(3, head, tail);
    printLinkedList(head); // Output: nullptr  3  4  5  nullptr

    insertAtHead(2, head, tail);
    printLinkedList(head); // Output: nullptr  2  3  4  5  nullptr

    insertAtHead(1, head, tail);
    printLinkedList(head); // Output: nullptr  1  2  3  4  5  nullptr

    insertAtTail(6, head, tail);
    printLinkedList(head); // Output: nullptr  1  2  3  4  5  6  nullptr

    insertAtTail(7, head, tail);
    printLinkedList(head); // Output: nullptr  1  2  3  4  5  6  7  nullptr

    insertAtTail(8, head, tail);
    printLinkedList(head); // Output: nullptr  1  2  3  4  5  6  7  8  nullptr

    insertAtTail(9, head, tail);
    printLinkedList(head); // Output: nullptr  1  2  3  4  5  6  7  8  9  nullptr

    
    insertAtTail(10, head, tail);
    printLinkedList(head); // Output: nullptr  1  2  3  4  5  6  7  8  9  10  nullptr
    
    // Insert 111 at position 11
    insertAtPosition(111, 11, head, tail);
    printLinkedList(head); // Output: nullptr  1  2  3  4  5  6  7  8  9  10  111  nullptr

    
    // cout << searchingInLL(3, head)<<endl; // 3

    // Delete the node at position 11
    deleteAtSpecificPoint(11, head, tail);

    // Print the linked list in reverse order
    printLinkedListReverse(tail);

    // Print the linked list in forward order
    printLinkedList(head);

    return 0;
}
