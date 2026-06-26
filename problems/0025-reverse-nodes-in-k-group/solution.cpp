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
        ListNode* prev=NULL;
        ListNode* curr=head;
        while (curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int r=0;
        ListNode* ptr=head;
        ListNode* dummyHead=new ListNode(-1);
        ListNode* startOfSegment=head;
        ListNode* connectionPtr=dummyHead;
        while (ptr){
            r++;
            if (r==k){
                ListNode* temp=ptr->next;
                ptr->next=NULL;
                connectionPtr->next=reverse(startOfSegment);
                startOfSegment->next=temp;
                ptr=temp;
                connectionPtr=startOfSegment;
                startOfSegment=ptr;
                r=0;
                continue;
            }
            ptr=ptr->next;
        }
        return dummyHead->next;
    }
};
