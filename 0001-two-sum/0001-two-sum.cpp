class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map stores: {value -> index}
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the number we need has already been seen
            if (seen.count(complement)) {
                return {seen[complement], i};  // Return both indices
            }

            // Otherwise store current number and its index
            seen[nums[i]] = i;
        }

        return {}; // Problem guarantees a solution, this is just a safety return
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna