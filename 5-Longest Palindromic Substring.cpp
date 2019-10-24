class Solution {
public:
    
//Approach 1: expand from center value
    string longestPalindrome(string s) {
        if(s.size() < 2) 
            return s;
        int n = s.size(), maxLen = 0, start = 0;
        for(int i = 0; i < n - 1; i++) {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        if(maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }   
    }
    
//Aproach 2: 
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int n = s.size(), maxLen = 0, start = 0;
        for(int i = 0; i < n; ) {
            if(n - i <= maxLen / 2) break;
            int left = i, right = i;
            while(right < n - 1 && s[right + 1] == s[right])
                right++;
            i = right + 1;
            while(right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            if(maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }

//Approach 3: dynamic programing
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n = s.size(), dp[n][n] = {0}, start = 0, maxLen = 1;
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
            for(int j = 0; j < i; j++) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if(dp[j][i] && maxLen < i - j + 1) {
                    maxLen = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxLen);
    }    
};
