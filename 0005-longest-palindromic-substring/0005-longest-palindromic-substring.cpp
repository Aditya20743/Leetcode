class Solution {
public:
    
    // brute force
    // 
    bool isPalindrome(string w){
        int l=0,r=w.size()-1;
        while(l<r){
            if(w[l]!= w[r]){
                return false;
            }
            else{
                l++, r--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="",temp="",longest="";
        
        for(int i=0;i<s.size();i++){
            int j=s.size()-1;

            while(i<j){
                if(s[i]==s[j] && longest.size()<(j-i+1)){ 
                    temp=s.substr(i,(j-i+1));
                    ans=temp;
                    reverse(temp.begin(),temp.end());
                    if(ans==temp)
                    longest=ans;
                }
                j--;
            }
        }
        if(longest.size()==0)   /*when the longest palindromic substring size can not be larger than 1*/
        longest=s[0];

        return longest;
    }
};
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         for(int x=i;x<=j;x++){
        //             word+= s[x];
        //         }
        //         if(isPalindrome(word)){
        //             if(ans< j-i+1){
        //                 a= word;
        //                 ans= j-i+1;
        //             }
        //         }
        //         word="";
        //     }
        // }
        // return a;
//     }
// };