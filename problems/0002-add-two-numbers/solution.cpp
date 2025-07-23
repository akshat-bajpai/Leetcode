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
        ListNode* answerDummy=new ListNode(-1);
        ListNode* temp=answerDummy;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while (temp1!=nullptr && temp2!=nullptr){
            int sum= temp1->val + temp2->val + carry;
            if (sum<10){
                ListNode* newNode=new ListNode(sum);
                temp->next=newNode;
                carry=0;
            }else{
                ListNode* newNode=new ListNode(sum%10);
                temp->next=newNode;
                carry=1;
            }
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while (temp1!=nullptr){
            int sum= temp1->val+carry;
            if (sum<10){
                ListNode* newNode=new ListNode(sum);
                temp->next=newNode;
                carry=0;
            }else{
                ListNode* newNode=new ListNode(sum%10);
                temp->next=newNode;
                carry=1;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
        while (temp2!=nullptr){
            int sum= temp2->val+carry;
            if (sum<10){
                ListNode* newNode=new ListNode(sum);
                temp->next=newNode;
                carry=0;
            }else{
                ListNode* newNode=new ListNode(sum%10);
                carry=1;
                temp->next=newNode;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        if (carry==1){
            ListNode* newNode= new ListNode(1);
            temp->next=newNode;
        }
        return answerDummy->next;
    }
};
