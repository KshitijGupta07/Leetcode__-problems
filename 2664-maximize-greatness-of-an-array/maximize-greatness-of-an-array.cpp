class Solution {
public:
    int maximizeGreatness(vector<int>&a) {
          int n=a.size();

    int maxi=INT_MIN;
    
    map<int,int>m;
    
    for(int i=0;i<n;i++){
       int element=a[i];
       
       m[element]++;
    }
    for(auto j:m){
        maxi=max(maxi,j.second);
    }
    return n-maxi;
    }
};