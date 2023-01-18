class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0,linear=INT_MIN;
        int total=0;
        for(int i=0;i<n;i++)
            total+=nums[i];
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            linear=max(linear,sum);
            if(sum<0)
                sum=0;
        }
        if(linear<=0)
            return linear;
            
        sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans=min(ans,sum);
            if(sum>0)
                sum=0;
        }
        return max(linear,total-ans);
    }
};