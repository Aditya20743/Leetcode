class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(75,0);
        
        for(auto it: s){
            freq[it-'0']++;
        }
        
        vector<pair<int,int>> v;
        for(int i=0;i<75;i++){
            v.push_back({freq[i],i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        string ans="";
        for(int i=0;i<75;i++){
            int freq= v[i].first;
            int alpha= v[i].second;
            
            while(freq--){
                char ele= '0'+alpha;
                ans+= ele;
            }
                
        }
        return ans;
    }
};