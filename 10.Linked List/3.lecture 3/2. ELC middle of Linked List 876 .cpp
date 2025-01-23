#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//METHOD 1ST 
/**
 * phle length(5) nikalo phir uska half kro for mid(2.5) aur phir us mid k ceil(3) value index pe jao vha ans hoga
 * TC = O(N) SC = O(1);
 */

 //* METHOD 2ND RABBIT AND TORTOISE APPROACH BETTER ONE

ListNode* middleNode(ListNode* head) {
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
            tortoise = tortoise->next;
        }
    }
    
    // When the rabbit pointer reaches the end of the list (or becomes nullptr),
    // the tortoise pointer will be at the middle of the list.
    return tortoise;
}
