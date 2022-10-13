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
    ListNode* removeElements(ListNode* ll, int k) {
        if(!ll) return ll;
        while(ll and ll->val == k){
            ll = ll->next;
        }
        ListNode *temp = ll, *prev = NULL;
        
    while(temp){
        if(temp->val == k){
            prev->next = temp->next;
        }
        else prev = temp;
        temp = temp ->next;
        }

        
        return ll;
    }
};