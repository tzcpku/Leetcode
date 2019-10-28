class Solution {
public:
//Approach 1: sliding window optimized
    int lengthOfLongestSubstring(string s) {
        //map <character, latest index>
        int n = s.size();
        unordered_map<char, int> m;
        int ans = 0;
        for(int i = 0, j = 0; j < n; j++) {
            if(m.count(s[j])) {          
                i = max(m[s[j]], i - 1) + 1;
            }
            ans = max(ans, j - i + 1);
            m[s[j]] = j;
        }
        return ans;
        
        //map <character, latest index + 1>
        // for(int i = 0, j = 0; j < n; j++) {
        //     if(m.count(s[j])) {
        //         i = max(m[s[j]], i);
        //     }
        //     ans = max(ans, j - i + 1);
        //     m[s[j]] = j + 1;
        // }
        //return ans;
    }

// Approach 2: sliding window
    int lengthOfLongestSubstring(string s) {
        //use array to check
        int n = s.size();
        int check[256] = {0};
        int ans = 0, i = 0, j = 0;
        while(i < n && j < n){
            if(!check[s[j]]){
                check[s[j++]] = 1;
                ans = max(ans, j - i);
            }
            else {
                check[s[i++]] = 0;
            }
        }
        return ans;
        
        //use set to check
        // int n = s.size();
        // set<char> m;
        // int ans = 0, i = 0, j = 0;
        // while(i < n && j < n){
        //     if(!m.count(s[j])){
        //         m.insert(s[j++]);
        //         ans = max(ans, j - i);
        //     }
        //     else {
        //         m.erase(s[i++]);
        //     }
        // }
        // return ans;
    }
    
//Approach 3: brute force
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j <= n; j++){
                if(allUnique(s, i, j))
                    ans = max(ans, j - i);
            }
        return ans;
    }
    
    bool allUnique(string s, int start, int end){
        //use array to check
        // int check[256] = {0};
        // for(int i = start; i < end; i++){
        //     if(!check[s[i]]){
        //         check[s[i]] = 1;
        //     }
        //     else
        //         return false;
        // }
        // return true;
        
        //use set to check
        set<char> m;
        for(int i = start; i < end; i++){
            if(m.count(s[i]))
                return false;
            else
                m.insert(s[i]);
        }
        return true; 
    }
};
