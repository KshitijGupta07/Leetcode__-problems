class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        vector<int>a(51,0);
        vector<int>b(51,0);
        for(int i=0;i<A.size();i++){
            a[A[i]]++;
            b[B[i]]++;
            int count=0;
            for(int i=0;i<51;i++){
                if(a[i]==b[i]&&a[i]>0){
                       count+=1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};