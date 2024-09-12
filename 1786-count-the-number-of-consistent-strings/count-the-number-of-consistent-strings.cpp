class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask1=0;
        int mask2=0;

        for(auto j:allowed){
            mask1=(mask1|(1<<(j-'a')));
        }
        int a=mask1;
        int count=0;

        for(int i=0;i<words.size();i++){
             for(auto j:words[i]){
                mask2=(mask2|(1<<(j-'a')));
             }
             bool signal=false;
             while(mask1>0&&mask2>0){
                if((mask2&1)-(mask1&1)==1){
                    signal=true;
                    break;
                }
                mask2=mask2>>1;
                mask1=mask1>>1;
             }
             
             if(signal==false&&mask2==0){
                count++;
             }
             mask2=0;
             mask1=a;
        }
        return count;
    }
};