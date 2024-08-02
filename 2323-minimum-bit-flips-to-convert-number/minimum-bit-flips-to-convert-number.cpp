class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        while(start>0&&goal>0){
            cout<<start<<" "<<goal<<endl;
            if(start%2!=goal%2){
                count++;
            }
           start=start>>1;
           goal=goal>>1; 
        }
        cout<<count<<endl;
        while(goal>0){
            if(goal&1==1){
                count++;
            }
            goal=goal>>1;
        }
        while(start>0){
            if(start&1==1){
                count++;
            }
            start=start>>1;
        }
        return count;
    }
};