class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;
        vector<vector<int>> ans(grid);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i-1>=0 && j-1>=0){
                    ans[i][j]+=min(ans[i-1][j],ans[i][j-1]);
                }
                else{
                    if(j-1>=0) ans[i][j]+=ans[i][j-1];
                    if(i-1>=0) ans[i][j]+=ans[i-1][j];
                } 
            }
        }
        return ans[m-1][n-1];
    }
};