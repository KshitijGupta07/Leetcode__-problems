class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int ans=0;
        int prev=0;
        int next=0;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                prev=next;
                next=i+1;
                if(next-prev+1-k>0){
                    ans+=next-prev-k+1;
                }
            }
        }
        prev=next;
        next=colors.size();
        if(ans==0){
            if(next==0&&prev==0){
                return colors.size()-k+1;
            }
        }
          if(next-prev-k+1>0){
        return ans+next-prev-k+1;
          }
          return ans;

    }
};