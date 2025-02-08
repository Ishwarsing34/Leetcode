class Solution {
    int winner(vector<bool>&person, int n, int k, int person_left, int ind)
    {//brute 0 n^2
        if(person_left == 1) {
            for(int i=0;i<n;i++){
                if(person[i] == 0) return i+1;
            }
        }

        int kill = (k-1)%person_left;//person_left ne div kela bcz n ne nhi kru shkt jar kela tr index wrong milnar
         while(kill--){
            ind = (ind + 1)%n;
            while(person[ind] == 1){

                ind = (ind+1)%n;
            
            }
         }

         person[ind] = 1;

         while(person[ind] == 1){
             ind = (ind + 1)%n;
         }

        return winner(person,n,k,person_left-1,ind);
    }
public:
    int findTheWinner(int n, int k) {
        vector<bool>person(n,0);
        int person_left = n;
        int ind = 0;
        return winner(person,n,k,person_left,ind);
    }
};