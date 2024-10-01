class Solution {
public:
int found(long long k){
    for(int i=0;i<100;i++){
        long long element=pow(2,i+1);
        if(element>k){
            return i;
        }
        if(element==k){
          return i+1;
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
      cout<<index<<endl;
      long long  a=k-pow(2,index);
      
      if(operations[index]==1){
      int l=(solve(a,operations)+1)-'a';
      l=l%26;
      return 'a'+l;
       
      }

        int l=( solve(a,operations))-'a';
        l=l%26;
        return 'a'+l;
      
      

  }
    char kthCharacter(long long k, vector<int>& operations) {
        char ans=solve(k-1,operations);
        return ans;
    }
};