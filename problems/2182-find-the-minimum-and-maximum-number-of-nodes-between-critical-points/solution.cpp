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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        int nodeNum=2;
        ListNode* temp=head->next;
        ListNode* prev=head;
        while (temp){
            if (temp->next==NULL) break;
            if (
                (temp->val>prev->val && temp->val>temp->next->val) ||
                (temp->val<prev->val && temp->val<temp->next->val)
            ){
                criticalPoints.push_back(nodeNum);
            }
            prev=temp;
            temp=temp->next;
            nodeNum++;
        }
        if (criticalPoints.size()<2) return {-1,-1};
        int maxDistance=criticalPoints.back()-criticalPoints[0];
        int minDistance=criticalPoints[1]-criticalPoints[0];
        for (int i=1;i<criticalPoints.size();i++){
            minDistance=min(minDistance,criticalPoints[i]-criticalPoints[i-1]);
        }
        return {minDistance,maxDistance};
    }

};
