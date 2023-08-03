class Solution {
public:
    void solve(string digits,vector<string> &ans, string &temp, int index,vector<string> &pad){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        string value = pad[digits[index]-'0'];
        for(int i=0; i<value.size(); i++){
            temp.push_back(value[i]);
            solve(digits,ans,temp,index+1,pad);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return {};
        string temp;
        vector<string> pad= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,temp,0,pad);
        return ans;
    }
};