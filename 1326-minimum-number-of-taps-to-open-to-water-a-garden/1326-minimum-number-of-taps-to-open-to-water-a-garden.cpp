class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int minn=0, maxx=0, tap=0;
        while(maxx<n){
            for(int i=0; i<ranges.size(); i++){
                if(i-ranges[i]<=minn && maxx<i+ranges[i])
                    maxx=i+ranges[i];
            }
            if(minn==maxx) return -1;
            tap++;
            minn=maxx;
        }
        return tap;
    }
};