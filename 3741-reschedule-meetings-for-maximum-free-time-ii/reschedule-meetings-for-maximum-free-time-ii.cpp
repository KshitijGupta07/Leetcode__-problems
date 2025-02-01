class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int ans=0;
        map<int,int>m;
        int n=startTime.size();
        m[startTime[0]]++;
        m[eventTime-endTime.back()]++;
        for(int i=1;i<n;i++){
            m[startTime[i]-endTime[i-1]]++;
        }
        for(int i=0;i<n;i++){
            int pre;
            int ne;
            if(i==0){
                pre=0;
                ne=startTime[i+1];
            }
            else if(i==n-1){
                pre=endTime[i-1];
                ne=eventTime;
            }
            else{
                pre=endTime[i-1];
                ne=startTime[i+1];
            }
            int previ=startTime[i]-pre;
            int next=ne-endTime[i];
            m[previ]--;
            m[next]--;
            if(m[previ]==0){
                m.erase(previ);
            }
            if(m[next]==0){
                m.erase(next);
            }
            int size=endTime[i]-startTime[i];
            if(m.lower_bound(size)!=m.end()){
                ans=max(ans,ne-pre);
            }
            else{
                ans=max(ans,ne-pre-size);
            }
             m[previ]++;
            m[next]++;
        }
        return ans;
    }
};