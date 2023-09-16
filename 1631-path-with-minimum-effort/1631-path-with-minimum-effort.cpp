class Solution {
public:
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,1,-1};
    bool isValid(int row, int col,int ROW,int COL)
    {
     // If cell lies out of bounds
     if (row < 0 || col < 0 || row >= ROW || col >= COL)
         return false;
     else
         return true;
    }
    
    int minimumEffortPath(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> eff(m,vector<int>(n,INT_MAX)); 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}}); //{maxEff,{row,col}}
        eff[0][0] = 0;
        
        while(!pq.empty())
        {
            int cEff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r == m - 1 && c == n - 1) return cEff;
          
            for(int k=0;k<4;k++)
            {
                int nr = r+dr[k];
                int nc = c+dc[k];
                
                if(!isValid(nr,nc,m,n)) continue;
                
                int cost = abs(grid[nr][nc] - grid[r][c]); // difference b/w two grid cells
                int new_cEff = max(cEff,cost); // A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
                 
                 if(new_cEff < eff[nr][nc]){
                    eff[nr][nc] = new_cEff;
                    pq.push({new_cEff,{nr,nc}});
                 }
            }
        }
        return 0;
    }
};