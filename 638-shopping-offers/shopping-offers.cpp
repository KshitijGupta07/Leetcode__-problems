class Solution {
public:
map<vector<int>,int>mpp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mpp.count(needs)!=0){
            return mpp[needs];
        }
        int ans=0;
        for(int i=0;i<price.size();i++){
            ans+=price[i]*needs[i];
        }
        for(int i=0;i<special.size();i++){
            int ans2=0;
            bool validoffer=true;
            for(int j=0;j<needs.size();j++){
                if(needs[j]<special[i][j]){
                    validoffer=false;
                    break;
                }
            }
            if(validoffer){
                for(int j=0;j<needs.size();j++){
                    needs[j]-=special[i][j];
             
                       
                }    
                   ans2=ans2+special[i].back()+shoppingOffers(price,special,needs);
                   ans=min(ans,ans2);
             
                for(int j=0;j<needs.size();j++){
                    needs[j]+=special[i][j];
                }
            }
        }
        mpp[needs]=ans;
        return mpp[needs];
    }
};