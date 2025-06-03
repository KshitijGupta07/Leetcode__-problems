class Solution {
public:
   void fill(vector<vector<int>>&image,int i,int j,int color,int m,int n,int prev){
    if(image[i][j]==color){
        return;
    }
      cout<<i<<" "<<j<<endl;
      image[i][j]=color;
      if(i+1<m&&image[i+1][j]==prev){
        fill(image,i+1,j,color,m,n,prev);
      }
       if(i-1>=0&&image[i-1][j]==prev){
        fill(image,i-1,j,color,m,n,prev);
      }
       if(j+1<n&&image[i][j+1]==prev){
        fill(image,i,j+1,color,m,n,prev);
      }
       if(j-1>=0&&image[i][j-1]==prev){
        fill(image,i,j-1,color,m,n,prev);
      }
      

   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int i=sr;
        int j=sc;
        int m=image.size();
        int n=image[0].size();
        int prev=image[i][j];
        fill(image,sr,sc,color,m,n,prev);
        return image;
    }
};