class Solution {
public:
    void solve(int start, int end, int k, int n, vector<int> &temp, vector<vector<int>> &ans){
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<=end; i++){
            temp.push_back(i);
            solve(i+1,end,k,n-i,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,9,k,n,temp,ans);
        return ans;
    }
};