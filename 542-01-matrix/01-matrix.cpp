class Solution {
public:
    bool valid(int i, int j, int n, int m){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    queue<pair<int, int>> q;
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        int row = curr.first;
        int col = curr.second;

        for (int k = 0; k < 4; k++)
        {
            int nr = row + x[k];
            int nc = col + y[k];

            if (valid(nr, nc, n, m) && dist[nr][nc] == -1)
            {
                dist[nr][nc] = dist[row][col] + 1;
                q.push({nr, nc});
            }
        }
    }
    return dist;
}
};