class Solution {
public:
    static bool cmp(vector<string> a, vector<string> b){
        if(a[0]>b[0]){
            return false;
        }
        else if(a[0]<b[0])  return true;
        
        else {
            return a[1]<b[1];
        }
    }
    int time(string s){
        int res=0,hr=0;
        
        hr+= (s[0]-'0')*10;
        hr+= (s[1]-'0');
        
        res+= (s[2]-'0')*10 + (s[3]-'0') + hr*60;
    
        return  res;
    }
    
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        vector<string> ans;
        
        sort(a.begin(), a.end(), (cmp));
        
        unordered_map<string, int> mp;
        
        if(a.size()<3)  return ans;
        
        for(int i=0;i<a.size()-2;i++){
            if(mp.find(a[i][0])== mp.end() && a[i][0] == a[i+2][0]){
                int t2= time(a[i+2][1]);
                int t1= time(a[i][1]);
                
                if(t2-t1 <60){
                    mp[a[i][0]]++;
                    ans.push_back(a[i][0]);
                }
            }
        }
        
        return ans;
    }
};