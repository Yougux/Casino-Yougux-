#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fun.h"
#include <time.h>

void avaliacaoCasino(StructCasino *casino, StructCliente *cliente, int *apontadorCerto, int *apontadorAvaliacao, int *apontadorNaoQueroResponderAvaliacao, int *apontadorNaoQueroResponderFeedback, char *feedback, char *respostaAvaliacao,char *password)
{
    int escolha = 0;
    printf("Já fez muitas transações. Gostaria de avaliar o casino de 0 a 100?\n");
    printf("1-Sim\n");
    printf("2-Não\n");
    printf("3-Não voltar a perguntar\n");

    if (scanf(" %d", &escolha) != 1)
    {
        printf("Digite apenas números!\n");
        (cliente->avisosCliente)++;
        return;
    }

    if (escolha == 1)
    {
        printf("Digite a nota (0-100):\n");
        if (scanf(" %d", apontadorAvaliacao) != 1)
        {
            printf("Erro: Digite um número.\n");
            (cliente->avisosCliente)++;
            return;
        }

        if (*apontadorAvaliacao < 100)
        {
            int choiceFeedback = 0;
            printf("O que podemos melhorar?\n1-Responder\n2-Não quero responder\n3-Nunca perguntar\n");
            scanf(" %d", &choiceFeedback);

            if (choiceFeedback == 1)
            {
                printf("Escreva seu feedback:\n");
                while (getchar() != '\n')
                    ;
                fgets(respostaAvaliacao, 200, stdin);
            }
            if (choiceFeedback == 2)
            {
                printf("Obrigado pela avaliação!\n");
            }
            if (choiceFeedback == 3)
            {
                (*apontadorNaoQueroResponderFeedback)++;
                printf("Não voltaremos a perguntar!\n");
            }
            if (choiceFeedback < 1)
            {
                (cliente->avisosCliente)++;
            }
            if (choiceFeedback > 3)
            {
                (cliente->avisosCliente)++;
            }
        }
    }
    if (escolha == 2)
    {
        printf("Obrigado!\n");
    }
    if (escolha == 3)
    {
        (*apontadorNaoQueroResponderAvaliacao)++;
        printf("Configuração guardada!\n");
    }
    if (escolha < 1)
    {
        (cliente->avisosCliente)++;
    }
    if (escolha > 3)
    {
        (cliente->avisosCliente)++;
    }
}
void organizarRankingPorJogadas(StructCliente listaDeClientes[], int quantidadeDeClientes) {
    StructCliente clienteTemporarioParaTroca;
    
    // O ciclo externo controla quantas vezes percorremos a lista
    for (int passoAtual = 0; passoAtual < quantidadeDeClientes - 1; passoAtual++) {
        
        // O ciclo interno compara cada cliente com o próximo
        for (int posicaoAtual = 0; posicaoAtual < quantidadeDeClientes - passoAtual - 1; posicaoAtual++) {
            
            // Se o cliente da frente tiver menos jogadas que o de trás, trocamos
            if (listaDeClientes[posicaoAtual].JogadasTotais < listaDeClientes[posicaoAtual + 1].JogadasTotais) {
                
                // Realiza a troca de lugar entre os dois clientes
                clienteTemporarioParaTroca = listaDeClientes[posicaoAtual];
                listaDeClientes[posicaoAtual] = listaDeClientes[posicaoAtual + 1];
                listaDeClientes[posicaoAtual + 1] = clienteTemporarioParaTroca;
            }
        }
    }
}
void mostrarRankingNaTela(StructCliente listaDeClientes[], int quantidadeDeClientes) {
    printf("\n--- TABELA DE LIDERES (RANKING) ---\n");
    
    for (int posicaoNoRanking = 0; posicaoNoRanking < quantidadeDeClientes; posicaoNoRanking++) {
        printf("%dº lugar: %s com %d jogadas totais\n", 
               posicaoNoRanking + 1, 
               listaDeClientes[posicaoNoRanking].username, 
               listaDeClientes[posicaoNoRanking].JogadasTotais);
    }
}
void organizarRankingPorRecordes(StructCliente listaDeClientes[], int quantidadeDeClientes) {
    StructCliente clienteTemporarioParaTroca;
    
    // O ciclo externo controla quantas vezes percorremos a lista
    for (int passoAtual = 0; passoAtual < quantidadeDeClientes - 1; passoAtual++) {
        
        // O ciclo interno compara cada cliente com o próximo
        for (int posicaoAtual = 0; posicaoAtual < quantidadeDeClientes - passoAtual - 1; posicaoAtual++) {
            
            // Se o cliente da frente tiver um recorde MENOR que o de trás, trocamos
            // Assim, o maior recorde sobe para as primeiras posições
            if (listaDeClientes[posicaoAtual].recordes < listaDeClientes[posicaoAtual + 1].recordes) {
                
                // Realiza a troca de lugar entre os dois clientes
                clienteTemporarioParaTroca = listaDeClientes[posicaoAtual];
                listaDeClientes[posicaoAtual] = listaDeClientes[posicaoAtual + 1];
                listaDeClientes[posicaoAtual + 1] = clienteTemporarioParaTroca;
            }
        }
    }
}
void mostrarRankingDeRecordesNaTela(StructCliente listaDeClientes[], int quantidadeDeClientes) {
    printf("\n--- TABELA DE LIDERES (MAIORES RECORDES) ---\n");
    
    for (int posicaoNoRanking = 0; posicaoNoRanking < quantidadeDeClientes; posicaoNoRanking++) {
        printf("%dº lugar: %s com %d pontos de recorde\n", 
               posicaoNoRanking + 1, 
               listaDeClientes[posicaoNoRanking].username, 
               listaDeClientes[posicaoNoRanking].recordes);
    }
}