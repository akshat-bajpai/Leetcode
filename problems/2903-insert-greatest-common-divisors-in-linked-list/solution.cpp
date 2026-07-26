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
    int gcd(int a, int b){
        int g=1;
        for (int i=1;i<=min(a,b);i++){
            if (a%i==0 && b%i==0) g=i;
        }
        return g;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr=head;
        while (ptr && ptr->next){
            int a=ptr->val;
            int b=ptr->next->val;
            int gcdd=gcd(a,b);
            ListNode* newNode=new ListNode(gcdd);
            newNode->next=ptr->next;
            ptr->next=newNode;
            ptr=ptr->next->next;
        }
        return head;
    }
};
