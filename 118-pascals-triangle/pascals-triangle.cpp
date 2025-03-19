class Solution {
public:
    vector<int>solve(int numRows,vector<int>&temp){
       if(numRows==1){
           return {1};

       }
       vector<int>prev=temp;
       temp.clear();
       int a=numRows-2;
       temp.push_back(1);
       int i=0;
       while(a>0){
        temp.push_back(prev[i]+prev[i+1]);
        i++;
        a--;
       }
       temp.push_back(1);
       prev=temp;
       return prev;

       
       
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>temp;
        
         for(int i=1;i<=numRows;i++){
            temp=solve(i,temp);
            ans.push_back(temp);
         }
        return ans;
    }
};