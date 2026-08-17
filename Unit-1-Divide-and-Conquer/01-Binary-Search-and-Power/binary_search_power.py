from typing import List


def search(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


def myPow(x: float, n: int) -> float:
    if n == 0:
        return 1.0

    if n < 0:
        x = 1 / x
        n = -n

    result = 1.0

    while n > 0:
        if n % 2 == 1:
            result *= x

        x *= x
        n //= 2

    return result

def main():
    print("Binary Search")
    nums = list(map(int, input("Enter sorted array elements: ").split()))
    target = int(input("Enter target: "))

    index = search(nums, target)

    if index != -1:
        print("Target found at index:", index)
    else:
        print("Target not found")

    print("\nFast Power")
    x = float(input("Enter base: "))
    n = int(input("Enter exponent: "))

    result = myPow(x, n)

    print("Result:", result)


if __name__ == "__main__":
    main()