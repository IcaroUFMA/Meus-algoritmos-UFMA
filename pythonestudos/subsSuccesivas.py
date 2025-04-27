def substituicoes_sucessivas(n, L, c):
    vetorSolucao = [0.0 for _ in range(n)]
    vetorSolucao[0] = c[0] / L[0][0]
    
    for i in range(1, n):
        soma = 0.0
        for j in range(i):
            soma += L[i][j] * vetorSolucao[j]
        vetorSolucao[i] = (c[i] - soma) / L[i][i]
    
    return vetorSolucao

L = [
    [2.0, 0.0, 0.0, 0.0],
    [3.0, 5.0, 0.0, 0.0],
    [1.0, -6.0, 8.0, 0.0],
    [-1.0, 4.0, -3.0, 9.0]
]
c = [4.0, 1.0, 48.0, 6.0]
n = 4

vetorSolucao = substituicoes_sucessivas(n, L, c)
print("Solução vetorSolucao:", vetorSolucao)