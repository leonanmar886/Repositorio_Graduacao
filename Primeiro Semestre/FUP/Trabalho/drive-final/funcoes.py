import linecache
import os
import datetime
from pickle import TRUE
'''Variáveis globais que serão utilizadas ao longo do código. '''
matrizPrincipal = []
matrizEstilos = []
matrizDoacao = []
matrizVenda = []
matrizAcessos = []
'''Variáveis que são strings contendo as restrições que o usuário terá ao cadastrar uma peça, para evitar informações avulsas e erros no funcio
namento do programa '''
listatipo = ['CALÇADO','INFERIOR','SUPERIOR']   
listatamanho = ['P','M','G']
listapadrao = ['MASCULINO','FEMININO','UNISSEX']
listasituacao = ['VENDER','FICAR','DOAR']
#cadastro das peças no arquivo e organização do arquivo em listas
#Essa função será utilizada ao adicionar alguma peça com o conjunto de informações a um arquivo ao longo do programa.
def AdcArquivo(itemSalvo,nomeArquivo):
    with open(nomeArquivo, 'a') as arquivo:
        arquivo.writelines(str(itemSalvo) + '\n')

#leitura de dados do arquivo      
'''Essa função é uma das bases do funcionamento da lógica do código, pois estamos trabalhando simultaneamente com matrizes e arquivos contendo
as informações sobre as peças, por isso, essa função é fundamental, já uqe no início de outras funções a utilizamos para atualizar as informações das
matrizes baseando-se no arquivo atualizado. Facilitando a segurança das informações e a manipulação de dados'''
def LerArquivo(matrizDesejada,nomeArquivo): #recebe a matriz que receberá os dados do arquivo, e o nome do arquivo que receberá os dados do arquivo.
    with open(nomeArquivo, 'r') as arquivo:
        dados = arquivo.readlines() #Armazenamento das informações do arquivo na variável.
    for i in range(len(dados)):
        string = dados[i].split('|') #Organização dos dados que estão organizados em 'strings' e separados pelo '|' em matrizes com os elementos
        if len(string) > 1:          #de forma organizada, característica por caracterísitca, em que cada linha da matriz é uma peça de roupa  
            string.pop()       #elimina o \n      # e as colunas são os atributos dessa peça
        else:
            string = string
        matrizDesejada.append(string) #adiciona os elementos do arquivo a matriz passada como parametro
    return matrizDesejada #retorna a matriz com os dados atualizados

'''Busca o último ID do arquivo de peças cadastradas e se baseia pelo último para cadastrar o ID da nova peça a ser inserida.'''
def BuscarUltimoId(matrizOriginal):
    LerArquivo(matrizPrincipal,'dados.txt') #leitura e atualização de dados nas matrizes.
    LerArquivo(matrizDoacao,'doacao.txt')
    LerArquivo(matrizVenda,'venda.txt')
    if len(matrizOriginal) == 0:
        id = 0 #se não houverem roupas, o id é 0
    else: #pega o ultimo ID cadastrado no guarda-roupa
        id = matrizOriginal[len(matrizOriginal) - 1][0]
    return id #retorna no id

'''Função que cadastra novas roupas e pede as informações corretas e formatadas para o usuário.'''
def CadastrarRoupa(matrizOriginal):
    print('-'*47 + '\n' + 'MENU --> CADASTRAR NOVAS PEÇAS\n' + '-'*47) #Printa para ficar bonito
    #Lista de características que precisam inseridas ao cadastrar uma nova peça. Para facilitar a formatação e dimiuir o tamanho do código
    #A mensagem será acessada por um for.
    listaCaracteristicas = ['o tipo(calçado/inferior/superior)', 'a descrição','o tamanho(P/M/G)','o padrão(masculino/feminino/unissex)','a cor principal','a data de aquisição(dia/mês/ano)','a situação(ficar/vender/doar)','o preço (deixar em branco caso não seja para venda.)', 'o estilo']
    #Não permite a inserção de uma string para o número de peças a serem inseridas, por ser um número inteiro, esse tratamento é necessário
    #para não bugar o código caso o usuário insira uma entrada inválida.
    while True:
        try: #tenta converter a entrada em inteiro, se conseguir, o laço é quebrado e o código continua, se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
            qtdItem = int(input('Quantas peças você deseja adicionar ao guarda-roupa? '))
            break #se conseguir, o laço é quebrado e o código continua
        except: #se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
            print('Quantidade de peças deve ser um número inteiro.')

    for i in range(qtdItem): #Vai percorrer a quantidade itens a serem adicionadas e fazer o processo de acrescentar informações a cada uma delas.
        stringAux = '' #adiciona em forma de arquivo, para inserir no arquivo
        id = BuscarUltimoId(matrizOriginal) #as próximas duas linhas adicionam automaticamente o id da peça inserida
        id = int(id)
        stringAux = stringAux + str(id + 1) + '|'
        print(f'Insira os dados da {i+1}ª peça: ') #Mensagem para mostrar ao usuário qual peça esta sendo cadastrada
        for j in range(9):
            adiciona = input(f'Qual {listaCaracteristicas[j]} da peça? ') #Percorre a lista de características e insere a mensagem correta e formatada de acordo com a característica a ser inserida
            while j == 0 and adiciona.upper() not in listatipo: #Se a característica pedida for um tipo e o tipo inserido não está de acordo com o padrão declarado em listatipo, o programa pede novamente.
                adiciona = input(f'Entrada inválida. Qual {listaCaracteristicas[j]} da peça? ')
            while j == 2 and adiciona.upper() not in listatamanho: #Se a característica pedida for um tamanho e o tamanho inserido não está de acordo com o padrão declarado em listatamanho, o programa pede novamente.
                adiciona = input(f'Entrada inválida. Qual {listaCaracteristicas[j]} da peça? ') 
            while j == 3 and adiciona.upper() not in listapadrao: #Se a característica pedida for um padrão e o padrão inserido não está de acordo com o padrão declarado em listapadrão, o programa pede novamente.
                adiciona = input(f'Entrada inválida. Qual {listaCaracteristicas[j]} da peça? ') 
            while j == 6 and adiciona.upper() not in listasituacao: #Se a característica pedida for um situacao e a situacao inserido não está de acordo com o padrão declarado em listasituacao, o programa pede novamente.
                adiciona = input(f'Entrada inválida. Qual {listaCaracteristicas[j]} da peça? ')
            if j == 6:
                situacao = adiciona.upper()[:]
            if j == 7 and situacao == 'VENDER' and adiciona.upper() == '' or adiciona.upper() == ' ':
                while True:
                    try:
                        adiciona = float(input('Quando a peça está para venda não é possível inserir um preço vazio, insira um valor para o preço: '))
                        adiciona = str(adiciona)
                        break
                    except:
                        print('Insira um valor válido para o preço (R$xx.xx): ')
            elif j == 7 and situacao != 'VENDER' and adiciona.upper() != '':
                while True:
                    if adiciona.upper() == '':
                        break
                    else:
                        adiciona = input('Se a peça não for para venda, não insira um preço de venda(aperte enter para continuar):')
            if j == 5:
                while True:
                    aux = VeriricarData(adiciona)
                    if aux == True:
                        break
                    else:
                        adiciona = input('Digite uma data válida no formato válido: ')

            stringAux = stringAux + adiciona.upper() + '|' #adiciona as informações inseridas na string que será adicionada a matrizPrincipal, contendo os itens do guarda-roupa
        matrizOriginal.append(stringAux) 
        if 'DOAR' in stringAux: #Se a situação da peça for para DOAR, o programa identifica automaticamente e já realiza a doação automaticamente.
            DoarRoupa(matrizOriginal)
        elif 'VENDER' in stringAux: #Se a situação da peça for para VENDER, o programa identifica automaticamente e já realiza a venda automaticamente.
            VenderRoupa(matrizOriginal)
        else: #Se a peça for para ficar, a peça é adicionada ao arquivo contendo os dados das peças no guarda-roupa automaticamente.
            AdcArquivo(stringAux,'dados.txt')
        IdentificarEstilo(stringAux) #chamada da função que registra o estilo(IdentificarEstilo) 
    return matrizOriginal

