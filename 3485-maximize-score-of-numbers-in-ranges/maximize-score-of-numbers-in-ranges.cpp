class Solution {
public:
  bool help(long long mid,vector<int>&start,int d){
     long long prev=start[0];
     for(int i=1;i<start.size();i++){
        long long element=start[i];
        long long diff=d;
        prev+=mid;
        if(prev>element+diff){
        return false;
        }
        else if(prev<=element){
             prev=element;
        }
     }
     return true;
  }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int n=start.size();
        long long st=0;
        long long end=start[n-1]+d;
       long long ans=0;
        while(st<=end){
            long long mid=(st+end)/2;
            if(help(mid,start,d)){
                st=mid+1;
               ans=mid;
            }
            else{
                end=mid-1;
            }
        }
        return ans;

    }
};