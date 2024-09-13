class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left;
        left.push_back(height[0]);
        int mini=height[0];
        for(int i=1;i<height.size();i++){
           mini=max(mini,height[i]); 
           left.push_back(mini);
        }
        vector<int>right;
        right.push_back(height[height.size()-1]);
        mini=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            mini=max(mini,height[i]);
            right.push_back(mini);
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<height.size();i++){
            int h=min(left[i],right[i]);
             int water=h-height[i];
             ans+=water;
        }
        return ans;
    }
};