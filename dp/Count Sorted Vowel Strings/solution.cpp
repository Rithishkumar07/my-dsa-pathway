class Solution {
public:
    int dfs(int ind,int ct,int n,vector<vector<int>>&dp){
        if(ct==n)return 1;
        if(dp[ind][ct]!=-1)return dp[ind][ct];
        int tot=0;
        for(int i=ind;i<5;i++){
            tot+=dfs(i,ct+1,n,dp);
        }
        return dp[ind][ct]=tot;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(5,vector<int>(n,-1));
        return dfs(0,0,n,dp);
    }
};
