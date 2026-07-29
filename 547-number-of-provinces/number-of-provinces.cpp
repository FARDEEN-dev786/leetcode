class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, vector<bool> &vis)
{
    vis[i] = true;
    for (int j = 0; j< adj.size();j++)
    {
        if (adj[i][j] ==1 && vis[j] == false)
        {
            dfs(adj, j, vis);
        }
    }
    return;
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int count = 0;
    int n = isConnected.size();
    vector<bool>vis(n,0);
    for(int i = 0;i<n;i++){
        if(vis[i]==0) {
            dfs(isConnected,i,vis);
            count +=1;
        }
    }
    return count;
}
};