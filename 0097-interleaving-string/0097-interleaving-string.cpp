class Solution {
public:
    int m,n,N;
    int t[101][101][201];
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k){
        if(i==m && j==n && k==N) return true;
        if(k>=N) return false;
        if(t[i][j][k]!=-1) return t[i][j][k];
        bool res=false;
        if(s1[i]==s3[k]) res=solve(s1,s2,s3,i+1,j,k+1);
        if(res==true) return true;
        if(s2[j]==s3[k]) res=solve(s1,s2,s3,i,j+1,k+1);
        return t[i][j][k]=res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        m=s1.size();
        n=s2.size();
        N=s3.size();
        memset(t,-1,sizeof(t));
        return solve(s1,s2,s3,0,0,0);
    }
};