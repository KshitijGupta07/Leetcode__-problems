class Solution {
public:
int distance(vector<int>& p1,vector<int>& p2){
    return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    
    
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int>ans;
        ans.push_back(distance(p1,p2));
        ans.push_back(distance(p1,p3));
        ans.push_back(distance(p1,p4));
        ans.push_back(distance(p2,p3));
        ans.push_back(distance(p2,p4));
        ans.push_back(distance(p3,p4));
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
         if(ans[ans.size()-1]==0){
            return false;
        }
        if(ans[0]==ans[1]&&ans[1]==ans[2]&&ans[2]==ans[3]&&ans[3]==ans[0]&&&ans[0]!=0&&ans[ans.size()-1]==2*ans[0]){
            return true;
        }
       


        return false;

    }
};