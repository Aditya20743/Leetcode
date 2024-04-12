class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxLeft= 0, maxRight=0;
        int ans=0;
        
        while(l<=r){
            if(height[l]> height[r]){
                if(height[r]> maxRight)     maxRight = height[r];
                else    ans+= maxRight- height[r];
                r--;
            }
            else{
                if(height[l]> maxLeft)      maxLeft = height[l];
                else    ans+= maxLeft - height[l];
                l++;
            }
        }
        
        return ans;
    }
};