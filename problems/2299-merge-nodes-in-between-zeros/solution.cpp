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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummyHead=new ListNode(-1);
        ListNode* dummyPtr=dummyHead;
        ListNode* ptr=head;
        while (ptr && ptr->next){
            if (ptr->val==0){
                ptr=ptr->next;
                int sum=0;
                while (ptr && ptr->val!=0){
                    sum+=ptr->val;
                    ptr=ptr->next;
                }
                ListNode* newNode=new ListNode(sum);
                dummyPtr->next=newNode;
                dummyPtr=newNode;
            }
        }
        return dummyHead->next;
    }
};
