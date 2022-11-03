#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int covid()
{
	char res;

	system("cls");

	printf("O paciente possui covid-19 ? \n");
	printf("[1]Sim \n[2]Não \n\nResposta: ");
	scanf("%c", &res);

	switch (res)
	{
	case '1':
		printf("Iniciar o Login\n\n");
		system("pause");
		system("cls");
		login();
		break;

	case '2':
		printf("Encaminhe para a ala não covid");
		break;

	default:
		printf("Digite penas o valor 1 ou 2 \n");
		covid();
		break;
	}
}

int login()
{
	char user[10] = "login";
	char password[10] = "login";
	char user1[10];
	char password1[10];
	do
	{
		printf("Digite o Login: ");
		scanf("%s", user1);

		printf("Digite a Senha: ");
		scanf("%s", password1);

		if (strcmp(user, user1) == 0 && strcmp(password, password1) == 0)
		{
			printf("\n\nLOGADO!\n\n");
		}
		else
		{
			printf("\n\nDADOS INVALIDOS!\n\n");
		}

		system("pause");
		system("cls");
	} while (strcmp(user, user1) != 0 || strcmp(password, password1) != 0);
}

int cadastro()
{
	char res;

	system("cls");

	printf("O que deseja? \n");
	printf("[1]Cadastrar \n[2]Visualizar \n[3]Deletar \n[4]Finalizar \n\nResposta: ");
	scanf("%c", &res);

	switch (res)
	{
	case '1':
		chamaPostPaciente();
		break;

	case '2':
		chamaPrintPaciente();
		break;

	case '3':
		printf("Deletar paciente: \n\n");
		break;

	case '4':
		printf("Operação finalizada!! \n\n");
		system("pause");
		break;

	default:
		printf("Digite penas o valor 1, 2 ou 3 \n");
		cadastro();
		break;
	}
}

typedef struct Paciente
{
	char nome[10];
	int cpf;
	struct Paciente *proximo;
} No;

No *primeiro, *atual, *novo;

No *inicio()
{
	return NULL;
};

No *PostPaciente()
{
	char temp[80];
	No *NovoLivro = (No *)malloc(sizeof(No));
	if (primeiro == (No *)NULL)
		primeiro = atual = NovoLivro;
	else
	{
		atual = primeiro;
		while (atual->proximo != (No *)NULL)
			atual = atual->proximo;
		atual->proximo = NovoLivro;
		atual = NovoLivro;
	}
	system("cls");
	printf("Digite Nome: ");
	scanf("%s", &atual->nome);
	printf("Digite CPF: ");
	scanf("%d", &atual->cpf);
	atual->proximo = (No *)NULL;
}

int chamaPostPaciente()
{
	char ch;
	primeiro = (No *)NULL;
	do
	{
		PostPaciente();
		system("cls");
		puts("\nInserir outro paciente(s/n?) ");
		ch = getch();
	} while ((ch != 'n') && (ch != 'N'));
	cadastro();
}

void PrintPaciente()
{
	if (primeiro == (No *)NULL)
	{
		puts("Lista VAZIA");
		return;
	}
	atual = primeiro;
	do
	{
		printf("Nome : %s\n", atual->nome);
		printf("CPF : %d\n", atual->cpf);
		atual = atual->proximo;
		puts("=================================");
	} while (atual != NULL);
}

int chamaPrintPaciente()
{
	system("cls");
	puts("\nLista do pacientes com Covid");
	puts("=================================");
	PrintPaciente();
	system("pause");
	cadastro();
}

int main()
{
	setlocale(LC_ALL, "#pragma endregionPortuguese");

	printf("\t\t\t\t\t Hospital PIM IV \n");
	covid();
	cadastro();
	printf("-------------------------------------------------------------------------------\n");
	printf("                           FIM                                  \n");
	printf("-------------------------------------------------------------------------------");
}