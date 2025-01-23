#include <iostream>
using namespace std;



//   Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



//*MEHTOD 1 make a copied linkedList and then reverse it and then compare the both if equal then palindrome otherwise not .
//TC = O(N) SC = O(N);



//reverse the LinkedList
ListNode* reverseListIteratively(ListNode* &head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr != nullptr){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

//find the middle node of LL through rabbit and tortoise approach which gives if 2 mid then 2nd mid always 
ListNode* middleNode(ListNode* &head,ListNode* &midkPahleWalaNode) {
    // Initialize two pointers: rabbit (fast pointer) and tortoise (slow pointer),
    // both starting at the head of the linked list.
    ListNode* rabbit = head;
    ListNode* tortoise = head;
    
    // Traverse the linked list.
    // The rabbit pointer can moves two steps at a time, the tortoise can move one step at that time.
    while (rabbit != nullptr) {
        // Move the rabbit pointer one step forward.
        rabbit = rabbit->next;
        
        // Check if rabbit can take another step forward.
        if (rabbit != nullptr) {
            // Move the rabbit pointer a second step forward.
            rabbit = rabbit->next;
            
            // Move the tortoise pointer one step forward.
            midkPahleWalaNode = tortoise;
            tortoise = tortoise->next;
        }
    }
    
    // When the rabbit pointer reaches the end of the list (or becomes nullptr),
    // the tortoise pointer will be at the middle of the list.
    return tortoise;
}
//mid of linkedList
//*METHOD 2: 
/**
 * break the LL from mid
 * reverse the 2nd LL
 * compare the reversed LL from 1st half
 * if equal to first LL its palindrome otherwisee not
 * *TC = O(N) SC = O(1)
 */
 //* MAIN CODE
bool isPalindrome(ListNode* head) {

    //edge cases
    if(head->next == nullptr){
            return true;
     }

    if(head->next->next == nullptr){
        if(head->val == head->next->val){
            return true;
        }else{
            return false;
        }
    }


    ListNode* midKPhleWalaNode = nullptr;
    ListNode* newHead = middleNode(head, midKPhleWalaNode); //TC = O(N) SC = O(1)

    //breaking the Linked List from mid
    midKPhleWalaNode->next = nullptr;

    //reversing the 2nd half LL
    newHead = reverseListIteratively(newHead); //TC = O(N/2) SC = O(1)

    ListNode *firsthead = head;
    ListNode *reversedHead = newHead;

    //comparing both Linked List //TC = O(N/2) SC = O(1)
    while(firsthead != nullptr){
        if(firsthead->val != reversedHead->val){
            return false;
        }

        //moving forward both pointers
        firsthead = firsthead->next;
        reversedHead = reversedHead->next;
    }

    //agr yha tak aa gye to mtlb sab equal hai 
    return true;

}