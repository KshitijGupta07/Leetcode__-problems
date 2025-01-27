class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>degree(n,0);
        for(int i=0;i<favorite.size();i++){
            degree[favorite[i]]++;
        }
        queue<int>q;
        for(int i=0;i<degree.size();i++){
            if(degree[i]==0){
                  q.push(i);
            }
        }
        vector<int>depth(n,1);
        while(q.empty()==false){
            int front=q.front();
            q.pop();
            int next=favorite[front];
            depth[next]=max(depth[next],depth[front]+1);
            degree[next]-=1;
            if(degree[next]==0){
                q.push(next);
            }

        }
        int longestcycle=0;
        int two=0;
        for(int i=0;i<n;i++){
            if(degree[i]!=0){
                int length=0;
                int c=i;
                while(degree[c]!=0){
                    degree[c]=0;
                    c=favorite[c];
                    length++;
                }
                if(length==2){
                    two+=depth[i]+depth[favorite[i]];
                }
                else{
                    longestcycle=max(longestcycle,length);
                }
            }
            
        }
        return max(longestcycle,two);
    }
};