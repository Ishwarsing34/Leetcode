class Solution {
public:
    string entityParser(string text) {

        unordered_map<string, char> mp = {{"&quot;", '"'}, {"&apos;", '\''},
                                          {"&amp;", '&'},  {"&gt;", '>'},
                                          {"&lt;", '<'},   {"&frasl;", '/'}};

        int n = text.size();

        string res = "";

        int i = 0;

        while (i < n) {

            if (text[i] == '&') {

                int j = i;

                while (j < n && text[j] != ';') {
                    j++;
                };

                if (j < n) {

                    string entity = text.substr(i, j - i + 1);
                    if (mp.find(entity) != mp.end()) {
                        res.push_back(mp[entity]);
                        i = j + 1;
                        continue;
                    }
                    
                }
  
            }
            res.push_back(text[i]);
            i++;
        }

        return res;
    }
};