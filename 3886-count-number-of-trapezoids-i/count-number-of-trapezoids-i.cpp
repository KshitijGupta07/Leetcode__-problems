class Solution {
public:
int element=pow(10,9)+7;
//   int fac(int n){
//      int ans=1;
//      for(int i=1;i<=n;i++){
//         ans=(ans%element * i%element)%element;
//      }
//      return ans%element;
//   }
//   int combi(int n ,int r){
//     int a=fac(n)%element;
//     int b=fac(r)%element;
//     int c=fac(n-r)%element;
//     int d=(b*c)%element;
//     return (a/d)%element;
//   }
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,long long >m;
        long long edges=0;
        for(int i=0;i<points.size();i++){
            int b=points[i][1];
            m[b]++;
            
        }
        for(auto j:m){
            if(j.second>=2){
                long long a=(j.second*j.second-j.second)/2;
                 edges+=a;
            }
           
        }
        
        long long  ans=(edges*edges-edges);
        ans=ans/2;
        for(auto j:m){
            if(j.second>2){
            long long a=(j.second*j.second-j.second)/2;
             
                ans-=(a*a-a)/2;
            }
        }
        return ans%element;
        

    }
};