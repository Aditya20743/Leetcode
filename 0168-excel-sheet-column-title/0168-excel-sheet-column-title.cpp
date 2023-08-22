class Solution {
public:
    string convertToTitle(int columnNumber) {
        //
        string ans="";
        while(columnNumber ){
            columnNumber--;
            char t= 'A' + (columnNumber%26 );
            ans+= t;
            columnNumber = columnNumber/26;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};