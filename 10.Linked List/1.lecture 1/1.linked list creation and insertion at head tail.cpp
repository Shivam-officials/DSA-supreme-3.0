#include <iostream>
#include <iterator>

using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int _value):data(_value){
        next = nullptr;
    }

    
};

// return the ptr advanceThePtr from specific position to specific steps ..doesnot modify original pointer 
Node* advanceThePtr(Node* itr,int steps){
    for(int i = 0;i<steps;i++){
        itr = itr->next;
    }
    return itr;
}

//passing head and tail is imp to insert for knowing linkedlist state
Node* insertAtHead(int _value,Node* &head, Node* &tail){
    //if linked list is empty then both taill and head will be poiting at null
     Node* newNode = new Node(_value);
    if(head == nullptr &&tail == nullptr){
       
        head = newNode; // after one value both head and tail will be poiting towards same node
        tail = newNode;
    }else {
    
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* insertAtTail(int _value,Node* &head, Node* &tail){
    //if linked list is empty then both taill and head will be poiting at null
     Node* newNode = new Node(_value);
    if(head == nullptr &&tail == nullptr){
       
        head = newNode; // after one value both head and tail will be poiting towards same node
        tail = newNode;
    }else {
    
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

//length of linkedList
int lengthOfLinkedList(Node* head){
    Node* temp = head;
     
    int length = 0;
    while(temp != nullptr){
        length++;
        temp = temp->next;
    }
    return length;
}

// insert at specific position .. assuemd valid position me hi dalna hoga
void insertAtSpecificPosition(int _value,Node*  &head,Node*& tail, int position){
    int len = lengthOfLinkedList(head);
   // position == 1 mean head pe dalo 
    if(position == 1){
       insertAtHead(_value, head, tail);
      
    }else if (position == len + 1) { // if position == len + 1 mtlb last(tail) pe lgao
      insertAtTail(_value, head, tail);
  
    }else { // nhi to specific position pe node dalo
        Node* newNode = new Node(_value);
        Node* temp = advanceThePtr(head, position-2); //* position - 2 instead of position -1 bcz of 1 based indexing
        newNode->next = temp->next;
        temp->next = newNode;
        
    }
    
}


//deost not change original head bcz of pass by copy 
void printLinkedList(Node* head){
    while(head != nullptr){
        cout<<head->data<<"->";
        // head = advanceThePtr(head,1); // both works
        head = head->next;
    }
    cout<<"nullptr\n"<<endl;
}



int main() {
    // Your code here

    // //stack object
    // Node first(5) ;
    // cout << first.data<<" "<<first.next;

/** 
    // //dynamic memory object creation
    // Node* first = new Node(5);
    // cout << first->data<<" "<<first->next;

    Node* head = nullptr;
    Node* tail = nullptr;
    
    //LL is empty
    head =  insertAtHead(10, head, tail);
    //10->nullptr
    printLinkedList(head);

    head =  insertAtHead(20, head, tail);
    //20 -> 10->nullptr
    printLinkedList(head);

    head =  insertAtHead(30, head, tail);
    // 30 -> 20 -> 10->nullptr
    printLinkedList(head);

    head =  insertAtHead(40, head, tail);
    //40 -> 30 -> 20 -> 10->nullptr
    printLinkedList(head);

    head =  insertAtHead(50, head, tail);
    //50 -> 40 -> 30 -> 20 -> 10->nullptr
    printLinkedList(head);

*/
    //* cout << head->next->next->next->data<<endl;
    // cout << advanceThePtr(head, 3)->data<<endl; // head is not changing bcz we are using pass by copy

    
    // cout <<"head ->"<< head->data<<" .... tail->"<<tail->data<<endl<<endl;


    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    //empty LL
    tail2 = insertAtTail(101, head2, tail2);
    printLinkedList(head2);
    //10->nullptr

    tail2 = insertAtTail(201, head2, tail2);
    printLinkedList(head2);
    //10->20->nullptr

    tail2 = insertAtTail(301, head2, tail2);
    printLinkedList(head2);
    //10->20->30nullptr

    tail2 = insertAtTail(401, head2, tail2);
    printLinkedList(head2);
    //10->20->30->40->nullptr

    tail2 = insertAtTail(501, head2, tail2);
    printLinkedList(head2);
    //10->20->30->40->50->nullptr

    cout <<"head ->"<< head2->data<<" .... tail->"<<tail2->data<<endl<<endl;

    insertAtSpecificPosition(555, head2, tail2, 1);

    printLinkedList(head2);

    cout << lengthOfLinkedList(head2);

    return 0;
}
