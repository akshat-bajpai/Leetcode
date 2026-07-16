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
        ListNode* ptr=head;
        while(ptr){
            ListNode* temp=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=temp;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL  || head->next==NULL) return head;
        ListNode* ptr=head;
        int size=0;
        while(ptr){
            size++;
            ptr=ptr->next;
        }
        k=k%size;
        if (k==0) return head;
        head=reverse(head);
        int c=0;
        ptr=head;
        ListNode* prev=NULL;
        while (c<k && ptr){
            c++;
            prev=ptr;
            ptr=ptr->next;
        }

        ListNode* temp=prev->next;
        prev->next=NULL;
        ListNode* connect=head;
        head=reverse(head);
        ListNode* otherEnd=reverse(temp);
        connect->next=otherEnd;
        return head;

    }
};
