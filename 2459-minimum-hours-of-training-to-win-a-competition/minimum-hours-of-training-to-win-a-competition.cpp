class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum=0;
        int a=0;
        int max=0;
        bool s=0;
        for(int i=0;i<experience.size();i++){
           if(initialExperience<=experience[i]){
               s=1;
               a=experience[i]-initialExperience+1;
               if(a>max){
                   max=a;
               }
               

               
           }
           
           sum+=energy[i];
           initialExperience+=experience[i];
        }
        
        if(initialEnergy>sum&&s==0){
        return 0;
              
            
        }
        if(initialEnergy>sum&&s==1){
            return max;
            
        }
        if(initialEnergy<=sum&&s==0){
             
            return sum-initialEnergy+1;
        }
        
        
        

      return sum-initialEnergy+1+max;
    }
};