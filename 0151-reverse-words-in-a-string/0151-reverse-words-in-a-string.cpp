class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string word;
        vector<string> temp;
        string ans="";
        while(str>>word){
            temp.push_back(word);
        }
        for(int i=temp.size()-1; i>=1; i--){
            ans+=temp[i]+" ";
        }
        ans+=temp[0];
        return ans;
    }
};