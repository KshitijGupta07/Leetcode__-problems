class Solution {
public:
    bool solve(vector<int>&nums,int i,int j,int sum1,int sum2,int bit){
        cout<<sum1<<" "<<sum2<<endl;
        if(i==j){
            if(bit==0){
                sum1+=nums[i];
            }
            else{
                sum2+=nums[j];
            }
            return sum1>=sum2;
        }
        
        bool x=false;
        if(bit==0){
            x=solve(nums,i+1,j,sum1+nums[i],sum2,bit^1)||solve(nums,i,j-1,sum1+nums[j],sum2,bit^1);
        }
        else{
            x=solve(nums,i+1,j,sum1,sum2+nums[i],bit^1)&&solve(nums,i,j-1,sum1,sum2+nums[j],bit^1);
        }
        return x;
    }
    bool predictTheWinner(vector<int>& nums) {
        bool x=solve(nums,0,nums.size()-1,0,0,0);
        return x;
    }
};