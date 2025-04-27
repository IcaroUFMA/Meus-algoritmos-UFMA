def sor(n, A, b, omega, Toler, IterMax):
    x = [0.0 for _ in range(n)]
    v = [0.0 for _ in range(n)]
    
    for i in range(n):
        r = 1 / A[i][i]
        for j in range(n):
            if i != j:
                A[i][j] = A[i][j] * r
        b[i] = b[i] * r
        x[i] = b[i]
    
    Iter = 0
    Erro = False
    
    while True:
        Iter += 1
        for i in range(n):
            Soma = 0.0
            for j in range(n):
                if i != j:
                    Soma += A[i][j] * x[j]
            v[i] = x[i]
            x[i] = (1 - omega) * x[i] + omega * (b[i] - Soma)
        
        Normal = 0.0
        Norma2 = 0.0
        for i in range(n):
            diff = abs(x[i] - v[i])
            if diff > Normal:
                Normal = diff
            if abs(x[i]) > Norma2:
                Norma2 = abs(x[i])
        
        DifMax = Normal / Norma2 if Norma2 != 0 else 0
        
        if DifMax < Toler or Iter >= IterMax:
            Erro = DifMax >= Toler
            break
    
    return x, Iter, Erro, DifMax

n = 3
A = [
    [10.0, 2.0, 1.0],
    [1.0, 5.0, 1.0],
    [2.0, 3.0, 10.0]
]
b = [7.0, -8.0, 6.0]
omega = 1.1  # Fator de relaxação

x, Iter, Erro, Epsilon = sor(n, A, b, omega, 1e-6, 1000)

print("Solução:", [round(val, 6) for val in x])
print("Iterações:", Iter)
print("Erro:", Erro)
print("Epsilon: {:.2e}".format(Epsilon))