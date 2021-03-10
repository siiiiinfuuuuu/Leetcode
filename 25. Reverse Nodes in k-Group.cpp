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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        bool changeHead = false;
        ListNode* last_end = nullptr;
        while(curr){
            //cout << curr->val<<endl;
            ListNode* currHead = curr;
            for(int i = 0; i < k-1; i++)
                if(curr)
                    curr = curr->next;
                else
                    break;
            if(curr){
                if(last_end)
                    last_end->next = curr;
                last_end = currHead;
                if(!changeHead){
                    head = curr;
                    changeHead = true;
                }
                ListNode* last = currHead->next;
                currHead->next = curr->next;
                curr = last;
                last = currHead;
                for(int i = 0; i < k-1; i++){
                    ListNode* next = curr->next;
                    curr->next = last;
                    last = curr;
                    curr = next;
                }

            }
        }
        return head;
    }
};