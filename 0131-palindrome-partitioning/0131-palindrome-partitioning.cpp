class Solution {
public:
    bool isPalindrome(string s){
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string s, vector<string> &temp, vector<vector<string>> &ans){
        //base-case
        if(s.size()==0){
            ans.push_back(temp);
        }
        for(int i=0; i<s.size(); i++){
            string subs = s.substr(0,i+1);
            if(isPalindrome(subs)){
                temp.push_back(subs);
                solve(s.substr(i+1),temp,ans);
                temp.pop_back();
            }
        }
    }
        
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,temp,ans);
        return ans;
    }
};