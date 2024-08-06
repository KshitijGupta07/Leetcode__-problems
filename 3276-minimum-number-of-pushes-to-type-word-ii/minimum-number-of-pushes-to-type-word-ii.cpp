class Solution {
public:
    int minimumPushes(string word) {
        vector<int>count(26,0);
        for(int i=0;i<word.length();i++){
            count[word[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<count.size();i++){
               if(count[i]>0){
                ans++;
               }
        }
        if(ans<=8){
            return word.length();
        }
           int ans2=0;
           
           int finalans=0;
           sort(count.begin(),count.end());
           reverse(count.begin(),count.end());
         for(int i=0;i<count.size();i++){
            ans2++;
            if(ans2%8==0){
                finalans+=count[i]*(ans2/8);
            }
            else{
                finalans+=count[i]*(ans2/8 +1);
            }
        }
        return finalans;
    }
};