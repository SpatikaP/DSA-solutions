class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxConsecutive=0, n=answerKey.size();
        for(char ch:{'T','F'}){
            int l=0, r=0, cnt=0;
            while(r<n){
                if(answerKey[r++]!=ch) cnt++;
                while(cnt>k){
                    if(answerKey[l++]!=ch) cnt--;
                }
                maxConsecutive=max(maxConsecutive,r-l);
            }
        }
        return maxConsecutive;
    }
};