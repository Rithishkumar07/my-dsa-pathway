class Solution {
public:
    string lcs(string &s1,string &s2){
        int l1=s1.length(),l2=s2.length();
        vector<vector<string>>dp(l1+1,vector<string>(l2+1));
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0||j==0)dp[i][j]="";
                else if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else{
                    if(dp[i-1][j].length()>dp[i][j-1].length()){
                        dp[i][j]=dp[i-1][j];
                    }
                    else dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[l1][l2];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string common=lcs(str1,str2),ans="";
        int p1=0,p2=0,p3=common.length();
        for(int i=0;i<p3;i++){
            while(str1[p1]!=common[i]){
                ans.push_back(str1[p1++]);
            }
            while(str2[p2]!=common[i]){
                ans.push_back(str2[p2++]);
            }
            ans.push_back(common[i]);
            p1++;
            p2++;
        }
        if(p1<str1.length())ans+=str1.substr(p1);
        if(p2<str2.length())ans+=str2.substr(p2);
        return ans;

    }
};
