class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        func(n,0,0,ans,s);
        return ans;
    }
    void func(int n, int open, int close, vector<string> &ans, string s){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
        if(open<n) func(n,open+1,close,ans,s+"(");
        if(close<open) func(n,open,close+1,ans,s+")");
    }
};