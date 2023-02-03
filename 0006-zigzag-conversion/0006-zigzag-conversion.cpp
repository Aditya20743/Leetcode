class Solution {
public:
    string convert(string s, int numRows) {
        int idx=0, n= s.size();
        vector<string> x(numRows);
        while(idx<n){
            for(int i=0;i<numRows;i++){
                if(idx>=n)  break;
                    x[i]+= s[idx];
                    idx++;
                
            }
            for(int i=numRows-2;i>0 ;i--){
                if(idx>=n)  break;
                    x[i]+=s[idx];
                    idx++;    
            }
        }
        
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+= x[i];
        }
        return ans;
    }
};