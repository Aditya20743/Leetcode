class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr_height=0;
        int maxi=0;
        for(auto it: gain){
            curr_height+= it;
            maxi=max(maxi,curr_height);
        }
        return maxi;
    }
};