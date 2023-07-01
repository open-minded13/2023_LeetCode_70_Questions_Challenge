// Complexity Analysis
//
// Time Complexity: O(log(N))
//                  The binary search algorithm used in this solution has a time complexity of O(log n),
//                  where n is the size of the input array nums. In each iteration, the search range is halved,
//                  reducing the number of elements to search by half.
//                  This logarithmic behavior allows the algorithm to find the minimum element efficiently.
//
// Space Complexity: O(1)
//                   It uses a constant amount of extra space.
//                   The algorithm does not rely on any additional data structures
//                   whose space usage depends on the size of the input array.
//                   It only uses a few variables to store indices and perform comparisons,
//                   which require constant space regardless of the input size.

#include <iostream>
#include <vector>

using namespace std;

// Optimized Solution: Binary Search, which follows the divide and conquer approach.
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {

            // Compared to pivot = (left+right)/2,
            // pivot = left + (right-left)/2 is better because it avoids potential integer overflow.
            int pivot = left + (right - left) / 2;

            if (nums[pivot] > nums[right])
            {
                left = pivot + 1;
            }
            else
            {
                right = pivot;
            }
        }
        return nums[left];
    }
};

// Some commonly used functions in std::vector:
//
// push_back(value) - adds an element to the end of the vector.
// pop_back() - removes the last element from the vector.
// size() - returns the number of elements in the vector.
// empty() - returns true if the vector is empty, false otherwise.
// clear() - removes all elements from the vector.
// resize(size) - changes the size of the vector. If the new size is greater than the current size,
//                new elements are default-constructed. If the new size is less than the current size,
//                elements at the end of the vector are removed.
// reserve(capacity) - increases the capacity of the vector to at least the specified size,
//                     but does not change the size of the vector.
// shrink_to_fit() - reduces the capacity of the vector to fit its size.
// operator[](index) - returns a reference to the element at the given index.
// at(index) - returns a reference to the element at the given index,
//             and throws a std::out_of_range exception if the index is out of range.
// front() - returns a reference to the first element in the vector.
// back() - returns a reference to the last element in the vector.
// erase(iterator) - removes the element pointed to by the iterator from the vector.
// insert(iterator, value) - inserts an element with the given value at the position pointed to by the iterator.
// begin() - returns an iterator pointing to the first element in the vector.
// end() - returns an iterator pointing to one past the last element in the vector.
//
// Note that std::vector is a dynamic array that can resize itself automatically
// as elements are added or removed. It provides constant-time access to elements by their index,
// and is a very efficient data structure for adding and removing elements from the back of the array.

class Other_Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return divideAndConquer(nums, 0, nums.size() - 1);
    }

    int divideAndConquer(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }

        if (nums[left] < nums[right])
        {
            return nums[left];
        }

        int pivot = (left + right) / 2;

        return min(divideAndConquer(nums, left, pivot), divideAndConquer(nums, pivot + 1, right));
    }
};

int main()
{

    vector<int> nums1 = {3, 4, 5, 6, 2};
    Solution solution1;
    int result1 = solution1.findMin(nums1);
    cout << "Output 1: " << result1 << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    Solution solution2;
    int result2 = solution2.findMin(nums2);
    cout << "Output 2: " << result2 << endl;

    return 0;
}