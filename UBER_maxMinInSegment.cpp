// Given an array of integers arr, and an integer K, your task is the following:
// 1 - Find theminimum value in each of the contiguous subarray of size K
// 2 - Return the maximum value among these minimums

// SAURABH - Very good question and as against the initial thought of priority queue, 
// it cannot be solved by priority queue as we cannot delete the elements from mid of the priority queue

int maxMinInSegments(vector<int> arr, int m){
    multiset<int> s;
    int ans = 0, n = arr.size();
    for(int i=0; i<m; i++)
        s.insert(arr[i]);
    ans = max(ans, *s.begin());
    for(int i=m; i<n; i++){
        s.insert(arr[i]);
        s.erase(s.find(arr[i-m]));
        ans = max(ans, *s.begin());
    }
    return ans;
}
