class Solution {
public:
vector<int>nextsmall(vector<int>& heights,int &n){
    stack<int>st;
    st.push(-1);
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
         while(st.top()!=-1&&heights[st.top()]>=heights[i]){
            st.pop();
         }
         ans.push_back(st.top());
         st.push(i);
    }
    
    return ans;
}
vector<int>prevsmall(vector<int>& heights,int &n){
      stack<int>st;
    st.push(-1);

    vector<int>ans;
    
    for(int i=0;i<n;i++){
         while(st.top()!=-1&&heights[st.top()]>=heights[i]){
            st.pop();
         }
         ans.push_back(st.top());
         st.push(i);
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev;
        vector<int>next;
        prev=prevsmall(heights,n);
        next=nextsmall(heights,n);
        reverse(next.begin(),next.end());
        int maxarea=0;
        for(int i=0;i<heights.size();i++){
            
            
            if(next[i]==-1){
                next[i]=n;
            }
           
            int breadth=next[i]-prev[i]-1;
            if(breadth==0){
                breadth=1;
            }
 
            int area=heights[i]*breadth;
            maxarea=max(area,maxarea);

        }
        return maxarea;
    }
};