class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int,int>>>a(n);
    for(int i =0; i<edges.size();i++){
        int s = edges[i][0];
        int d = edges[i][1];
        int w = edges[i][2];
        a[s].push_back({d,w});
        a[d].push_back({s,w});
    }

    vector<int>ans(n,0);
    for(int i = 0; i<n;i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[i]=0;
        pq.push({0,i});
        while (!pq.empty())
        {
            pair<int,int>p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d>dist[node]) continue;
            for(int j = 0; j<a[node].size(); j++){
                int neigh = a[node][j].first;
                int wt = a[node][j].second;
                if(d+wt<dist[neigh]){
                    dist[neigh]=wt+d;
                    pq.push({d+wt,neigh});
                }
            }

        }
        int count= 0;
        for(int j = 0; j<n;j++){
            if(i==j) continue;
            if(dist[j]<=distanceThreshold) count++;
        }
        ans[i]=count;  
    }
    int answer=0;
    for(int i =1; i<n;i++){
        if(ans[i]<=ans[answer]) answer = i;
    }
    return answer;
}
};