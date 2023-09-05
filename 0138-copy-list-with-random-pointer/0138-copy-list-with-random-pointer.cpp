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
    Node *copyRandomList(Node *head) {
        Node *temp=head;
        unordered_map<Node*,Node*>u;
        while(temp!=NULL){
            u[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            Node*curr=u[temp];
            Node* nex=u[temp->next];
            Node*r=u[temp->random];
            curr->next=nex;
            curr->random=r;
            temp=temp->next;
        }
        return u[head];
    }
};