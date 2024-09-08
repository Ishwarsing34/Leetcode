//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  private:
    int range(int N)
    {
        if(N%4==1) return 1;
        else if(N%4==2) return N+1;
        else if(N%4==3) return 0;
        else return N;
    }
  public:
    int findXOR(int l, int r) {
        // complete the function here
        return range(l-1) ^ range(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends