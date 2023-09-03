class Solution {
public:
    bool check(int x){
        string t= to_string(x);
        int n= t.size();
        if(n%2==1)  return false;
        
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                s1+= t[i]-'0';
            }
            else{
                s2+= t[i]-'0';
            }
        }
        return s1==s2;
    }
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++){
            if(check(i)){
                c++;
            }
        }
        return c;
    }
};