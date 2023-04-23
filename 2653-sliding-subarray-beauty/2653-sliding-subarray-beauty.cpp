class Solution {
public:
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n= nums.size();
        
        unordered_map<int,int> mp;
        int i=0;
        for(int i=0;i<k-1;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        int c=0, j=0;
        i=k-1;
        while(i<nums.size()){
            mp[nums[i]]++;
            i++;
            
            for(int j=-50;j<51;j++){
                c+= mp[j];
                if(c>= x){
                    ans.push_back(j);
                    c=0;
                    break;
                }
            }
            
            mp[nums[j]]--;
            j++;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]>0){
                ans[i]=0;
            }
        }
        return ans;
        
        
//         deque<int> st,cst;
        
//         vector<int> ans;
//         int i=0;
        
//         for(int i=0;i<k;i++){
//             st.push_back(nums[i]);
//         }
//         i=k;
//         cst= st;
//         sort(cst.begin(),cst.end());
//         if(cst[x-1]<0)
//             ans.push_back(cst[x-1]);
//         else
//             ans.push_back(0);
//         while(i<nums.size()){
//             st.pop_front();
//             st.push_back(nums[i++]);
//             cst= st;
            
//             sort(cst.begin(),cst.end());
//             if(cst[x-1]<0)
//             ans.push_back(cst[x-1]);
//             else
//             ans.push_back(0);
        
//         }
//         return ans;
    }
};