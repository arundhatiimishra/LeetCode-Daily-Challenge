// 443. String Compression
// Problem Link - https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars){
        int answer=0;
        int count=1;
        int ptr1=0;
        for(int i=1;i<chars.size();i++){
            if(chars[i]!=chars[i-1]){
                if(count==1){
                    answer+=1;
                    chars[ptr1]=chars[i-1];
                    ptr1++;
                }else{
                    if(count<10){
                        answer+=2;
                        chars[ptr1]=chars[i-1];
                        ptr1++;
                        chars[ptr1]=(char)(count+'0');
                        ptr1++;
                    }else{
                        chars[ptr1]=chars[i-1];
                        ptr1++;
                        answer+=1;
                        string countb="";
                        while(count!=0){
                            countb+=to_string(count%10);
                            count/=10;
                        }
                        count=1;
                        for(int j=countb.size()-1;j>=0;j--){
                            chars[ptr1]=countb[j];
                            ptr1++;
                            answer++;
                        }
                    }
                }
                count=1; 
            }else{
                count++;
            }
        }
        if(count==1){
            answer+=1;
            chars[ptr1]=chars[chars.size()-1];
        }else{
            answer+=1;
            chars[ptr1]=chars[chars.size()-1];
            ptr1++;
            string countb="";
            while(count!=0){
                countb+=to_string(count%10);
                count/=10;
            }
            for(int j=countb.size()-1;j>=0;j--){
                chars[ptr1]=countb[j];
                ptr1++;
                answer++;
            }
        }
        return answer;
    }
};
