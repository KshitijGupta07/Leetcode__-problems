class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        long long sum=0;
        for(auto j:piles){
            maxi=max(maxi,j);
            long long element=j;
            sum+=element;
        }
        int start=1;
        int end=maxi;
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2 ;
            int count=0;
             for(int i=0;i<piles.size();i++){
                  count=count+piles[i]/mid+min(1,piles[i]%mid);
                  if(count>h){
                    break;
                  }
             }
             if(count>h){
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