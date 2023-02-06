class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> mp,mp1,mp2,dp,dp1,dp2;
        sort(basket1.begin(),basket1.end());
        sort(basket2.begin(),basket2.end());
        long long mini= min(basket1[0],basket2[0]);
        long long mod= 1e9+7;
        for(auto it: basket1){
            mp1[it]++;
            dp1[it]++;
            dp[it]++;
            mp[it]++;
        }
        for(auto it: basket2){
            mp2[it]++;
            dp2[it]++;
            mp[it]++;
            dp[it]++;
        }
        vector<int> toswap, arr,brr;
        
        for(auto it: mp){
            if(it.second%2) return -1;
        }
        int l=0,r=0;
        while(l<basket1.size() && r<basket2.size()){
            if(basket1[l]==basket2[r]){
                l++;
                r++;
            }
            else if(basket1[l]> basket2[r]){
                arr.push_back(basket2[r]);
                r++;
            }
            else{
                brr.push_back(basket1[l]);
                l++;
            }
        }
        while(l<basket1.size()){
            brr.push_back(basket1[l]);
            l++;
        }
        while(r<basket2.size()){
            arr.push_back(basket2[r]);
            r++;
        }
        // for(int i=0;i<basket1.size();i++){
        //     if(basket1[i]!= basket2[i]){
        //         arr.push_back(basket1[i]);
        //         brr.push_back(basket2[i]);
        //     }
        //     else{
        //         mp1[basket1[i]]--;
        //         mp2[basket2[i]]--;
        //     }
        // }
        vector<int> ans1,ans2;
        
        // for(auto it: mp1){
        //     if((it.second +dp2[it.first] ) %2) return -1;
        //     else {
        //         int x= abs((it.second)-dp[it.first]/2);
        //         while(x--){
        //             ans1.push_back(it.first);
        //         }
        //         // while(y--){
        //         //     ans2.push_back(it.first);
        //         // }
        //     }
        // }
        // for(auto it: dp2){
        //     if((it.second + mp1[it.first] ) %2) return -1;
        //     else {
        //         int x= abs((it.second)-mp[it.first]/2);
        //         while(x--){
        //             ans2.push_back(it.first);
        //         }
        //         // while(y--){
        //         //     ans2.push_back(it.first);
        //         // }
        //     }
        // }
        // for(auto it: mp2){
        //     if((it.second + mp1[it.first]) %2) return -1;
        //     else {
        //         int x= it.second/2;
        //         while(x--){
        //             ans2.push_back(it.first);
        //         }
        //     }
        // }
        // for(auto it: arr) cout<<it<<" ";
        // cout<<endl;
        // for(auto it: brr) cout<<it<<" ";
        // cout<<endl;
        
         int z= arr.size();
//         int x= ans2.size();
         long long sum=0;

        for(int i=0;i<z;i++){
            long long a= min(arr[i],brr[z-i-1]);
            long long b= 2* mini;
            //return a;
            sum+= min(b, a);
            //return sum;
            //cout<<sum<< " ";
        }
        //cout<< arr.size()<< " "<<brr.size();
        //cout<<endl;
        return sum/2;
        
    }
};