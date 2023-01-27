class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int> > q;
        set <string> s(wordList.begin(),wordList.end());
        
        q.push({beginWord,1});
        s.erase(beginWord);
        
        while(!q.empty()){
            string word= q.front().first;
            int step= q.front().second;
            s.erase(word);
            
            q.pop();
            if(word== endWord)   return step;
            
            for(int i=0;i<word.size();i++){
                char original= word[i];
                for(char ch ='a'; ch<= 'z';ch++){
                    word[i]=ch;
                    if(s.find(word)!= s.end()){
                        q.push({word,step+1});
                        s.erase(word);
                    }
                }
                word[i]= original;
            }
        }
        return 0;
    }
};