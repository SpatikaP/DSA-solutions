class Solution {
public:
    bool check(int n, vector<int> v, long time){
        long summ=0;
        for(int i=0; i<v.size(); i++){
            summ+=min((long)v[i],time);
        }
        return summ>=(long)time*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long sum=0;
        for(auto e:batteries){
            sum+=e;
        }
        long low=1, high=sum/n;
        long ans=-1;
        while(low<=high){
            long mid = (low+high+1)/2;
            if(check(n,batteries,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};