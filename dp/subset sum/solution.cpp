#include <bits/stdc++.h> 
bool subsetSumToK(int n, int tar, vector<int> &a) {
  vector<vector<bool>>dp(n,vector<bool>(tar+1,0));
    for(int i=0;i<n;i++)
    dp[i][0] = 1;

    dp[0][a[0]] = 1;

    for(int i =1;i<n;i++){

        for(int j=1;j<=tar;j++){

            bool excl = dp[i-1][j];

            bool inclu = 0;

            if(j-a[i]>=0)

            inclu = dp[i-1][j-a[i]];

            dp[i][j] = (inclu | excl);

        }

    }

    return dp[n-1][tar];
}
