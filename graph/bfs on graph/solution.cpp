class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0),ans;
        visited.at(0)=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
            for(auto i:adj[a]){
                if(!visited.at(i)){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        return ans;
    }
};
