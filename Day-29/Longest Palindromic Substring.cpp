class Solution {
public
    bool isPalindrome(string str) {
        int left = 0;
        int right = str.length() - 1;

        while(left < right) {
            if(str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string temp = s.substr(i, j - i + 1);
                if(isPalindrome(temp)) {
                    if(temp.length() > ans.length()) {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};
