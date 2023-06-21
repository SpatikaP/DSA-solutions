class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int s=0,m=0;
        for(int i=0; i<gain.size(); i++){
            
            s+=gain[i];
            m=max(m,s);

        }
        return m;
    }
};