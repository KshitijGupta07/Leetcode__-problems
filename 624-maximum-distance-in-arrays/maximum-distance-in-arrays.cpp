class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<arrays.size();i++){
            mini=min(mini,arrays[i][0]);
            int element=arrays[i].back();
            maxi=max(maxi,element);
        }
        int secondmini=INT_MAX;
        int secondmaxi=INT_MIN;
        int index=-1;
        for(int i=0;i<arrays.size();i++){
            int element=arrays[i].back();
            if(maxi==element&&mini==arrays[i][0]){
                index=i;
                break;
            }
        }

        if(index==-1){
            return maxi-mini;
        }
        for(int i=0;i<arrays.size();i++){
            if(i!=index){
                int element=arrays[i].back();
                secondmini=min(secondmini,arrays[i][0]);
                secondmaxi=max(secondmaxi,element);
            }
        }
        cout<<secondmaxi-mini<<endl;
        return max(maxi-secondmini,secondmaxi-mini);

    }
};