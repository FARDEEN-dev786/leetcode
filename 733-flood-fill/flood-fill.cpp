class Solution {
public:
    bool valid(int i, int j, int n, int m){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
void dfs(vector<vector<int>>&a,int n, int m,int i,int j,vector<vector<bool>>&vis, int color,int startpix){
    vis[i][j] = 1;
    for(int k =0;k<4;k++){
        int row = i +x[k];
        int col = j+y[k];
        if(valid(row,col,n,m) && a[row][col]==startpix && vis[row][col]==0){
            dfs(a,n,m,row,col,vis,color,startpix);
        }
    }
    a[i][j]=color;
    return;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int n = image.size();
    int m = image[0].size();
    int i,j;
    vector<vector<bool>>vis(n);
    for(i = 0;i<n; i++){
        vector<bool>t(m,0);
        vis[i] = t;
    }
    int starpix = image[sr][sc];
    dfs(image,n,m,sr,sc,vis,color,starpix);
    return image;
}
};