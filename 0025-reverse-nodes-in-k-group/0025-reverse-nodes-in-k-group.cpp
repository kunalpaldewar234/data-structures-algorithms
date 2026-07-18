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
    #define null NULL
    #define Node ListNode
    #define data val
    void reverse(Node* &head,int times){
        Node * curr = head;
        Node * prev = null;
        while(times--){
            Node * nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == null){
            return null;
        }

        Node* left = head;
        Node* res = null;
        Node* right;
        int size = k;
        Node* prevleft = null;

        while(true){
            right =left;
            for(int i=0;i<k-1;i++){
                if(right == null){
                    break;
                }
                right = right->next;
            }

            if(right){
                Node* leftnext = right->next;
                reverse(left,size);
                if(prevleft){
                    prevleft->next = right;
                }
                if(res == null){
                    res = right;
                }
                prevleft = left;
                left = leftnext;
            }else{
                if(prevleft){
                    prevleft->next = left;
                }
                if(res == null){
                    res = left;
                }

                break;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna