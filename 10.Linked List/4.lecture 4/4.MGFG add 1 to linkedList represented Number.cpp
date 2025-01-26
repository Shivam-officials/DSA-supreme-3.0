//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void printList(Node *node) {
  while (node != NULL) {
    cout << node->data % 10;
    node = node->next;
  }
  cout << "\n";
}

// } Driver Code Ends

// User function template for C++

/*

    struct Node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };

*/

// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//note:INTITUION: simply reverse the linked list add the number in nodes one by one acc to LL and after adding reverse the LL again

class Solution {
public:

    //reverse function
  Node *reverse(Node *head) {

    if (head->next == nullptr || head == nullptr) return head;

    Node *prev = nullptr;
    Node *current = head;

    while (current != nullptr) {

      Node *forward = current->next;
      current->next = prev;
      prev = current;
      current = forward;

    }

    return prev;

  }

  Node *addOne(Node *head) {

    if (head == nullptr) return nullptr;

    // Step 1: Reverse the linked list
    Node *reversedLL = reverse(head);

    // Step 2: Add one to the reversed list
    int carry = 1; // Initial carry is 1 (for adding one)
    Node *current = reversedLL;

    while (current != nullptr) {
      int sum = current->data + carry;
      current->data = sum % 10; // Update the digit at the current node
      carry = sum / 10;         // Compute the carry for the next digit

      // If there's no carry, we're done
      if (carry == 0) break;

      // If we're at the last node and still have a carry, add a new node
      if (current->next == nullptr && carry != 0) {
        current->next = new Node(carry);
        carry = 0; // Reset carry since it's been added
      }

      current = current->next; // Move to the next node
    }

    // Step 3: Reverse the list back to original order
    return reverse(reversedLL);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
      arr.push_back(number);
    }

    if (arr.empty()) {
      cout << -1 << endl;
      continue;
    }

    int data = arr[0];
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 1; i < arr.size(); ++i) {
      data = arr[i];
      tail->next = new Node(data);
      tail = tail->next;
    }
    Solution ob;
    head = ob.addOne(head);
    printList(head);
    cout << "~" << endl;
  }
  return 0;
}

// } Driver Code Ends