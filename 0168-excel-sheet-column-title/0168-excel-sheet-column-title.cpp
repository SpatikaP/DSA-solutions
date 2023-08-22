class Solution {
public:
    string convertToTitle(int n) {
        int x=0; string s="";
        while(n>0){
            int x='A'+(n-1)%26;
            s=char(x)+s;
            n=(n-1)/26;
        }
        return s;
    }
};