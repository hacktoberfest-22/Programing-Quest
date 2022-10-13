class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=1e8;
        }
        dp[0]=cost[0];
        dp[1]=min(cost[0]+cost[1],cost[1]);
        for(int i=2;i<n;i++){
            if(dp[i]>dp[i-1]+cost[i]){
                dp[i]=dp[i-1]+cost[i];
            }
            if(dp[i]>dp[i-2]+cost[i]){
                dp[i]=dp[i-2]+cost[i];
            }
        }
        return min(dp[n-1],dp[n-2]);
    }
};
