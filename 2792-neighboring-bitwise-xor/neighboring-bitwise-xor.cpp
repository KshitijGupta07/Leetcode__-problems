class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int a=1;
        int x=1;
        for(int i=0;i<derived.size();i++){
            x=x^derived[i];
        }
        cout<<x<<endl;
        if(a==x){
            return true;
        }
        return false;
    }
};