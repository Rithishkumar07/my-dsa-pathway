class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0])return true;
        if(a[0]==b[0]){
            if(a[1]>b[1])return true;//width greater means more envelopes;)
            return false;
        }
        return false;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int>ans;
        for(int i=0;i<envelopes.size();i++){
            int element=envelopes[i][1];
            int ind=lower_bound(ans.begin(),ans.end(),element)-ans.begin();
            if(ind>=ans.size())ans.push_back(element);
            else ans[ind]=element;
        }
        return ans.size();
    }
};
