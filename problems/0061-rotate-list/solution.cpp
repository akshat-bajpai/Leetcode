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
    ListNode* rotateRight(ListNode* head, int k) {
        int size=0;
        ListNode* cur=head;
        while (cur){
            size++;
            cur=cur->next;
        }
        if (size==0) return NULL;
        k=k%size;
        if (k==0) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        for (int i=0;i<k;i++){
            fast=fast->next;
        }

        while (fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* newHead=slow->next;
        slow->next=NULL;
        fast->next=head;
        return newHead;
    }
};
