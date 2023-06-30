class Solution {
public:
    int canCross(int row, int col,int day,vector<vector<int>>& cells){
        vector<vector<int>>grid(row, vector<int>(col,0));
        for (int i = 0; i<day; i++){
            //making water
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        for (int i = 0; i<col; i++){

            if (grid[0][i]==0 && DFS(grid,0,i,row,col)){
                return true;
            }
        }
        return false;
    }

    bool DFS(vector<vector<int>>&grid,int r, int c, int row,int col){
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]!=0){
            return false;
        }

        if (r==row-1) return true;

        grid[r][c] = 1;

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,-1,1};

        for (int i =0; i<4; i++){
           int newR = r + dr[i];
           int newC = c + dc[i];
           if (DFS(grid,newR,newC,row,col)){
               return true;
           }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

    int left  = 1;
    int right = row*col;   // size of grid

    while(left<right){
    	int mid = right - (right-left)/2;
    	if (canCross(row,col,mid,cells)){
            left = mid;
        }
        else{
            right = mid-1;
        }
    }
    return left;
        
    }
};