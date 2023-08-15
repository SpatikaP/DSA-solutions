class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int j = getgcd(str1.size(),str2.size());
        return str1+str2==str2+str1 ? str1.substr(0,j) : "";
    }
    int getgcd(int a,int b){
        if(b==0) return a;
        return getgcd(b,a%b);
    }
};