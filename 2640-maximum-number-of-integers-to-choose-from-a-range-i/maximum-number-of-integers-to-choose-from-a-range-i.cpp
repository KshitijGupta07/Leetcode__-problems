class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count=0;
        int totalsum=0;
        map<int,bool>m;
        for(int i=0;i<banned.size();i++){
            m[banned[i]]=true;
        }
        for(int i=1;i<=n;i++){
           if(maxSum-totalsum>=i&&m[i]==false){
             count++;
             totalsum+=i;
           }  
        }
        return count;
    }
};