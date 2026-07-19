/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    #define Node ListNode
    #define null nullptr

    string reverseList(Node *head) {
        Node *curr = head;
        Node *prev = null;

        while (curr) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        string num = "";

        while (prev) {
            num += char(prev->val + '0');
            prev = prev->next;
        }

        return num;
    }

    string addStrings(string a, string b) {

        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            ans += char(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        string s1 = reverseList(l1);
        string s2 = reverseList(l2);

        string ans = addStrings(s1, s2);

        Node *head = null;
        Node *tail = null;

        // Create answer list in reverse order
        for (int i = ans.length() - 1; i >= 0; i--) {

            Node *node = new Node(ans[i] - '0');

            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }

        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna