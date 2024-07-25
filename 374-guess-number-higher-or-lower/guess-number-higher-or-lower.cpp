/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 			      1 if num is lower than the picked number
               otherwise return 0
  int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans=1;
        int low=1;
        int high=n;
        while(guess(ans)!=0){
        ans=(low)+(high-low)/2;
         if(guess(ans)==-1){
            high=ans-1;
         }
         else if(guess(ans)==1){
            low=ans+1;
         }
        }
        return ans;
    }
};