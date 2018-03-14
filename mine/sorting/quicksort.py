# O(n), O(1)
def partition(A, p, q):
    wall = p
    pivot = A[q]

    for i in range(p, q):
        if A[i] < pivot:
            A[wall], A[i] = A[i], A[wall]
            wall += 1
    A[wall], A[q] = A[q], A[wall]
    return wall

# O(nlgn), O(1)
def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)

A = [8, 5, 2, 6, 9, -1]
quicksort(A, 0, len(A)-1)
print(A)
