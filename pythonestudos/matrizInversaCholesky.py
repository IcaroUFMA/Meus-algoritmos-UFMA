import math

def eh_simetrica(A, n):
    for i in range(n):
        for j in range(i+1, n):
            if A[i][j] != A[j][i]:
                return False
    return True

def cholesky(n, A):
    if not eh_simetrica(A, n):
        return None, None, True
    
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
            print("Matriz não é definida positiva")
            return None, None, True
        
        L[j][j] = math.sqrt(t)
        r = 1 / L[j][j]
        
        for i in range(j+1, n):
            Soma = 0.0
            for k in range(j):
                Soma += L[i][k] * L[j][k]
            L[i][j] = (A[i][j] - Soma) * r
    
    return L, Det, False

def resolver_sistema_triangular_inferior(n, L, b):
    x = [0.0 for _ in range(n)]
    for i in range(n):
        Soma = 0.0
        for j in range(i):
            Soma += L[i][j] * x[j]
        x[i] = (b[i] - Soma) / L[i][i]
    return x

def resolver_sistema_triangular_superior(n, Lt, b):
    x = [0.0 for _ in range(n)]
    for i in range(n-1, -1, -1):
        Soma = 0.0
        for j in range(i+1, n):
            Soma += Lt[i][j] * x[j]
        x[i] = (b[i] - Soma) / Lt[i][i]
    return x

def inversa_por_cholesky(n, A):
    if not eh_simetrica(A, n):
        print("Matriz não é simétrica")
        return None
    
    L, Det, Erro = cholesky(n, A)
    if Erro:
        return None
    
    Lt = [[L[j][i] for j in range(n)] for i in range(n)]

    inversa = [[0.0 for _ in range(n)] for _ in range(n)]
    identidade = [[0.0 for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        identidade[i][i] = 1.0
    
    for col in range(n):
        b = [identidade[i][col] for i in range(n)]
        y = resolver_sistema_triangular_inferior(n, L, b)
        x = resolver_sistema_triangular_superior(n, Lt, y)
        
        for i in range(n):
            inversa[i][col] = x[i]
    
    return inversa

n = 3
A = [
    [4, -6, 2],
    [-6, 10, -5],
    [2, -5, 30]
]

print("Matriz original:")
for linha in A:
    print(linha)

inversa = inversa_por_cholesky(n, A)

if inversa is not None:
    print("\nMatriz inversa:")
    for linha in inversa:
        print([round(x, 4) for x in linha])
