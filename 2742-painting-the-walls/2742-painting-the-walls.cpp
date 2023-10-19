class Solution {
public:
    int n;
    int t[501][501];
    int solve(vector<int>& cost, vector<int>& time, int idx, int remain){
        if(remain<=0) return 0;
        if(idx>=n) return 1e9;
        if(t[idx][remain]!=-1) return t[idx][remain];
        int paint=cost[idx] + solve(cost,time,idx+1,remain-1-time[idx]);
        int no_paint=solve(cost,time,idx+1,remain);
        return t[idx][remain]=min(paint,no_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=cost.size();
        memset(t,-1,sizeof(t));
        return solve(cost,time,0,n);
    }
};