class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int n=nums.size();
        int pre=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            pre=(pre+nums[i]%k+k)%k;
            ans+=mp[pre];
            mp[pre]++;
        }
        return ans;
    }
};