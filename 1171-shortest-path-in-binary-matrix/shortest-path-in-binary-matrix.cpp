class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid[0][0] == 1)
        return -1;
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});

    vis[0][0] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();

        if (p.first.first == n - 1 && p.first.second == n - 1)
            return p.second;

        int row = p.first.first;
        int col = p.first.second;
        int dist = p.second;
        for (int k = 0; k < 8; k++)
        {

            int nr = row + dx[k];
            int nc = col + dy[k];
            if (valid(nr, nc, n, n) &&
                vis[nr][nc] == false &&
                grid[nr][nc] == 0)
            {
                vis[nr][nc] = true;

                q.push({{nr, nc}, dist + 1});
            }
        }
    }

    return -1;
}
};