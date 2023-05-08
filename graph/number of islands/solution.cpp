//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int row,int col,int s1,int s2){
        queue<pair<int,int>>q;
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            int newrow=q.front().first,newcol=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int r=newrow+i,c=newcol+j;
                    if(r>=0&&r<s1&&c>=0&&c<s2&&grid[r][c]=='1'&&!vis[r][c]){
                        vis[r][c]=1;
                        q.push({r,c});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0,s1=grid.size(),s2=grid.at(0).size();
        for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    dfs(grid,visited,i,j,s1,s2);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
