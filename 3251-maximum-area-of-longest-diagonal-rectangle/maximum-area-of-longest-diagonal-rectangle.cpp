class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        
        int maxindex=0;
        vector<int>ans;
        for(int i=0;i<dimensions.size();i++){
            int element=(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            ans.push_back(element);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[maxindex]<=ans[i]){
                maxindex=i;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[maxindex]==ans[i]){
                if(dimensions[maxindex][0]*dimensions[maxindex][1]<=dimensions[i][0]*dimensions[i][1]){
                    return dimensions[i][0]*dimensions[i][1];
                }
}
        }
        return dimensions[maxindex][0]*dimensions[maxindex][1];

        
        
    }
};