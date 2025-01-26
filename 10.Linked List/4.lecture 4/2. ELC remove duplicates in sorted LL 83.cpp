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

// Approach: Remove duplicates from a sorted linked list by iterating through nodes.
// Intuition: Compare the current node's value with the previous node. If equal, remove the current node.
// Time Complexity: O(N) - Traverse each node once.
// Space Complexity: O(1) - No extra space used.

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head; // Handle edge cases //empty LL or 1 node only 

    ListNode* curr = head->next; // Pointer to the current node
    ListNode* prev = head;       // Pointer to the previous node

    while (curr != nullptr) {

        if (prev->val == curr->val) { // If duplicate, remove the current node

           

            prev->next = curr->next;           // Skip duplicate
            curr->next = nullptr;           // Isolate duplicate node

            delete curr;                    // Free memory of duplicate

            curr = curr->next;                 // Move to the next node

        } else { // No duplicate, move both pointers
            prev = curr;
            curr = curr->next;
        }

    }

    return head; // Return updated list
}

