// 142. Linked List Cycle II
// Problem Link - https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head){
        map<ListNode*,bool> mp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(mp[temp]==true){
                return temp;
            }else{
                mp[temp]=true;  
            }
            temp=temp->next;
        }
        return NULL;
    }
};
