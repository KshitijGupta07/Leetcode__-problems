class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prev;
        int maxi=height[0];
        for(int i=0;i<height.size();i++){
            maxi=max(maxi,height[i]);
            prev.push_back(maxi);
        }
        maxi=height.back();
        vector<int>next;
        for(int i=height.size()-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            next.push_back(maxi);
        }
        reverse(next.begin(),next.end());
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans=ans+min(prev[i],next[i])-height[i];
        }
        return ans;
    }
};