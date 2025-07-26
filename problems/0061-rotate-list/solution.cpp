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

    ListNode* reverseLL(ListNode* head){
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            temp=temp->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }


    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr || head->next==nullptr) return head;
        int len=0;
        ListNode* lenTemp=head;
        while (lenTemp!=nullptr){
            len++;
            lenTemp=lenTemp->next;
        }
        k=k%len;
        if (k==0) return head;
        ListNode* rotatePoint;
        head=reverseLL(head);
        ListNode* temp=head;
        int c=1;
        while (temp!=nullptr){
            if (c==k){
                rotatePoint=temp;
                break;
            }
            temp=temp->next;
            c++;
        }
        temp=head;
        ListNode* save=rotatePoint->next;
        rotatePoint->next=nullptr;
        head=reverseLL(head);
        save=reverseLL(save);
        temp->next=save;
        return head;

    }
};
