class Solution {
    int winner(vector<bool>& person, int person_left, int n, int k, int ind) {

        if (person_left == 1) {

            for (int i = 0; i < n; i++) {
                if (person[i] == 0)
                    return i + 1;
            }
        }

        int kill = (k - 1) % person_left;

        while (kill--) {

            ind = (ind + 1) % n;
            while (person[ind] == 1) {
                ind = (ind + 1) % n;
            }
        }

        person[ind] = 1;

        while (person[ind] == 1) {
            ind = (ind + 1) % n;
        }

        return winner(person,person_left-1,n,k,ind);
    }

public:
    int findTheWinner(int n, int k) {
        vector<bool> person(n, 0);
        int person_left = n;
        int ind = 0;

        return winner(person, person_left, n, k, ind);
    }
};