#funcao para registrar qual o estilo da peça
def IdentificarEstilo(estiloEscolhido): #o parametro dessa função sera definido na func "CadastrarRoupa, ele recebe uma string formatada"
    matrizEstilos.clear() #limpa a matriz de estilos para evitar dados repetidos
    LerArquivo(matrizEstilos,'estilos.txt') #essa funcao vai acessar o arquivo salvo, não perdendo nenhum dado anterior e adicionando a matriz de estilos os dados atualizados
    listaAux = estiloEscolhido.split('|') #apos os processos que ocorrem dentro da func "CadastrarRoupa" é aplicado um split para tranformar os dados de str para list
    listaAux.pop() #no fim da lista, justamente por conta dos processos da func "CadastrarRoupa", acaba por aparecer um espaco vazio (" "), que é o motivo da aplicação desse .pop
    estiloEmLista = [] #nas proximas linhas, o estilo, antes string ('estilo|'), vai virar uma lista (['estilo'])
    estiloEmLista.append(listaAux[-1])
    estilo = listaAux[-1] + '|' #a lista é acessada no seu ultimo indice, pois o estilo agora ocupa o ultimo indice da listaAux
    if len(matrizEstilos) != 0: #caso a matriz possua algum elemento ela entrara no interior do if e verificar se o estilo já existe
        if estiloEmLista not in matrizEstilos:    
            matrizEstilos.append(estiloEmLista) #a matriz que armazenará os estilos, ira receber o estilo ja formatado como lista, apenas para facilitar a comparacao entre os elementos da matriz estilos
            AdcArquivo(estilo,'estilos.txt') #o que acontece aqui pode ser entendido melhor na func "AdcArquivo", mas ocorre aqui a inserção no arquivo
    else:
        matrizEstilos.append(estiloEmLista) #para a matriz estilos vai a lista com o estilo, para quesito de comparação
        AdcArquivo(estilo,'estilos.txt') #para o arquivo que armazena os estilos vai o estilo como string, para que todos os processor de leitura e escrita no arquivo funcionem.

