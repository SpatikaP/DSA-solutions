class Solution {
public:
    long long t[4001][1001];
    int MOD=1e9+7;
    long long solve(int start, int end, int k){
        
        if(k==0 && start==end) return 1;
        if(k==0) return 0;
        
        if(t[start+1000][k]!=-1) return t[start+1000][k];
        
        long long res=solve(start+1,end,k-1);
        res=(res+solve(start-1,end,k-1));
        
        return t[start+1000][k]=res%MOD;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        for(int i=0; i<=3000; i++){
            for(int j=0; j<=k; j++){
                t[i][j]=-1;
            }
        }
        long long ans = solve(startPos, endPos, k);
        return ans%MOD;
    }
};