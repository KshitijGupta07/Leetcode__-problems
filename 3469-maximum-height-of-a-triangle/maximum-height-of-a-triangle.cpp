class Solution {
public:
   int check(int a,int b){
    int l=1;
    int count=0;
    int f=0;
    while(a>0||b>0){
        if(f==0){
            if(a>=l){
                a=a-l;
            }
            else{
                break;
            }
        }
        else{
            if(b>=l){
                b=b-l;
            }
            else{
                break;
            }
        }
        f=f^1;
        count++;
        l++;
    }
    return count;
   }
    int maxHeightOfTriangle(int red, int blue) {
        int a=check(red,blue);
        int b=check(blue,red);
        return max(a,b);
    }
};