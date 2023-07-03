class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i=0,f=-1,sc=-1;
        int n=s.size(), m= goal.size();
        
        
        
        if(s==goal){
            unordered_map<int,int> mp;
            for(auto it: s){
                mp[it]++;
                if(mp[it]>=2){
                    return true;
                }
            }
            
        }
        
        if(n!=m )   return false;
        int c=0;
        while(i!=n){
            if(s[i]!=goal[i]){
                c++;
                if(f==-1){
                    f= i;
                }
                else if(f!= -1){
                    sc= i;
                }
            }
            i++;
        }
        if(c==2){
            if(s[f]==goal[sc] && s[sc]== goal[f]){
                return true;
            }
        }
        return false;
        
    }
};