class Solution {
public:
    string decodeString(string s) {
        stack<string> sString;
        stack<int> sNum;
        string res;
        int n=0;
        
        for(int i=0; i<s.size(); i++){
            if (isdigit(s[i])) {
                    n=n*10+s[i]-'0';
            }
            else if (isalpha(s[i])) {
                res.push_back(s[i]);
            }
            else if(s[i]=='['){
                sString.push(res);
                sNum.push(n);
                
                res="";
                n=0;
            }

            else if(s[i]==']'){
                string temp=res;
                for(int i=0; i<sNum.top()-1; ++i){
                    res+=temp;
                }
                res=sString.top()+res;
                sString.pop();
                sNum.pop();
            }
        }
        return res;
    }
};