class Solution {
public:
    int compress(vector<char>& chars) {
        int j=0, count=1;
        if(chars.size()==1) return 1;
        for(int i=1; i<=chars.size(); i++){
            while(i<chars.size() && chars[i]==chars[i-1]){
                count++;
                i++;
            }
            chars[j++]=chars[i-1];
            if(count>1){
                string c = to_string(count);
                for(auto ch:c){
                    chars[j++] = char(ch);
                }
            }
            count=1;
        }
        return j;
    }
};