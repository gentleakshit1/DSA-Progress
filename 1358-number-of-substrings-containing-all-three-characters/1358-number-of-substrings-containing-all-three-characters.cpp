class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1}; // last seen index of 'a', 'b', 'c'
        int count = 0;
        
        for (int i = 0; i < (int)s.size(); i++) {
            last[s[i] - 'a'] = i;
            // If all three characters have appeared so far,
            // every substring starting from 0..min(last[a],last[b],last[c])
            // and ending at i is valid.
            int minLast = min({last[0], last[1], last[2]});
            if (minLast != -1) {
                count += minLast + 1;
            }
        }
        
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna