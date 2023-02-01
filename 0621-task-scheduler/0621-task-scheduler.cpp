class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        map<char,int> mp;
        int maxfreq=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            maxfreq= max(maxfreq,mp[tasks[i]]);
        }
        int count=0;
        for(auto it: mp){
            if(it.second== maxfreq) count++;
        }
        return max( (int)tasks.size(), (maxfreq-1)*(n+1)+count );
        
        
        
        
        
//         int z= tasks.size();
//         unordered_map<char,int> mp;
//         for(int i=0;i<z;i++){
//             mp[tasks[i]]++;
//         }
//         int time=0;
//         map<char,pair<char,int>> s;
//             vector<int> ini[mp.size()];
//             while(mp.size()!=0){
                
            
//             for(int i=0;i<z;i++){
//                 ini[tasks[i]].push_back(s[tasks[i]].second);
//                 cout<< ini<<" "<<s[tasks[i]].second<<" "<<time<<" "<<mp.size()<<endl;
//                 if( time-ini[0]>=n || s[tasks[i]].second==0)
//                 {
//                     mp[tasks[i]]--;
//                     if(mp[tasks[i]]==0) mp.erase(tasks[i]);
//                     // s.erase(tasks[i]);
//                     s[tasks[i]]= {tasks[i],time};
                    
//                 }
//                 time++;
//             }
//             }
//         return time;
    }
};