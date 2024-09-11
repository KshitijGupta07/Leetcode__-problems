class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count =0;
        while(start>0&&goal>0){
            
            cout<<(start&1)<<" "<<(goal&1)<<endl;
            if((start&1)!=(goal&1)){
                count++;
            }
            start=start>>1;
            goal=goal>>1;
        }
        
       cout<<count<<endl;
        while(start>0){
            if(start&1){
                count++;
            }
            start=start>>1;
        }
        while(goal>0){
            if(goal&1){
                count++;
            }
            goal=goal>>1;
        }
        return count;
    }
};