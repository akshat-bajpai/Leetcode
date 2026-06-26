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
    ListNode* merge(ListNode* low, ListNode* midNext){
        ListNode* ptr1=low;
        ListNode* ptr2=midNext;
        ListNode* dummyHead=new ListNode(-1);
        ListNode* dummyPtr=dummyHead;
        while (ptr1 && ptr2){
            if (ptr1->val<=ptr2->val){
                dummyPtr->next=ptr1;
                ptr1=ptr1->next;
                dummyPtr=dummyPtr->next;
            }else{
                dummyPtr->next=ptr2;
                ptr2=ptr2->next;
                dummyPtr=dummyPtr->next;
            }
        }
        while (ptr1){
            dummyPtr->next=ptr1;
            ptr1=ptr1->next;
            dummyPtr=dummyPtr->next;
        }while (ptr2){
            dummyPtr->next=ptr2;
            ptr2=ptr2->next;
            dummyPtr=dummyPtr->next;
        }
        return dummyHead->next;
    }
    ListNode* middle(ListNode* head){
        if (head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head){
        if (head==NULL || head->next==NULL) return head;
        ListNode* mid=middle(head);
        ListNode* midNext=mid->next;
        mid->next=NULL;
        head=mergeSort(head);
        midNext=mergeSort(midNext);
        head=merge(head,midNext);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
