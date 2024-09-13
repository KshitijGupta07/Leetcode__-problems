class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int maxi=INT_MIN;
        vector<int>ans;
       for(int i=0;i<arr.size();i++){
              maxi=max(maxi,arr[i]);
       } 
       int count=0;
       while(maxi!=0){
        maxi=maxi>>1;
        count++;
       }
       vector<vector<int>>counter(count);
       for(int i=0;i<count;i++){
        int c=0;
        for(int j=0;j<arr.size();j++){
            int element=arr[j];
            element=element>>i;
            if((element&1)==0){
                c=c+1;
               
            }
            counter[i].push_back(c);
        }
       }
       for(int i=0;i<queries.size();i++){
        
        int a=queries[i][0];
        int b=queries[i][1];
        
          int mask=0;
        for(int j=0;j<count;j++){
             int count0=0;
            int count1=0;
            int bit=0;
            
           if(a==0){
            count0=counter[j][b];
            count1=b-a+1-count0;
           }
           else{
            count0=counter[j][b]-counter[j][a-1];
            count1=b-a+1-count0;
           }
           
           if(count1%2==1){
            mask=(mask|(1<<j));
           }
           

        }
            cout<<endl;
           ans.push_back(mask);
       }
       
       return ans;
    }
};