//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            //cout<<mp[nums[i]]<<" ";
            
        }
        
        for(auto it: mp){
            //cout<<it.first<<"- "<<it.second<<endl;
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans(k);
        while(!pq.empty()){
            ans[--k]=(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends