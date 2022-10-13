#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fila.h"

float nota;

float teste_novo_com_dados_validos() {
	char nome[50];
	char curso[30];
	float pontuacao = 0;

	Aluno *aluno = alu_novo(1, "Abraão", "Computação");

	if (aluno != NULL){
		printf("[Passou 1.50] - Teste da função novo_a() com dados válidos!\n");
		pontuacao = 1.5;
	} else {
		printf("[Falhou 0.00] - Teste da função novo_a() com dados válidos!\n");
	}
	return pontuacao;
}

float teste_novo_com_dados_invalidos() {
	char nome[55] = "N";
	char curso[35] = "C";
	float pontuacao = 0;

	for (int i = 0; i < 53; i++) {
		strcat(nome, "N");
	}

	for (int i = 0; i < 33; i++) {
		strcat(curso, "C");
	}

	Aluno *aluno = alu_novo(-1, nome, curso);
	if (aluno == NULL){
		printf("[Passou 1.00] - Teste da função novo_a() com dados inválidos!\n");
		pontuacao = 1;
	} else{
		printf("[Falhou 0.00] - Teste da função novo_a() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeNovoComDadosNulos() {
	float pontuacao = 0;

	Aluno *aluno = novo_a(-1, NULL, NULL);
	if (aluno == NULL){
		printf("[Passou 0.67] - Teste da função novo_a() com dados nulos!\n");
		pontuacao = 0.67;
	} else{
		printf("[Falhou 0.00] - Teste da função novo_a() com dados nulos!\n");
	}
	return pontuacao;
}

float testeAcessa() {
	int matricula;
	char nome[50];
	char curso[30];
	float pontuacao = 0;

	Aluno *aluno = novo_a(1, "Abraão", "Computação");
	if (aluno != NULL){
		acessa_a(aluno, &matricula, nome, curso);
		if(matricula == 1 && strcmp(nome,"Abraão") == 0 && strcmp(curso,"Computação") == 0) {
			printf("[Passou 1.50] - Teste da função acessa_a() com dados válidos!\n");
			pontuacao = 1.5;
		} else {
			printf("[Falhou 0.00] - Teste da função acessa_a()com dados válidos!\n");
		} 
	} else {
		printf("[Falhou 0.00] - Teste da função acessa_a() com dados válidos!\n");
	}
	return pontuacao;	
}

float testeAtribuiComDadosValidos() {
	int matricula;
	char nome[50];
	char curso[30];
	float pontuacao = 0;

	Aluno *aluno = novo_a(1, "Abraão", "Computação");
	if (aluno != NULL){
		atribui_a(aluno, 2, "Jacó", "Sistemas de Informação");
		acessa_a(aluno, &matricula, nome, curso); 
		if(matricula == 2 && strcmp(nome,"Jacó") == 0 && strcmp(curso,"Sistemas de Informação") == 0) {
			printf("[Passou 1.50] - Teste da função atribui_a() com dados válidos!\n");
			pontuacao = 1.5;
		} else {
			printf("[Falhou 0.00] - Teste da função atribui_a() com dados válidos!\n");	
		}
	} else {
		printf("[Falhou 0.00] - Teste da função atribui_a() com dados válidos!\n");
	}
	return pontuacao;
}

float testeAtribuiComDadosInvalidos() {
	int matricula;
	char nome[55] = "N";
	char curso[35] = "C";
	float pontuacao = 0;

	for (int i = 0; i < 53; i++) {
		strcat(nome, "N");
	}

	for (int i = 0; i < 33; i++) {
		strcat(curso, "C");
	}

	Aluno *aluno = novo_a(1, "Abraão", "Computação");
	if (aluno != NULL){
		atribui_a(aluno, 2, nome, curso);
		acessa_a(aluno, &matricula, nome, curso); 
		if(matricula == 1 || strcmp(nome,"Abraão") == 0 || strcmp(curso,"Computação") == 0) {
			printf("[Passou 1.00] - Teste da função atribui_a() com dados inválidos!\n");
			pontuacao = 1;
		} else {
			printf("[Falhou 0.00] - Teste da função atribui_a() com dados inválidos!\n");
		}	
	} else{
		printf("[Falhou 0.00] - Teste da função atribui_a() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeAtribuiComDadosNulos() {
	int matricula;
	char nome[50];
	char curso[30];
	float pontuacao = 0;

	Aluno *aluno = novo_a(1, "Abraão", "Computação");
	if (aluno != NULL){
		atribui_a(aluno, 2, NULL, NULL);
		acessa_a(aluno, &matricula, nome, curso); 
		if(matricula == 1 && strcmp(nome,"Abraão") == 0 && strcmp(curso,"Computação") == 0) {
			printf("[Passou 0.67] - Teste da função atribui_a() com dados nulos!\n");
			pontuacao = 0.67;
		} else {
			printf("[Falhou 0.00] - Teste da função atribui_a() com dados nulos!\n");	
		}
	} else {
		printf("[Falhou 0.00] - Teste da função atribui_a() com dados nulos!\n");
	}
	return pontuacao;
}

float testeLiberaComDadosValidos() {
	int matricula;
	char nome[50];
	char curso[30];
	float pontuacao = 0;

	Aluno *aluno = novo_a(1, "Abraão", "Computação");
	libera_a(aluno);
	if (aluno != NULL) {
		acessa_a(aluno, &matricula, nome, curso); 
		if(matricula == 1 || strcmp(nome,"Abraão") == 0 || strcmp(curso,"Computação") == 0) {
			printf("[Falhou 0.00] - Teste da função libera_a() com dados válidos!\n");
		} else {
			printf("[Passou 1.50] - Teste da função libera_a() com dados válidos!\n");	
			pontuacao = 1.5;
		}
	} else {
		printf("[Passou 1.50] - Teste da função libera_a() com dados válidos!\n");
		pontuacao = 1.5;
	}
	return pontuacao;
}

float testeLiberaComDadosNulos() {
	int matricula;
	char nome[50];
	char curso[30];
	float pontuacao = 0;

	Aluno *aluno = NULL;
	libera_a(aluno);
	if (aluno == NULL) {
		printf("[Passou 0.67] - Teste da função libera_a() com dados nulos!\n");	
		pontuacao = 0.67;
	} else {
		printf("[Falhou 0.00] - Teste da função libera_a() com dados nulos!\n");
	}
	return pontuacao;
}


float testeNovaComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(1);
	if(fila != NULL) {
		printf("[Passou 1.00] - Teste da função nova_f() com dados válidos!\n");
		pontuacao = 1;
	} else {
		printf("[Falhou 0.00] - Teste da função nova_f() com dados válidos!\n");
	}
	return pontuacao;
}

float testeNovaComDadosInvalidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(-1);
	if(fila == NULL) {
		printf("[Passou 0.67] - Teste da função nova_f() com dados inválidos!\n");
		pontuacao = 0.67;
	} else {
		printf("[Falhou 0.00] - Teste da função nova_f() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeDestroiComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(2);
	destroi_f(fila);
	if(fila != NULL) {
		printf("[Falhou 0.00] - Teste da função destroi_f() com dados válidos!\n");
	} else {
		printf("[Passou 1.00] - Teste da função destroi_f() com dados válidos!\n");
		pontuacao = 1;
	}
	return pontuacao;
}

float testeDestroiComDadosNulos() {
	float pontuacao = 0;
	Fila *fila = NULL;
	destroi_f(fila);
	if(fila == NULL) {
		printf("[Passou 0.50] - Teste da função destroi_f() com dados nulos!\n");
		pontuacao = 0.50;
	} else {
		printf("[Falhou 0.00] - Teste da função destroi_f() com dados nulos!\n");
	}
	return pontuacao;
}

float testeCheia() {
	float pontuacao = 0;
	Fila *fila = nova_f(3);
	if(fila != NULL && !cheia_f(fila)) {
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		Aluno *jaco = novo_a(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		if (!cheia_f(fila)) {
			Aluno *jose = novo_a(3, "Jose", "Computação");
			adiciona_f(fila, jose);
			if(cheia_f(fila)) {
				printf("[Passou 1.00] - Teste da função cheia_f() com dados válidos!\n");
				pontuacao = 1;
			}
		} else {
			printf("[Falhou 0.00] - Teste da função cheia_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função cheia_f() com dados válidos!\n");
	}
	return pontuacao;
}


float testeAdicionaComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(3);
	if(fila != NULL) {
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		if(adiciona_f(fila, abraao)) {
			Aluno *jaco = novo_a(2, "Jaco", "Computação");
			if(adiciona_f(fila, jaco)) {
				Aluno *jose = novo_a(3, "Jose", "Computação");
				if(adiciona_f(fila, jose)) {
					printf("[Passou 1.00] - Teste da função adiciona_f() com dados válidos!\n");
					pontuacao = 1;
				} else {
					printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
				}	
			} else {
				printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
			}		
		} else {
			printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função adiciona_f() com dados válidos!\n");
	}
	return pontuacao;
}

float testeAdicionaComDadosInvalidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(2);
	if(fila != NULL) {
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		if(adiciona_f(fila, abraao)) {
			Aluno *jaco = novo_a(2, "Jaco", "Computação");
			if(adiciona_f(fila, jaco)) {
				Aluno *jose = novo_a(3, "Jose", "Computação");
				if(!adiciona_f(fila, jose)) {
					printf("[Passou 0.67] - Teste da função adiciona_f() com dados inválidos!\n");
					pontuacao = 0.67;
				} else {
					printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
				}	
			} else {
				printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
			}		
		} else {
			printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função adiciona_f() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeAdicionaComDadosNulos() {
	float pontuacao = 0;
	Fila *fila = nova_f(2);
	if(!adiciona_f(fila, NULL)) {
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		if(!adiciona_f(NULL, abraao)) {
			if(!adiciona_f(NULL, NULL)) {
				printf("[Passou 0.50] - Teste da função adiciona_f() com dados nulos!\n");
				pontuacao = 0.50;
			}else {
				printf("[Falhou 0.00] - Teste da função adiciona_f() com dados nulos!\n");
			}
		}else {
			printf("[Falhou 0.00] - Teste da função adiciona_f() com dados nulos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função adiciona_f() com dados nulos!\n");
	}
	return pontuacao;
}

float testeRetiraComDadosValidos() {
	float pontuacao = 0;
	Fila *fila = nova_f(3);
	if(fila != NULL) {
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		Aluno *jaco = novo_a(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		Aluno *jose = novo_a(3, "Jose", "Computação");
		adiciona_f(fila, jose);
		if(retira_f(fila)){
			if(retira_f(fila)){
				if (retira_f(fila)) {
					if(!retira_f(fila)) {
						printf("[Passou 1.00] - Teste da função retira_f() com dados válidos!\n");
						pontuacao = 1;
					} else {
						printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
					}
				} else {
					printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
				}
			} else {
				printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
			}
		} else {
			printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função retira_f() com dados válidos!\n");
	}
	return pontuacao;
}

float testeRetiraComDadosNulos() {
	float pontuacao = 0;
	if(!retira_f(NULL)){
		printf("[Passou 0.50] - Teste da função retira_f() com dados nulos!\n");
		pontuacao = 0.50;
	} else {
		printf("[Falhou 0.00] - Teste da função retira_f() com dados nulos!\n");
	}
	return pontuacao;
}

float testeBuscaComDadosValidos() {
	float pontuacao = 0;
	int matricula;
	char nome[50];
	char curso[30];

	Fila *fila = nova_f(3);
	if(fila != NULL) {
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		Aluno *jaco = novo_a(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		Aluno *jose = novo_a(3, "Jose", "Computação");
		adiciona_f(fila, jose);
		Aluno *aux = busca_f(fila, 2);
		if(aux != NULL){
			acessa_a(aux, &matricula, nome, curso);
			if(matricula == 2 && strcmp(nome,"Jaco") == 0 && strcmp(curso,"Computação") == 0) {
				printf("[Passou 1.00] - Teste da função busca_f() com dados válidos!\n");
				pontuacao = 1;				
			} else {
				printf("[Falhou 0.00] - Teste da função busca_f() com dados válidos!\n");
			}
		} else {
			printf("[Falhou 0.00] - Teste da função busca_f() com dados válidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função busca_f() com dados válidos!\n");
	}
	return pontuacao;
}

float testeBuscaComDadosInvalidos() {
	float pontuacao = 0;
	int matricula;
	char nome[50];
	char curso[30];

	Fila *fila = nova_f(3);
	if(fila != NULL) {
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		Aluno *jaco = novo_a(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		Aluno *jose = novo_a(3, "Jose", "Computação");
		adiciona_f(fila, jose);
		Aluno *aux = busca_f(fila, 5);
		if(aux == NULL){
			printf("[Passou 0.67] - Teste da função busca_f() com dados inválidos!\n");
			pontuacao = 0.67;				
		} else {
			printf("[Falhou 0.00] - Teste da função busca_f() com dados inválidos!\n");
		}
	} else {
		printf("[Falhou 0.00] - Teste da função busca_f() com dados inválidos!\n");
	}
	return pontuacao;
}

float testeBuscaComDadosNulos() {
	float pontuacao = 0;
	int matricula;
	char nome[50];
	char curso[30];

	Aluno *aux = busca_f(NULL, 1);
	if(aux == NULL){
		printf("[Passou 0.50] - Teste da função busca() com dados nulos!\n");
		pontuacao = 0.50;
	} else {
		printf("[Falhou 0.00] - Teste da função busca() com dados nulos!\n");
	}
	return pontuacao;
}

float bateriaTestes01() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Aluno: Bateria de Testes 01 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao = teste_novo_com_dados_validos() + testeAtribuiComDadosValidos() + testeAcessa() + testeLiberaComDadosValidos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

float bateriaTestes02() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Aluno: Bateria de Testes 02 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao = teste_novo_com_dados_invalidos() + testeAtribuiComDadosInvalidos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

float bateriaTestes03() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Aluno: Bateria de Testes 03 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao = testeNovoComDadosNulos() + testeAtribuiComDadosNulos() + testeLiberaComDadosNulos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

float bateriaTestes04() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Fila: Bateria de Testes 04 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao += testeNovaComDadosValidos() + testeAdicionaComDadosValidos();
	pontuacao += testeDestroiComDadosValidos() + testeRetiraComDadosValidos();
	pontuacao += testeBuscaComDadosValidos() + testeCheia();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

float bateriaTestes05() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Fila: Bateria de Testes 05 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao += testeNovaComDadosInvalidos() + testeAdicionaComDadosInvalidos();
	pontuacao += testeBuscaComDadosInvalidos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

float bateriaTestes06() {
	printf("=========================================================================================\n");
	printf(".:: Teste do TAD Fila: Bateria de Testes 06 ::.\n");
	printf("=========================================================================================\n");
	float pontuacao = 0;
	pontuacao += testeAdicionaComDadosNulos() + testeDestroiComDadosNulos();
	pontuacao += testeRetiraComDadosNulos() + testeBuscaComDadosNulos();
	printf("\nTotal: %f\n", pontuacao);
	printf("=========================================================================================\n\n");
	return pontuacao;
}

int main(void) {
	float pontuacaoTADAluno = bateriaTestes01();
	pontuacaoTADAluno += bateriaTestes02();
	pontuacaoTADAluno += bateriaTestes03();
	float pontuacaoTADFila = bateriaTestes04();
	pontuacaoTADFila += bateriaTestes05();
	pontuacaoTADFila += bateriaTestes06();
	printf("Nota Lista: %f\n", 0.3*pontuacaoTADAluno + 0.7*pontuacaoTADFila);
	return 0;
}