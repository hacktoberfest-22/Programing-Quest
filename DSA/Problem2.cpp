// Check if a subarray with 0 sum exists or not

// We can easily solve this problem in linear time by using hashing. The idea is to use a set to check if a subarray with zero-sum is present in the given array or not. Traverse the array and maintain the sum of elements seen so far. If the sum is seen before (i.e., the sum exists in the set), return true as there exists at least one subarray with zero-sum that ends at the current index; otherwise, insert the sum into the set.

// The algorithm can be implemented as follows in C++, Java, and Python:

#include <iostream>
#include <unordered_set>
using namespace std;
 
// Function to check if subarray with zero-sum is present in a given array or not
bool hasZeroSumSubarray(int nums[], int n)
{
    // create an empty set to store the sum of elements of each
    // subarray `nums[0…i]`, where `0 <= i < n`
    unordered_set<int> set;
 
    // insert 0 into the set to handle the case when subarray with
    // zero-sum starts from index 0
    set.insert(0);
 
    int sum = 0;
 
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far
        sum += nums[i];
 
        // if the sum is seen before, we have found a subarray with zero-sum
        if (set.find(sum) != set.end()) {
            return true;
        }
        else {
            // insert sum so far into the set
            set.insert(sum);
        }
    }
 
    // we reach here when no subarray with zero-sum exists
    return false;
}
 
int main()
{
    int nums[] = { 4, 2, -3, -1, 0, 4 };
    int n = sizeof(nums)/sizeof(nums[0]);
 
    hasZeroSumSubarray(nums, n) ?
            cout << "Subarray exists":
            cout << "Subarray does not exist";
 
    return 0;
}
