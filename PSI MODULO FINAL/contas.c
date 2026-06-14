#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fun.h"
#include <time.h>

void geradorCodigo(StructCliente *cliente, StructCasino *casino)
{
    int escolha = 0;
    menuGerador();
    if (scanf("%d", &escolha) != 1)
        return;

    if (escolha == 1)
    {
        int codigoSalvo = 0;
        char passwordSalva[20] = "";
        int dadosCorretos = 0;

        do
        {
            printf("Digite o seu código: ");
            scanf("%d", &cliente->codigoCliente);

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            printf("Digite a sua password: ");
            fgets(cliente->password, 20, stdin);
            cliente->password[strcspn(cliente->password, "\n")] = 0;

            FILE *f = fopen("dados.txt", "r");
            if (f != NULL)
            {
                if (fscanf(f, "%d\n", &codigoSalvo) != 1)
                    codigoSalvo = 0;
                if (fgets(passwordSalva, 20, f) != NULL)
                    passwordSalva[strcspn(passwordSalva, "\n")] = 0;
                fclose(f);
            }
            if (f == NULL)
            {
                codigoSalvo = 0;
                strcpy(passwordSalva, "");
            }

            if (codigoSalvo != 0)
            {
                if (cliente->codigoCliente == codigoSalvo)
                {
                    if (strcmp(cliente->password, passwordSalva) == 0)
                    {
                        printf("\nLogin efetuado com sucesso!\n");
                        dadosCorretos = 1;
                    }
                }
            }

            if (dadosCorretos == 0)
            {
                printf("\nErro: Código ou Password incorretos ou Conta Inexistente! Tente novamente.\n\n");
            }

        } while (dadosCorretos == 0);
    }
    if (escolha == 2)
    {
        criarConta(cliente, casino);
    }
    if (escolha == 0)
    {
        printf("A sair...\n");
        exit(0);
    }
    if (escolha < 0)
    {
        printf("Opção inválida!\n");
    }
    if (escolha > 2)
    {
        printf("Opção inválida!\n");
    }
}

void criarConta(StructCliente *cliente, StructCasino *casino)
{
    int c;
    int petsLocal = 0;

    printf("Digite a sua idade: ");
    if (scanf("%d", &cliente->idadeClienteMain) != 1)
    {
        printf("Digite números, não letras!\n");
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        return;
    }

    if (cliente->idadeClienteMain > 117)
    {
        printf("Idade inválida ou menor de 18 anos!\n");
        return;
    }
    if (cliente->idadeClienteMain < 18)
    {
        printf("Idade inválida ou menor de 18 anos!\n");
        return;
    }

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Digite o seu nome: ");
    fgets(cliente->nomeClienteMain, 50, stdin);
    cliente->nomeClienteMain[strcspn(cliente->nomeClienteMain, "\n")] = 0;

    printf("Digite dia de nascimento: ");
    if (scanf("%d", &cliente->aniversarioClienteMain) != 1)
    {
        printf("Dia inválido!\n");
        return;
    }
    if (cliente->aniversarioClienteMain > 31)
    {
        printf("Dia inválido!\n");
        return;
    }
    if (cliente->aniversarioClienteMain <= 0)
    {
        printf("Dia inválido!\n");
        return;
    }

    printf("Digite o seu mês de nascimento: ");
    if (scanf("%d", &cliente->mesNascimentoClienteMain) != 1)
    {
        printf("Mês inválido!\n");
        return;
    }
    if (cliente->mesNascimentoClienteMain > 12)
    {
        printf("Mês inválido!\n");
        return;
    }
    if (cliente->mesNascimentoClienteMain <= 0)
    {
        printf("Mês inválido!\n");
        return;
    }

    printf("Digite o seu ano de nascimento: ");
    if (scanf("%d", &cliente->anoNascimentoClienteMain) != 1)
    {
        printf("Ano inválido!\n");
        return;
    }
    if (cliente->anoNascimentoClienteMain > casino->anoAtual)
    {
        printf("Ano inválido!\n");
        return;
    }

    int idadePorAno = casino->anoAtual - cliente->anoNascimentoClienteMain;
    int margemErro = idadePorAno - cliente->idadeClienteMain;

    if (margemErro < 0)
    {
        printf("\nA tua idade não bate certo com o teu ano de nascimento!\n");
        cliente->codigoCliente = -1;
        return;
    }
    if (margemErro > 1)
    {
        printf("\nA tua idade não bate certo com o teu ano de nascimento!\n");
        cliente->codigoCliente = -1;
        return;
    }

    printf("Quantos animais de estimação tem???\n");
    if (scanf("%d", &petsLocal) != 1)
    {
        printf("Valor inválido!\n");
        return;
    }
    if (petsLocal < 0)
    {
        printf("Valor inválido!\n");
        return;
    }

    // Correção: Atribuir o valor validado à struct do cliente para não se perder
    cliente->pets = petsLocal;

    printf("Conta criada com sucesso!\n");
}

void apagarContaNoArray(StructCliente listaClientes[], int *totalClientes, char *usernameParaApagar)
{
    int posicaoDaContaAlvo = -1;

    for (int posicao = 0; posicao < *totalClientes; posicao++)
    {
        if (strcmp(listaClientes[posicao].username, usernameParaApagar) == 0)
        {
            posicaoDaContaAlvo = posicao;
            break;
        }
    }

    if (posicaoDaContaAlvo != -1)
    {
        for (int posicao = posicaoDaContaAlvo; posicao < (*totalClientes) - 1; posicao++)
        {
            listaClientes[posicao] = listaClientes[posicao + 1];
        }

        (*totalClientes)--;

        printf("Conta apagada com sucesso da memoria!\n");
    }
    if (posicaoDaContaAlvo == -1)
    {
        printf("Esse utilizador não foi encontrado!\n");
    }
}