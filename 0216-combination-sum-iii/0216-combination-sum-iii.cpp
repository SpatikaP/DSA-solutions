class Solution {
public:
    void solve(int start, int end, vector<vector<int>> &ans, vector<int> &temp, int k, int n){
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=start; i<=end; i++){
            temp.push_back(i);
            solve(i+1, end, ans, temp, k, n-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,9,ans,temp,k,n);
        return ans;
    }
};