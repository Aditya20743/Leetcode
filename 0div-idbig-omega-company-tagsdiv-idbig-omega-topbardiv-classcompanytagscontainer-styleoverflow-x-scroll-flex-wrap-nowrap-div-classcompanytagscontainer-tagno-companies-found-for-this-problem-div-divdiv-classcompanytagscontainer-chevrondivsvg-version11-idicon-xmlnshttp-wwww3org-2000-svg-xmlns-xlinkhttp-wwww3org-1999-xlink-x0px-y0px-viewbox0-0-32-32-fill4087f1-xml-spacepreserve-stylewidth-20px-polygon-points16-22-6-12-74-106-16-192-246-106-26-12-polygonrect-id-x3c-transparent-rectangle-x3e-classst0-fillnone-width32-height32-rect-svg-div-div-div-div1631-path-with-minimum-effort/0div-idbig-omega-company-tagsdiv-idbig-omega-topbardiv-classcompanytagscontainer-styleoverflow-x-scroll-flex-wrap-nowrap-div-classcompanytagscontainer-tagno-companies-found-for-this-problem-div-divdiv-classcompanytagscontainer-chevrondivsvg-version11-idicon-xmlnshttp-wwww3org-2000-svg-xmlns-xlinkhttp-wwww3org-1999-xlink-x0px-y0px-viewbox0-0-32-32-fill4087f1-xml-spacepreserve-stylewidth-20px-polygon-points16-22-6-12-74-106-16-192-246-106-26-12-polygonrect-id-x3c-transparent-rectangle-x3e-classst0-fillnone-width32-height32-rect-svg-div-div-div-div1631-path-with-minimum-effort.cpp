class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater< pair<int,pair<int,int>>> > pq;
        
        pq.push({0,{0,0}});
        
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        
        effort[0][0]=0;
        
        int dir[5]={-1,0,1,0,-1};
        
        while(!pq.empty()){
            int curr_eff= pq.top().first;
            int row= pq.top().second.first;
            int col= pq.top().second.second;
            
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nr= row+ dir[i];
                int nc= col+ dir[i+1];
                
                if(nr>=0 && nc>=0 && nr< n && nc< m){
                    int neweff= max(abs(heights[nr][nc]- heights[row][col]),curr_eff);
                    if(effort[nr][nc]> neweff){
                        effort[nr][nc]= neweff;
                        
                        //cout<< effort[nr][nc] << " ";
                        pq.push({effort[nr][nc],{nr,nc}});
                    }
                   
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<effort[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //if(eff[n-1][m-1]== INT_MAX) return -1;
        return effort[n-1][m-1];
        
    }
};