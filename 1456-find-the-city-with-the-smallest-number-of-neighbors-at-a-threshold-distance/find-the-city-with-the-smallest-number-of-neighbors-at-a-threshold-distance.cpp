class Solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]);
            }
        }
    }
    int answer = 0;
    int smallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] <= distanceThreshold)
            {
                count++;
            }
        }

        if (count <= smallest)
        {
            smallest = count;
            answer = i;
        }
    }
    return answer;
}
};