#funcao para listar os estilos
def ListarEstilos(matrizDesejada): #o parametro da func sera uma matriz, no caso, a matrizEstilos
    matrizDesejada.clear() #evitar repeticoes
    matrizPrincipal.clear()
    cond = False #importante parte da logica, essa condição booleana vai auxiliar em tratamentos de erros e na propria execução do programa
    print('-'*47 + '\n' + 'MENU --> LISTAR ESTILOS\n' + '-'*47) 
    LerArquivo(matrizDesejada,'estilos.txt') #essa funcao vai acessar o arquivo salvo, não perdendo nenhum dado anterior
    LerArquivo(matrizPrincipal,'dados.txt')
    if len(matrizDesejada) == 0: #por existir a possibilidade de não haver estilos salvos (como na primeira execução, com o arquivo limpo ainda), foi implementado um if/else para lidar com o problema
        print('Ainda não há estilos cadastrados.') #lembrando que a base da logica do nosso codigo é a utilização de arquivos e matrizes, o que existe no arquivo esta tambem em uma matriz
    else:   
        listaAux = [] #lista auxiliares, vão ganhar sentido mais adiante
        listaAcessos = []
        for aux in range(len(matrizDesejada)): #a impressao a ser feita sera a de uma matriz, por conta disso, toda a ideia de lidar com matrizes sera aplicada. o for exterior vai ate o num de linhas
            for j in range(1): #o for interior vai ate 1 (por ser só um elemento, existe apenas uma coluna)
                print(aux,'- ESTILO: ',matrizDesejada[aux][j])#a string da func vai receber a cada laço do for um elemento da matriz, nao como lista, mas sim como string        
                listaAux.append(aux) #como poderão surgir sempre novos estilos, a comparação vai ser dada por indices que vão até a quantidade de estilos armazenadas, essa é uma lista de indices
    opc = int(input('Deseja vizualizar as peças de algum desses estilos?\n1.sim\n2.não\n3.Estilo do momento\n')) #apenas opções    
    if opc == 1: #caso a opção escolhida acima seja a de vizualizar as peças... A PARTIR DAQ NÃO ESTA COMENTADO
        while True:  #o while True foi aplicado para executar o tratamento de erro
            indice = int(input('Digite o indice do estilo que você deseja vizualizar as peças: ')) #receberemos um indice
            if indice >= 0 and indice <= len(matrizDesejada)-1:
                stringAcessos = ''
                stringAcessos = stringAcessos + matrizDesejada[indice][0] + '|' #formatação para preencher o arquivo de maneira adequada de acordo com a logica do nosso programa
                AdcArquivo(stringAcessos,'AcessosEstilos.txt') #esse processo já foi explicado varias vezes durante o codigo
                listaAcessos.append(matrizDesejada[indice][0]) #cada elemento do arquivo vai vir para essa lista para facilitar a manipulação
             #tratamento de entradas inválidas, indices negativos e que sejam maior que o len da matriz, pois a impressão no programa vai variar de acordo com o tamanho da matriz
                for i in range(len(matrizDesejada)): 
                    if indice in listaAux: #caso o indice recebido esteja na lista auxiliar
                        cond = True #a condição fixada como False, ira virar True para dar processeguimento ao programa
                if cond == True: #se a cond for realmente True
                    contT = 0 #iniciaremos contadores de condiçoes(quantas vezes True e quantas vezes False)
                    contF = 0
                    print('O estilo desejado foi: ',matrizDesejada[indice][0],', e as peças com esse estilo AINDA no seu guarda-roupa são:') #a matriz tem só uma coluna, entao acessaremos ela variando apenas de linha
                    for i in range(len(matrizPrincipal)):  
                        if matrizDesejada[indice][0] in matrizPrincipal[i]: #se a matriz na linha desejada estiver na matriz peincipal, significa que o estilo ainda esta no guarda-roupa
                            contT += 1 #portanto, a condição aq seria verdadeira, e por isso contT(contador de True) é incrementado
                            print(ExibirFormatado(matrizPrincipal[i])) #exibição padrão do programa
                        else: #se não, a peça não esta mais no guarda-roupa e a condição será false
                            contF += 1
                    if contF == i+1: #o contador inicia de 0, mas logo no primeiro laço se torna 1, o i nao, ele assume durante todo o primeiro laço 0, ficando sempre atrás do cont uma posição, por esse motivo 'i+1'
                        print('O estilo já passou pelo seu guarda-roupa, mas não está mais nele.') #aconte nesse if o seguinte, se o numero de incrementos no contador tiver ocorrido a cada laço, todas as peças não estão no guarda roupa, logo será impresso uma outra mensagem
            else:
                print('O numero digitado não é uma opção.') #tratamento do caso basico, onde o usuario tenta acessar uma opção
                ChamarFuncao(MostrarMenu())
                break
            confirmacao = int(input('\nO estilo selecionado foi o escolhido pelo usuario?\n1.sim\n2.não\n')) #pergunta se o usuário confirma a sua escolha de estilo.      
            if confirmacao == 1: #se sim, o laço é quebrado e o usuário volta para o menu
                ChamarFuncao(MostrarMenu())
                break
            elif confirmacao == 2: #se não a função roda novamente para que o usuário escolha o estilo correto.
                continue
            else:
                print('O numero digitado não é uma opção.')

    elif opc == 2: #para as demais opções
        ChamarFuncao(MostrarMenu())
    elif opc == 3:
        EstilosEmAlta(listaAcessos)
    else: #caso digite uma opção que não consta, como 4, caira nesse caso
        print('O numero digitado não é uma opção.')
        ChamarFuncao(MostrarMenu())

def EstilosEmAlta(acessos): #acessos = listaAcessos da função ListarEstilos
    LerArquivo(acessos,'AcessosEstilos.txt')
    EmAlta = 0 #inicia vazia
    if len(acessos) == 0: #com nenhum estilo no arquivo, não se pode fazer nada
        print('Ainda não há estilos dados suficientes')
    else:    
        for i in range(len(acessos)): #começa do 1, pois o 0 é o inicializador da variavel
            maior = acessos.count(EmAlta) #maior sera igual a qtd de vezes que o elemento em alta ira aparecer
            if maior < acessos.count(acessos[i]): #se aparecer mais vzs que o maior, o atual maior sera ele
                EmAlta = acessos[i]
            else: #se não, o maior continua o msm
                EmAlta = EmAlta
        print('-'*47 + f'\nO estilo mais acessado recentemente foi: {EmAlta[0]} com {acessos.count(EmAlta)} acessos. Pode ser uma boa opção ver peças desse estilo!\n' + '-'*47)

#listar peças do guarda-roupa
def ListarPecas(matrizOriginal): 
    print('-'*47 + '\n' + 'MENU --> VISUALIZAR GUARDA-ROUPA\n' + '-'*47)
    matrizOriginal.clear() #limpa a matriz pra evitar duplicar informações
    LerArquivo(matrizPrincipal,'dados.txt') #Realiza a lógica de atualizar as informações da matriz com base no arquivo atualizado.
    cond = False
    if len(matrizOriginal) != 0:
        while True:
            try: #tenta converter a entrada em inteiro, se conseguir, o laço é quebrado e o código continua, se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
                filtro = int(input('Você deseja listar peças por:\n' + '-'*47 + '\n' + '1.ID\n2.Tipo\n3.Descrição\n4.Tamanho\n5.Padrão\n6.Cor\n7.Data de aquisição\n8.Situação\n9.Preço\n10.Para listar todas as peças cadastradas.\n' + '-'*47 + '\n'))
                break
            except:
                print('O número inserido deve ser um inteiro.')       
        if filtro == 1: 
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> ID\n' + '-'*47)
            filtroEspecifico = input('qual id você deseja? ')
            if int(filtroEspecifico) > 0:
                cond = True
            else:
                while int(filtroEspecifico) <= 0:
                    cond = cond
                    filtroEspecifico = int(input('O id deve ser positivo. Digite-o da maneira adequada: '))
                    if int(filtroEspecifico) > 0:
                        cond = True
                        break
                    else:
                        continue           
        #Realiza a checagem do filtro inserido pelo usuário e pede para ele inserir a especificação do filtro que ele deseja, por exemplo,
        #se ele escolher o filtro de tamanho, o programa pergunta qual tamanho específico o usuário deseja (P/M/G).
        #Em cada caso, o programa faz o tratamento de erros, caso o filtro específico não atenda aos padrôes estabelecidos anteriormente, 
        #o programa perguntará novamente até inserir uma entrada que atenda aos padrões.
        elif filtro == 2:
            cond = True
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> TIPO\n' + '-'*47)
            filtroEspecifico = input('Digite o tipo você deseja(calçado/inferior/superior): ').upper()
            while filtroEspecifico.upper() not in listatipo:
                filtroEspecifico = input('Tipo inválido. Digite o tipo você deseja(calçado/inferior/superior): ').upper()
        elif filtro == 3:
            cond = True
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> DESCRIÇÃO\n' + '-'*47)
            filtroEspecifico = input('Digite a descrição da peça que você deseja: ').upper()
        elif filtro == 4:
            cond = True
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> TAMANHO\n' + '-'*47)
            filtroEspecifico = input('Digite o tamanho você deseja(P/M/G): ').upper()
            while filtroEspecifico.upper() not in listatamanho:
                filtroEspecifico = input('Tamanho inválido. Digite o tamanho você deseja(P/M/G): ').upper()
        elif filtro == 5:
            cond = True
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> PADRÃO\n' + '-'*47)
            filtroEspecifico = input('Digite o padrão que você deseja(masculino/feminino/unissex): ').upper()
            while filtroEspecifico.upper() not in listapadrao:
                filtroEspecifico = input('Padrão inválido. Digite o padrão que você deseja(masculino/feminino/unissex): ').upper()
        elif filtro == 6:
            cond = True
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> COR\n' + '-'*47)
            filtroEspecifico = input('Digite a cor que você deseja: ').upper()
        elif filtro == 7:
            cond = True
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> DATA DE AQUISIÇÃO\n' + '-'*47)
            filtroEspecifico = input('Digite a data de aquisição que você deseja (dd/mm/aaaa): ').upper()
        elif filtro == 8:
            cond = True
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> SITUAÇÃO\n' + '-'*47)
            filtroEspecifico = input('Digite a situação que você deseja (ficar/doar/vender): ').upper()
            while filtroEspecifico.upper() not in listasituacao:
                filtroEspecifico = input('Situação inválida. Digite a situação que você deseja (ficar/doar/vender): ').upper()
        elif filtro == 9: #Se o filtro for 9 (preço), o programa checa se tem alguma peça para venda, se não estiver, printa que nenhuma peça possui preço pois não estão para venda.
            print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> PREÇO\n' + '-'*47)
            contAux = 0
            for i in range(len(matrizOriginal)):
                if matrizOriginal[i][7] == 'VENDER':
                    cond = True
                    filtroEspecifico = input('Digite o preço que você deseja: ')
                else:
                    cond = cond
                    contAux += 1
            if contAux == len(matrizOriginal):
                print('As peças cadastradas não estão a venda, portanto, não possuem preço.')
        else:
            cond = True

        if cond == False:
            ChamarFuncao(MostrarMenu())
        #Depois de obter as informações de filtro e filtro específico o programa faz a filtragem dentro da matrizPrincipal, que contem os dados das peças
        #cadastradas no guarda-roupa, e imprime de forma formatada todas as peças que correspondem com os valores inseridos nos filtros.
        else:
            if filtro == 1:
                for i in range(len(matrizOriginal)):
                    if matrizOriginal[i][0] == str(filtroEspecifico): 
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
                    if matrizOriginal[i][5][0:-1] == filtroEspecifico[0:-1]: # 
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
                print('-'*47 + '\n' + 'VISUALIZAR GUARDA-ROUPA --> VISUALIZAR TODAS AS PEÇAS\n' + '-'*47)
                for i in range(len(matrizOriginal)):
                    print(ExibirFormatado(matrizOriginal[i]))
            else: #Se nenhuma peça no guarda-roupa contém o filtro específico inserido, o programa imprime uma mensagem constando esse fato.
                print('O filtro desejado não consta no seu guarda-roupa.')
    else: #Se o guarda-roupa não possuir peças cadastradas em seu interior, imprime uma mensagem constatando esse fato.
        print('Não há peças cadastradas no Guarda-Roupa, cadastre peças no menu para prosseguir.')
    
