class Solution {
public:
   long long binarysearch(int target,vector<long long>&digit){
    int start=0;
    int end=digit.size()-1;
    while(start<=end){
          int mid=start+(end-start)/2;
          if(digit[mid]==target){
            return mid;
          }
          else if(digit[mid]>target){
            end=mid-1;
          }
          else{
            start=mid+1;
          }
    }
    if(start==0){
        return 0;
    }
    if(digit[start]<target){
        return start+1;
    }
    return start;
   }
    int findNthDigit(int n) {
        vector<long long>digit;
        digit.push_back(9);
        int i=1;
        long long  element=9;
        while(element<INT_MAX){
            if(element<INT_MAX){
            element+=9*(i+1)*pow(10,i);
            digit.push_back(element);
            }
            i++;
        }
        if(n<10){
            return n;
        }
        
         long long start=binarysearch(n,digit);
         cout<<start<<endl;
         long long d=pow(10,start)-1;
         long long num=d+(n-digit[start-1])/(start+1);
         cout<<num<<endl;
         if((n-digit[start-1])%(start+1)!=0){
        
            num++;
         }
         else{
            return num%10;
         }
         int count=start+1;
         int b=(n-digit[start-1])%(start+1);
         cout<<b<<" ";
         while(count>b){
            num=num/10;
            count--;
          }
         
        return num%10;
    }
};