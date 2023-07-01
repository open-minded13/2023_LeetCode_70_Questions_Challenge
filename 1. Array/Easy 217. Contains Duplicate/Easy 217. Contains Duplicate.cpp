// Complexity
// Time complexity: O(N);
// Space Complexity: O(N);
// Both solutions can correctly determine whether there are duplicate elements,
// but the second solution is more concise and efficient,
// because it does not need to store redundant index information.
// The space complexity of the containsDuplicate function is O(n),
// where n is the number of elements in the nums vector.
// Inside the function, an unordered_set<int> called seen is created to store the elements
// that have been encountered so far. The size of this set will depend on
// the number of unique elements in the nums vector.
// In the worst case, when there are no duplicate elements in the nums vector,
// the size of the seen set will be equal to the number of elements in the nums vector.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// unordered map is a data structure that stores key-value pairs,
// where each key corresponds to a value, and keys cannot be duplicated.
// unordered map is internally implemented by a hash table,
// so the time complexity of lookup, insertion and deletion are all constant level.
// unordered map’s keys and values can be of any type,
// as long as a suitable hash function and equality comparison function are provided.
//
// unordered map:
//
// | Key | Value |
// |---|---|
// | 1 | a |
// | 2 | b |
// | 3 | c |
//
// Hash table:
//
// | Index | Key | Value |
// |----|---|---|
// | 0  |   |   |
// | 1  | 1 | a |
// | 2  | 2 | b |
// | 3  | 3 | c |
//
// Some common functions and methods in the unordered_set class:
// operator[] - returns a reference to the value associated with the given key.
//              If the key is not found, a new element with the given key is inserted and
//              a default-constructed value is returned.
//              e.g., unordered_map map;
//                    // Insert a new element with key "foo" and value 42
//                    map["foo"] = 42;
//                    cout << map["foo"] << std::endl;
// at(key) - returns a reference to the value associated with the given key.
//           If the key is not found, a std::out_of_range exception is thrown.
// insert({key, value}) - inserts a new element with the given key-value pair.
// erase(key) - removes the element with the given key, if it exists.
// clear() - removes all elements from the map.
// size() - returns the number of elements in the map.
// empty() - returns true if the map is empty, false otherwise.
// find(key) - searches the map for an element with the given key and
//             returns an iterator to the element if found,
//             otherwise returns an iterator to the end of the map.

class Other_Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) == map.end())
            {
                map[nums[i]] = i;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// unordered set is a data structure that stores unique elements,
// where each element cannot be duplicated.
// unordered set is also internally implemented by a hash table,
// so the time complexity of lookup, insertion and deletion are also constant level.
// unordered set’s elements can be of any type,
// as long as a suitable hash function and equality comparison function are provided.
//
// unordered set:
//
// | Element |
// |----|
// | a  |
// | b  |
// | c  |
//
// Hash table:
//
// | Index | Element |
// |----|----|
// | 0  |    |
// | 1  | a  |
// | 2  | b  |
// | 3  | c  |
//
// Some common functions and methods in the unordered_set class:
//
// insert(key) - adds a new element with the key key to the set if it doesn't already exist
// erase(key) - removes the element with the key key from the set if it exists
// clear() - removes all elements from the set
// size() - returns the number of elements in the set
// empty() - returns true if the set is empty, false otherwise
// find(key) - searches the set for an element with the key key and
//             returns an iterator to the element if found, otherwise returns an iterator to the end of the set

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            // You are right, for unordered set, .count() and .find() have the same functionality,
            // which is to determine whether an element exists in the set. However, they have different return types.
            //
            // .count() returns a value of type size_t, which is an unsigned integer,
            // indicating how many times an element appears in the set. For unordered set,
            // this number can only be 0 or 1, because there are no duplicate elements in the set.
            // But for other containers, such as vector or multiset, this number may be greater than 1,
            // because they can store duplicate elements.
            //
            // .find() returns an iterator, which is a pointer to an element in the set.
            // If it finds the element, it returns an iterator pointing to that element;
            // if it does not find it, it returns an iterator pointing to the end of the set.
            // Usually, we compare the return value of .find() with .end() to determine whether an element exists in the set.
            // If they are equal, it means that it did not find it; if they are not equal, it means that it found it.
            //
            // So, .count() and .find() can both be used to determine whether an element exists in the set,
            // but they may have different usages and efficiencies. Generally speaking, .count() is simpler than .find(), because it only needs to return an integer, not an iterator. But in some cases, .find() may be more useful than .count(), because it allows us to access the found element, not just know whether it exists or not.
            if (seen.count(nums[i]))
            {
                cout << seen.count(nums[i]) << endl;
                // An iterator is not a value, but a pointer.
                // A pointer is a variable that stores the address of another variable in memory.
                cout << *(seen.find(nums[i])) << endl;
                return true;
            }
            else
            {
                seen.insert(nums[i]);
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 6, 3, 3, 5};
    bool result = sol.containsDuplicate(nums);
    return 0;
}
