class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> a(2001,0);
        
        for(int i=0;i<arr.size();i++){
            a[arr[i]+1000]++;
        }
        set<int> st;
        
        for(int i=0;i<2001;i++){
            if(a[i]!= 0){
                if(st.find(a[i])!= st.end())  return false;
                st.insert(a[i]);
            }
        }
        
        return true;
    }
};