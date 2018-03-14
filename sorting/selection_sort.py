# O(n^2), O(1)
def selection_sort(A):
    for i in range(len(A)):
        #   find min
        min = i
        for j in range(i+1, len(A)):
            min = j if A[j] < A[min] else min

        if min != i:
            A[min], A[i] = A[i], A[min]

    return A

A = [8, 5, 2, 6, 9]
print(selection_sort(A))
