class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size=0;
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                size*=s[i]-'0';
            }
            else{
                size+=1;
            }
        }
        for(int i=s.size()-1; i>=0; i--){
            k=k%size;
            if(isalpha(s[i]) && k==0){
                return string(1,s[i]);
            }
            if(isalpha(s[i])){
                size-=1;
            }
            else{
                size=size/(s[i]-'0');
            }
        }
        return "";
    }
};