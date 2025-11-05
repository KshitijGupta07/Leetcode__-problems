class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         map<int,int>m;
         int l=0;
         int r=0;
         int ans=0;
         while(r<fruits.size()){
             m[fruits[r]]++;
             while(m.size()>2){
                m[fruits[l]]-=1;
                if(m[fruits[l]]==0){
                    m.erase(fruits[l]);
                }
                l++;
             }
             ans=max(ans,r-l+1);
             r++;

         }
         return ans;
    }
};