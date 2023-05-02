class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long n=0;
        for(auto i:nums){
            if(i==0)return 0;
            if(i<0)n++;
        }
        if(n&1)return -1;
        return 1;
    }
};
