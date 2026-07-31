class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
    int count_initial= 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size();j++){
            if(grid[i][j]==1) count_initial++;
        }
    }  
    vector<vector<int>> newgrid = grid;
    solve(newgrid);
    int count_final=0;
    for(int i = 0; i<newgrid.size(); i++){
        for(int j = 0; j<newgrid[0].size();j++){
            if(newgrid[i][j]==1) count_final++;
        }
    }  
    return count_initial-count_final;
}




bool valid(int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
void dfs(vector<vector<int>> &grid, int n, int m, int i, int j)
{
    grid[i][j] = 2;
    for (int k = 0; k < 4; k++)
    {
        int row = i + x[k];
        int col = j + y[k];
        if (valid(row, col, n, m) && grid[row][col] == 1)
        {
            dfs(grid, n, m, row, col);
        }
    }
    return;
}

void solve(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();
    int i, j;

    for (j = 0; j < m; j++)
    {
        if (board[0][j] == 1)
        {
            dfs(board, n, m, 0, j);
        }
        if (board[n - 1][j] == 1)
        {
            dfs(board, n, m, n - 1, j);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (board[i][0] == 1)
        {
            dfs(board, n, m, i, 0);
        }
        if (board[i][m - 1] == 1)
        {
            dfs(board, n, m, i, m - 1);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (board[i][j] == 2)
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }
    return;
}
};