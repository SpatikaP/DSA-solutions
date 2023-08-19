class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;
        for(int i=0; i<as.size(); i++){
            //positive
            if(as[i]>0 || st.empty()) st.push(as[i]);
            //negative
            else{
                //collision
                while(!st.empty() && st.top()>0 && st.top()<abs(as[i])) st.pop();
                //equal and opposite
                if(!st.empty() && st.top()>0 && st.top()==abs(as[i])) st.pop();
                else{
                    if(st.empty() || st.top()<0){
                        st.push(as[i]);
                    }
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};