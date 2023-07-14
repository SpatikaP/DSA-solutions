class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int e=height.size()-1;
        int s=0;
            while(s<e){
                
                int f = min(height[s],height[e])*(e-s);
                ans=max(ans,f);
                
                if(height[s]>height[e]) e--;
                else s++;
            }
        
        return ans;
    }
};