class Solution {
public:
int countsetbit(int num){
    int count=0;
    while(num>0){
       if(((num>>1)&1)==1){
        count++;
       }
       num=num>>1;
    }
    return count;
}
    int maxProduct(vector<string>& words) {
        map<string,int>m;
        int ans=INT_MIN;
        for(int i=0;i<words.size();i++){
            int mask=0;
            mask=mask<<31;
            for(int j=0;j<words[i].length();j++){
                mask=mask|1<<(words[i][j]-'a');
            }
        
        
            m[words[i]]=mask;
         
        }
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                   if((m[words[i]]&m[words[j]])==0){
                    int a=words[i].length();
                    int b=words[j].length();
                    ans=max(ans,a*b);
                   }
            }
        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};