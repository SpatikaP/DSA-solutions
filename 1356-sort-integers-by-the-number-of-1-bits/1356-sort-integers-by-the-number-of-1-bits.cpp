class Solution {
public:
    int countBits(int x){
        int cnt=0;
        while(x){
            cnt+=x&1;
            x>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&](int &a, int &b)
        {
            int cA = countBits(a);
            int cB = countBits(b);
            if(cA==cB) return a<b;
            return cA<cB;
        };
        
        sort(begin(arr),end(arr),lambda);
        return arr;
    }
};