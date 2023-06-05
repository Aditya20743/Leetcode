class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> nge;
        unordered_map<int,int> mp;
        // nge.push_back(-1);
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty()){
                nge.push_back(-1);
            }
            else {
                if(s.top()> nums2[i]){
                    nge.push_back(s.top());
                }
                else{
                    while(!s.empty() && s.top()<= nums2[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        nge.push_back(-1);
                    }
                    if(!s.empty() && s.top()> nums2[i]){
                        nge.push_back(s.top());   
                    }
                }
            }
            s.push(nums2[i]);
            mp[nums2[i]]= i;
            
        }
        
            
        reverse(nge.begin(),nge.end());
        
        vector<int> ans;
        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(nge[mp[nums1[i]]]);
        }
        return ans;
    }
};