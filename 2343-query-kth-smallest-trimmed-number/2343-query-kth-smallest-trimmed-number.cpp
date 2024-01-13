class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& a, vector<vector<int>>& q) {
        vector<int> ans;
        
        for(auto it: q){
            
            
            priority_queue<pair<string,int>> pq;
            for(int i=0;i<a.size();i++){
                string s="";
    
                for(int j=a[i].size()-it[1];j<a[i].size();j++){
                    s+=a[i][j];
                }
                // cout<<nm<<" ";
                pq.push({s, i});
            }
            // cout<<endl;
            int c= pq.size()-it[0];
            
            while(c){
                pq.pop();
                c--;
            }
            
            
            // cout<<it[0]-1<<" ";
            ans.push_back(pq.top().second);
        }
        
        return ans;
    }
};