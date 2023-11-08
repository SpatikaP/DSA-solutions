class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int horizontal = abs(sy-fy);
        int vertical = abs(sx-fx);
        if(horizontal==0 && vertical==0 && t==1) return false;
        int min_time = max(horizontal,vertical);
        if(t<min_time) return false;
        return true;
    }
};