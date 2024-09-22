class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        int c=1;
        
        for(int i=0;i<n;i++){
             ans.push_back(c);
             if(c*10<=n){
                c=c*10;
            
             }
             else {
                while(c%10==9||c>=n){
                    c=c/10;
                }
                c=c+1;
             }
        }
        return ans;
    }
};