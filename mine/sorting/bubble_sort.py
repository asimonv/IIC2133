# O(n^2), O(1)
def bubblesort(A):
    while True:
        stop = True
        for i in range(1, len(A)):
            if A[i-1] > A[i]:
                A[i], A[i-1] = A[i-1], A[i]
                stop = False
        if stop: break

    return A

A = [8, 5, 2, 6, 9, -1]
print(bubblesort(A))
