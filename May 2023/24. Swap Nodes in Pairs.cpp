// 24. Swap Nodes in Pairs
// Problem Link - https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* swapPairs(ListNode* head){
        ListNode* temp=head;
        if(temp==NULL || temp->next==NULL){
            return head;
        }
        while(temp!=NULL && temp->next!=NULL){
            int tempo=temp->val;
            temp->val=temp->next->val;
            temp->next->val=tempo;
            temp=temp->next->next;
        }
        return head;
    }
};
