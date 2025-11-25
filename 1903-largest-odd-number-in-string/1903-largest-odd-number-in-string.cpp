class Solution {
private:
    bool CheckOdd(char ch)
    {
        string temp="";
        temp+=ch;
        int num = stoi(temp);
        if(num%2 != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string ans="";

        for(int i=n-1;i>=0;i--)
        {
            if(CheckOdd(num[i]))
            {
                return num.substr(0,i+1);
            }
        }
        return ans;
        
    }
};