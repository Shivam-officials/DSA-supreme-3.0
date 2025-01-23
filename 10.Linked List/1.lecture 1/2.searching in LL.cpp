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


//* searching and returns 1 based index of the element
 int searchInLinkedList(int _value, Node* head){
    int position = 0;
    auto temp = head;
    while(temp !=nullptr){
        position++;
        if(temp->data == _value){
            return position ;
        }
        temp = temp->next;

    }

    return -1; // if not found return -1;
}

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

//deost not change original head bcz of pass by copy 
void printLinkedList(Node* head){
    while(head != nullptr){
        cout<<head->data<<"->";
        // head = advanceThePtr(head,1); // both works
        head = head->next;
    }
    cout<<"nullptr\n"<<endl;
}



int main(int argc, char const *argv[])
{
    
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

    //*searching
    auto ans = searchInLinkedList(30, head);

    if(ans!=-1){
        cout << "element is at "<<ans<<endl;
    }else 
    {
        cout << "element not found\n";
    }

    return 0;
}
