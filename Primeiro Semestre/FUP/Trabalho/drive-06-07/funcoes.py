import os

matrizPrincipal = []
matrizEstilos = []

#cadastro das peças no arquivo e organização do arquivo em listas
def AdcArquivo(itemSalvo):
    with open('dados.txt', 'a') as arquivo:
        arquivo.writelines(str(itemSalvo) + '\n')

#leitura de dados do arquivo      
def LerAquivo():
    with open('dados.txt', 'r') as arquivo:
        dados = arquivo.readlines()
    for i in range(len(dados)):
        string = dados[i].split('|')
        string.pop()
        matrizPrincipal.append(string)

def BuscarUltimoId(matrizOriginal):
    LerAquivo()
    if len(matrizOriginal) == 0:
        id = 0 #se não houverem roupas, o id é 0
    else:
        id = matrizOriginal[len(matrizOriginal) - 1][0] #retorna o id da ultima roupa
    return id

#listar peças do guarda-roupa
#as partes comentadas com ''' são partes que necessitam do id, que ainda não temos
def ListarPecas(matrizOriginal): 
    matrizOriginal.clear() #limpa a matriz pra evitar duplicar informações
    LerAquivo()
    if len(matrizOriginal) != 0:
        filtro = int(input('-----------------------------------------------\nVocê deseja listar peças por:\n-----------------------------------------------\n1.id\n2.tipo\n3.descrição\n4.tamanho\n5.padrão\n6.cor\n7.data de aquisição\n8.situação\n9.preço\n10.para "abrir" seu guarda-roupa.\n-----------------------------------------------\n'))
        if filtro == 1: 
            filtroEspecifico = input('qual id você deseja? ')
        elif filtro == 2:
            filtroEspecifico = input('qual tipo você deseja? ')
        elif filtro == 3:
            filtroEspecifico = input('qual descrição você deseja? ')
        elif filtro == 4:
            filtroEspecifico = input('qual tamanho você deseja? ')
        elif filtro == 5:
            filtroEspecifico = input('qual padrão você deseja? ')
        elif filtro == 6:
            filtroEspecifico = input('qual cor você deseja? ')
        elif filtro == 7:
            filtroEspecifico = input('qual data de aquisição você deseja? ')
        elif filtro == 8:
            filtroEspecifico = input('qual situação você deseja? ')
        elif filtro == 9:
            filtroEspecifico = input('qual preço você deseja? ')

        if filtro == 1:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][0] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 2:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][1] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 3:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][2] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 4:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][3] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 5:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][4] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 6:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][5] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 7:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][6] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 8:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][7] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 9:
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][8] == filtroEspecifico: 
                    print(ExibirFormatado(matrizOriginal[i]))
        elif filtro == 10:
            for i in range(len(matrizOriginal)):
                print(ExibirFormatado(matrizOriginal[i]))
        else:
            print('o filtro desejado não consta no seu guarda-roupa.')

def CadastrarRoupa(matrizOriginal):
    listaTipos = ['o tipo(calçado/inferior/superior)', 'a descrição','o tamanho(P/M/G)','o padrão(masculino/feminino/unissex)','a cor principal','a data de aquisição(dia/mês/ano)','a situação(ficar/venda/doação)','o preço (deixar em branco caso não seja para venda.)', 'o estilo.']
    qtdItem = int(input('Quantas peças você deseja adicionar ao guarda-roupa? '))
    for i in range(qtdItem): 
        stringAux = ''
        id = BuscarUltimoId(matrizOriginal) #as próximas duas linhas adicionam automaticamente o id da peça inserida
        id = int(id)
        stringAux = stringAux + str(id + 1) + '|'
        print(f'Insira os dados da {i+1}ª peça: ')
        for j in range(9):
            adiciona = input(f'Qual {listaTipos[j]} da peça? ')
            stringAux = stringAux + adiciona + '|'
        AdcArquivo(stringAux)
        matrizOriginal.append(stringAux) 
    return matrizOriginal