def RemoverRoupa(matrizOriginal):
    LerArquivo(matrizOriginal,'dados.txt') #lê a matriz de dados
    if len(matrizOriginal) != 0: #se o guarda roupa não estiver vázio, o programa executa a função normalmente.
        matrizOriginal.clear() #limpa a matriz para revitar a duplicação ao ler na função abaixo
        LerArquivo(matrizPrincipal,'dados.txt') #lê o arquivo e adiciona os dados a matrizOriginal
        for i in range(len(matrizOriginal)): #printa os elementos da matriz (roupas e suas características) para o usuário visualizar e escolher melhor
            print('Linha',i,'-',ExibirFormatado(matrizOriginal[i]))
        #Não permite a inserção de uma string para o número de peças a serem inseridas, por ser um número inteiro, esse tratamento é necessário
        #para não bugar o código caso o usuário insira uma entrada inválida.
        while True:
            try: #tenta converter a entrada em inteiro, se conseguir, o laço é quebrado e o código continua, se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
                linharemov = int(input('Qual é o número da linha que você deseja remover? ')) #pega o índice (da matriz) da linha a ser removida
                break
            except:
                print('Digite um número inteiro para selecionar a linha da peça a ser removida.')
        while linharemov >= len(matrizOriginal) or linharemov < 0: #trata erros(entradas negativas ou maiores do que o tamanho da lista)
            try:#tenta converter a entrada em inteiro, se conseguir, o laço é quebrado e o código continua, se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
                linharemov = int(input('Linha digitada inválida. Qual é o número da linha que você deseja remover? '))
                if linharemov >= len(matrizOriginal) or linharemov < 0: #se a linha digitada não constar na lista de peças, imprime uma mensagem de erro e tenta novamente.
                    print('Digite um número de linha válido na lista peças para remover.')
            except:
                print('Entrada inválida. Digite um número inteiro.')
        with open('dados.txt', 'r') as arquivo: #abre arquivo e armazena os dados do arquivo na varáviel 'dados' para sobescrever o arquivo sem a linha que será removida
            dados = arquivo.readlines()
        with open('dados.txt','w') as arquivo: #abre o arquivo no modo de escrita para sobescrever os dados anteriores sem a linha a ser removida utilizando a variável do tipo lista 'dados' 
            for i in range(0,len(dados)): #percorre os itens em dados, que são listas cujo são armazenadas apenas uma string
                if i != linharemov: #caso o indice i seja igual o indice indicado para remoção, a função não escreverá a linha atrelada a 'linharemov'
                    arquivo.write(dados[i])
        del matrizOriginal[linharemov] #retira a linha atrelada a variável de remoção da matriz e a retorna atualizada
        print('Peça removida!')
        repetir = input('Deseja remover mais uma peça? \n Digite 1 para sim, aperte enter para não. \n') #pegunta ao usuário se ele deseja remover outra roupa
        if repetir == '1': #se a reposta for positiva chama a função novamente
            RemoverRoupa(matrizOriginal) 
        else: #se a resposta for negativa, retorna a matrizoriginal atualizada e retona ao menu. 
            return matrizOriginal
        return matrizOriginal
    else: #se o guarda roupas estiver vazio ele imprime uma mensagem constatando esse fato.
        print('Guarda-Roupas não possui elementos para remover')
#listaCaracteristicas = ['o tipo(calçado/inferior/superior)', 'a descrição','o tamanho(P/M/G)','o padrão(masculino/feminino/unissex)','a cor principal','a data de aquisição(dia/mês/ano)','a situação(ficar/venda/doação)','o preço (deixar em branco caso não seja para venda.)', 'o estilo.']                                                                                                                        
def ExibirFormatado(lista):
    if lista[8] != '' : #se a roupa estiver a venda, a mensagem a ser exibida é diferente, e deve conter o preço da peça.
        mensagemFormatada = '• A peça possui id {0} e é uma/um {1} de tamanho {2}, do padrão {3}, com {4} como a cor principal, e possui o estilo {5}.\nEla foi adquirida no dia {6} e atualmente foi vendida no valor de R${7} para {8}.'.format(lista[0], lista[2], lista[3], lista[4], lista[5], lista[9], lista[6], lista[8], lista[10])
    elif lista[7] == 'DOAR': #se a roupa não estiver a venda, deve ser exibida a situação da peça
        mensagemFormatada = '• A peça possui id {0} e é uma/um {1} de tamanho {2}, do padrão {3}, com {4} como a cor principal, e possui o estilo {5}.\nEla foi adquirida no dia {6} e atualmente está com a situação de {7}, sendo doada para a instituição {8}.'.format(lista[0], lista[2], lista[3], lista[4], lista[5], lista[9], lista[6], lista[7], lista[10])
    else:
        mensagemFormatada = '• A peça possui id {0} e é uma/um {1} de tamanho {2}, do padrão {3}, com {4} como a cor principal, e possui o estilo {5}.\nEla foi adquirida no dia {6} e atualmente está com a situação de {7}.'.format(lista[0], lista[2], lista[3], lista[4], lista[5], lista[9], lista[6], lista[7])
    return mensagemFormatada

def VeriricarData(data):
    formato = '%d/%m/%Y' #formato certo da data
    #verifica se a data ta no formato correto utilizando o datetime.
    try:
        aux = bool(datetime.datetime.strptime(data, formato)) #função que realiza a verificação
    except ValueError:
        aux = False #se a verificação não pode ser feita, o programa retorna um valor falso.
    return aux


