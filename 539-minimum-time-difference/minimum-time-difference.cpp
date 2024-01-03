class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>ans;
        int element=0;
        for(int i=0;i<timePoints.size();i++){
            if((timePoints[i])[0]=='0'&&(timePoints[i])[1]=='0'&&(timePoints[i])[3]=='0'&&(timePoints[i])[4]=='0'){
            element=1440;
            }
            else if((timePoints[i])[0]=='0'&&(timePoints[i])[1]=='0'){
                element=1440+((timePoints[i])[3]-'0')*10+((timePoints[i])[4]-'0');
            }
            else{
             element=(((timePoints[i])[0]-'0')*10+((timePoints[i])[1]-'0'))*60+((timePoints[i])[3]-'0')*10+((timePoints[i])[4]-'0');
        }
            ans.push_back(element);
        }
        sort(ans.begin(),ans.end());
        
        int min=ans[1]-ans[0];
         for(int i=2;i<ans.size();i++){
            if(min>=ans[i]-ans[i-1]){
                if(min<1440-min){
                min=ans[i]-ans[i-1];
            }
            else{
                min=ans[i]-ans[i-1];
            }
            }
         }
         
         int a=0;
         int e=ans[ans.size()-1]-ans[0];
         if(e>1440-e){
             e=1440-e;
         }
         cout<<e<<endl;
         if(min>1440-min){
             a= 1440-min;
         }
         else{
             a=min;
         }
         cout<<a<<endl;
         if(a>e){
             return e;
         }
         return a; 
        
    }
};