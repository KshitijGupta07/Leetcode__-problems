class Solution {
public:
   int solve(vector<vector<int>>&books,int &shelfWidth,int currenwidth,int currentheight,int index,vector<vector<int>>&dp){
    int maxheight=max(currentheight,books[index][1]);
    if(index==books.size()-1){
        if(books[index][0]<=currenwidth)return max(currentheight,books[index][1]);
        return currentheight+books[index][1];
    }
    if(dp[currenwidth][index]!=-1){
        return dp[currenwidth][index];
    }
      int sameshelf=INT_MAX;
    
      if(currenwidth>=books[index][0]){
        sameshelf=solve(books,shelfWidth,currenwidth-books[index][0],maxheight,index+1,dp);
      }
      
       int newshelf=currentheight+solve(books,shelfWidth,shelfWidth-books[index][0],books[index][1],index+1,dp);
       dp[currenwidth][index]= min(sameshelf,newshelf);
       return dp[currenwidth][index];
      

   }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int currenwidth=shelfWidth;
        int currentheight=0;
        int index=0;
        vector<vector<int>>dp(shelfWidth+1,vector<int>(books.size(),-1));
        int ans=solve(books,shelfWidth,currenwidth,currentheight,index,dp);
          return ans;
    }
};