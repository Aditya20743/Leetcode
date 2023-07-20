class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        long long penscost = 0;
        long long t= total / cost1;
        for(int i=0;i<=t;i++) {
            long long remainingAmount = total - i*cost1;
            long long pencils = remainingAmount/cost2 + 1;
            ways += pencils;
        }
        return ways;
    }
};