def AlterarRoupa(matrizOriginal):
    LerArquivo(matrizOriginal,'dados.txt') #atualiza a matrizOriginal com base nos dados do arquivo.
    listaCaracteristicas = ['o tipo(calçado/inferior/superior)', 'a descrição','o tamanho(P/M/G)','o padrão(masculino/feminino/unissex)','a cor principal','a data de aquisição(dia/mês/ano)','a situação(ficar/venda/doação)','o preço (deixar em branco caso não seja para venda.)', 'o estilo.']
    if len(matrizOriginal) != 0: #se o tamanho da matriz (quantidade de peças do guarda roupa) for diferente de 0, a função ocorre normalmente.
        contador = 0 #auxilia ao imprimir mensagem para o usuário.
        matrizOriginal.clear() #limpa a matriz para revitar a duplicação ao ler na função abaixo
        LerArquivo(matrizPrincipal,'dados.txt') #lê o arquivo e adiciona os dados a matrizOriginal
        for i in range(len(matrizOriginal)): #printa os elementos da matriz (roupas e suas características) para o usuário visualizar e escolher melhor
            print('Linha',i,'-',ExibirFormatado(matrizOriginal[i]))
        #Não permite a inserção de uma string para o número de peças a serem inseridas, por ser um número inteiro, esse tratamento é necessário
        #para não bugar o código caso o usuário insira uma entrada inválida.
        while True:
            try: #tenta converter a entrada em inteiro, se conseguir, o laço é quebrado e o código continua, se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
                linha_a_ser_alterada = int(input('Digite o número da linha que você deseja alterar: '))
                if linha_a_ser_alterada >= len(matrizOriginal[0]) or linha_a_ser_alterada <= 0: #
                    print('Digite uma linha válida para a lista de características da peça.')
                break
            except:
                print('Digite um número inteiro para selecionar a linha da peça a ser alterada.')
        #Não permite a inserção de uma string para o número de peças a serem inseridas, por ser um número inteiro, esse tratamento é necessário
        #para não bugar o código caso o usuário insira uma entrada inválida.
        while linha_a_ser_alterada >= len(matrizOriginal) or linha_a_ser_alterada < 0:
            try:
                linha_a_ser_alterada = int(input('Digite a linha que você deseja alterar? ')) #recolhe o indice da linha a ser alterada
                if linha_a_ser_alterada >= len(matrizOriginal) or linha_a_ser_alterada < 0:
                    print('Digite um número de linha válido na lista de peças para alterar.')
            except:
                print('Entrada inválida. Digite um número inteiro.')
                
        with open('dados.txt','r') as arquivo: #recolhe os dados do arquvo na varíavel dados
            dados = arquivo.readlines()
        for i in range(0,len(listaCaracteristicas)): #printa as características da peça escolhida para ser alterada (printa as características que estão na linha da peça dentro da matriz.)
            contador = contador + 1 #auxilia na contagem para facilitar a leitura e inserção de dados do usuário
            print('Característica','-',contador,'-',listaCaracteristicas[i],'-',matrizOriginal[linha_a_ser_alterada][contador]) #printa de uma forma legível para o usuário
        #Não permite a inserção de uma string para o número de peças a serem inseridas, por ser um número inteiro, esse tratamento é necessário
        #para não bugar o código caso o usuário insira uma entrada inválida.
        while True:
            try: #tenta converter a entrada em inteiro, se conseguir, o laço é quebrado e o código continua, se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
                caracteristica_a_ser_alterada = int(input('Digite o indice da característica que você deseja alterar: ')) #recolhe o indice (coluna) em que a característica está armazenada dentro da linha
                if caracteristica_a_ser_alterada >= len(matrizOriginal[0]) or caracteristica_a_ser_alterada <= 0:
                    print('Digite uma linha de característica válida para a lista de características da peça.')
                break
            except:
                print('Digite um número inteiro para selecionar a linha da característica a ser alterada.')
        while caracteristica_a_ser_alterada >= len(matrizOriginal[0]) or caracteristica_a_ser_alterada <= 0: #trata erros(entradas negativas ou maiores do que o tamanho da lista)
            try: #tenta converter a entrada em inteiro, se conseguir, o laço é quebrado e o código continua, se não conseguir, imprime uma mensagem de erro e o laço continua até o usuário inserir uma entrada válida.
                caracteristica_a_ser_alterada = int(input('Característica digitada inválida. Digite a linha da característica que você deseja alterar: '))
                if caracteristica_a_ser_alterada >= len(matrizOriginal[0]) or caracteristica_a_ser_alterada <= 0:
                    print('Digite uma linha de característica válida para a lista de características da peça.') #se a entrada for inválida (maior que o número de peças ou negativa) imprime uma mensagem de erro e tenta novamente
            except:
                print('Entrada inválida. Digite um número inteiro.')
        nova_caracteristica = input('Digite a nova característica que você deseja implementar: ').upper() #recebe do usuário nova característica para substituir a antiga.
        while caracteristica_a_ser_alterada == 1 and nova_caracteristica.upper() not in listatipo: #Realiza a checagem se a nova entrada do usuuário está de acordo com os padrões das características 
            nova_caracteristica = input('Entrada inválida. Qual é o tipo novo da peça? ').upper()  #propostos anteriormente, se não estiverem, pergunta novamente ao usuário até obter uma entrada válida
        while caracteristica_a_ser_alterada == 3 and nova_caracteristica.upper() not in listatamanho:
            nova_caracteristica = input('Entrada inválida. Qual é o tamanho novo da peça? ').upper()
        while caracteristica_a_ser_alterada == 4 and nova_caracteristica.upper() not in listapadrao:
            nova_caracteristica = input('Entrada inválida. Qual o padrão novo da peça? ').upper()
        while caracteristica_a_ser_alterada == 7 and nova_caracteristica.upper() not in listasituacao:
            nova_caracteristica = input('Entrada inválida. Qual a situação nova da peça? ').upper()

        
        matrizOriginal[linha_a_ser_alterada][caracteristica_a_ser_alterada] = nova_caracteristica #substitui o elemento atrelado a linha e coluna de remoção inseridas pelo usuário anteriormente (linha_a_ser_alterada e coluna_a_ser alterada) pela nova variável (nova_característica).
        matriz_alterar = [] #matriz para auxiliar a inserção dos novos dados (matriz com o elemento alterado) no arquivo
        for i in range(len(dados)): #transfere os dados que estão como uma única string em dados, em vários elementos (strings) separados para efetuar a alteração
            string = dados[i].split('|')
            string.pop() #retira o /n da linha
            matriz_alterar.append(string) #adiciona as novas strings a matriz_alterar que serve de auxiliar
        matriz_alterar[linha_a_ser_alterada][caracteristica_a_ser_alterada] = nova_caracteristica # substitui o elemento atrelado as variáveis 'linha_a_ser_alterada' e 'caracteristica_a_ser_alterada' pela variável inserida 'nova_caracteristica'(todas strings)
        listaAux = [] #linha auxiliar para converter as várias strings da matriz_alterar em uma string só no formato correto para voltar ao arquivo os dados alterados
        for i in range(len(matriz_alterar)): #percorre as linhas de matriz_alterar
            strAux = '' #cria uma string para adicionar os elementos de matriz_alterar em uma só string e depois adicionala a uma listaaux
            for j in range(len(matriz_alterar[0])): #percorre as colunas (informações das características das linhas)
                strAux = strAux + matriz_alterar[i][j] + '|' #adiciona as caracteristicas armazenadas em matriz_alterar em uma unica string utilizando o | para separar no arquivo
            strAux = strAux + '\n' #adiciona a quebra de linha para formatar corretamente no arquivo
            listaAux.append(strAux) #adiciona as novas strings a lista auxiliar que será percorrida para sobescrever no arquivo
        with open('dados.txt','w') as arquivo: #abre o arquivo em formato de escrita
            for i in range(len(listaAux)): #percorre os elementos da listauxiliar que contem as strings completas com as caracterísitcas de cada roupa
                arquivo.write(listaAux[i]) #escreve as strings completas no arquivo
        print("Alteração efetuada!")
        IdentificarEstilo(strAux) #identifica se a característica alterada foi um estilo, se sim, verifica se o estilo é novo, se for, acrescenta o estilo a lista de estilos.
        listaAux2 = []
        if nova_caracteristica == 'DOAR': #verifica se a nova caracteristica foi na na situacao, se foi, o programa efetua a venda ou doação automaticamente, perguntando
            DoarRoupa(matrizOriginal)     # ao usuário para quem foi a venda/doaçao e o preço (se tiver preço)
        elif nova_caracteristica == 'VENDER':
            VenderRoupa(matrizOriginal)
        for i in range(len(matrizOriginal)): #considera agora a alteração de situação para sobescrever o arquivo de dados caso alguma peça alterada tenha sido vendida/doada
            strAux2 = ''
            for j in range(len(matrizOriginal[0])): #formata os elementos de matrizOriginal no formato para escrever no arquivo ('|' e '\n')
                strAux2 = strAux2 + matrizOriginal[i][j] + '|'
            strAux2 = strAux2 +'\n'
            listaAux2.append(strAux2) #acrescenta a string na lista de strings que serão escritas no arquivo
        with open('dados.txt','w') as arquivo: #percorre as strings em listaAux2 e escreve cada elemento no arquivo
            for i in range(len(listaAux2)):
                arquivo.write(listaAux2[i])
        repetir = input('Deseja alterar mais uma peça? \n Digite 1 para sim, aperte enter para não. \n') #Pergunta ao usuário se ele deseja alterar mais uma peças e checa a resposta
        if repetir == '1':
            AlterarRoupa(matrizOriginal) #se o usuário quiser, chama a função novamente
        else:
            return matrizOriginal #se não, retona a matrizprincipal atualizada
        return matrizOriginal #retorna a matriz com os itens alterados.
    else:
        print('Guarda-Roupas não possui elementos para alterar')
