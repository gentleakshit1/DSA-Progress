class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort so we can use two-pointer technique and skip duplicates easily
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Early exit: smallest possible sum is already > 0
            if (nums[i] > 0) break;
            
            int left = i + 1;
            int right = n - 1;
            
            // Classic two-pointer scan
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for second and third elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;   // Need a larger value
                }
                else {
                    right--;  // Need a smaller value
                }
            }
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna