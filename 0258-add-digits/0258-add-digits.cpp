class Solution {
public:
    
    int addDigits(int num) {
        int ans=0;
        while(num>0){
            ans+= num%10;
            num= num/10;
        }
        int ans2=0;
        while(ans>0){
                ans2+= ans%10;
                ans= ans/10;
            }
        ans= ans2;

        while(ans2>=10 ){
            
            ans2=0;
            while(ans>0){
                ans2+= ans%10;
                ans= ans/10;
            }
            ans= ans2;
            //if(ans2==10)    ans2=1;
        }
        
        return ans2;
    }
};