class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {  
      int rowIdx=potentialRow(matrix,target);
      if(rowIdx!=-1) return searchIdx(matrix,target,rowIdx);
      return false;
    }
    int potentialRow(vector<vector<int>>& matrix, int target){
        int low=0, high=matrix.size()-1;
        int idx=matrix[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][idx]) 
            return mid;
            else if(matrix[mid][0]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    bool searchIdx(vector<vector<int>>& matrix, int target, int rowIdx){
        int low=0, high=matrix[rowIdx].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target==matrix[rowIdx][mid]) return true;
            else if(matrix[rowIdx][mid]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};