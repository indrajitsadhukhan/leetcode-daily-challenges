class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> currList;
        recursion(nums,0,currList);
        
        vector<vector<int>> fans;
        for(auto it: ans)
        {
            fans.push_back(it);
        }
        return fans;
    }
    void recursion(vector<int> &nums,int curr,vector<int> &currList)
    {
        if(currList.size()>1)
            ans.insert(currList);
        int n=currList.size();
        for(int i=curr;i<nums.size();i++)
        {
            if(currList.size()==0 || currList[n-1]<=nums[i])
            {
                currList.push_back(nums[i]);
                recursion(nums,i+1,currList);
                currList.pop_back();
            }
        }
    }
    
};