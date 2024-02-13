class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto it: words){
            int l= 0, r=it.size()-1;
            while(l<=r && it[l]==it[r]){
                l++;
                r--;
            }
            if(l>r)     return it;
        }
        return "";
    }
};