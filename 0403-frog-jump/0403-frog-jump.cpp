class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int t[2001][2001];
    bool solve(vector<int> stones, int curr_stone_idx, int prev_jump){
        if(curr_stone_idx==n-1) return true;
        if(t[curr_stone_idx][prev_jump]!=-1) return t[curr_stone_idx][prev_jump];
        bool res=false;
        for(int next_jump=prev_jump-1; next_jump<=prev_jump+1; next_jump++){
            if(next_jump>0){
                int next_stone = stones[curr_stone_idx] + next_jump;
                if(mp.find(next_stone)!=mp.end()){
                    res = res || solve(stones,mp[next_stone],next_jump); 
                }
            }
        }
        return t[curr_stone_idx][prev_jump]=res;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        memset(t,-1,sizeof(t));
        if(stones[1]!=1) return false;
        for(int i=0; i<n; i++){
            mp[stones[i]]=i;
        }
        return solve(stones,mp[0],0);
    }
};