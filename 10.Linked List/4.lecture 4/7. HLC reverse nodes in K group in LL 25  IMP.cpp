//{ Driver Code Starts
    #include <bits/stdc++.h>
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>
    using namespace std;

    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
    };

    /* Function to print linked list */
    void printList(Node* node) {
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }


// } Driver Code Ends



class Solution {
  public:

    // helper function for Iterative approach 
   void reverese(Node* &groupStart, Node* &groupEnd) { 
    // Reverse the sublist between groupStart and groupEnd
    Node* prev = nullptr;
    Node* forEnd = groupStart; // Store the original start of the group
    Node* curr = groupStart;

    while (curr != nullptr) {
        Node* forward = curr->next; // Store the next node
        curr->next = prev;          // Reverse the current node
        prev = curr;                // Move prev and curr one step forward
        curr = forward;
    }

    // Update groupStart to the new head of the reversed group
    groupStart = prev; 
    groupEnd = forEnd; // Update groupEnd to the original groupStart
   }

    //idea:intution: simple traverse kro jab ek group ban jaye to use break kro reverse kro aur phir link kr do aur usi process ko repeat kro
    //TC = O(N) Sc = O(1)
    Node* reverseKGroupIterativaly_BEST_APPROACH(Node* &head,int &k){
        int count = 0; 
        Node* prev = nullptr; // End of the previous processed group
        Node* groupStart = head; // Start of the current group
        Node* curr = head;       // Current node in the list
        Node* groupEnd = nullptr; // End of the current group
        Node* forward = nullptr; // Next node after the current group

        while (curr != nullptr) {
            count++;

            // When a group of size k is found or it's the end of the list
            if (count % k == 0 || curr->next == nullptr) {
                groupEnd = curr;          // End of the current group
                forward = curr->next;     // Save the next node after the group

                if (prev != nullptr) {
                    prev->next = nullptr; // Disconnect the previous group from the current one
                }
                groupEnd->next = nullptr; // Disconnect the current group from the next

                // Reverse the current group
                reverese(groupStart, groupEnd);

                // Connect the reversed group back to the list
                if (prev != nullptr) {
                    prev->next = groupStart;
                } else {
                    head = groupStart;    // Update head for the first group
                }

                groupEnd->next = forward; // Connect the group end to the next part
                prev = groupEnd;          // Update prev to the end of the current group
                groupStart = forward;     // Move to the next group
                
                //note: This below step is essential to avoid re-processing the same nodes.
                // Move curr to the start of the next group
                curr = groupStart; 
            } else {
                curr = curr->next; // Move to the next node
            }
        }

        return head;
    }

    Node* reverseKGroup(Node* head, int k) {
    return reverseKGroupIterativaly_BEST_APPROACH(head, k);
    // return reverseKGroup_Recursivaly(head, k);
    }


    //idea:intution: ek case group tum reverse kr do baki recursion krke layega
    //TC = O(N) SC = O(N/K)
    Node* reverseKGroup_Recursivaly(Node* head, int &k) {
        Node* prev = nullptr;     // Previous node for reversing
        Node* curr = head;        // Current node in the list
        Node* forward = nullptr;  // Pointer to the next node
        int position = 0;         // Counter to track group size

        //1 case (group tum reverse kr do)  baki recursion sambhal lega

        // Reverse the current group of size 'k'
        while (position < k && curr != nullptr) {
            forward = curr->next; // Save the next node
            curr->next = prev;    // Reverse the current node
            prev = curr;          // Move prev and curr one step forward
            curr = forward;
            position++;
        }
        
        // baki recursion krke layega 
        // After reversing the group, recursively process the next group
        Node* recursionKaHead = curr ? reverseKGroup_Recursivaly(curr, k) : nullptr;

        // to usko connect krdo 
        // Connect the end of the reversed group to the head of the next reversed group
        head->next = recursionKaHead;

        //return kr do prev kyuki reverse hone k baad ye head ban jayega
        // Return the new head of the reversed group
        return prev;
}


};


//{ Driver Code Starts.

    /* Driver program to test above function*/
    int main(void) {

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
            Node* head = new Node(data);
            Node* tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                data = arr[i];
                tail->next = new Node(data);
                tail = tail->next;
            }
            int k;
            cin >> k;
            cin.ignore();

            Solution ob;
            head = ob.reverseKGroup(head, k);
            printList(head);
            cout << "~" << endl;
        }

        return 0;
    }
// } Driver Code Ends