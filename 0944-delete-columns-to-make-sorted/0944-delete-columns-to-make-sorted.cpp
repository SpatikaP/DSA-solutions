class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int column = strs[0].size();
        int row = strs.size();
        int ans=0;
        for(int i=0; i<column; i++){
            for(int j=0; j<row-1; j++){
                if(strs[j][i]>strs[j+1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};