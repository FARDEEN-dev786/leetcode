class Solution {
public:
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<bool>path(graph.size());
    vector<int>ans;
    for(int i = 0;i<graph.size();i++){
        vector<bool>vis(graph.size(),0);
        bool cycle= false;
        dfs(graph,i,path,vis,cycle);
        if(cycle==false){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
void dfs(vector<vector<int>>&a,int node, vector<bool>&path,vector<bool>&vis,bool&cycle){
    if(cycle) return;
    vis[node]=1;
    path[node]=1;
    for(int j =0; j<a[node].size(); j++){
        int neigh = a[node][j];
        if(vis[neigh]==1&& path[neigh]==1) {
            cycle=1;
            return;
        }

        if(vis[neigh]==0){
            dfs(a,neigh,path,vis,cycle);
        }
    }
    path[node]=0;
    return;
}
};