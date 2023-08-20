class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int count=0;
        for(int i=0; i<k; i++){
            if(isVowel(s[i])) count++;
        }
        int maxCount=count;
        int start=0; int end=k; 
        while(end<s.size()){
            if(isVowel(s[start++])) count--;
            if(isVowel(s[end++])) count++;
            maxCount=max(count,maxCount);
        }
        return maxCount;
    }
};