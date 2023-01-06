class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size(), i = 0;
        
// pushing till no overlapping
        while(i < n && intervals[i][1] < newInterval[0]) 
            ans.push_back(intervals[i++]);

// find the min and the max element to push as an interval by merging it
        while(i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);

// pushing all left out elements
        while(i < n)
            ans.push_back(intervals[i++]);
        return ans;
    }
};