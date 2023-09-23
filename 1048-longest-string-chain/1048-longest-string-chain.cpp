class Solution {
public:
    
    int t[1001][1001];
    static bool myCompare(string &w1, string &w2){
        return w1.length() < w2.length();
    }
    
    bool isPred(string &prev_str, string &curr_str){
        
        int c=curr_str.size();
        int p=prev_str.size();
        
        if(p>=c || c-p != 1) return false;
        
        int j=0, i=0;
        for(int i=0; i<curr_str.size(); i++){
            if(prev_str[j] == curr_str[i]) j++;
        }
        
        return j==prev_str.size();
        
    }
    
    int lis(vector<string> &words, int prev_idx, int curr_idx){
        
        if(curr_idx==words.size()) return 0;
        
        if(prev_idx!=-1 && t[prev_idx][curr_idx]!=-1) return t[prev_idx][curr_idx];
        
        int taken=0, not_taken=0;
        
        if(prev_idx==-1 || isPred(words[prev_idx],words[curr_idx])){
            taken = 1+lis(words,curr_idx, curr_idx+1);
        }
        
        not_taken = lis(words,prev_idx,curr_idx+1);
        
        if(prev_idx!=-1) t[prev_idx][curr_idx]=max(taken,not_taken);
        
        return max(taken,not_taken);
        
    }
    
    int longestStrChain(vector<string>& words) {
        
        memset(t,-1,sizeof(t));
        sort(words.begin(),words.end(),myCompare);
        return lis(words,-1,0);
        
    }
    
};