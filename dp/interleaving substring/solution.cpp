class Solution {
public:
    unordered_map<string,bool>mp;
    bool dfs(string &s1,string &s2,string &s3,int len1,int len2,int len3,int p1,int p2,int p3){
        if(p3==len3)return p1==len1&&p2==len2;
        if(mp.count(to_string(p1)+"|"+to_string(p2)+"|"+to_string(p3)))return mp[to_string(p1)+"|"+to_string(p2)+"|"+to_string(p3)];
        bool ans=false;
        if(p1==len1){
            if(s2[p2]!=s3[p3])ans=false;
            else ans|=dfs(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
        }
        if(p2==len2){
            if(s1[p1]!=s3[p3])ans=false;
            else ans|=dfs(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
        }
        // bool first=false,second=false;
        if(s1[p1]==s3[p3])ans|=dfs(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3])ans|=dfs(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
        return mp[to_string(p1)+"|"+to_string(p2)+"|"+to_string(p3)]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        if(len1+len2!=len3)return false;
        return dfs(s1,s2,s3,len1,len2,len3,0,0,0);
    }
};
