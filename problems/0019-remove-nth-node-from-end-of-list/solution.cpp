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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==nullptr || head->next==nullptr) return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        int ct=0;
        while (ct<n){
            fast=fast->next;
            if (fast==nullptr) return head->next;
            ct++;

        }
        while (fast!= nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* deleteKaro=slow->next;
        slow->next=slow->next->next;
        delete deleteKaro;
        return head;
    }
};
