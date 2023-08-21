class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        int l;
        for(int l=n/2; l>=1; l--){
            if(n%l==0){
                string pattern=s.substr(0,l);
                string new_str="";
                int times=n/l;
                while(times--){
                    new_str+=pattern;
                }
                if(new_str==s) return true;
            }
        }
        return false;
    }
};