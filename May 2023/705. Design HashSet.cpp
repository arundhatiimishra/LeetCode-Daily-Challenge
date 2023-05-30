// 705. Design HashSet
// Problem Link - https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    vector<int> myHashMap;
    
    MyHashSet(){
        vector<int> temp(1e6+1,0);
        myHashMap=temp;
    }
    
    void add(int key){
        myHashMap[key]++;
    }
    
    void remove(int key){
        myHashMap[key]=0;
    }
    
    bool contains(int key){
        if(myHashMap[key]!=0){
            return true;
        }
        return false;
    }
};
