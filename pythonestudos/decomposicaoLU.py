def decomposicao_lu(n, A):
    Pivot = [i for i in range(n)]
    Det = 1
    
    for j in range(n - 1):
        p = j
        Amax = abs(A[j][j])
        
        for k in range(j + 1, n):
            if abs(A[k][j]) > Amax:
                Amax = abs(A[k][j])
                p = k
        
        if p != j:
            A[j], A[p] = A[p], A[j]
            Pivot[j], Pivot[p] = Pivot[p], Pivot[j]
            Det = -Det
        
        Det *= A[j][j]
        
        if abs(A[j][j]) != 0:
            r = 1 / A[j][j]
            
            for i in range(j + 1, n):
                m = A[i][j] * r
                A[i][j] = m
                
                for k in range(j + 1, n):
                    A[i][k] -= m * A[j][k]
    
    Det *= A[n-1][n-1]
    
    return A, Det, Pivot

n = 3
A = [
    [1.0, 2.0, 3.0],
    [4.0, 5.0, 6.0],
    [7.0, 8.0, 9.0]
]

A, Det, Pivot = decomposicao_lu(n, A)

print("Matriz decomposta:")
for linha in A:
    print(linha)
print("Determinante:", Det)
print("Vetor de pivôs:", Pivot)