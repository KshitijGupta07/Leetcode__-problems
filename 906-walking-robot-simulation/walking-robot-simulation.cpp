class Solution {
public:
   int helper(vector<int>&commands,int& i,int& x,int &y,char& ch,map<vector<int>,bool>&location,bool& visited){
           int maxi=INT_MIN;
            if(ch=='N'){
                for(int j=1;j<=commands[i];j++){
                     y=y+1;
                    if(location[{x,y}]){
                        y=y-1;
                    }
                    
                    maxi=max(maxi,x*x+y*y);
                }
            }
              if(ch=='S'){
                for(int j=1;j<=commands[i];j++){
                    y=y-1;
                    if(location[{x,y}]){
                        y=y+1;
                    }
                    
                     maxi=max(maxi,x*x+y*y);
                }
            }
              if(ch=='E'){
                for(int j=1;j<=commands[i];j++){
                    x=x+1;
                    if(location[{x,y}]){
                        x=x-1;
                    }
                    
                     maxi=max(maxi,x*x+y*y);
                }
            }
              if(ch=='W'){
                for(int j=1;j<=commands[i];j++){
                    x=x-1;
                    if(location[{x,y}]){
                        x=x+1;
                        
                    }
                    
                     maxi=max(maxi,x*x+y*y);
                }
            }
              
          return maxi;
   }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<vector<int>,bool>location;
        for(int i=0;i<obstacles.size();i++){
            location[obstacles[i]]=true;
        }
        bool visited=false;
        bool s=false;
        int x=0;
        int y=0;
        char ch='N';
         int maxi=INT_MIN;
        for(int i=0;i<commands.size();i++){
    
            if(commands[i]==-1){
                if(ch=='N'){
                    ch='E';
                }
                else if(ch=='W'){
                    ch='N';
                }
                else if(ch=='S'){
                    ch='W';
                }
                else{
                    ch='S';
                }
            }
            else if(commands[i]==-2){
                   if(ch=='N'){
                    ch='W';
                }
                else if(ch=='W'){
                    ch='S';
                }
                else if(ch=='S'){
                    ch='E';
                }
                else{
                    ch='N';
                }
            }
           
            else{
                int element=helper(commands,i,x,y,ch,location,visited);
               
                maxi=max(maxi,element);
            }
        }
        cout<<x<<" "<<y<<endl;
    cout<<maxi<<endl;
        
        return maxi;
    }
};