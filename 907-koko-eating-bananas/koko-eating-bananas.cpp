class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long  start=1;
        int maxi=-1;
        for(auto j:piles){
            maxi=max(maxi,j);
        }
        long long  end=maxi;
        long long  ans=pow(10,10);
        while(start<=end){
            long long  mid=(start+end)/2;
            int count=0;
            for(int i=0;i<piles.size();i++){
                long long element=piles[i];
                count+=(element/mid + min(element%mid,1LL));
            }
        
            if(count<=h&&count>0){
                cout<<count<<" "<<mid<<endl;
                if(mid>0){
                ans=min(ans,mid);
                }
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        cout<<ans<<endl;
        return ans;
    }
};