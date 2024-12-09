class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;

        for(auto el:s){
            mp[el]++;
        }

        int first = mp.begin()->second;

        for(auto it:mp) {
            if(it.second != first) return false;
        }

        return true;
    }
};