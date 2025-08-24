class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> mergedIntervals;

        intervals.emplace_back(newInterval);

        sort(intervals.begin(), intervals.end());

        mergedIntervals.emplace_back(intervals.front());

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (mergedIntervals.back()[1] < intervals[i][0])
            {
                mergedIntervals.emplace_back(intervals[i]);
            }
            else
            {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }

        return mergedIntervals;
    }
};