def RemoverRoupa(matrizOriginal):
    if len(matrizOriginal) != 0:
        matrizOriginal.clear() #limpa a matriz para revitar a duplicação ao ler na função abaixo
        LerAquivo() #lê o arquivo e adiciona os dados a matrizOriginal
        for i in range(len(matrizOriginal)): #printa os elementos da matriz (roupas e suas características) para o usuário visualizar e escolher melhor
            print('Linha',i,'-',matrizOriginal[i])
        linharemov = int(input('Qual é o número da linha que você deseja remover? ')) #pega o índice (da matriz) da linha a ser removida
        while linharemov >= len(matrizOriginal) or linharemov < 0: #trata erros(entradas negativas ou maiores do que o tamanho da lista)
            linharemov = int(input('Linha digitada inválida. Qual é o número da linha que você deseja remover? '))
        with open('dados.txt', 'r') as arquivo: #abre arquivo e armazena os dados do arquivo na varáviel 'dados' para sobescrever o arquivo sem a linha que será removida
            dados = arquivo.readlines()
        with open('dados.txt','w') as arquivo: #abre o arquivo no modo de escrita para sobescrever os dados anteriores sem a linha a ser removida utilizando a variável do tipo lista 'dados' 
            for i in range(0,len(dados)): #percorre os itens em dados, que são listas cujo são armazenadas apenas uma string
                if i != linharemov: #caso o indice i seja igual o indice indicado para remoção, a função não escreverá a linha atrelada a 'linharemov'
                    arquivo.write(dados[i])
        del matrizOriginal[linharemov] #retira a linha atrelada a variável de remoção da matriz e a retorna atualizada
        return matrizOriginal
    else:
        print('Guarda-Roupas não possui elementos para remover')
    
def ExibirFormatado(lista):
    if lista[8] != '': #se a roupa estiver a venda, a mensagem a ser exibida é diferente, e deve conter o preço da peça.
        mensagemFormatada = '• A peça de id {0} é uma/um {1} de tamanho {2}, do padrão {3}, com {4} como a cor principal, e possui o estilo {5}.\n  Ela foi adquirida no dia {6} e atualmente está para a venda no valor de R${7}.'.format(lista[0], lista[2], lista[3], lista[4], lista[5], lista[9], lista[6], lista[8])
    else: #se a roupa não estiver a venda, deve ser exibida a situação da peça
        mensagemFormatada = '• A peça de id {0} é uma/um {1} de tamanho {2}, do padrão {3}, com {4} como a cor principal, e possui o estilo {5}.\n  Ela foi adquirida no dia {6} e atualmente está com a situação de {7}.'.format(lista[0], lista[2], lista[3], lista[4], lista[5], lista[9], lista[6], lista[6])
    return mensagemFormatada

def AlterarRoupa(matrizOriginal):
    listaTipos = ['o tipo(calçado/inferior/superior)', 'a descrição','o tamanho(P/M/G)','o padrão(masculino/feminino/unissex)','a cor principal','a data de aquisição(dia/mês/ano)','a situação(ficar/venda/doação)','o preço (deixar em branco caso não seja para venda.)', 'o estilo.']
    if len(matrizOriginal) != 0:
        contador = 0
        matrizOriginal.clear() #limpa a matriz para revitar a duplicação ao ler na função abaixo
        LerAquivo() #lê o arquivo e adiciona os dados a matrizOriginal
        for i in range(len(matrizOriginal)): #printa os elementos da matriz (roupas e suas características) para o usuário visualizar e escolher melhor
            print('Linha',i,'-',matrizOriginal[i])
        linha_a_ser_alterada = int(input('Digite a linha que você deseja alterar? ')) #recolhe o indice da linha a ser alterada
        while linha_a_ser_alterada >= len(matrizOriginal) or linha_a_ser_alterada < 0: #trata erros(entradas negativas ou maiores do que o tamanho da lista)
            linha_a_ser_alterada = int(input('Linha digitada inválida. Qual é o número da linha que você deseja alterar? '))
        
        with open('dados.txt','r') as arquivo: #recolhe os dados do arquvo na varíavel dados
            dados = arquivo.readlines()
        for i in range(0,len(listaTipos)): #printa as características da peça escolhida para ser alterada (printa as características que estão na linha da peça dentro da matriz.)
            contador = contador + 1 #auxilia na contagem para facilitar a leitura e inserção de dados do usuário
            print('Característica','-',contador,'-',listaTipos[i],'-',matrizOriginal[linha_a_ser_alterada][contador]) #printa de uma forma legível para o usuário
            
        caracteristica_a_ser_alterada = int(input('Digite o indice característica que você deseja alterar: ')) #recolhe o indice (coluna) em que a característica está armazenada dentro da linha
        while caracteristica_a_ser_alterada >= len(matrizOriginal[0]) or caracteristica_a_ser_alterada <= 0: #trata erros(entradas negativas ou maiores do que o tamanho da lista)
            caracteristica_a_ser_alterada = int(input('Característica digitada inválida. Digite a linha da característica que você deseja alterar: '))

        nova_caracteristica = input('Digite a alteração que você deseja implementar: ') #recebe do usuário nova característica para substituir a antiga.

        matrizOriginal[linha_a_ser_alterada][caracteristica_a_ser_alterada] = nova_caracteristica #substitui o elemento atrelado a linha e coluna de remoção inseridas pelo usuário anteriormente (linha_a_ser_alterada e coluna_a_ser alterada) pela nova variável (nova_característica).
        matriz_alterar = [] #matriz para auxiliar a inserção dos novos dados (matriz com o elemento alterado) no arquivo
        for i in range(len(dados)): #transfere os dados que estão como uma única string em dados, em vários elementos (strings) separados para efetuar a alteração
            string = dados[i].split('|')
            string.pop() #retira o /n da linha
            matriz_alterar.append(string) #adiciona as novas strings a matriz_alterar que serve de auxiliar
        matriz_alterar[linha_a_ser_alterada][caracteristica_a_ser_alterada] = nova_caracteristica # substitui o elemento atrelado as variáveis 'linha_a_ser_alterada' e 'caracteristica_a_ser_alterada' pela variável inserida 'nova_caracteristica'(todas strings)
        linhaAux = [] #linha auxiliar para converter as várias strings da matriz_alterar em uma string só no formato correto para voltar ao arquivo os dados alterados
        for i in range(len(matriz_alterar)): #percorre as linhas de matriz_alterar
            strAux = '' #cria uma string para adicionar os elementos de matriz_alterar em uma só string e depois adicionala a uma listaaux
            for j in range(len(matriz_alterar[0])): #percorre as colunas (informações das características das linhas)
                strAux = strAux + matriz_alterar[i][j] + '|' #adiciona as caracteristicas armazenadas em matriz_alterar em uma unica string utilizando o | para separar no arquivo
            strAux = strAux + '\n' #adiciona a quebra de linha para formatar corretamente no arquivo
            linhaAux.append(strAux) #adiciona as novas strings a linha auxiliar que será percorrida para sobescrever no arquivo
        with open('dados.txt','w') as arquivo: #abre o arquivo em formato de escrita
            for i in range(len(linhaAux)): #percorre os elementos da listauxiliar que contem as strings completas com as caracterísitcas de cada roupa
                arquivo.write(linhaAux[i]) #escreve as strings completas no arquivo
        return matrizOriginal #retorna a matriz com os itens alterados.
    else:
        print('Guarda-Roupas não possui elementos para alterar')
    
