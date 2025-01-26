//{ Driver Code Starts
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>
    using namespace std;

    /* Linked list Node */
    struct Node {
        int data;
        struct Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
    };

    Node* buildList() {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            return NULL;
        }
        int val = arr[0];
        int size = arr.size();

        Node* head = new Node(val);
        Node* tail = head;

        for (int i = 1; i < size; i++) {
            val = arr[i];
            tail->next = new Node(val);
            tail = tail->next;
        }

        return head;
    }

    void printList(Node* n) {
        while (n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }


// } Driver Code Ends


// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-list/#expected-approach-by-storing-sum-on-the-longer-list-om-n-time-and-o1-space


class Solution {
  public:

   // Function to reverse a linked list and calculate its length
   Node *reverse(Node *head, int &length) {
       // If the list is empty or contains only one node, no reversal is needed
       if (head == nullptr || head->next == nullptr) return head;

       Node *prev = nullptr;   // Pointer to track the previous node
       Node *current = head;  // Pointer to traverse the list

       // Traverse the list and reverse the links
       while (current != nullptr) {
           length++;  // Increment the length for each node
           Node *forward = current->next;  // Store the next node
           current->next = prev;  // Reverse the current node's pointer
           prev = current;  // Move `prev` to the current node
           current = forward;  // Move `current` to the next node
       }

       return prev;  // Return the new head of the reversed list
   }

   // Function to remove leading zeroes from a linked list
   Node* removeLeadingZero(Node* &head) {
       if (head == nullptr) return head;  // If the list is empty, return

       Node* curr = head;
       // Traverse and delete nodes with value 0 until a non-zero node is found
       while (curr->data == 0) {
           Node* toDelete = curr;
           curr = curr->next;
           toDelete->next = nullptr;  // Clean up the deleted node's pointer
           delete toDelete;  // Free the memory
           head = curr;  // Update the head of the list
           if (head == nullptr) break;  // Stop if the list becomes empty
       }
       return head;  // Return the updated head of the list
   }

   // Function to add two numbers represented as linked lists
   Node* addTwoLists(Node* num1, Node* num2) {
       // Remove leading zeroes from both lists
       removeLeadingZero(num1);
       removeLeadingZero(num2);

       // If both lists are empty, return null
       if (num1 == nullptr && num2 == nullptr) return 0;

       // Reverse both lists and calculate their lengths
       int l1 = 0, l2 = 0;
       Node* curr1 = reverse(num1, l1);
       Node* curr2 = reverse(num2, l2);

       // Ensure `curr1` points to the longer list
       if (l1 < l2) {
           swap(curr1, curr2);
       }

       // Initialize variables for the addition process
       Node* resultHead = curr1;  // The head of the resulting list
       int carry = 0;  // To store carry during addition

       // Traverse both lists and perform addition
       while (curr2 != nullptr || carry != 0) {
           // Calculate the sum of the current digits and carry
           int sum = curr1->data + carry + (curr2 ? curr2->data : 0);

           curr1->data = sum % 10;  // Update the current node with the digit
           carry = sum / 10;  // Update the carry

           // If the first list ends and there is still a carry, create a new node
           if (curr1->next == nullptr && carry != 0) {
               curr1->next = new Node(carry);
               carry = 0;  // Reset carry
           }

           curr1 = curr1->next;  // Move to the next node in the first list
           curr2 = curr2 ? curr2->next : curr2;  // Move to the next node in the second list if curr2 is not poiting at nullptr 
       }

       // Reverse the result list to restore the original order and return it
       return reverse(resultHead, l1);
   }
};

/** 
** Intuition:
    1. The two input linked lists represent numbers, with the least significant digit at the tail. To simplify addition, the lists are reversed.
    2. Reversing the lists enables digit-by-digit addition starting from the least significant digit, managing carry effectively.
    3. To handle cases where the input lists have leading zeroes, we remove those zeroes to avoid redundant calculations.
    4. The resulting sum is stored in the first list (or the longer list), updating it in-place to optimize space usage.
    5. Finally, the result list is reversed back to restore the original number order.

** Complexity Analysis:
    **1. Time Complexity:
    - Reversing both lists: O(n_1 + n_2), where n_1 and n_2 are the lengths of the two lists.
    - Removing leading zeroes: O(n_1 + n_2), as it requires traversing each list once.
    - Addition process: O(max(n_1, n_2)), as we traverse both lists for addition.
    - Reversing the result list: O(max(n_1, n_2)).
    - Total: O(n_1 + n_2).
    **2. Space Complexity:
    - O(1) additional space, as the input lists are modified directly without extra data structures.
*/

//{ Driver Code Starts.

    int main() {
        int t;
        cin >> t;
        cin.ignore(); // To ignore the newline character after the integer input

        while (t--) {
            Node* num1 = buildList();
            Node* num2 = buildList();
            Solution ob;
            Node* res = ob.addTwoLists(num1, num2);
            printList(res);
            cout << "~" << endl;
        }
        return 0;
    }

// } Driver Code Ends