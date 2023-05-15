// 1721. Swapping Nodes in a Linked List
// Problem Link - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k){
        int sizeOfLL=0;
        ListNode* temp=head;
        while(temp!=NULL){
            sizeOfLL++;
            temp=temp->next;
        }
        ListNode* kthFromStart;
        ListNode* kthFromEnd;
        temp=head;
        int idx=0;
        while(temp!=NULL){
            idx++;
            if(idx==k){
                kthFromStart=temp;
            }
            if(idx==sizeOfLL-k+1){
                kthFromEnd=temp;
            }
            temp=temp->next;
        }
        int tem=kthFromStart->val;
        kthFromStart->val=kthFromEnd->val;
        kthFromEnd->val=tem;
        return head;
    }
};