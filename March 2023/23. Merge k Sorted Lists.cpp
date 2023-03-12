// 23. Merge k Sorted Lists
// Problem Link - https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        if(pq.empty()==true){
            return NULL;
        }
        ListNode* head=new ListNode(pq.top());
        ListNode* temp=head;
        pq.pop();
        while(pq.empty()==false){
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return head;
    }
};
