class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size()<=k)   return "0";
        
        string st;
        for(int i=0;i<num.size();i++){
            if(st.empty()){
                st.push_back(num[i]);
            }
            else if(k && st.back() > num[i]){
                while(k && !st.empty() && st.back()>num[i]){
                    st.pop_back();
                    k--;
                }
                st.push_back(num[i]);
            }
            else{
                st.push_back(num[i]);
            }
        }
        int i=0;
        string ans="";
        while(i!= st.size()){
            if(!(ans.empty() && st[i]=='0')){
                ans.push_back(st[i]);
            }
            i++;
        }
        // return ans;
        i=0;
        string res="";
        
        while(ans.size() && k){
            ans.pop_back();
            k--;
        }
        
        if(ans=="") return "0";
        return ans;
    }
    
};