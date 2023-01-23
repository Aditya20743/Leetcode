class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int> > maxh;
        for(int i=0;i<arr.size();i++){
            int dif= abs(arr[i]-x);
            //if(dif!=0)
            maxh.push({dif,arr[i]});
            // else if(maxh.top.first== dif){
            //     if(maxh.top.second<)
            // }
            
            if(maxh.size()>k){
                maxh.pop();
            }   
        }
        vector<int> v(k);
        int i=k-1;
        while(!maxh.empty()){
            v[i--]=(maxh.top().second);
            maxh.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};