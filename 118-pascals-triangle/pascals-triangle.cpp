class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1){
            return ans;
        }
        int count=2;
        
         vector<int>prev=temp;
         temp.clear();
         while(count<=numRows){
            temp.push_back(1);
            int a=count-2;
            int i=0;
            while(a>0){
               temp.push_back(prev[i]+prev[i+1]); 
               i++;
               a-=1;
            }
            temp.push_back(1);
            ans.push_back(temp);
            prev=temp;
            temp.clear();
            count+=1;
         }
         return ans;
    }
};