class Solution {
public:
    void dfs(string node, string &des, unordered_map<string, unordered_map<string, double>>& mp, unordered_set<string>& v, double& a, double temp){
        if(v.find(node) != v.end()) return;
        
        v.insert(node);
        
        if(node==des){
            a =temp;
            return;
        }
        
        for(auto it: mp[node]){
            dfs(it.first,des,mp,v,a,temp*it.second);
        }
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,   unordered_map<string,double>> mp;
        
        for(int i=0;i<equations.size();i++){
            
            string dividend= equations[i][0];
            string divisor= equations[i][1];
            double val= values[i];
            
            mp[dividend][divisor] =val;
            
            mp[divisor][dividend] = 1.0/val;
            
        }
        
        vector<double> ans;
        
        for(auto it:queries){
            string dividend= it[0];
            string divisor =it[1];
            
            if(mp.find(dividend)== mp.end() || mp.find(divisor)==mp.end() ){
                ans.push_back(-1.0);
            }
            else{
                unordered_set<string> v;
                double a= -1.0, temp=1.0;
                dfs(dividend,divisor,mp,v,a,temp);
                ans.push_back(a);
            }
        }
        
        return ans;
        
    }
};