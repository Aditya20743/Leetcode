class Solution {
public:
    int trap(vector<int>& height) {
        // stack<int> st;
        int n= height.size();
        vector<int> pre,suf;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            pre.push_back(maxi);
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            suf.push_back(maxi);
        }
        reverse(suf.begin(),suf.end());
        int ans=0;

        // for(auto it: pre){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it: suf){
        //     cout<<it<<" ";
        // }
        for(int i=0;i<n;i++){
            
            ans+= min(suf[i],pre[i])-height[i];
        }
        return ans;
        
    }
};