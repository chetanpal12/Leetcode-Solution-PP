class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        unordered_map<char, bool> inResult;
        string result = "";

        // Count the occurrences of each character in the input string.
        for (char c : s) {
            count[c]++;
        }

        for (char c : s) {
            count[c]--; // Decrement the count of the current character.

            // If the character is already in the result, skip it.
            if (inResult[c]) {
                continue;
            }

            // While there are characters left in the result and the current character is smaller
            // and lexicographically greater than the last character in the result, remove the last character.
            while (!result.empty() && c < result.back() && count[result.back()] > 0) {
                inResult[result.back()] = false;
                result.pop_back();
            }

            // Add the current character to the result.
            result += c;
            inResult[c] = true;
        }

        return result;
    }
};
