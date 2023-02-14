// 67. Add Binary
// Problem Link - https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b){
        if(a.size()>b.size()){
            int k=a.size()-b.size();
            for(int i=0;i<k;i++){
                b="0"+b;
            } 
        }else{
            int k=b.size()-a.size();
            for(int i=0;i<k;i++){
                a="0"+a;
            }
        }
        string ans="";
        int carry=0;
        int ptr1=a.size()-1;
        int ptr2=b.size()-1;
        while(ptr1!=-1 && ptr2!=-1){
            if(a[ptr1]=='1' && b[ptr2]=='1' && carry==0){
                ans="0"+ans;
                carry=1;
            }else if(a[ptr1]=='1' && b[ptr2]=='1' && carry==1){
                ans="1"+ans;
                carry=1;
            }else if(a[ptr1]=='0' && b[ptr2]=='0' && carry==1){
                ans="1"+ans;
                carry=0;
            }else if(a[ptr1]=='0' && b[ptr2]=='0' && carry==0){
                ans="0"+ans;
                carry=0;
            }else if(a[ptr1]=='0' && b[ptr2]=='1' && carry==0){
                ans="1"+ans;
                carry=0;
            }else if(a[ptr1]=='0' && b[ptr2]=='1' && carry==1){
                ans="0"+ans;
                carry=1;
            }else if(a[ptr1]=='1' && b[ptr2]=='0' && carry==0){
                ans="1"+ans;
                carry=0;
            }else if(a[ptr1]=='1' && b[ptr2]=='0' && carry==1){
                ans="0"+ans;
                carry=1;
            }
            ptr1--;
            ptr2--;
        }
        if(carry==1){
            ans="1"+ans;
        }
        return ans;
    }
};
