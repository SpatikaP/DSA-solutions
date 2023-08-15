class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int st=0;
        int end=s.size()-1;
        while(st<end){
            if(isVowel(s[st]) && isVowel(s[end])){
                swap(s[st],s[end]);
                st++;
                end--;
            }
            else if(!isVowel(s[st])){
                st++;
            }
            else{
                end--;
            } 
        }
        return s;
    }
};