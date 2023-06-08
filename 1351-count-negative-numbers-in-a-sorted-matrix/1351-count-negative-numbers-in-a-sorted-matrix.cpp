class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        int left= 0;
        int right= n-1;
        int up= 0;
        int down= m-1;
        int ans=0;
        
        
        while (up < m) {
            while (right >= 0 && grid[up][right] < 0) right--;
            ans += n - right - 1;
            up++;
        }
        return ans;
    }
};