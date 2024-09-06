class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int right = 0;
        int left = 0;
        int cnt = 0;

       
        while(right<n){
            freq[s[right]-'a']++;

            while(freq[s[right]-'a']>1)
            {
                freq[s[left]-'a']--;
                left++;
            }

            cnt = max(cnt,right-left+1);
            right++;


        }

         return cnt;
    }
   
};