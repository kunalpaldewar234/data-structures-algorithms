class Solution {
public:
    #define Node ListNode
    #define null nullptr
    #define data val

    void reorderList(Node* head) {

        if(head == null || head->next == null)
            return;

        // Step 1 : Find Middle

        Node *slow = head;
        Node *fast = head;

        while(fast->next != null && fast->next->next != null){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2 : Reverse second half

        Node *second = slow->next;
        slow->next = null;

        Node *prev = null;
        Node *curr = second;

        while(curr){
            Node *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        second = prev;

        // Step 3 : Merge

        Node *first = head;

        while(second){

            Node *t1 = first->next;
            Node *t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna