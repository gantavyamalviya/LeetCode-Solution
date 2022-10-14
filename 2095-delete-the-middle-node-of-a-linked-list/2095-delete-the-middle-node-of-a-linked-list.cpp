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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode *slow = head, *fast = head, *prev = head;
        while(fast->next and fast->next->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next){
            prev = slow;
            slow = slow->next;
        }
        if(prev->next->next){
            prev->next = prev->next->next;
        }
        else{
            prev->next = NULL;
        }
        return head;
    }
};