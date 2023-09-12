class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto it: s){
            freq[it-'a']++;
        }
        unordered_set<int> st;
        int ans=0;
        for(int i=0;i<26;i++){
            while(st.find(freq[i])!= st.end() && freq[i]!= 0){
                ans++;
                freq[i]--;
            }
            st.insert(freq[i]);
            
        }
        
        return ans;
    }
};