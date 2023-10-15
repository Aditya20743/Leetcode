class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
      int n=s.size(),cnt=0,temp=INT_MAX;
      string s1="";
        vector<string> v;
        for(int i=0;i<n;i++){
            string s2="";
            for(int j=i;j<n;j++){
                if(s[j]=='1'){
                    cnt++;
                }
                if(cnt<=k){
                 s2+=s[j];   
                }
                if(cnt==k){
                    v.push_back(s2);
                    int n1=s2.size();
                    temp=min(temp,n1);
                }
            }
            cnt=0;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
                if(v[i].size()==temp){
                    s1+=v[i];
                    break;
                }
            }
            return s1;
        
    }
};