#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

//{ Driver Code Starts
    #include <bits/stdc++.h>
    using namespace std;

    /* Link list Node */
    struct Node {
    int data;
    struct Node *next;

    Node(int x) {
    data = x;
    next = nullptr;
    }
    };

    void printList(Node *node) {
    while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
    }
    cout << "\n";
    }

    void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
    }
}


//*Main code is in the Solution class

/**   
  **Intuition & complexity:
    - The problem is essentially sorting the linked list based on the node values (0, 1, 2).
    - Instead of sorting traditionally, we can segregate the nodes into three separate lists:
      one for 0s, one for 1s, and one for 2s.
    - After segregating, we merge the three lists sequentially: 0s -> 1s -> 2s.
    - This approach is efficient because it avoids modifying node values and works by rearranging pointers only.

    **Time Complexity:
    - Traversing the list to separate nodes: O(n), where n is the number of nodes in the list.
    - Merging the lists: O(1) (simple pointer rearrangements).
    - Overall: O(n).

    **Space Complexity:
    - No extra memory is used for the data; only pointers are rearranged.
    - Auxiliary space: O(1) (constant space usage).
*/

class Solution {
public:
  // Insert a node at the tail of a list
  void insertAtTail(Node *toMove, Node *&head, Node *&tail) {
    if (head == nullptr && tail == nullptr) { // Empty list
      head = toMove;
      tail = toMove;
    } else { // Append to the tail
      tail->next = toMove;
      tail = toMove;
    }
  }

  // Function to sort a linked list containing 0s, 1s, and 2s
    Node *segregate(Node *head) {
        // Separate lists for nodes with values 0, 1, and 2
        Node *zeroHead = nullptr, *zeroTail = nullptr;
        Node *oneHead = nullptr, *oneTail = nullptr;
        Node *twoHead = nullptr, *twoTail = nullptr;

        Node *current = head;

        // Traverse the original list and divide nodes into three separate lists
        while (current != nullptr) {
            Node *toMove = current;         // Store the current node
            current = current->next;       // Move to the next node in the original list
            toMove->next = nullptr;        // Disconnect the current node from the list

            // Add the node to the corresponding list based on its value
            if (toMove->data == 0)
                insertAtTail(toMove, zeroHead, zeroTail); // Add to the list of 0s
            else if (toMove->data == 1)
                insertAtTail(toMove, oneHead, oneTail);  // Add to the list of 1s
            else
                insertAtTail(toMove, twoHead, twoTail);  // Add to the list of 2s
        }

        // Merge the separate lists: 0s -> 1s -> 2s
        if (zeroHead != nullptr) { // If the list of 0s is not empty

            // Connect the list of 0s to the list of 1s or 2s
            //idea:int x = (condition ? value1 : value2); is working like this
            //note: if oneHead is nullptr twoHead will assigned otherwise oneHead
            zeroTail->next = oneHead ? oneHead : twoHead; 

            // If the list of 1s exists, connect it to the list of 2s
            if (oneTail)  oneTail->next = twoHead;

            // Return the head of the merged list (starting with 0s)
            return zeroHead;
        }

        if (oneHead != nullptr) { // If the list of 1s exists but no 0s
            // Connect the list of 1s to the list of 2s
            oneTail->next = twoHead;

            // Return the head of the merged list (starting with 1s)
            return oneHead;
        }

        // If there are only 2s in the list, return the head of the list of 2s
        return twoHead;
    }

};

//{ Driver Code Starts.

    // Driver program to test above functions
    int main() {
    int t, k;
    int*z;
    
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
        head = new Node(x);
        tail = head;

        while (ss >> x) {
            tail->next = new Node(x);
            tail = tail->next;
        }

        // Link the last node to the head if k is 1 to make it circular
        if (k == 1) {
            tail->next = head;
        }
        }

        Solution ob;
        Node *newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
    }
// } Driver Code Ends