class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1,0),cnt(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            arr[trust[i][0]]=1;
            cnt[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==0 && cnt[i]==n-1)
                return i;
        }
        return -1;
    }
};