class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= needle.size();
        
        for(int i=0;i<haystack.size();i++){
            if(haystack[i] == needle[0]){
                // cout<<haystack.substr(i,n)<<endl;
                if(i+n-1< haystack.size() && haystack.substr(i,n) == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};