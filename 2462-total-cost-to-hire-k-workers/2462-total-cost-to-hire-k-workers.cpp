class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<int, vector<int>, greater<int> > pq1;
        priority_queue<int, vector<int>, greater<int> > pq2;
        
        int n= costs.size();
        
        int stop= n- 2*c;
        int l=0,r=n-1;
        
        vector<int> taken(n,0);
        if(stop>0){
            while(l<c){
                taken[l]=1;
                pq1.push(costs[l++]);
            }

            while(r+c>= n){
                taken[r]=1;
                pq2.push(costs[r--]);
            }
        }
        
        long long ans=0;
        int workers=0;
        while(stop-- >0 && k){
            if((!pq2.empty() && !pq1.empty())&&  pq1.top() > pq2.top()){
                ans+= pq2.top();
                pq2.pop();
                k--;
                if(stop){
                    taken[r]=1;
                    pq2.push(costs[r--]);
                }
                if(pq2.empty()){
                    cout<<"pq2"<<endl;
                    break;
                }
                // workers++;
                
                
            }
            else if(!pq1.empty()){
                ans+= pq1.top();
                pq1.pop();
                k--;
                
                if(stop){
                    taken[l]=1;
                    pq1.push(costs[l++]);
                }
                if(pq1.empty()){
                    cout<<"pq1"<<endl;
                    break;
                }

            }
        }
        while(!pq2.empty()){
            pq1.push(pq2.top());
            pq2.pop();
        }
        for(int i=0;i<n;i++){
            if(taken[i]==0){
                cout<<"100"<<endl;
                pq1.push(costs[i]);
            }
        }
        
        cout<<k<<endl;
        while(k){
            ans+= pq1.top();
            pq1.pop();
            k--;
            // workers++;
        }
        return ans;
    }
};
// [31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58]
// 11
// 2
//423