def Doar(matrizOriginal):
    matrizOriginal.clear()
    LerAquivo()
    listaID = ListarDoacao(matrizOriginal)
    for i in listaID:
        for j in range(len(matrizOriginal)):
            if i == matrizOriginal[j][0]:
                print(matrizOriginal[j])
    return matrizOriginal
    




#listar peças de roupa doadas
def ListarDoacao(matrizOriginal):
    listaId = [] #lista que vai receber o id das peças que estão para doacao
    for i in range(len(matrizOriginal)):
        if matrizOriginal[i][7] == 'doar':
            listaId.append(matrizOriginal[i][0]) #se a roupa estiver para doação, o id dela vai para essa lista.
    return listaId #retorna a lista de ids.

def LimparTerminal():
    os.system('cls' if os.name == 'nt' else 'clear') #codigo para limpar o terminal.

#cadastrar um novo estilo de roupa
def CadastrarEstilo(matrizEstilos):
    listaAux = []
    novoEstilo = input('Qual é o nome do seu novo estilo? ')
    id = len(matrizEstilos) + 1 # pega o tamanho da lista de estilos, e soma 1
    listaAux.append(id)
    listaAux.append(novoEstilo)
    matrizEstilos.append(listaAux)

#chamar a função que o usuário deseja
def ChamarFuncao(id):
    if id == 1:
        ListarPecas(matrizPrincipal)
    elif id == 2:
        CadastrarRoupa(matrizPrincipal)
        LimparTerminal()
    elif id == 3:
        AlterarRoupa(matrizPrincipal)
    elif id == 4:
        RemoverRoupa(matrizPrincipal)
    elif id == 5:
        Doar(matrizPrincipal)
    ChamarFuncao(MostrarMenu()) #no final essa função é chamada para retornar para o menu

#def BuscarPecas(matrizOriginal):

def MostrarMenu():
    #menu padrão do programa
    mensagemTerminal = "-----------------------------------------------\nGUARDA-ROUPA PESSOAL\n----------------------------------------------- \nSeja bem-vindo(a) ao seu guarda-roupa pessoal.\nO que você deseja fazer?\n1.Listar peças.\n2.Cadastrar nova roupa.\n3.Alterar peças.\n4.Remover Peças.\n5.Cadastrar nova roupa.\n-----------------------------------------------\n"
    #variável que armazena o que o usuário que fazer
    funcaoDesejada = int(input(mensagemTerminal))
    return funcaoDesejada