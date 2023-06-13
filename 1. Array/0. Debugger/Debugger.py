class Solution:
    def threeSum(self, nums):
        positive_dict = defaultdict(int)
        negative_dict = defaultdict(int)
        zeros = 0

        for num in nums:
            if num > 0:
                positive_dict[num] += 1
            elif num < 0:
                negative_dict[num] += 1
            else:
                zeros += 1

        result = []

        # [0, 0, 0]
        if zeros >= 3:
            result.append([0, 0, 0])

        # [0, positive, negative]
        if zeros >= 1:
            for num in positive_dict:
                if -num in negative_dict:
                    result.append([-num, 0, num])

        # [positive_1, positive_2, negative] and [negative_1, negative_2, positive]
        for dict1, dict2 in (
            (positive_dict, negative_dict),
            (negative_dict, positive_dict),
        ):
            dict1_list = list(dict1.items())
            for index, (num_1, count_of_num_1) in enumerate(dict1_list):
                for num_2, count_of_num_2 in dict1_list[index:]:
                    if num_1 == num_2 and count_of_num_1 > 1:
                        if -(2 * num_1) in dict2:
                            result.append([num_1, num_1, -2 * num_1])
                    if num_1 != num_2:
                        if -(num_1 + num_2) in dict2:
                            result.append([num_1, num_2, -(num_1 + num_2)])

        return result
