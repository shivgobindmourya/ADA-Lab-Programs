from typing import List, Tuple

def findKthLargest(nums: List[int], k: int) -> int:
    nums.sort(reverse=True)
    return nums[k - 1]


def findMinMax(nums: List[int]) -> Tuple[int, int]:
    min_val = nums[0]
    max_val = nums[0]

    for num in nums:
        if num < min_val:
            min_val = num
        if num > max_val:
            max_val = num

    return min_val, max_val


nums = [3, 2, 1, 5, 6, 4]

print(findKthLargest(nums, 2))
print(findMinMax(nums))