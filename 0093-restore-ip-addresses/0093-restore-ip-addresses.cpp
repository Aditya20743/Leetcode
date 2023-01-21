class Solution {
public:
    vector<string> res;
    int n;
    
    bool isValid(string temp){
        if(temp[0]=='0')    return false;
        int val= stoi(temp);
        if(val>255) return false;
        return true;
    }
    void solve(int idx, string &s, int parts, string str){
        
        if(parts>4) return ;
        if(idx== n && parts==4){
            str.pop_back();
            res.push_back(str);
            return ;
        }
        
        if(idx+1<= n){
            solve(idx+1,s,parts+1,str +s.substr(idx,1)+".");
        }
        if( idx+2 <=n && isValid(s.substr(idx,2)) ){
            solve(idx+2,s,parts+1,str +s.substr(idx,2)+".");
        }
        if( idx+3 <=n && isValid(s.substr(idx,3))){
            solve(idx+3,s,parts+1,str +s.substr(idx,3)+".");
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        n= s.size();
        res.clear();
        string str="";
        
        if(n>12) return {};
        // int idx=0;
        // int parts=0;
        
        solve(0,s,0,str);
        return res;
    }
};