class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       
        int l=0;
        int r=0;
        map<int,int>m;
        int ans=0;
        while(r<fruits.size()){
              m[fruits[r]]+=1;
              if(m.size()==2){
                ans=max(ans,r-l+1);
              }
              while(m.size()>2){
                 m[fruits[l]]-=1;
                 if(m[fruits[l]]==0){
                     m.erase(fruits[l]);
                 }
                 l++;
              }
              r++;
        }
        if(ans==0){
            return fruits.size();
        }
        return ans;
    }
};