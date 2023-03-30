class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(s1==s2) return true;   
        if(n==1) return false;
        
        string key = s1+" "+s2;
        
        if(mp.find(key)!=mp.end()) return mp[key];

        for(int i=1;i<n;i++)
        {
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && 
                            isScramble(s1.substr(i),s2.substr(i)))
                return mp[key] = true;
            
            if(isScramble(s1.substr(0,i),s2.substr(n-i)) &&
                        isScramble(s1.substr(i),s2.substr(0,n-i)))
                return mp[key] = true;
        }
        
        return mp[key] = false;
    }
};
// class Solution {
// public:
//     void Scramble (string o,string s1, set<string>&s){
//         if(s1.size()==1 || s1.size()==0)    return ;
        
//         for(int i=1;i<s1.size();i++){
//             string x= s1.substr(0,i);
//             string y= s1.substr(i, s1.size()-i);
//             cout<<i<<" "<<o<<" "<<x<<" "<<y<<endl;
//             s.insert(o+x+y);
//             s.insert(y+o+x);
//             s.insert(o+y+x);
            
//             s.insert(x+o+y);
            
//             string c1= o+x, c2= o+y, c3= x, c4= y;
//             Scramble(c1, c4, s);
//             //Scramble(c4, c1, s);
//             //Scramble(c3, c2, s);
//             Scramble(c2, c3, s);
//         }
//     }
//     bool isScramble(string s1, string s2) {
//         if(s1== s2) return true;
//         set<string> s;
//         string o="";
//         Scramble(o,s1, s);
//         // for(auto it: s){
//         //     cout<<it<<" ";
//         // }
//         if(s.count(s2)>0)
//             return true;
//         return false;
        
//     }
// };