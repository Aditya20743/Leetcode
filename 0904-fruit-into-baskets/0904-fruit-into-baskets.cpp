class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi=0;
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r< fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)   { mp.erase(fruits[l]);}
                l++;
            }
            maxi=max(maxi,r-l+1); 
            r++;
        }
        return maxi;
    }
};