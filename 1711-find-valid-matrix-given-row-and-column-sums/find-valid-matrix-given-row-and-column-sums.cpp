class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>ans;
        for(int i=0;i<rowSum.size();i++){
            vector<int>temp;
            for(int j=0;j<colSum.size();j++){
                if(colSum[j]>rowSum[i]){
                    temp.push_back(rowSum[i]);
                    
                    colSum[j]=colSum[j]-rowSum[i];
                    rowSum[i]=0;
                }
                else{
                    temp.push_back(colSum[j]);
                        rowSum[i]-=colSum[j];
                        colSum[j]=0;
                    }
                }
                 ans.push_back(temp);
            temp.clear();
            }
           
        
        return ans;
    }
};