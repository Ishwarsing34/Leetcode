class Solution {
    void mS(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;    // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

   int getPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    long long cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * (long long)arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

    int merge(vector<int>& nums, int low, int high) {
        long long cnt = 0;
        if (low >= high)
            return cnt;
        int mid = low + (high - low) / 2;
        cnt += merge(nums, low, mid);
        cnt += merge(nums, mid + 1, high);
        cnt += getPairs(nums, low, mid, high);
        mS(nums, low, mid, high);
        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {

        int n = nums.size();

        return merge(nums, 0, n - 1);
    }
};