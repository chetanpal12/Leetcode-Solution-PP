class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0; // Initialize size as a long long to handle large numbers
        int i;

        // Calculate the size of the decoded string
        for (i = 0; size < k; i++) {
            if (isdigit(s[i])) {
                size *= s[i] - '0';
            } else {
                size++;
            }
        }

        // Backtrack to find the kth character
        while (i--) {
            if (isdigit(s[i])) {
                size /= s[i] - '0';
                k %= size;
            } else if (k % size-- == 0) {
                return string(1, s[i]);
            }
        }

        return "";
    }
};
