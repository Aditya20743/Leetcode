class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        if(hand.size() % groupSize !=0) return false;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(mp.size()){
            int l= mp.begin()-> first;
            int h= l+groupSize-1;

            for(int i=l;i<=h;i++){
                if(mp[i]==0)  return false;
                else{
                    mp[i]--;
                    if(mp[i]==0)  mp.erase(i);
                }
            }
        }
        return true;
    }
};