class Solution {
public:
    int maximumSwap(int num) {
        vector<int>ans;
        while(num!=0){
            ans.push_back(num%10);
            num/=10;
        }
        reverse(ans.begin(),ans.end());
      
        for(int i=0;i<ans.size()-1;i++){
            bool signal=false;
            int maxi=ans[i];
            int maxindex=-1;
            for(int j=i+1;j<ans.size();j++){
                if(maxi<ans[j]){
                    maxi=ans[j];
                    maxindex=j;
                    signal=true;
                    
                }
                else if(maxi==ans[j]){
                    if(maxindex<j){
                        maxindex=j;
                    }
                }
            }
            cout<<maxi<<endl;
            if(signal==true){
                swap(ans[i],ans[maxindex]);
                break;
            }
            
        }
        int newnum=0;
        cout<<endl;
        for(auto j:ans){
            cout<<j<<" ";
        }
        for(int i=0;i<ans.size();i++){
            newnum+=pow(10,ans.size()-i-1)*ans[i];
        }
        return newnum;
    }
};