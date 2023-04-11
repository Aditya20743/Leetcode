class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto it: s){
            if(it!= '*'){
                st.push(it);
            }
            else {
                st.pop();
            }
        }
        int n= st.size()-1;
        string ans(n+1,'.');
        
        while(!st.empty()){
            ans[n--]= st.top();
            st.pop();
        }
        return ans;
    }
};