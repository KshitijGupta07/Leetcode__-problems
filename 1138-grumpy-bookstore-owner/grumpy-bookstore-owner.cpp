class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int n=grumpy.size();
        for(int i=0;i<n;i++){
            sum+=customers[i]*(1^grumpy[i]);
        }
        int l=0;
        int r=0;
        int s=0;
        int maxi=0;
        while(r<grumpy.size()&&l<=grumpy.size()-minutes){
            while(r-l+1<=minutes&&r<grumpy.size()){
                
                s+=customers[r]-customers[r]*(1^grumpy[r]);
                r++;
            }
            maxi=max(maxi,s);
            s=0;
            l=l+1;
             r=l;
        }
        return (sum+maxi);
    }
};