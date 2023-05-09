    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        if(nums.size()<2)return false;
        int target=sum/2;
        bool dp[nums.size()+1][target+1];
        // vector<vector<bool>>dp(nums.size()+1,vector<bool>(target+1,false));
        for(int i=0;i<=nums.size();i++){
            for(int j=0;j<=target;j++){
                if(i==0||j==0)dp[i][j]=0;
                else if(nums[i-1]==j)dp[i][j]=1;
                else if(nums[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][target];
    }
