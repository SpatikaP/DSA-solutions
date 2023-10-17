class Solution {
public:
    int MOD=1e9+7;
    int t[4001][1001];
    int solve(int start, int end, int k){
        if(k==0 && start==end) return 1;
        if(k==0) return 0;
        if(t[start+1000][k]!=-1) return t[start+1000][k];
        int res=solve(start+1,end,k-1);
        res=(res+solve(start-1,end,k-1))%MOD;
        return t[start+1000][k]=res;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(t,-1,sizeof(t));
        return solve(startPos,endPos,k);
    }
};