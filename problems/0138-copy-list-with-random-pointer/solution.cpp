/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
  
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while (temp!=nullptr){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }

        temp=head;
        while (temp!=nullptr){
            if (temp->random) temp->next->random=temp->random->next;
            else temp->next->random=nullptr;
            temp=temp->next->next;
        }
        temp=head;
        Node* res;
        Node* dummy=new Node(-1);
        res=dummy;
        while (temp!=nullptr){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
