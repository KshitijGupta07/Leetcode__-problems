class Solution {
public:
   int binarytodecimal(string &a){
     int ans=0;
     for(int i=0;i<a.length();i++){
        ans+=((a[i]-'0')*pow(2,a.length()-i-1));
     }
     return ans;
   }
    vector<int> grayCode(int n) {
        vector<string>temp;
        temp.push_back("0");
        temp.push_back("1");
        if(n==1){
            return {0,1};
        }
        vector<string>ans;
        for(int i=2;i<=n;i++){
            ans.clear();
             for(int j=0;j<temp.size();j++){
                temp[j].insert(temp[j].begin(),'0');
                ans.push_back(temp[j]);
             }
             for(int j=temp.size()-1;j>=0;j--){
                   string a=temp[j];
                   a[0]='1';
                   ans.push_back(a);
             }
             
             temp=ans;
             
        }
        vector<int>finalans;
        for(int i=0;i<ans.size();i++){
           finalans.push_back(binarytodecimal(ans[i]));
        }
        return finalans;
    }
};