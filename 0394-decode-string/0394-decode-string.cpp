class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans="";
        int n= s.size();
        
        for(int i=0;i<n;i++){
            
            if(s[i]==']'){
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp= st.top()+ temp;
                    st.pop();
                }
                st.pop();   // for [ 
                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top()+ num;
                    st.pop();
                }
                int k= stoi(num);
                // cout<<temp<<endl;
                while(k--){
                    for(auto it: temp){
                        st.push(it);
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans= st.top()+ ans;
            st.pop();
        }
        
        return ans;
    }
};