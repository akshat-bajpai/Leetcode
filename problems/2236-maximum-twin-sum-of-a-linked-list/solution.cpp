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
    int pairSum(ListNode* head) {
        unordered_map<ListNode*,ListNode*> prev;
        ListNode* curr=head;
        ListNode* prevNode=NULL;
        while(curr){
            prev[curr]=prevNode;
            prevNode=curr;
            curr=curr->next;
        }
        ListNode* l=head;
        ListNode* r=prevNode;
        int maxSum=INT_MIN;
        while (l && r){
            if (l->val+r->val>maxSum){
                maxSum=l->val+r->val;
            }
            l=l->next;
            r=prev[r];
        }
        return maxSum;
    }
};
