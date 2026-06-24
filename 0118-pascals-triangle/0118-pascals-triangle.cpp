
class Solution {
public:
    // Return a vector of vectors containing the first `numRows` of Pascal's triangle.
    vector<vector<int>> generate(int numRows) {
        // 1️⃣ Prepare the container that will hold all rows.
        vector<vector<int>> triangle;

        // 2️⃣ Iterate over each row index (0‑based).
        for (int r = 0; r < numRows; ++r) {
            // 👉 Create a new row with `r + 1` elements.
            vector<int> row(r + 1, 1);   // fill with 1s – first & last are always 1

            // 3️⃣ Fill interior positions (if any) using the previous row.
            //    For row `r`, valid interior columns are 1 … r‑1.
            for (int c = 1; c < r; ++c) {
                // Each element = sum of two elements from the row above.
                // previous row is `triangle[r‑1]`
                row[c] = triangle[r-1][c-1] + triangle[r-1][c];
            }

            // 4️⃣ Append the completed row to the triangle.
            triangle.push_back(row);
        }

        // 5️⃣ Return the full triangle.
        return triangle;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna