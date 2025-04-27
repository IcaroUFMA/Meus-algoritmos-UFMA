def substituicoes_sucessivas_pivotal(n, L, c, Pivot):
    x = [0.0 for _ in range(n)]
    x[0] = c[Pivot[0]]
    
    for i in range(1, n):
        soma = 0.0
        for j in range(i):
            soma += L[i][j] * x[j]
        x[i] = c[Pivot[i]] - soma
    
    return x

n = 3
L = [
    [1.0, 0.0, 0.0],
    [0.5, 1.0, 0.0],
    [0.25, 0.3, 1.0]
]
c = [4.0, 5.0, 6.0]
Pivot = [2, 0, 1]

x = substituicoes_sucessivas_pivotal(n, L, c, Pivot)
print("Solução x:", x)