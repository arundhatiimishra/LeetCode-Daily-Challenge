// 380. Insert Delete GetRandom O(1)
// Problem Link - https://leetcode.com/problems/insert-delete-getrandom-o1/

// Time Complexity - O(N*log N)
// Space Complexity - O(N)

class RandomizedSet {
public:
    unordered_map<int,int> idx;
    vector<int> store;
    
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(idx.find(val)!=idx.end()){
            return false;
        }
        idx[val]=store.size();
        store.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(idx.find(val)==idx.end()){
            return false;
        }
        int idxOfVal=idx[val];
        store[idxOfVal]=store[store.size()-1];
        idx[store[idxOfVal]]=idxOfVal;
        store.pop_back();
        idx.erase(val);
        return true;
    }
    
    int getRandom() {
        return store[rand()%store.size()];
    }
};