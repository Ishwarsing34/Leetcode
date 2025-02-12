class Solution {
    bool check(char ch){
        
        if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
       else return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>temp;

        for(int i=0;i<n;i++){
            string str = words[i];
            if(check(words[i][0]) && check(str[str.size()-1])){
                temp.push_back(1);
            }else{
                temp.push_back(0);
            }
        }

       vector<int>prefsum(temp.size());

       prefsum[0] = temp[0];

       for(int i=1;i<n;i++){

          prefsum[i] = prefsum[i-1] + temp[i];
        }


        for(int i=0;i<temp.size();i++){
            cout<<prefsum[i]<<' ';
        }

        vector<int>res;

        for(int i=0;i<queries.size();i++){

            int start = queries[i][0];
            int end = queries[i][1];


           int ans = prefsum[end] - ((start == 0) ? 0 : prefsum[start-1]);
           res.push_back(ans);
        }
     

       return res;


    }
};