class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int e) {
        priority_queue<pair<double,int>>ans;
        
        double c=0;
        
        for(int i=0;i<classes.size();i++){
            double a=classes[i][0];
            double b=classes[i][1];
            
                c=(a+1)/(b+1)-a/b;
                ans.push({c,i});
            

        }
        while(e>0){
            double d=ans.top().first;
            int index=ans.top().second;
            ans.pop();
            e=e-1;
            classes[index][0]+=1;
            classes[index][1]+=1;
               double a=classes[index][0];
            double b=classes[index][1];
              c=(a+1)/(b+1)-a/b;
            ans.push({c,index});
        }
        c=0;
        for(int i=0;i<classes.size();i++){
          double a=classes[i][0];
            double b=classes[i][1];
            c+=a/b;
        }
          double size=classes.size();
       


        return c/size;

      
    }
};