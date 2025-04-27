def lu_pivotacao_parcial(A):
    n = len(A)
    
    L = [[0.0 for _ in range(n)] for _ in range(n)]
    U = [linha[:] for linha in A]
    P = [[1.0 if i == j else 0.0 for j in range(n)] for i in range(n)]
    
    for k in range(n - 1):
        max_linha = k
        maior_valor = abs(U[k][k])
        
        for i in range(k + 1, n):
            if abs(U[i][k]) > maior_valor:
                maior_valor = abs(U[i][k])
                max_linha = i
        
        if max_linha != k:
            U[k], U[max_linha] = U[max_linha], U[k]
            P[k], P[max_linha] = P[max_linha], P[k]
            
            for j in range(k):
                L[k][j], L[max_linha][j] = L[max_linha][j], L[k][j]
        
        for i in range(k + 1, n):
            L[i][k] = U[i][k] / U[k][k]
            
            for j in range(k, n):
                U[i][j] -= L[i][k] * U[k][j]
    
    for i in range(n):
        L[i][i] = 1.0
    
    return P, L, U

A = [
    [1.0, -3.0, 2.0],
    [-2.0, 8.0, -1.0],
    [4.0, -6.0, 5.0]
]

P, L, U = lu_pivotacao_parcial(A)

print("Matriz P:")
for linha in P:
    print(linha)

print("\nMatriz L:")
for linha in L:
    print(linha)

print("\nMatriz U:")
for linha in U:
    print(linha)