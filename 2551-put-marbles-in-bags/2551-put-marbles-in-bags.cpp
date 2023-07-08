class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long ma=0, mi =0, n=weights.size();
        vector<int> pairs(n-1);
        for(int i=1; i<n; i++){
            pairs[i-1]=weights[i]+weights[i-1];
        }
        sort(pairs.begin(), pairs.end());
        for(int i=0; i<k-1; i++){
            mi+=pairs[i];
            ma+=pairs[n-i-2];
        }
        return ma-mi;
    }
};