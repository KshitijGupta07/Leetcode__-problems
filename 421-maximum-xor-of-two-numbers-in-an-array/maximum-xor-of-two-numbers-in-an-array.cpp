class Solution {
public:
   struct Node{
         Node* link[2];
         

         bool contain(int bit){
           return link[bit]!=NULL;
         }
         void put(int bit,Node* node){
            link[bit]=node;
         }
         Node* get(int bit){
            return link[bit];
         }
        
   };
    int findMaximumXOR(vector<int>& nums) {
        Node* root=new Node();
        for(int i=0;i<nums.size();i++){
            Node* node=root;
            for(int j=30;j>=0;j--){
                int bit=((nums[i]>>j)&1);
                
                if(node->contain(bit)==false){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            Node* node=root;
            int m=0;
            for(int j=30;j>=0;j--){
                int bit=((nums[i]>>j)&1);
                 if(node->contain(1-bit)){
                      m=m+(1<<j);
                      node=node->get(1-bit);
                 }
                 else{
                    node=node->get(bit);
                 }

            }
            ans=max(ans,m);
        }
        return ans;
    }
};