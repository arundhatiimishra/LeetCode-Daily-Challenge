// 2130. Maximum Twin Sum of a Linked List
// Problem Link - https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

class Solution {
public:
    int pairSum(ListNode* head){
        ListNode* first;
        ListNode* last;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        last=slow;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex;
        while(curr!=slow){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head->next=slow;
        head=prev;
        
        int answer=0;
        first=head;
        while(last!=NULL){
            answer=max(answer,first->val+last->val);
            first=first->next;
            last=last->next;
        }
        return answer;
    }
};
