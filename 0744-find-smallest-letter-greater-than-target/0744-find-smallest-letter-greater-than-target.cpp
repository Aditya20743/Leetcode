class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,r=letters.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(letters[m]>target)   r=m-1;
            else if(letters[m]<target)  l=m+1;
            else 
                {
                while(m+1<letters.size() && letters[m]==letters[m+1]) m++;
                if(m+1<letters.size())
                    return letters[m+1];
                else
                    return letters[0];
            }
        }
        if(r==letters.size()-1){
            return letters[0];
        }
        return letters[l];
    }
};