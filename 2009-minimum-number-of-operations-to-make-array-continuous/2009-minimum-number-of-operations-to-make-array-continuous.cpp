class Solution {
public:
    int minOperations(vector<int>& A) {
        int N = A.size(), i = 0, j = 0, ans = 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A)); 
        for (int M = A.size(); j < M; ++j) {
            while (A[i] + N <= A[j]) ++i; 
            ans = max(ans, j - i + 1);
        }
        return N - ans;
    }
};