class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())   return -1;
        int n= needle.size();
        for(int i=0;i<=haystack.size()-n;i++){
            string s= haystack.substr(i,n);
            if(s== needle){
                return i;
            }
        }
        return -1;
        
    }
};