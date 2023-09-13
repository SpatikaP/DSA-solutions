class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n,1);

        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
        }

        int right=1;
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                right++;
                left[i]=max(left[i],right);
            }
            else{
                right=1;
            }
        }
        
        int total_candies=0;
        
         for(int x:left){
            total_candies+=x;
         }
        return total_candies;
    }
};