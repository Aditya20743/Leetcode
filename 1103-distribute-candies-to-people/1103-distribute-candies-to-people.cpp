class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>v(num_people,0);
        int i=0,s=1;
        while(candies>=0){
            if(candies>=s)
                v[i]+=s;
            else{
                v[i]+= candies;
                break;
            }
            candies= candies-s++;
            i++;
            if(i== num_people){
                i=0;
            }
            
        }
        return v;
    }
};