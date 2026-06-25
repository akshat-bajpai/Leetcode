/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1=headA;
        ListNode* p2=headB;
        bool p1Toggle=false;
        bool p2Toggle=false;
        while (p1 && p2){
            if (p1==p2) return p1;
            p1=p1->next;
            p2=p2->next;
            if (p1==NULL){
                if (p1Toggle){
                    return NULL;
                }
                p1Toggle=true;
                p1=headB;
            }
            if (p2==NULL){
                if (p2Toggle){
                    return NULL;
                }
                p2Toggle=true;
                p2=headA;
            }
        }

        return NULL;
    }
};
