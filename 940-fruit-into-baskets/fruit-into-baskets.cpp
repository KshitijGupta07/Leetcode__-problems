class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    
        int r=0;
        int l=0;
        int maxlength=0;
       unordered_map<int,int>m;
       
        while(r<fruits.size()){
            cout<<l<<" "<<r<<" "<<m.size()<<endl;
           m[fruits[r]]++;
           
           if(m.size()>2){
            while(m.size()>2){
                
                m[fruits[l]]--;
            
                if(m[fruits[l]]==0){
                    m.erase(fruits[l]);
                    
                }
                l++;
            }
            
           }
           else{
           maxlength=max(maxlength,r-l+1);
           }
        
         r++;
        }
        return maxlength;
    }
};