class Solution {
public:
    void solve(vector<int> &lps, string a){
        int i=0, j=1;
        while(j<a.size()){
            if(a[i]==a[j]){
                lps[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i==0) j++;
                else i=lps[i-1];
            }
        }
    }
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        string a=s+'#'+t;
        vector<int> lps(a.size(),0);
        solve(lps,a);
        
        int x=lps[a.size()-1];
        string temp=s.substr(x);
        
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};