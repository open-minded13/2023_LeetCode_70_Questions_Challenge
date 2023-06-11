// https://leetcode.com/problems/sum-of-two-integers/description/

// Time complexity: O(log n);
// The time complexity of this code is O(log n),
// where n is the maximum number of bits in the binary representation of the input values a and b.
// In the recursion of getSum (), if (ua & ub) is equal 000...001,
// then it has to shift to the left "log base 2 to n" times to complete the calculation,
// which is also the depth of recursion.

// Space Complexity: O(1);
// The space complexity of the getSum function is O(1)
// because the function only uses a fixed amount of memory that does not depend on the size of the input.

#include <iostream>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        unsigned ua = a, ub = b;
        if (ub == 0)
        {
            return ua;
        }
        else
        {
            return getSum(ua ^ ub, (ua & ub) << 1);
        }
    }
};

class Bad_Solution
{
public:
    int getSum(int a, int b)
    {
        // The following code will make runtime errors because left shifting
        // a negative value is undefined behavior according to the C++ standard.
        // For example, if 011 (= 3) is the biggest signed value and 101 (= -3) is the smallest value.
        // When we want to add the two numbers using bitwise manipulation,
        // the problem generates as shown below:
        //
        // Level 1:
        // a = 011
        // b = 101
        //
        // a ^ b = 110
        // (a & b) << 1= 010
        //
        // Level 2:
        // a = 110
        // b = 010
        //
        // a ^ b = 100
        // (a & b)  << 1 = 100
        //
        // Level 3:
        // a ^ b= 000
        // (a & b) << 1 = 1000
        // Note: The problem occurs here because we don't define how to shift left 100.
        if (b == 0)
        {
            return a;
        }
        else
        {
            return getSum(a ^ b, (a & b) << 1);
        }
    }
};

int main()
{
    int a = 3;
    int b = -3;

    Solution solution;
    int result = solution.getSum(a, b);
    cout << result << endl;
}
