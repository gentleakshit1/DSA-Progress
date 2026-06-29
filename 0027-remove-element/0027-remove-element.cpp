class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // points to next valid position

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {   // keep this element
                nums[k] = nums[i];  // move it to front
                k++;
            }
            // if nums[i] == val, just skip it
        }

        return k; // k = count of elements that aren't val
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna