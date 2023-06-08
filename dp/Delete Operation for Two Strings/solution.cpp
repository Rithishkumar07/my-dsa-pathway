class Solution {
public:
    int lcs(string &s1,string &s2){
        int dp[s1.size()+1][s2.size()+1];
        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i==0||j==0)dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
    int minDistance(string &word1, string &word2) {
        int len=lcs(word1,word2);
        return word1.size()+word2.size()-2*len;
    }
};
