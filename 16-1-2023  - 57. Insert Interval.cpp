class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         If you consider newInterval and ith interval we can consider following three cases.
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
//             Case-1: newInterval is before ith interval. Then include newInterval in the answer and put all the rest of the intervals in the answer.
            if(newInterval[1]<intervals[i][0])
            {
                ans.push_back(newInterval);
                for(int j=i;j<n;j++)
                {
                    ans.push_back(intervals[j]);
                }
                return ans;
            }
//             Case-2: newInterval is after interval. Then include the ith interval in answer.
            else if(newInterval[0]>intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
//             Case-3: newInterval overlaps with ith interval. Then take the minimum of start point of both the intervals and maximum of end point of both.
            else
            {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};