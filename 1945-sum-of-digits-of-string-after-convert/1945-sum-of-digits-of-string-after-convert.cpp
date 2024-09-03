class Solution {
public:
    int getLucky(string s, int k) {
        int n =  s.size();
        string count="";


        for(int i=0;i<n;i++) {

            count+=to_string(s[i]-'a'+1);
        }

        int ans=0;

       while(k--){
          ans=0;
         for(int i=0;i<count.size();i++){

            ans+=count[i]-'0';
        }

        count =  to_string(ans);

        }

        return ans;
        
        
        // int ans=0;
        // while(count) {
        //     if(k==0) break;

        //     ans+=count%10;
        //     count/=10;
        //     k--;
        // }
        // count = ans;

        // return ans;
        
        

        
    };
};