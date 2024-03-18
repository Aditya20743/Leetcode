class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first<b.first){
            return true;
        }
        else if(a.first> b.first){
            return false;
        }
        return  a.second<b.second;
    }
    string minimizeStringValue(string s) {
        vector<int> f(26,0);
        vector<pair<int,int>> pv;
        // for(int i=0;i<26;i++){
        //     pv.push_back({0,i});
        // }
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='?'){
                f[s[i]-'a']++;
            }
        }
        for(int j=0;j<26;j++){
            pv.push_back({f[j],j});
        }
        
        sort(pv.begin(),pv.end(),cmp);
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                ans += 'a'+pv[0].second;
                f[pv[0].second]++;
            }
            pv.clear();
            for(int j=0;j<26;j++){
                pv.push_back({f[j],j});
            }
            sort(pv.begin(),pv.end(),cmp);
            
            
            // cout<<endl;
        }
        int j=0;
        string res="";
        sort(ans.begin(), ans.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                res+= ans[j++];
            }
            else{
                res+= s[i];
            }
        }
        // cout<<endl;
        return res;
    }
};