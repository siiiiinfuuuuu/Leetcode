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
        map<Node*, Node*> nodePtr;
        Node* newHead = nullptr;
        Node* curr = head;
        Node* newCurr;
        while(curr){
            if(newHead == nullptr){
                newHead = new Node(curr->val);
                nodePtr[head] = newHead;
                newCurr = newHead;
            }
            else{
                newCurr->next = new Node(curr->val);
                newCurr = newCurr->next;
                nodePtr[curr] = newCurr;
            }
            curr = curr->next;
        }
        curr = head;
        newCurr = newHead;
        while(newCurr){
            newCurr->random = nodePtr[curr->random];
            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};