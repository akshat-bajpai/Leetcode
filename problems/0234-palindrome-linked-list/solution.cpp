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
    ListNode* reverse(ListNode* head){
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while (temp!=nullptr){
            temp=temp->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        ListNode* second=reverse(slow->next);
        while (second!=nullptr){
            if (first->val != second->val) return false;
            first=first->next;
            second=second->next;
        }
        reverse(slow->next);
        return true;


    }
};
