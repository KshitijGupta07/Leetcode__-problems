class Solution {
public:
  int found(long long k){
    for(int i=0;i<100;i++){
        long long element=pow(2,i);
        if(element>k){
             return i-1;
        }
        else if(element==k){
            return i;
        }
        
    }
    return -1;
  }
  char solve(long long k,vector<int>&operations){
         if(k==1){
            if(operations[0]==1){
                return 'b';
            }
            else{
                return 'a';
            }
         }
         if(k==0){
            return 'a';
         }

        
        
         int index=found(k);
         cout<<index<<" ";
         long long pos=k-pow(2,index);
         if(operations[index]==1){
            int ans=solve(pos,operations)-'a'+1;
            ans=ans%26;
            return 'a'+(ans)%26;
         }
         int ans=solve(pos,operations)-'a';
         ans=ans%26;
         return 'a'+ans;


  }
    char kthCharacter(long long k, vector<int>& operations) {
    
        char ans=solve(k-1,operations);
             return ans;
    }
};