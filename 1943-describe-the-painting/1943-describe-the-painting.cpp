class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        sort(segments.begin(),segments.end());
        
        vector<long long> c(1e5+1,0);
        vector<int> end(1e5+1,0);
        
        for(auto it: segments){
            c[it[0]]+= it[2];
            c[it[1]]-= it[2];
            end[it[1]]=1;
            end[it[0]]=1;
        }
        
        vector<vector<long long>> ans;
        
        for(int i=1;i<1e5+1;i++){
            c[i]+= c[i-1];
        }
        // for(int i=0;i<15;i++){
        //     cout<<c[i]<<" ";
        // }
        // cout<<endl;
        vector<long long> temp;
        
        for(int i=1;i<1e5+1;i++){
            if( c[i]!=0 && temp.size()==0 && end[i]){
                temp.push_back(i);
            }
            else if( temp.size()==1 && end[i]){
                temp.push_back(i);
                temp.push_back(c[i-1]);
                ans.push_back(temp);
                temp.clear();
                i--;
            }

        }
        // for(auto it: temp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};