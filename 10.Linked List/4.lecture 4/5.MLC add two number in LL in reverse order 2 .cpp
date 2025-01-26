#include <iostream>
using namespace std;

// https://leetcode.com/problems/add-two-numbers/description/

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

// Helper function to insert a new node at the tail of the linked list
// This function ensures the list grows dynamically as we add digits.
ListNode* insertAtTail(int value, ListNode*& head, ListNode*& tail) {
    // Create a new node with the given value
    ListNode* newNode = new ListNode(value);
    
    // If the list is empty, the new node becomes both the head and tail
    if (head == nullptr && tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, append the new node to the tail and update the tail pointer
        tail->next = newNode;
        tail = newNode;
    }
    
    return tail; // Return the updated tail
}

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Initialize pointers for traversing the two input lists
    ListNode* curr1 = l1, *curr2 = l2;
    
    int carry = 0; // To keep track of carry during addition
    ListNode* ansHead = nullptr, *ansTail = nullptr; // For the result list

    // Traverse both lists while nodes are present in both
    while (curr1 != nullptr && curr2 != nullptr) {

        int sum = curr1->val + curr2->val + carry; // Add corresponding digits and carry
        int digit = sum % 10; // Extract the digit for the current node
        carry = sum / 10; // Update carry for the next iteration
        insertAtTail(digit, ansHead, ansTail); // Add the digit to the result list
        curr1 = curr1->next; // Move to the next node in the first list
        curr2 = curr2->next; // Move to the next node in the second list

    }

    // If the first list has remaining nodes, continue adding them with carry
    while (curr1 != nullptr) {

        int sum = curr1->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(digit, ansHead, ansTail);
        curr1 = curr1->next;

    }

    // If the second list has remaining nodes, continue adding them with carry
    while (curr2 != nullptr) {

        int sum = curr2->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(digit, ansHead, ansTail);
        curr2 = curr2->next;

    }


    // If there is a carry left after processing both lists, add a new node for it
    if (carry != 0) {

        insertAtTail(carry, ansHead, ansTail);

    }

    // Return the head of the resulting list
    return ansHead;
}

/** 
  **Intuition & Complexity: 

    1. The problem involves adding two numbers represented by linked lists. Each node contains a single digit, 
    and the digits are stored in reverse order 
    2. To solve the problem:
    - Traverse both lists simultaneously, adding corresponding digits and managing the carry.
    - If one list is shorter, process the remaining digits of the longer list with the carry.
    - If there's still a carry left after processing both lists, add a new node for it.
    3. Use a helper function (`insertAtTail`) to dynamically build the result linked list.

    **Time Complexity:
    - O(max(n, m)), where `n` and `m` are the lengths of the two input lists. 
    The algorithm processes each node exactly once.

    **Space Complexity:
    - O(max(n, m)), for the space required to store the result linked list. 
    No additional space is used other than the result list and a few pointers.
*/
