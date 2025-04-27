def substituicoes_retroativas(n, U, d):
    x = [0.0 for _ in range(n)]
    x[n-1] = d[n-1] / U[n-1][n-1]
    
    for i in range(n-2, -1, -1):
        soma = 0.0
        for j in range(i+1, n):
            soma += U[i][j] * x[j]
        x[i] = (d[i] - soma) / U[i][i]
    
    return x

U = [
    [2.0, 3.0, 1.0],
    [0.0, 1.0, 4.0],
    [0.0, 0.0, 3.0]
]
d = [9.0, 7.0, 6.0]
n = 3

x = substituicoes_retroativas(n, U, d)
print("Solução x:", x)