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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* dummyHead=new ListNode(-1);
        ListNode* ptr=dummyHead;
        int carry=0;
        while (p1!= NULL && p2!=NULL){
            int sum=carry+p1->val+p2->val;
            ListNode* newNode=new ListNode(sum%10);
            ptr->next=newNode;
            ptr=newNode;
            carry=sum/10;
            p1=p1->next;p2=p2->next;
        }
        while (p1!=NULL){
            int sum=carry+p1->val;
            ListNode* newNode=new ListNode(sum%10);
            ptr->next=newNode;
            ptr=newNode;
            carry=sum/10;
            p1=p1->next;
        }
        while (p2!=NULL){
            int sum=carry+p2->val;
            ListNode* newNode=new ListNode(sum%10);
            ptr->next=newNode;
            ptr=newNode;
            carry=sum/10;
            p2=p2->next;
        }
        if (carry!=0){
            ListNode* newNode=new ListNode(carry);
            ptr->next=newNode;
            ptr=newNode;
        }
        
        return dummyHead->next;
    }
};
