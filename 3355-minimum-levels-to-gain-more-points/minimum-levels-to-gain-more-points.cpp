class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum=0;
        int a=0;
        int b=0;
        for(int i=0;i<possible.size();i++){
            if(possible[i]==1){
                sum++;
            }
            else{
                sum--;
            }
        }
        int count=1;
        for(int i=0;i<possible.size()-1;i++){
            if(possible[i]==0){
                a=a-1;
            }
            else{
                a=a+1;
            }
            
            if(a>sum-a){
                return count;
            }
            
            else{
                count++;
            }
        }
        
        if(a==sum){
            return -1;
        }
        return -1;
    }
};