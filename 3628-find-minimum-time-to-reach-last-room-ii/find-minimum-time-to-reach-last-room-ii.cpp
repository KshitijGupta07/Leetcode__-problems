class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>>time(moveTime.size(),(vector<int>(moveTime[0].size(),INT_MAX)));
        int x=0;
        int y=0;
        int timer=0;
        int c=1;
        int m=moveTime.size();
        int n=moveTime[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>p;
        
        time[0][0]=0;

        p.push({timer,x,y});
        vector<pair<int,int>>v{{1,0},{0,1},{0,-1},{-1,0}};
        while(p.empty()==false){

            vector<int>top=p.top();
            int t=top[0];
            int xi=top[1];
            int yi=top[2];
            if(xi==m-1&&yi==n-1){
                cout<<t<<endl;
            }
            
            p.pop();
            for(auto j:v){
                if(j.first+xi>=0&&j.first+xi<m&&j.second+yi>=0&&j.second+yi<n){
                        c=2-(j.first+xi+j.second+yi)%2;
                        int next=max(t,moveTime[xi+j.first][yi+j.second])+c;
                        
                    
                        if(time[xi+j.first][yi+j.second]>next){
                            time[xi+j.first][yi+j.second]=next;
                             p.push({next,xi+j.first,yi+j.second});
                        }
                       
                    
                }
            }
           if(c==1){
            c=2;
           }
           else{
            c=1;
           }
        }
        
        return time[m-1][n-1];
    }
};