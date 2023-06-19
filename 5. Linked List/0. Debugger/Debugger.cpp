// Complexity Analysis
//
// Time Complexity: O(n), where n is the size of the nums vector,
//                  because it uses two for loops to iterate over the vector,
//                  but both loops iterate over all elements of the vector, which takes O(n) time in total.
//
// Space Complexity: O(1),  because it uses a constant amount of extra space to
//                   store two integers (product and maximum_product) throughout the execution of the function,
//                   regardless of the size of the input nums vector.

#include <iostream>
#include <vector>
// It defines INT_MAX and INT_MIN.
#include <limits.h>

using namespace std;

int main()
{
    vector<int> nums = {3, 4, 0, 1, 2};
    int rotated_index = 2;

    int rotation = rotated_index % nums.size();

    vector<int> rotated_nums(nums.size());
    copy(nums.begin() + rotation, nums.end(), rotated_nums.begin());
    copy(nums.begin(), nums.begin() + rotation, rotated_nums.end() - rotated_index);

    // Print the rotated vector
    for (int num : rotated_nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}