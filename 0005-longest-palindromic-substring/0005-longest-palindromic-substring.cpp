class Solution {
public:
    int t[1001][1001];
    bool solve(string &s, int i, int j){
        if(t[i][j]!=-1) return t[i][j];
        if(i>=j) return 1;
        else if(s[i]==s[j]) return t[i][j]=solve(s,i+1,j-1);
        else return 0;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int max_len=INT_MIN, sp = 0;
        memset(t,-1,sizeof(t));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,max_len);
    }
};