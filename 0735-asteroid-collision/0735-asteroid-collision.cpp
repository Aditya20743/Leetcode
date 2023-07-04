class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n= asteroids.size();
        vector<int> ans;
        bool flag=true;
        
        // if neg comes first then collision we never be there
        for(int i=0;i<n;i++){
            bool flag=true;
            
            // while is used becoz until st.top()>0 we cant add neg as they we do the collision.
            while((!st.empty() && st.top()>0 && asteroids[i]<0)){
                int x= abs(asteroids[i]);
                int y= st.top();
                
                if(x>y){
                    st.pop();
                    flag=true;
                }
                else if(x==y){
                    st.pop();
                    flag=false;
                    break;
                }
                else if(x<y){
                    flag= false;
                    break;
                }
            }
            if(flag==true){
                st.push(asteroids[i]);
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};