#Depois de realizar a checagem se a peça é para doação, chama essa função.
def DoarRoupa(matrizOriginal):
    roupasDoacao = [] #Lista de peças a serem doadas
    roupaDoada = '' #String de peças a serem doadas
    for i in range(len(matrizOriginal)): #Percorre os itens da matrizprincipal
        if 'DOAR' in matrizOriginal[i]: #realiza a checagem novamente, se for para doação.
            roupasDoacao.append(matrizOriginal[i]) # adiciona a peça na lista de roupasDoacao.
            del matrizOriginal[i] #deleta o elemento da matriz principal
            break #quebra o laço pois ele já cumpriu seu papel de deletar na matriz principal o elemento que será doado
    if type(roupasDoacao[0]) == list: #se a peça tiver sido enviada por meio da função de alterar, a forma de escrever é diferente, pois 
        for j in range(len(roupasDoacao)): #nesse caso a peça é enviada como forma de uma matriz, contendo listas, em que cada lista possui strings, que são as características da peça.
            for k in range(len(roupasDoacao[0])): #percorre a matriz de características, linha por linha (peça por peça.) coluna por coluna (caracteristicas)
                roupaDoada = roupaDoada + roupasDoacao[j][k] + '|' #formata no formato correto
    else:
        for j in range(len(roupasDoacao)): #pega cada elemento da lista de roupasDoacao e formata corretamente em string no formato adequado '|' e adiciona ao arquivo de doacao.txt
            roupaDoada = roupaDoada + roupasDoacao[j]
    roupaDoada = roupaDoada + input('Para qual instituição você doou esta roupa? ').upper() + '|' #pergunta para quem foi a doação e adiciona a string que sera escrita no arquivo.
    AdcArquivo(roupaDoada, 'doacao.txt') #adiciona a string roupa doada no arquivo de doação.
    LerArquivo(matrizDoacao,'doacao.txt') #atualiza a matriz de venda com base nas alterações do arquivo

