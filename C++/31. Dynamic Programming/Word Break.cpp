class Solution {
public:
    unordered_map<string,int> mpp;
    bool solve(string& s,int idx,vector<int>& dp){
        if(idx>=s.length()){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        bool ans = false;
        for(int i=idx;i<s.length();i++){
            if(mpp[s.substr(idx,i-idx+1)]!=0){
                ans = ans||solve(s,i+1,dp);
                if(ans){
                    return true;
                }
            }
        }
        return dp[idx]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(),-1);
        for(auto v:wordDict){
            mpp[v]++;
        }
        return solve(s,0,dp);
    }
};
