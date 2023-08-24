class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq;
        queue<int> rq;
        int n=senate.size();
        for(int i=0; i<senate.size(); i++){
            if(senate[i]=='D') dq.push(i);
            else rq.push(i);
        }
        while(!rq.empty() && !dq.empty()){
            int ri=rq.front();
            int di=dq.front();
            rq.pop();
            dq.pop();
            if(ri<di){
                rq.push(ri+n);
            }
            else{
                dq.push(di+n);
            }
        }
        return rq.size()>dq.size() ? "Radiant" : "Dire";
    }
};