#Depois de realizar a checagem se a peça é para venda, chama essa função.
def VenderRoupa(matrizOriginal):
    roupasVenda = [] #Lista de peças a serem vendidas
    roupaVendida = '' #String de peças a serem vendidas
    for i in range(len(matrizOriginal)): #Percorre os itens da matrizprincipal
        if 'VENDER' in matrizOriginal[i]: #realiza a checagem novamente, se for para venda.
            roupasVenda.append(matrizOriginal[i]) # adiciona a peça na lista de roupasVenda.
            del matrizOriginal[i] #deleta o elemento da matriz principal
            break #interrompe o laço pois ele já cumpiu sua função de deletar o elemento que será vendido da matrizprincipal.
    if type(roupasVenda[0]) == list: #se a peça tiver sido enviada por meio da função de alterar, a forma de escrever é diferente, pois
        for j in range(len(roupasVenda)): #nesse caso a peça é enviada como forma de uma matriz, contendo listas, em que cada lista possui strings, que são as características da peça.
            for k in range(len(roupasVenda[0])): #percorre a matriz de características, linha por linha (peça por peça.) coluna por coluna (caracteristicas)
                if k !=8: #se k (caracteristica) for diferente de 8(preço) o programa adiciona as caracteristicas da peça
                    roupaVendida = roupaVendida + roupasVenda[j][k] + '|' #formata no formato correto
                else: #se k (caracteristicas da peça) for igual a 8 (preço) o programa pergunta ao usuário por quanto a peça será vendida e adiciona a posição referente ao preço, que antes era vázia.
                    while True:
                        try:
                            adiciona = float(input('Quando a peça está para venda não é possível inserir um preço vázio, insira um valor para o preço: '))
                            adiciona = str(adiciona)
                            break
                        except:
                            print('Insira um valor válido para o preço (R$xx.xx): ')
                    roupaVendida = roupaVendida + adiciona + '|'
    else:
        for j in range(len(roupasVenda)): #pega cada elemento da lista de roupasVenda e formata corretamente em string no formato adequado '|' e adiciona ao arquivo de venda
            roupaVendida = roupaVendida + roupasVenda[j]
    roupaVendida = roupaVendida + input('Para quem você vendeu esta roupa? ').upper() + '|' #pergunta para quem foi a venda e adiciona a string que sera escrita no arquivo.
    AdcArquivo(roupaVendida,'venda.txt') #adiciona a nova peça a ser vendida no arquivo de venda.txt
    LerArquivo(matrizVenda,'venda.txt') #atualiza a matriz de venda com base nas alterações do arquivo
 
#listar peças de roupa doadas
def ListarDoacao(matrizDoacao):
    matrizDoacao.clear()
    LerArquivo(matrizDoacao,'doacao.txt')
    dicionarioDatas = {} #inicializa o dicionario.
    for i in range(len(matrizDoacao)):
        data = matrizDoacao[i][6]
        dia = data[0:2] #usa o slice pra pegar o dia, o mes e o ano da data.
        mes = data[3:5]
        ano = data[6:10]
        dataFormatada1 = datetime.datetime(int(ano), int(mes), int(dia)) #constroi um objeto datetime.
        dicionarioDatas['data'+str(i)] = dataFormatada1 #adiciona no dicionario.
    for item in sorted(dicionarioDatas, key = dicionarioDatas.get, reverse=True): #um for que exibe os itens do dicionario em ordem crescente da data.
        dataComparar = dicionarioDatas[item] # variavel que armazena o valor da data atual do dicionario.
        dicionarioDatas.pop(item)
        for j in range(len(matrizDoacao)): #esse for basicamente percorre a matriz e verifica se a data da linha atual é igual ao da data comparada.
                data2 = matrizDoacao[j][6]
                dia2 = data2[0:2]
                mes2 = data2[3:5]
                ano2 = data2[6:10]
                dataFormatada2 = datetime.datetime(int(ano2), int(mes2), int(dia2))
                if dataComparar == dataFormatada2:
                    print(ExibirFormatado(matrizDoacao[j])) 
                    matrizDoacao.pop(j)   
                    break  
                       
#Lista as peças que foram vendidas, se baseando pelo arquivo de venda.txt
def ListarVenda(matrizVenda):
    matrizVenda.clear() #Utiliza da lógica de limpar a matriz e atualizar se baseando pelo arquivo atualizado
    LerArquivo(matrizVenda,'venda.txt')
    dicionario = {}
    for i in range(len(matrizVenda)): #Acessa os indices da matriz venda
        dicionario['preco' + str(i)] = float(matrizVenda[i][8].replace(',', '.'))  #transforma o preço em dicionarios para facilitar a impressão.
    for item in sorted(dicionario, key = dicionario.get): #ordena os preços
        preco = dicionario[item] 
        dicionario.pop(item)
        for j in range(len(matrizVenda)):
            if float(matrizVenda[j][8].replace(',', '.'))  == preco:
                print(ExibirFormatado(matrizVenda[j]))
                matrizVenda.pop(j) 
                break
#Limpa o terminal
def LimparTerminal():
    os.system('cls' if os.name == 'nt' else 'clear') #codigo para limpar o terminal.

#chamar a função que o usuário deseja baseado na entrada inserida no Id, (menu)
def ChamarFuncao(id):
    if id == 1:
        CadastrarRoupa(matrizPrincipal)
        LimparTerminal()
    elif id == 2:
        ListarPecas(matrizPrincipal)
    elif id == 3:
        AlterarRoupa(matrizPrincipal)        
    elif id == 4:
        RemoverRoupa(matrizPrincipal)
    elif id == 5:
        ListarEstilos(matrizEstilos)
    elif id == 6:
        ListarDoacao(matrizPrincipal)
    elif id == 7:
        ListarVenda(matrizPrincipal)
    ChamarFuncao(MostrarMenu()) #no final essa função é chamada para retornar para o menu

def MostrarMenu():
    #menu padrão do programa
    mensagemTerminal = "-----------------------------------------------\nGUARDA-ROUPA PESSOAL\n----------------------------------------------- \nSeja bem-vindo(a) ao seu guarda-roupa pessoal.\nO que você deseja fazer?\nDigite o número da opção desejada:\n\n1.CADASTRAR NOVAS PEÇAS.\n2.BUSCAR E LISTAR PEÇAS\n3.ALTERAR PEÇAS.\n4.REMOVER PEÇAS.\n5.LISTAR ESTILOS.\n6.LISTAR PEÇAS DOADAS.\n7.LISTAR PEÇAS VENDIDAS.\n-----------------------------------------------\n"
    #variável que armazena o que o usuário que fazer
    try: #Trata caso a opção inserida pelo usuário não for um inteiro. Para caso o usuário errar na entrada, não bugar o programa
        funcaoDesejada = int(input(mensagemTerminal)) #Tenta converter para inteiro, se conseguir, retorna a função desejada.
        return funcaoDesejada
    except ValueError: #Se não conseguir realizar a conversão, printa uma mensagem de erro e volta para o menu.
        print('A opção inserida precisa ser um número inteiro.')
    return None
