class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0 && mp.find(arr[i]/2)!=mp.end()){
                return true;
            }
            if(mp.find(arr[i]*2)!= mp.end()){
                return true;
            }
            mp[arr[i]]=i;
        }
        return false;
    }
};