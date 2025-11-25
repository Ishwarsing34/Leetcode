class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();

        string res = "";

        int i = 0;

        while(i < n)
        {
            string temp = "";
            while(i<n && s[i]==' ') i++;

            while(i<n && s[i] != ' '){
                temp.push_back(s[i]);
                i++;
            }

            if(temp.size() > 0){

                if(res.size() == 0)
                {
                    res = temp;
                }else{
                    res = temp + " " + res;
                }
            }
        }


        return res;
    }

};