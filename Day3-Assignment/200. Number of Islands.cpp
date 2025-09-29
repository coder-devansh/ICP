class Solution {
public:
int rows[4]={-1,0,1,0};
int cols[4]={0,-1,0,1};
void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<4;i++){
        int new_row=row+rows[i];
        int new_col=col+cols[i];
        if(new_row>=0 && new_col>=0 && new_row<n && new_col<m && !vis[new_row][new_col] && grid[new_row][new_col]=='1'){
            dfs(new_row,new_col,grid,vis);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]=='1' && !vis[i][j]){
                count++;
                dfs(i,j,grid,vis);
            }


            }
            
        }
        return count;


        
    }
};