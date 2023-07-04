class Solution {
public:
    bool vowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')  return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int maxi=0,count=0;
        for(int i=0;i<k;i++){
            if(vowel(s[i])){
                count++;
            }
        }
        maxi=count;
        int j=k,i=0,n=s.size();
        
        while(j<n){
            if(vowel(s[j++])){
                count++;
            }
            if(vowel(s[i++])){
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};