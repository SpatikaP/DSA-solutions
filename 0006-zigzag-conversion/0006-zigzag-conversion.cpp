class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1) return s;
        
        string zigzag=""; //stores the answer
        
        vector<string> ans(numRows); //stores the string values of the respective rows
        
        bool flag = false;
        
        int i=0; //to keep the count of the row
        for(int j=0; j<s.size(); j++){
            
            if(i==0 || i==numRows-1) flag=!flag;
            
            ans[i]+=s[j];
            
            if(flag) //downward direction
            {
                i++;
            } 
            else //upward direction
            {
                i--;
            } 
        }
        // add the strings of all the rows.
        for(int i=0; i<ans.size(); i++){
            zigzag+=ans[i];
        }
        return zigzag;
    }
};