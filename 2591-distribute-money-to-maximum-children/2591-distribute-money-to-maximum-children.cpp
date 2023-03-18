class Solution {
public:
    int distMoney(int money, int children) {
        int m= money,c=children;
        
        if(m< c) return -1;
        if(m< 8) return 0;
        if(m> 8*c)  return c-1;
        int ans=0;
        while(m>=8 && m-8>=c-1){
            ans++;
            m=m-8;
            c--;
            
        }
        if(m==4 && c==1){
            return ans -1;
        }
        return ans;
    }
};
