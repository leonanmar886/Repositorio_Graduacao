n = int(input())

if n < 1:
    print("invalido")
else:
    numDiv = 0
    somaPrimos = 0
    for j in range(1,n+1): #laço de repetição que analisa cada número até n
        for i in range(1,j+1): #laço de repetição que analisa cada número até j
            if  j % i == 0: # verificação se j é divisível por i
                numDiv += 1
        if numDiv == 2:# se durante o laço de repetição só houverem 2 números que sejam divisores de j, então ele 
                    #é um número primo, e será somado
            somaPrimos += j
        numDiv = 0 # aqui é preciso zerar o contador de divisão pois há outro laço de repetição 
    print(somaPrimos)