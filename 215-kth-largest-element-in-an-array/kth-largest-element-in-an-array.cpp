class Solution {
public:
    void insert(int val,vector<int>&arr,int size){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    
       
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>arr(k+1);
        
        arr[0]=-1;
        int size=1;
        for(int i=1;i<=k;i++){
            insert(nums[i-1],arr,i-1);
    
        }
         for(int i=k;i<nums.size();i++){
              if(nums[i]>=arr[1]){
                arr[1]=nums[i];
                int j=1;
                int large=j;
                 while(large<arr.size()){
            int leftindex=2*large;
            int rightindex=2*large+1;
            if(leftindex<arr.size()&&arr[leftindex]<arr[large]){
                
                large=leftindex;
            }
             if(rightindex<arr.size()&&arr[rightindex]<arr[large]){
                
                large=rightindex;
            }
            if(large!=j){
                swap(arr[large],arr[j]);
                j=large;
            }
            else{
                break;
            }
        }
              }

            }
        
        
                
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
       
        
        return arr[1];

    }
};