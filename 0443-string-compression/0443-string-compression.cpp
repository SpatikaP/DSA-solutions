class Solution {
public:
    int compress(vector<char>& chars) {
        int c=1;
        string ans;
        for(int i=1; i<=chars.size(); i++){
            if(i<chars.size() && chars[i]==chars[i-1]){
                c++;
            }
            else{
                if(c==1) ans.push_back(chars[i-1]);
                else{
                    ans.push_back(chars[i-1]);
                    string str = to_string(c);
                    for(auto x:str){
                        ans.push_back(char(x));
                    }
                    c=1;
                }
            }   
        }
        for(int i=0; i<ans.size(); i++){
            chars[i]=ans[i];
        }
        return ans.size();
    }
};