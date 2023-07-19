class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         // sort the array 
         sort(intervals.begin(),intervals.end());
        // two pointers for keeping track of two consecutive non-overlapping intervals (left,right)
        int left=0, right=1;
        // store the answer
        int count = 0;
        
        while(right<intervals.size()){
            // case: 1 -> When two intervals are non overlapping. Ex: [[1,3],[4,5]]
            if(intervals[left][1] <= intervals[right][0]) {
                left=right;
                right++;
            }
            // case: 2 -> When one interval overlaps another interval (not entirely, only from one side) Ex: [[1,3],[2,5]]
            else if(intervals[left][1] <= intervals[right][1]){
                count++;
                right++;
            }
            // case 3: -> When one interval entirely overlaps another interval(s). Ex: [[1,5],[2,5]]
            else if(intervals[left][1] > intervals[right][1]){
                count++;
                left=right;
                right++;
            }
        }        
        return count;
    }
};