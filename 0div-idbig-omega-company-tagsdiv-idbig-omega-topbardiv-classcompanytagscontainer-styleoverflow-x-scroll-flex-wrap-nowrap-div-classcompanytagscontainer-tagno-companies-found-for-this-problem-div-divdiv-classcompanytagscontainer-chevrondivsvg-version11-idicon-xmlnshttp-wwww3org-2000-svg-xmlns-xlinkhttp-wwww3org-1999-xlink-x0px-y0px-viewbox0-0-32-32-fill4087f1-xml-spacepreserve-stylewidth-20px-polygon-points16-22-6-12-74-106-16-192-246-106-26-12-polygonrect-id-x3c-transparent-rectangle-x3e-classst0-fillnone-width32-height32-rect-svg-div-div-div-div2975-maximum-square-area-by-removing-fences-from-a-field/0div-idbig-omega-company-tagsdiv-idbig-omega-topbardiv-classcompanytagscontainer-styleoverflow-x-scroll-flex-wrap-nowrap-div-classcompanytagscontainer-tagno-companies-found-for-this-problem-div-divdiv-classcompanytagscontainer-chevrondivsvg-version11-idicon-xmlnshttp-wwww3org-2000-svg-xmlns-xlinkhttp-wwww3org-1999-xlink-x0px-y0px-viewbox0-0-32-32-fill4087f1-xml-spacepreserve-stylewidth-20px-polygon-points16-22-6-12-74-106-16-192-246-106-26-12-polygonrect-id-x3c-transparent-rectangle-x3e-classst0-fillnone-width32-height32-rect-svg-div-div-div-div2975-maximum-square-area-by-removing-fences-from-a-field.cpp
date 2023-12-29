class Solution {
public:
    int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        
        
        unordered_set<int> st;
        
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                st.insert(abs(1LL*hFences[i]- 1LL*hFences[j])%mod);
            }
        }
        
        int ans=0;
        
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                if(st.find(abs(vFences[j]- vFences[i]))!= st.end()){
                    ans= max(ans, abs(vFences[i]- vFences[j])%mod);
                }
            }
        }
        if(ans==0)  return -1;
        return 1LL*ans*ans%mod ;
        
    }
};