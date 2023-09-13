class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> leftgreater(n), rightgreater(n), ans(n,1);
        leftgreater[0] = 0;
        rightgreater[n-1] = 0;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                leftgreater[i] = 1;
            else{
                leftgreater[i] = 0;
            }
        }
        for(int i=0;i<n-1;i++){
            if(ratings[i]>ratings[i+1]){
                rightgreater[i] = 1;
            }
            else{
                rightgreater[i] = 0;
            }
        }
        
        for(int i=1;i<n;i++){
            if(leftgreater[i] == 1 && ans[i]<= ans[i-1]){
                ans[i] = ans[i-1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(rightgreater[i] == 1 && ans[i]<= ans[i+1]){
                ans[i] = ans[i+1] + 1;
            }
        }
        int count=0;
        for(auto it: ans)   cout<<it<<" " ,count+= it;
        return count;
    }
};