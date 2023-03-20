class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            string word= q.front().first;
            string original= word;
            int steps= q.front().second;
            q.pop();
            
            if(word== endWord){
                return steps;
            }
            
            for(int i=0;i<word.size();i++){
                for(char x='a';x<='z';x++){
                    word[i]= x;
                    if(s.find(word)!= s.end()){
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                word= original;
            }
        }
        return 0;
    }
};