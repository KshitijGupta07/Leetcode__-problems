class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>m;
        map<string,bool>visited;
        if(s.length()<=10){
            return {};
        }
        vector<string>ans;
        int l=0;
        int r=9;
        while(r<s.length()&&l<=r){
            string a="";
            for(int i=l;i<=r;i++){
                a.push_back(s[i]);
            }
            if(m[a]>0&&visited[a]==false){
                ans.push_back(a);
                visited[a]=true;
            }
            m[a]++;
            l++;
            r++;
        }
        return ans;
    }
};