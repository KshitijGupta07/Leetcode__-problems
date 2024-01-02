class Solution {
public:
int minterm(vector<int>& ans){
    int min=ans[0];
    for(int i=1;i<ans.size();i++){
        if(min>ans[i]){
            min=ans[i];
        }
    }
    return min;
}
    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int count=1;
        
        vector<int>ans;
        for(int i=1;i<deck.size();i++){
            
            if(deck[i]==deck[i-1]){
               count++;
            }
            else {
                ans.push_back(count);
                count=1;
            }
            

          
        }
        if(deck.size()==1){
            return false;
        }
        if(ans.size()==0){
            return true;
    }
        ans.push_back(count);
        int a=0;
        
        for(int i=0;i<ans.size()-1;i++){
        a=__gcd(ans[i],ans[i+1]);
        if(a==1){
            return false;
        }
        }
        a=__gcd(ans[0],ans[ans.size()-1]);
            if(a==1){
                return false;
            }
        
        
        return true;
    }
};