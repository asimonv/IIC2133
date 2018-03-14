# O(n^2), O(1)
def insertion_sort(A):
    i = 1
    while i < len(A):
        j = i
        while j > 0 and A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            j -= 1
            print(A)
        print('')
        i += 1
    return A

A = [8, 5, 2, 6, 9]
print(insertion_sort(A))
