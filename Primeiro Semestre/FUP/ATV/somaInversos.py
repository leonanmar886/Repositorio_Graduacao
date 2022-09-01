from re import I


n = int(input())
somaTermos = 0

if n <= 0:
    print("invalido")
else:
    for i in range(1, n+1): #laço que percorre até o numero n
        if i%2 == 0: #verifica se o número em questão é par
            somaTermos += 1/i #se for, o seu inverso é somado
    print(somaTermos)