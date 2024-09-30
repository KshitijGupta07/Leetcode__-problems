class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>dir(s.length()+1,0);
        for(int i=0;i<shifts.size();i++){
            int a=shifts[i][0];
            int b=shifts[i][1];
            if(shifts[i][2]==1){
                 dir[a]++;
                 dir[b+1]--;
            }
            else{
                dir[a]--;
                dir[b+1]++;
            }
            
        }
        long long job=0;
        for(int i=0;i<s.length();i++){
            job+=dir[i];
            long long num=(s[i]-'a'+job+26000000)%26;
            s[i]='a'+num;
        }
        return s;
    }
};