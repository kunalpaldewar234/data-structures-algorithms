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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode * t = head;
       ListNode * before = NULL;
       int pos = 1;

       if(head == NULL){
            return NULL;
       }
       if(left == right){
        return head;
       }
       while(pos < left){
        
            before = t;
            t = t->next;
            pos++;
       } 

    ListNode * curr = t;
    ListNode * prev = NULL;
    int times = right-left+1;

    while(times--){
        
        ListNode * nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        
    }

    t->next = curr;
    if(before != NULL){
        before->next = prev;
        return head;
    }else{
        return prev;
    }
       
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna