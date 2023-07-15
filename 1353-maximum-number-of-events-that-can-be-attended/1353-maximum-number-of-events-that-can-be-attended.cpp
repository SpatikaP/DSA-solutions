class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> q;
        sort(events.begin(), events.end());
        
        int ans = 0, day = 0, i = 0, n = events.size();
        while(q.size() > 0 || i < n) {
            // Start with the first events day
            if(q.size() == 0)
                day = events[i][0];
            
            // push all events on that day
            while(i < n && events[i][0] == day) {
                q.push(events[i++][1]);
            }
            
            //pop the earliest ending event and increment 
            // the day and result-count
            q.pop();
            day++, ans++;
            
            // remove all other events ending before the next day
            while(q.size() > 0 && q.top() < day) {
                q.pop();
            }
        }
        return ans;
    }
};