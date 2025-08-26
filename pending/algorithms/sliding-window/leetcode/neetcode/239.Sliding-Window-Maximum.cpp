
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        using numIndex = int;
        deque<numIndex> dq;
        vector<numIndex> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (not dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            while (not dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};