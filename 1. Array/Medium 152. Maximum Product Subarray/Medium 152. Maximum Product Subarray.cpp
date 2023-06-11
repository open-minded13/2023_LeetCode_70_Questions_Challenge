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

// Optimized Solution: Kadane's Algo
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int product = 1;
        int maximum_product = INT32_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            product *= nums[i];
            maximum_product = max(maximum_product, product);
            if (product == 0)
            {
                product = 1;
            }
        }

        product = 1;
        // Note: it is size(nums)-1 instead of size(nums)
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            product *= nums[i];
            maximum_product = max(maximum_product, product);
            if (product == 0)
            {
                product = 1;
            }
        }

        return maximum_product;
    }
};

class Solution_using_Kadane_Algo
{
public:
    // The maxProduct function takes in a vector of integers called nums
    // as its argument and returns an integer value.
    int maxProduct(vector<int> &nums)
    {

        // Two integer variables maxi and prod are initialized.
        // maxi is initialized to the smallest possible integer value that
        // can be represented by INT_MIN macro defined in the limits.h header file.
        // prod is initialized to 1.
        int maxi = INT_MIN;
        int prod = 1;

        // A for loop is used to iterate through each element of the nums vector.
        for (int i = 0; i < nums.size(); i++)
        {
            // In each iteration, the value of prod is updated by multiplying it with the current element of nums
            prod *= nums[i];
            // The maxi value is updated by taking the maximum value between the current maxi and the prod value.
            maxi = max(prod, maxi);
            // If the current element of nums is 0, then the value of prod is reset to 1,
            // to start calculating the product of the next subarray.
            if (prod == 0)
            {
                prod = 1;
            }
        }

        // After the first loop is completed, prod is reset to 1,
        // to start iterating from the end of the nums vector.
        prod = 1;

        // To handle an odd number of minus signs in the subarray, we have to iterate from right to left again.
        // e.g., [-8, 5, 3, -1, -6] or [5, 4, -1, 7, 8]
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if (prod == 0)
            {
                prod = 1;
            }
        }
        return maxi;
    }
};

int main()
{
    Solution s;
    // Solution_using_Kadane_Algo s;

    // Test case 1: [-2,1,-3,4,-1,2,1,-5,4]
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = s.maxProduct(nums1);
    cout << "Maximum subarray sum of [-2,1,-3,4,-1,2,1,-5,4] is: " << result1 << endl;

    // Test case 2: [1]
    vector<int> nums2 = {1};
    int result2 = s.maxProduct(nums2);
    cout << "Maximum subarray sum of [1] is: " << result2 << endl;

    // Test case 3: [5,4,-1,7,8]
    vector<int> nums3 = {5, 4, -1, 7, 8};
    int result3 = s.maxProduct(nums3);
    cout << "Maximum subarray sum of [5,4,-1,7,8] is: " << result3 << endl;

    return 0;
}