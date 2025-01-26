#include <iostream>
#include <unordered_map>
using namespace std;


// https://leetcode.com/problems/linked-list-cycle/description/

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


// Approach: Use a hash map to track visited nodes.
// Intuition: If a node is revisited, a cycle exists.
// Time Complexity: O(N) - Traverse each node once.
// Space Complexity: O(N) - Store node addresses in the hash map.
bool hasCycle(ListNode *head) {
    unordered_map<ListNode*, bool> map; // To store visited node addresses
    ListNode* cur = head;

    while (cur != nullptr) {
        if (map.find(cur) != map.end()) { // Check if the node is already visited
            return true; // Cycle detected
        }

        map[cur] = true; // Mark the current node as visited
        cur = cur->next; // Move to the next node
    }
    return false; // No cycle found
}


    //* Approach: Use two pointers (Floyd's Cycle Detection Algorithm).
    // Intuition: A "rabbit" moves two steps while a "tortoise" moves one step. 
    // If there's a cycle, the two pointers will DEFINATELY meet(point at same node).
    //* rabbit tez chalega aur tort aram se .. agr cycle hui to rabbit usi cycle me ghumta rhega aur jab vha tortoise pahuchega to dono ka amna samna to hi jayega ek point pe
    // Edge cases: Handle empty or single-node lists explicitly.
    // Time Complexity: O(N) - Traverse the list with two pointers.
    // Space Complexity: O(1) - Constant space used.

bool hasCycle_BETTER_APPROACH(ListNode *head) {
    // Edge cases: empty list or single-node list
    if (head == nullptr || head->next == nullptr) return false;

    ListNode *rabbit = head; // Fast pointer
    ListNode *tort = head;   // Slow pointer

    while (rabbit != nullptr) {
        rabbit = rabbit->next; // Move fast pointer one step

        if (rabbit != nullptr) {
            rabbit = rabbit->next; // Move fast pointer another step
            tort = tort->next;     // Move slow pointer one step

            // If pointers meet, a cycle exists
            if (rabbit == tort) {
                return true;
            }
        }
    }
    return false; // No cycle detected
}

