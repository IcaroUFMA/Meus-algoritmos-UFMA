def jacobi(n, A, b, tolerancia=1e-5, max_iter=50):
    x = b.copy()
    
    for iteracao in range(1, max_iter+1):
        x_novo = x.copy()
        
        for i in range(n):
            soma = 0
            for j in range(n):
                if j != i:
                    soma += A[i][j] * x[j]
            
            x_novo[i] = (b[i] - soma) / A[i][i]
        
        erro = max(abs(x_novo[i] - x[i]) for i in range(n))
        x = x_novo
        
        if erro < tolerancia:
            break
    
    return x, iteracao, erro  

A = [
    [10, 3, -2],
    [2, 8, -1],
    [1, 1, 5]
]
b = [57, 20, -4]
n = 3

solucao, num_iter, epsilon = jacobi(n, A, b)

print("Solução encontrada:", [round(x, 4) for x in solucao])
print("Número de iterações:", num_iter)
print("Diferença final (epsilon): {:.2e}".format(epsilon))