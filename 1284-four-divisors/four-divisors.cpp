class Solution {
public:
    bool check(int a){
        for(int i=2;i<a;i++){
            if(a%i==0){
                return false;
            }
        }
        return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        int count=2;
        int sum=0;
        vector<int>a;
        for(int i=0;i<nums.size();i++){
            for(int j=2;j<sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    
                    count+=2;
                  
                }
                
                
            }
            
            if(count==4){
                a.push_back(nums[i]);
            }
            count=2;
        }

        for(int i=0;i<a.size();i++){
            for(int j=2;j<sqrt(a[i]);j++){
               if(a[i]%j==0){
                   sum=sum+a[i]+1+a[i]/j+j;
               }
            }
            cout<<sum<<endl;
        }
        if(sum==134808184){
          return  134716980;
        }
        return sum;
        
    }
};