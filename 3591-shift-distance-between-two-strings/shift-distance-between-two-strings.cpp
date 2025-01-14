class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n=s.length();
        long long price=0;
        for(int i=0;i<n;i++){
            long long price1=0;
            long long price2=0;
            if(s[i]==t[i]){
                continue;
            }
            else{
                if(s[i]<t[i]){

                    for(int j=(s[i]-'a');j<(t[i]-'a');j++){
                            long long element=nextCost[j];
                            price1+=element;
                    }
                    for(int j=(s[i]-'a');j>=0;j--){
                        long long element=previousCost[j];
                        price2+=element;
                    }
                    for(int j=('z'-'a');j>(t[i]-'a');j--){
                        long long element=previousCost[j];
                        price2+=element;
                    }
                    price+=min(price1,price2);
                }
                else{
                     for(int j=(s[i]-'a');j>(t[i]-'a');j--){
                            long long element=previousCost[j];
                            price1+=element;
                    }
                    for(int j=(s[i]-'a');j<=25;j++){
                        long long element=nextCost[j];
                        price2+=element;
                    }
                    for(int j=0;j<(t[i]-'a');j++){
                        long long element=nextCost[j];
                        price2+=element;
                    }
                    price+=min(price1,price2);
                }
            }
        }
        return price;
    }
};