// 382. Linked List Random Node
// Problem Link - https://leetcode.com/problems/linked-list-random-node/

class Solution {
public:
    ListNode* head1=NULL;
    
    Solution(ListNode* head){
        head1=head;
    }
    
    int getRandom(){
        vector<int> temp;
        ListNode* tem=head1;
        while(tem!=NULL){
            temp.push_back(tem->val);
            tem=tem->next;
        }
        int random=rand()%temp.size();
        return temp[random];   
    }
};
