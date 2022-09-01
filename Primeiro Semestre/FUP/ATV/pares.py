n = int(input())
somaPares = 0

if n <= 0:
    print("invalido")
else:
    for i in range(1, n+1): #loop que percorre todos os números até n
        if i%2 == 0: #aqui é verificado se o número i é par
            somaPares += i #se ele for par, é somado

    print(somaPares)