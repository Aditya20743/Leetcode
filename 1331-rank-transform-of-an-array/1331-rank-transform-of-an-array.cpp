class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N= arr.size();
        vector<pair<int,int>> v;
        int c=0;
        for(auto it: arr){
            pair<int,int> p;
            p.first= it;
            p.second= c++;
            
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        
        vector<int> ans(N);
        int idx=0;
        for(int i=0;i<N;i++){
            if(i>0 && v[i].first== v[i-1].first)    idx--;
            ans[v[i].second]= idx+1;
            idx++;
        }
        return ans;
    }
};