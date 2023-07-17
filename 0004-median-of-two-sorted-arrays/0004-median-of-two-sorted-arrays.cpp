class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        
        int low=0;
        int high=m;
        int l1,l2,r1,r2;
        
        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=((m+n)/2)-cut1;
             l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
             l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
             r1 = cut1==m ? INT_MAX : nums1[cut1];
             r2 = cut2==n ? INT_MAX : nums2[cut2];
            
            if(l1>r2) high=cut1-1;
            else if(l2>r1) low=cut1+1;
            else break;
        }
        return (m+n)%2==0 ? double(max(l1,l2)+min(r1,r2))/2 : min(r1,r2);
    }
};
