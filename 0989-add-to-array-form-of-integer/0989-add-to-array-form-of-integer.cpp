class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        int carry=0;
        while(k>=1 && i>=0){
            int t= k%10;
            if(num[i]+ t + carry > 9){
                num[i]= (num[i]+t+carry)%10;
                carry=1;
            }
            else {
                num[i]= num[i]+t+carry;    
                carry=0;
            }
            k/=10;
            i--;
        }
        while(i>=0){
            if(num[i] + carry > 9){
                num[i]= (num[i]+carry)%10;
                carry=1;
            }
            else {
                num[i]= num[i]+carry; 
                carry=0;
            }
            i--;
        }
        vector<int> ans;
        if(k>=1){
            if(carry==1){
                k+= 1;
            }
            while(k>=1){
                ans.push_back(k%10);
                k/=10;
            }
            reverse(ans.begin(),ans.end());
        }
        else{
            if(carry==1){
                ans.push_back(1);
            }
        }
        for(auto it: num){
                ans.push_back(it);
        }
        return ans;
    }
};