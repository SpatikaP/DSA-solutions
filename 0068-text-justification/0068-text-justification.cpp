class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> list;
    while(i<words.size()){
        int wc=words[i].size();
        int j=i+1;

        int can=0;
        while(j<words.size() && wc+can+words[j].size()+1 <= maxWidth){
            wc+=words[j].size();
            can++;
            j++;
        }
        int vac=maxWidth-wc;
        

        int atleast = can==0 ? 0 : (vac/can);
        int extra = can==0 ? 0 : (vac%can);

        if(j==words.size()){
            atleast=1;
            extra=0;
        }
        string sb;
        for(int k=i;k<j;k++){
            sb.append(words[k]);
            if(k==j-1) break;
            for(int p=0; p<atleast; p++){
                sb.append(" ");
            }
            if(extra>0){
                sb+=" ";
                extra--;
            }
        }
        while(sb.size() < maxWidth) sb.append(" ");
        list.push_back(sb);
        i=j;  
    }
    return list;
    }
};