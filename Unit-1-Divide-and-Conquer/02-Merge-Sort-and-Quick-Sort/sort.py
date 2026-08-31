class Sort:
    def merge_sort(self, arr: list[int]) -> list[int]:
        if len(arr) <= 1:
            return arr

        mid = len(arr) // 2

        left = self.merge_sort(arr[:mid])
        right = self.merge_sort(arr[mid:])

        result = []
        i = 0
        j = 0

        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1

        result.extend(left[i:])
        result.extend(right[j:])

        return result

    def quick_sort(self, arr: list[int]) -> list[int]:
        if len(arr) <= 1:
            return arr

        pivot = arr[-1]

        left = []
        right = []

        for i in range(len(arr) - 1):
            if arr[i] <= pivot:
                left.append(arr[i])
            else:
                right.append(arr[i])

        return self.quick_sort(left) + [pivot] + self.quick_sort(right)


# Example
arr = [5, 2, 8, 1, 9, 3]

sorter = Sort()

print("Original:", arr)
print("Merge Sort:", sorter.merge_sort(arr))
print("Quick Sort:", sorter.quick_sort(arr))