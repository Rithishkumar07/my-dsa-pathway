class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]&&ans[j]<=ans[i]){
                    ans[j]=1+ans[i];
                }
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};
