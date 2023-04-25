// 2336. Smallest Number in Infinite Set
// Problem Link - https://leetcode.com/problems/smallest-number-in-infinite-set/

class SmallestInfiniteSet {
public:
    int ptr1=1;
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_map<int,bool> mp;
    
    SmallestInfiniteSet(){
        
    }
    
    int popSmallest(){
        int eleToPop=-1;
        if(pq.empty()==true){
            eleToPop=ptr1;
            ptr1++;
        }else{
            if(pq.top()<ptr1){
                eleToPop=pq.top();
                mp[eleToPop]=false;
                pq.pop();
            }else{
                eleToPop=ptr1;
                ptr1++;
            }
        }
        return eleToPop;
    }
    
    void addBack(int num){
        if(ptr1<=num){
            return;
        }else{
            if(mp[num]==false){
                pq.push(num);
                mp[num]=true;
            }
        }
    }
};