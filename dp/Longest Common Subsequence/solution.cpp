class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int r=text1.size(),k=text2.size();
        int dp[r+1][k+1];
        for(int i=0;i<=r;i++){
            for(int j=0;j<=k;j++){
                if(i==0||j==0)dp[i][j]=0;
                else{
                    if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[r][k];
    }
};
