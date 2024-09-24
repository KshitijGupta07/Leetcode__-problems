class Solution {
public:
   int len(int num){
    
     int count=0;
     while(num!=0){
        count++;
        num/=10;
     }
     return count-1;
   }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        map<int,int>t;
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]<10){
                m[arr1[i]]++;
            }
            else{
                int a=len(arr1[i]);
                int element=arr1[i];
                m[element]++;
                while(a>0){
                   
                   element=element/pow(10,a);
                   m[element]++;
                   a--;
                   element=arr1[i]; 
                }
            }
        }
          for(int i=0;i<arr2.size();i++){
            if(arr2[i]<10){
                t[arr2[i]]++;
            }
            else{
                int a=len(arr2[i]);
                int element=arr2[i];
                t[element]++;
                while(a>0){
                   
                   element=element/pow(10,a);
                   t[element]++;
                   a--;
                   element=arr2[i]; 
                }
            }
          }
        int a=0;
        int b=0;
        for(auto j:m){
            cout<<t[j.first]<<endl;
            if(t[j.first]>0){
                a=max(a,j.first);
            }
        }
        
        
        return len(a)+1;
        
    }
};