import math

def cholesky(n, A):
    L = [[0.0 for _ in range(n)] for _ in range(n)]
    Det = 1
    Erro = False
    
    for j in range(n):
        Soma = 0.0
        for k in range(j):
            Soma += L[j][k] ** 2
        
        t = A[j][j] - Soma
        Det *= t
        Erro = t <= 0
        
        if Erro:
            print("ERRO: A matriz não é definida positiva")
            return L, Det, Erro
        
        L[j][j] = math.sqrt(t)
        r = 1 / L[j][j]
        
        for i in range(j + 1, n):
            Soma = 0.0
            for k in range(j):
                Soma += L[i][k] * L[j][k]
            
            L[i][j] = (A[i][j] - Soma) * r
    
    return L, Det, Erro

n = 3
A = [
    [4.0, 12.0, -16.0],
    [12.0, 37.0, -43.0],
    [-16.0, -43.0, 98.0]
]
# matriz não positiva: [1.0, 2.0, 3.0],
#                      [2.0, 4.0, 5.0],
#                      [3.0, 5.0, 6.0]

L, Det, Erro = cholesky(n, A)

if not Erro:
    for linha in L:
        print(linha)
    print("Determinante:", Det)