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
    ListNode* middle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left != nullptr) tail->next = left;
        if (right != nullptr) tail->next = right;

        return dummy->next;
    }

    ListNode* mS(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* mid = middle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        leftHead = mS(leftHead);
        rightHead = mS(rightHead);

        return merge(leftHead, rightHead);
    }

    ListNode* sortList(ListNode* head) {
        return mS(head);
    }
};

