class Solution {
public:
   int length(int a){
       int count=0;
       while(a!=0){
           a=a/10;
           count++;
       }
       return count;
   }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>a(9);
        vector<int>ans;
        int b=1;
        
        for(int i=0,j=2;i<9,j<=9;i++,j++){
            a[i]=b*10+j;
            b=b*10+j;
            
        }
        
        for(int i=length(low);i<=length(high);i++){
            int element=a[i-2];
            int add=(10*(pow(10,i-1)-1))/9+1;
            while(element<=high&&element%10!=0){
                if(element>=low&&element<=high){
                    ans.push_back(element);
                }
               
               element+=add;
            }
        }

       return ans; 
    }
};