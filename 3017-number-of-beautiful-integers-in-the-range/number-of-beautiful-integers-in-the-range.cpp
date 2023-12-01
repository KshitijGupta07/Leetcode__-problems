class Solution {
public:
bool check(int a){
   int c=0;
   int d=0;
   while(a!=0){
       
       if((a%10)%2==0){
           c++;
       }
       else{
           d++;
       }
       a=a/10;
   }
   if(c==d){
       return true;
   }
   return false;

}

    int numberOfBeautifulIntegers(int low, int high, int k) {
        int count=0;
        if(high<pow(10,8)){
        for(int i=low;i<=high;i++){
            if(i%k==0&&check(i)==1){
                count++;
            }
            
        }
        }
        
        if(high>=pow(10,8)){
            for(int i=low;i<=pow(10,8);i++){
                if(i%k==0&&check(i)==1){
                    count++;
                }
            }
        }
    
        return count;
    }
};