class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> reveal;

        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        
        int j=0;
        
        while(!q.empty()){
            reveal.push_back(q.front());
            q.pop();
            
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        vector<int> ans(reveal.size());
        
        for(int i=0;i<reveal.size();i++){
            ans[reveal[i]] = deck[i];
        }
        return ans;
    }
};