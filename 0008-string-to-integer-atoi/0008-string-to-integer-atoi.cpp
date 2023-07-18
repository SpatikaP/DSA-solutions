class Solution {
public:
    int myAtoi(string s) {
        int MIN=INT_MIN;
        int MAX=INT_MAX;
        
        // 1.Read in and ignore any leading whitespace.
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        } 
        
        s=s.substr(i);
        
        // 2.Check if the next character is '-' or '+'. 
        int sign = +1;
        if(s[0]=='-') sign= -1;
        
        long ans=0;
        
        i = (s[0]=='-' || s[0]=='+') ? 1:0;
        
        while(i<s.size()){
            //3.
            if(s[0]==' ' || !isdigit(s[i])) break;
            ans = ans*10 + s[i]-'0';
            //4.
            if((sign==-1) && -1*ans < MIN) return MIN;
            if(sign==1 && ans > MAX) return MAX;
            i++;
        }
        return (int)(sign*ans);
    }
};