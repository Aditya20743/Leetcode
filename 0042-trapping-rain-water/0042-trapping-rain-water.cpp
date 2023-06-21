class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        vector<int> greatest_to_left(n);
        vector<int> greatest_to_right(n);
        
        
        int ans=0;
        greatest_to_left[0]= height[0];
        greatest_to_right[n-1]= height[n-1];
        
        for(int i=1;i<n;i++){
            greatest_to_left[i]= max(greatest_to_left[i-1], height[i]);
            
            greatest_to_right[n-i-1]=max(greatest_to_right[n-i],height[n-i-1]);
        }
        
        for(int i=0;i<n;i++){
            ans+= min(greatest_to_left[i], greatest_to_right[i])- height[i];
        }
        
        return ans;
   
    }
};