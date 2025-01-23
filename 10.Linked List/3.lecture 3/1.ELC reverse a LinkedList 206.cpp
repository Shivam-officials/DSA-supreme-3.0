
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/

// Definition for singly-linked list.
struct ListNode {
    int val; // Value of the node
    ListNode *next; // Pointer to the next node
    ListNode() : val(0), next(nullptr) {} // Default constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next node
};


//*  MAIN CODE:: Reverse a linked list iteratively    BETTER APPROACH THAN RECURSIVE ONE
//TC = O(N) SC = O(1)
ListNode* reverseListIteratively(ListNode* head) {
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

//* MAIN CODE:: recursivaly reverse a Linked List   TC = O(N) SC = O(N) 
ListNode* reverseLinkedListRecursively(ListNode* &prev, ListNode* &curr){
    //base case
    if(curr == nullptr){
        return prev;
    }

    ListNode* forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    return reverseLinkedListRecursively(prev, curr);
}


// Main function
int main() {
    
    return 0;
}