// 989. Add to Array-Form of Integer
// Problem Link - https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k){
        vector<int> temp;
        while(k!=0){
            temp.push_back(k%10);
            k=k/10;
        }
        reverse(num.begin(),num.end());
        if(temp.size()<num.size()){
            while(temp.size()!=num.size()){
                temp.push_back(0);
            }
        }else if(num.size()<temp.size()){
            while(num.size()!=temp.size()){
                num.push_back(0);
            }
        }
        int carry=0;
        for(int i=0;i<num.size();i++){
            if(num[i]+temp[i]+carry<10){
                num[i]=num[i]+temp[i]+carry;
                carry=0;
            }else{      
                num[i]=(num[i]+temp[i]+carry)%10;
                carry=1;
            }
        }
        if(carry==1){
            num.push_back(1);
        }
        reverse(num.begin(),num.end());
        return num;
    }
};
