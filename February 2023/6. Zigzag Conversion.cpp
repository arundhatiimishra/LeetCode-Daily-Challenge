// 6. Zigzag Conversion
// Problem link - https://leetcode.com/problems/zigzag-conversion/

class Solution{
public:
    string convert(string s, int numRows){
        if(numRows==1){
            return s;
        }
        vector<vector<char>> rows(numRows);
        vector<int> rowInOrder(s.size(),0);
        int idx1=0;
        while(true){
            if(idx1<s.size()){
                rowInOrder[idx1]=1;
                idx1=idx1+((numRows-1)+(numRows-1)); 
            }else{
                break;
            }
        }
        rows[0].push_back(s[0]);
        bool got1=true;
        bool gotnumRows=false;
        for(int i=1;i<s.size();i++){
            if(rowInOrder[i]==1){
                gotnumRows=false;
                got1=true;
            }
            if(got1==true && rowInOrder[i]==0){
                rowInOrder[i]=rowInOrder[i-1]+1;
            }else if(gotnumRows==true && rowInOrder[i]==0){
                rowInOrder[i]=rowInOrder[i-1]-1;
            }
            if(rowInOrder[i]==numRows){
                gotnumRows=true;
                got1=false;
            }
            rows[rowInOrder[i]-1].push_back(s[i]);
        }
        string answer="";
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<rows[i].size();j++){
                answer+=rows[i][j];
            }
        }
        return answer; 
    }
};