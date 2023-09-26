class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> taken(26,false);
        vector<int> last_seen_idx(26);
        string result="";
        
        for(int i=0; i<s.size(); i++){
            
            char ch=s[i];
            last_seen_idx[ch-'a']=i;
            
        }
        
        for(int i=0; i<s.size(); i++){
            
            char ch=s[i];
            if(taken[ch-'a'] == true) continue;
            
            while(result.size()>0 && last_seen_idx[result.back()-'a']>i && result.back()>ch){
                taken[result.back() -'a']=false;
                result.pop_back();
            }
            
            result.push_back(ch);
            taken[ch -'a']=true;
        }
        
        return result;
    }
};
 