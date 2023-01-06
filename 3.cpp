class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), ans = 0;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n - 1; i++) {
            if(intervals[i][1] > intervals[i + 1][0]) {
                intervals[i + 1][1] = min(intervals[i + 1][1], intervals[i][1]);
                ans++;
            }
        }
        return ans;

    }
};