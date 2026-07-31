class Solution {
public:
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> revgraph(graph.size());
    vector<int>indegree(n,0);
    for (int i = 0; i < graph.size(); i++)
    {
        indegree[i] = graph[i].size();
        for (int j = 0; j < graph[i].size(); j++)
        {
            revgraph[graph[i][j]].push_back(i);
            
        }
    }
    vector<int> ans = topoSort(n,revgraph,indegree);
    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> topoSort(int V, vector<vector<int>>& edges,vector<int>&indegree) {
        // code here
    int i;
    queue<int> q;
    for(i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> result;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for(int j=0;j<edges[node].size();j++)
        {
            int neigh = edges[node][j];
            indegree[neigh]--;
            if(indegree[neigh]==0)
            {
                q.push(neigh);
            }
        }
    }
    return result;
}
};