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


    ListNode* middleNode(ListNode* node){
        if (node==nullptr || node->next==nullptr) return node;
        ListNode* slow=node;
        ListNode* fast=node;
        while (fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* x=slow->next;
        slow->next=nullptr;
        return x;
    }

    ListNode* merge(ListNode* firstNode, ListNode* secondNode){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* temp1=firstNode;
        ListNode* temp2=secondNode;

        while (temp1!=nullptr && temp2!=nullptr){
            if (temp1->val<=temp2->val){
                temp->next=temp1;
                temp=temp->next;
                temp1=temp1->next;
            }else{
                temp->next=temp2;
                temp=temp->next;
                temp2=temp2->next;
            }
        }
        while (temp1!=nullptr){
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }
        while (temp2!=nullptr){
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
        return dummy->next;

    }

    ListNode* mS(ListNode* head){
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* middle=middleNode(head);
        ListNode* left=mS(head);
        ListNode* right=mS(middle);
        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return mS(head);  
    }
};
