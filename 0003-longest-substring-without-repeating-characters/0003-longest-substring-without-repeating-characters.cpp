class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> Set;
        int start=0, end=0;
        int len=0;
        
        while(end<s.size())
        {
            if(Set.find(s[end])==Set.end()){
                len=max(len,end-start+1);
                Set.insert(s[end++]);
            }
            else Set.erase(s[start++]);
        }
        return len;
    }
};