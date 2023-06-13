class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        vector<int>ans(cuboids.size());
        for(int i=0;i<cuboids.size();i++){
            int curh=cuboids[i][2];
            ans[i]=curh;
            for(int j=0;j<i;j++){
                if(cuboids[i][0]>=cuboids[j][0]&&cuboids[i][1]>=cuboids[j][1]
                &&cuboids[i][2]>=cuboids[j][2]){
                    ans[i]=max(ans[i],ans[j]+curh);
                }
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};
