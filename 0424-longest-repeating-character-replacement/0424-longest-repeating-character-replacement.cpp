class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        

        int right = 0;
        int left = 0;
        int maxLen = 0;
        int cnt[26] = {};
        int ans = 0;

        for(right=0;right<n;right++) {
            cnt[s[right]-'A']++;

            while(right-left+1 - *max_element(cnt,cnt+26) > k){
                cnt[s[left]-'A']--;
                left++;
            }

            ans = max(ans,right-left+1);
        }

        return ans;



    }
};