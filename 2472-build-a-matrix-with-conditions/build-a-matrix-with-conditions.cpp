class Solution {
public:
   void dfs(vector<vector<int>>&row,unordered_map<int,bool>&visited,int& index,stack<int>&st){
    
     visited[index]=true;
     for(auto j:row[index]){

        if(visited[j]==false){
            dfs(row,visited,j,st);
        }
     }
     st.push(index);
   }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>row(k+1);
        vector<vector<int>>col(k+1);
        for(int i=0;i<rowConditions.size();i++){
            int x=rowConditions[i][0];
            int y=rowConditions[i][1];
            row[x].push_back(y);
        }
        for(int i=0;i<colConditions.size();i++){
              int x=colConditions[i][0];
            int y=colConditions[i][1];
            col[x].push_back(y);
        }
        unordered_map<int,bool>visited;
        stack<int>st;
      for(int i=1;i<=k;i++){
        if(visited[i]==false){
            dfs(row,visited,i,st);
        }
      }
      vector<int>r;
      map<int,int>check;
      int i=0;
      while(st.empty()==false){
         r.push_back(st.top());
         check[st.top()]=i;
         i++;
         st.pop();
      }
      for(int i=0;i<rowConditions.size();i++){
          int x=rowConditions[i][0];
            int y=rowConditions[i][1];
        if(check[x]>check[y]){
            return {};
        }
      }
      stack<int>st2;
      unordered_map<int,bool>visited2;
      
      for(int i=1;i<=k;i++){
        if(visited2[i]==false){
            dfs(col,visited2,i,st2);
        }
      }
      vector<int>c;
      map<int,int>check2;
      int j=0;
      while(st2.empty()==false){
        c.push_back(st2.top());
        check2[st2.top()]=j;
        j++;
        st2.pop();
      }
        for(int i=0;i<colConditions.size();i++){
          int x=colConditions[i][0];
            int y=colConditions[i][1];
        if(check2[x]>check2[y]){
            return {};
        }
      }
      vector<vector<int>>ans(k,vector<int>(k,0));
      for(int i=1;i<=k;i++){
        ans[check[i]][check2[i]]=i;
      }
   
      
      return ans;


    }
};