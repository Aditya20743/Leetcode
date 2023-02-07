class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi=0;
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r< fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>2){
                cout<<"w";
                
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)   { mp.erase(fruits[l]); cout<<"r"; cout<<mp.size();}
                l++;
            }
            
                maxi=max(maxi,r-l+1); 
                //mp[fruits[r]]++;
                
                r++;
                //mp[fruits[r]]++;
                cout<<"l";
            
        }
        cout<<endl;
        return maxi;
    }
};