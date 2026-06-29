class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto& interval : intervals) {
            // If result is empty OR current interval doesn't overlap with last one
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                // Overlap exists — extend the end of the last interval if needed
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna