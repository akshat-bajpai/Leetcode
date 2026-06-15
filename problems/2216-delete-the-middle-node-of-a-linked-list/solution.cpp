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
        ListNode* l=head;
        ListNode* r=head;
        ListNode* prev=NULL;
        while (r && r->next){
            prev=l;
            l=l->next;
            r=r->next->next;
        }
        if (prev){
            prev->next=l->next;
        }else{
            return l->next;
        }
        delete(l);
        return head;
    }
};
