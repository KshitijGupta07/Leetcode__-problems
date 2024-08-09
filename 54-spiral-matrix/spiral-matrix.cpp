class Solution {
public:
  void solve(vector<int>&ans,int &rightcolumn,int &leftcolumn,int &toprow,int &bottomrow,vector<vector<int>>&matrix,bool &signal){
     
    if(rightcolumn<leftcolumn||toprow>bottomrow){
        return;
    }
   
    if(signal==false){
    for(int i=leftcolumn;i<=rightcolumn;i++){
        ans.push_back(matrix[toprow][i]);
    }
       toprow=toprow+1;
       for(int i=toprow;i<=bottomrow;i++){
        ans.push_back(matrix[i][rightcolumn]);
        
       }
       rightcolumn=rightcolumn-1;
       signal=true;
       solve(ans,rightcolumn,leftcolumn,toprow,bottomrow,matrix,signal);
    }
    else{
        for(int i=rightcolumn;i>=leftcolumn;i--){
            ans.push_back(matrix[bottomrow][i]);
        }
        bottomrow=bottomrow-1;
        for(int i=bottomrow;i>=toprow;i--){
            ans.push_back(matrix[i][leftcolumn]);
        }
        leftcolumn=leftcolumn+1;
        signal=false;
        solve(ans,rightcolumn,leftcolumn,toprow,bottomrow,matrix,signal);
    }

  }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rightcolumn=matrix[0].size()-1;
        int leftcolumn=0;
        int toprow=0;
        int bottomrow=matrix.size()-1;
        vector<int>ans;
        bool signal=false;
        solve(ans,rightcolumn,leftcolumn,toprow,bottomrow,matrix,signal);
        return ans;
        
       }
};