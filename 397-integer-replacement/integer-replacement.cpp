class Solution {
public:
    int integerReplacement(int n) {
        int count=0;
        long long a=n;
        while(a!=1){
            if(a%2==0){
                a=a>>1;
                count++;
            }
            else{
                if(((a+1)/2)%2==0&&((a-1)/2)%2==1){
                    if(((a-1)/2)==1){
                        a=a-1;
                        count=count+2;
                        break;
                    }
                    else{
                  a=a+1;
                  count++;
                    }
                  
                }
                else if(((a-1)/2)%2==0&&(((a+1)/2)%2)==1){
                    if(((a+1)/2)==1){
                        a=a+1;
                        count=count+2;
                        break;
                    }
                    else{
                    a=a-1;
                    count++;
                    }
                }
                else{
                    a=a-1;
                    count++;
                }
            }
        }
        return count;
    }
};