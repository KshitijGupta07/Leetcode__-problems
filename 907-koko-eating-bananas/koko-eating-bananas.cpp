class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;;
        int end=INT_MIN;
        for(int i=0;i<piles.size();i++){
            
            end=max(end,piles[i]);
        }
        int ans=0;
        while(start<=end){
            int mid=(start+end)>>1;
        long long  sum=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0){
                     sum+=(long long)piles[i]/mid;
                }
                else{
                    sum+=piles[i]/mid +1;
                }
            }
            if(sum>h){
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;

    }
};