class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            string curr = q.front().first;
            int step = q.front().second;
            string original = curr;
            q.pop();
            
            if(curr==endWord)   return step;
            
            for(int i=0;i<curr.size();i++){
                for(char a= 'a'; a<='z'; a++){
                    curr[i] = a;
                    
                    if(st.find(curr)!= st.end()){
                        if(curr == endWord) return step+1;
                        q.push({curr, step+1});
                        st.erase(curr);
                    }
                }
                curr = original;
            }
        }
        
        return 0;
        
    }
};