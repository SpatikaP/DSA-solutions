class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_seen(26);
        vector<bool> taken(26,false);
        string result="";
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            last_seen[ch-'a']=i;
        }
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(taken[ch-'a']==true) continue;
            
            while(result.size()>0 && result.back()>ch && last_seen[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            
            result.push_back(ch);
            taken[ch-'a']=true;
        }
        return result;
    }
};