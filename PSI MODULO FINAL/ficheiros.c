#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fun.h"
#include <time.h>

// ============================================================================
// 1. CARREGAMENTO DE DADOS (READ)
// ============================================================================

void carregarDinheiroFichasCasino(StructCasino *casino)
{
    FILE *fptr = fopen("dinheiroFichasCasino.txt", "r");

    if (fptr == NULL)
    {
        printf("\n[AVISO] O ficheiro de dados do Casino não existe ou falhou a abrir!\n");
        printf("O sistema vai usar os valores padrão de fábrica.\n");
        return;
    }

    if (fscanf(fptr, "%d %d %d %d",
               &casino->dinheiroCasinoTotal,
               &casino->dinheiroCasinoAtual,
               &casino->fichasCasinoTotal,
               &casino->pontosTotaisCasino,
               &casino->fichasCasinoAtual)
        == 5)
    {
        printf("\n[SUCESSO] Dados do Casino carregados com sucesso!\n");
    }
    else
    {
        printf("\n[ERRO CRÍTICO] O ficheiro existe, mas os dados estão corrompidos!\n");
    }
    fclose(fptr);
}

void carregarContasSeguranca(StructCasino *casino, StructCliente *cliente)
{
    FILE *fptr = fopen("contasSeguranca.txt", "r");

    if (fptr == NULL)
    {
        printf("\n[AVISO] O ficheiro de credenciais e contas não existe!\n");
        printf("O sistema vai pedir um novo registo ao iniciar.\n");
        return;
    }

    if (fscanf(fptr, "%d %d %d %d %d %d %d",
               &casino->pinNumero,
               &casino->anoAtual,
               &cliente->idadeClienteMain,
               &cliente->anoNascimentoClienteMain,
               &cliente->aniversarioClienteMain,
               &cliente->mesNascimentoClienteMain,
               &cliente->JogadasTotais) == 7)
    {
        fscanf(fptr, " %[^\n]", casino->password);
        fscanf(fptr, " %[^\n]", cliente->username);
        fscanf(fptr, " %[^\n]", cliente->nomeClienteMain);

        printf("\n[SUCESSO] Dados de conta e segurança carregados com sucesso!\n");
    }
    else
    {
        printf("\n[ERRO CRÍTICO] O ficheiro de contas existe, mas os dados numéricos estão corrompidos!\n");
    }
    fclose(fptr);
}

void carregarFeedbackAvaliacoes(StructCliente *cliente, int *avaliacao, int *avaliacaoSingular, char *feedback, int *naoQueroResponderAvaliacao, int *naoQueroResponderFeedback, char *respostaAvaliacao)
{
    FILE *fptr = fopen("feedbackAvaliacoes.txt", "r");

    if (fptr == NULL)
    {
        printf("\n[AVISO] O ficheiro de feedback e avaliações ainda não existe!\n");
        printf("O sistema de inquéritos iniciará vazio.\n");
        return;
    }

    if (fscanf(fptr, "%d %d %d %d",
               avaliacao,
               avaliacaoSingular,
               naoQueroResponderAvaliacao,
               naoQueroResponderFeedback) == 4)
    {
        fscanf(fptr, " %[^\n]", feedback);
        fscanf(fptr, " %[^\n]", respostaAvaliacao);

        printf("\n[SUCESSO] Avaliações e notas anteriores carregadas com sucesso!\n");
    }
    else
    {
        printf("\n[ERRO] O ficheiro de feedback existe, mas os dados estão corrompidos!\n");
    }
    fclose(fptr);
}

void carregarEstatisticasCasino(StructCasino *casino)
{
    FILE *fptr = fopen("estatisticasCasino.txt", "r");

    if (fptr == NULL)
    {
        printf("\n[AVISO] O ficheiro de estatísticas do casino não existe!\n");
        printf("Os contadores administrativos vão iniciar com os valores padrão.\n");
        return;
    }

    if (fscanf(fptr, "%d %d %d %d %d %d %d %d %d %d %d",
               &casino->lucroCasinoTotal,
               &casino->prejuizoCasinoTotal,
               &casino->avisoFaltaDinheiroCasino,
               &casino->avisoFaltaFichasCasino,
               &casino->transacoes,
               &casino->dinheiroCasinoTroca,
               &casino->fichasCasinoTrocadas,
               &casino->fichasCasinoTroca,
               &casino->dinheiroRetiradoTotalClientes,
               &casino->dinheiroDepositadoTotalClientes,
               &casino->limiteSegurancaAlto) == 11)
    {
        printf("\n[SUCESSO] Estatísticas administrativas do casino carregadas!\n");
    }
    else
    {
        printf("\n[ERRO] Ficheiro administrativo detetado, mas os dados estão corrompidos!\n");
    }
    fclose(fptr);
}

void carregarEstatisticasCliente(StructCliente *cliente)
{
    FILE *fptr = fopen("estatisticasCliente.txt", "r");

    if (fptr == NULL)
    {
        printf("\n[AVISO] O ficheiro de estatísticas do cliente não existe!\n");
        printf("Os contadores e recordes vão iniciar a zeros.\n");
        return;
    }

    if (fscanf(fptr, "%d %d %d %d %d %d %d %d %d %d %d %d",
               &cliente->dinheiroDepositado,
               &cliente->dinheiroRetirado,
               &cliente->fichasDepositadas,
               &cliente->fichasRetiradas,
               &cliente->lucroClienteDiario,
               &cliente->prejuizoClienteTotal,
               &cliente->maiorTransacao,
               &cliente->maiorTransacaoDinheiro,
               &cliente->maiorTransacaoFichas,
               &cliente->maiorCompraFichas,
               &cliente->maiorVendaFichas,
               &cliente->avisosCliente) == 12)
    {
        printf("\n[SUCESSO] Estatísticas e recordes do cliente carregados!\n");
    }
    else
    {
        printf("\n[ERRO] Ficheiro de estatísticas detetado, mas os dados estão incompletos!\n");
    }
    fclose(fptr);
}

void carregarDinheiroFichasCliente(StructCliente *cliente)
{
    FILE *fptr = fopen("dinheiroFichasCliente.txt", "r");

    if (fptr == NULL)
    {
        printf("\n[AVISO] O ficheiro de dados do Cliente não existe ou falhou a abrir!\n");
        printf("O cliente vai começar com os valores padrão de carteira.\n");
        return;
    }

    if (fscanf(fptr, "%d %d %d %d %d %d",
               &cliente->codigoCliente,
               &cliente->dinheiroTotal,
               &cliente->dinheiroAtual,
               &cliente->fichasTotais,
               &cliente->fichasAtuais) == 5)
    {
        printf("\n[SUCESSO] Dados do Cliente '%s' carregados com sucesso!\n", cliente->username);
    }
    else
    {
        printf("\n[ERRO CRÍTICO] O ficheiro do cliente existe, mas os dados estão corrompidos!\n");
    }
    fclose(fptr);
}

// ============================================================================
// 2. GRAVAÇÃO DE DADOS (WRITE - RAW DATA PARA LEITURA)
// ============================================================================

void guardarDinheiroFichasCasino(StructCasino *casino)
{
    FILE *fptr = fopen("dinheiroFichasCasino.txt", "w");
    if (fptr == NULL)
        return;

    fprintf(fptr, "%d %d %d %d %d\n",
            casino->dinheiroCasinoTotal,
            casino->dinheiroCasinoAtual,
            casino->fichasCasinoTotal,
            casino->fichasCasinoAtual,
            casino->pontosTotaisCasino);
    fclose(fptr);
}

void guardarContasSeguranca(StructCasino *casino, StructCliente *cliente)
{
    FILE *fptr = fopen("contasSeguranca.txt", "w");
    if (fptr == NULL)
        return;

    fprintf(fptr, "%d %d %d %d %d %d %d\n",
            casino->pinNumero, casino->anoAtual, cliente->idadeClienteMain,
            cliente->anoNascimentoClienteMain, cliente->aniversarioClienteMain,
            cliente->mesNascimentoClienteMain, cliente->JogadasTotais);

    fprintf(fptr, "%s\n", casino->password[0] == '\0' ? "SemPassword" : casino->password);
    fprintf(fptr, "%s\n", cliente->username[0] == '\0' ? "SemUsername" : cliente->username);
    fprintf(fptr, "%s\n", cliente->nomeClienteMain[0] == '\0' ? "Nenhum" : cliente->nomeClienteMain);
    fclose(fptr);
}

void guardarFeedbackAvaliacoes(int avaliacao, int avaliacaoSingular, int naoQueroResponderAvaliacao, int naoQueroResponderFeedback, char *feedback, char *respostaAvaliacao)
{
    FILE *fptr = fopen("feedbackAvaliacoes.txt", "w");
    if (fptr == NULL)
        return;

    fprintf(fptr, "%d %d %d %d\n", avaliacao, avaliacaoSingular, naoQueroResponderAvaliacao, naoQueroResponderFeedback);
    fprintf(fptr, "%s\n", feedback[0] == '\0' ? "(SemComentario)" : feedback);
    fprintf(fptr, "%s\n", respostaAvaliacao[0] == '\0' ? "(SemResposta)" : respostaAvaliacao);
    fclose(fptr);
}

void guardarEstatisticaCasino(StructCasino *casino)
{
    FILE *fptr = fopen("estatisticasCasino.txt", "w"); // Nome corrigido (.txt correto)
    if (fptr == NULL)
        return;

    fprintf(fptr, "%d %d %d %d %d %d %d %d %d %d %d\n",
            casino->lucroCasinoTotal, casino->prejuizoCasinoTotal, casino->avisoFaltaDinheiroCasino,
            casino->avisoFaltaFichasCasino, casino->transacoes, casino->dinheiroCasinoTroca,
            casino->fichasCasinoTrocadas, casino->fichasCasinoTroca, casino->dinheiroRetiradoTotalClientes,
            casino->dinheiroDepositadoTotalClientes, casino->limiteSegurancaAlto);
    fclose(fptr);
}

void guardarEstatisticasCliente(StructCliente *cliente)
{
    FILE *fptr = fopen("estatisticasCliente.txt", "w");
    if (fptr == NULL)
        return;

    fprintf(fptr, "%d %d %d %d %d %d %d %d %d %d %d %d\n",
            cliente->dinheiroDepositado, cliente->dinheiroRetirado, cliente->fichasDepositadas,
            cliente->fichasRetiradas, cliente->lucroClienteDiario, cliente->prejuizoClienteTotal,
            cliente->maiorTransacao, cliente->maiorTransacaoDinheiro, cliente->maiorTransacaoFichas,
            cliente->maiorCompraFichas, cliente->maiorVendaFichas, cliente->avisosCliente);
    fclose(fptr);
}

void guardarDinheiroFichasCliente(StructCliente *cliente)
{
    FILE *fptr = fopen("dinheiroFichasCliente.txt", "w"); // Nome e formato corrigidos
    if (fptr == NULL)
        return;

    fprintf(fptr, "%d %d %d %d %d\n",
            cliente->codigoCliente, cliente->dinheiroTotal,
            cliente->dinheiroAtual, cliente->fichasTotais, cliente->fichasAtuais);
    fclose(fptr);
}

// ============================================================================
// 3. RELATÓRIOS VISUAIS (APENAS PARA HUMANOS LEREM - SEM FUNÇÃO DE CARREGAR)
// ============================================================================

void estatisticaClientes(StructCliente *cliente)
{
    FILE *fptr = fopen("Log_EstatisticaClientes_Visual.txt", "a"); // Nome alterado para não confundir com o Save
    if (fptr == NULL)
        return;

    fprintf(fptr, "=== ESTATISTICAS DO JOGADOR: %s ===\n", cliente->username);
    fprintf(fptr, "Jogadas Totais realizadas: %d\n", cliente->JogadasTotais);
    fprintf(fptr, "Recorde de Pontuacao/Ganhos: %d\n", cliente->recordes);
    fprintf(fptr, "[FINANCEIRO DO JOGADOR]\n");
    fprintf(fptr, "Maior Transacao em Dinheiro: %d\n", cliente->maiorTransacaoDinheiro);
    fprintf(fptr, "Maior Transacao em Fichas: %d\n", cliente->maiorTransacaoFichas);
    fprintf(fptr, "Maior Compra de Fichas: %d\n", cliente->maiorCompraFichas);
    fprintf(fptr, "Maior Venda de Fichas: %d\n", cliente->maiorVendaFichas);
    fprintf(fptr, "[SALDO FINAL DA SESSÃO]\n");
    fprintf(fptr, "Lucro do Dia: %d\n", cliente->lucroClienteDiario);
    fprintf(fptr, "Prejuizo Acumulado: %d\n", cliente->prejuizoClienteTotal);
    fprintf(fptr, "Dinheiro com que saiu: %d\n", cliente->dinheiroAtual);
    fprintf(fptr, "Fichas com que saiu: %d\n", cliente->fichasAtuais);
    fprintf(fptr, "--------------------------------------------------\n\n");
    fclose(fptr);
}

void guardarContas(StructCliente *cliente)
{
    FILE *fptr = fopen("Log_Contas_Visual.txt", "a"); // Nome alterado para não confundir com o Save
    if (fptr == NULL)
        return;

    fprintf(fptr, "O %s tem %d nasceu em %d chama-se %s e nasceu a %d de %d \n",
            cliente->username, cliente->idadeClienteMain, cliente->anoNascimentoClienteMain,
            cliente->nomeClienteMain[0] == '\0' ? "Nenhum" : cliente->nomeClienteMain,
            cliente->aniversarioClienteMain, cliente->mesNascimentoClienteMain);
    fclose(fptr);
}
void guardarRankingDeJogadasEmFicheiro(StructCliente listaDeClientes[], int quantidadeDeClientes) {
    FILE *ficheiro = fopen("leaderboard.txt", "a"); 

    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro para guardar o ranking.\n");
        return;
    }

    fprintf(ficheiro, "--- TABELA DE LIDERES (JOGADAS) ---\n");
    
    for (int posicaoNoRanking = 0; posicaoNoRanking < quantidadeDeClientes; posicaoNoRanking++) {
        fprintf(ficheiro, "%dº lugar: %s com %d jogadas totais\n", 
               posicaoNoRanking + 1, 
               listaDeClientes[posicaoNoRanking].username, 
               listaDeClientes[posicaoNoRanking].JogadasTotais);
    }

    fclose(ficheiro); // Fecha o ficheiro para salvar as alterações
    printf("Ranking de jogadas guardado com sucesso em 'leaderboard.txt'!\n");
}
void guardarRankingDeRecordesEmFicheiro(StructCliente listaDeClientes[], int quantidadeDeClientes) {
    // Usamos "a" (append) se quiseres adicionar ao fim do ficheiro, 
    // ou "w" (write) se quiseres apagar o que lá estava e escrever apenas este ranking.
    FILE *ficheiro = fopen("leaderboard.txt", "a"); 

    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro para guardar o ranking.\n");
        return;
    }

    fprintf(ficheiro, "\n--- TABELA DE LIDERES (MAIORES RECORDES) ---\n");
    
    for (int posicaoNoRanking = 0; posicaoNoRanking < quantidadeDeClientes; posicaoNoRanking++) {
        fprintf(ficheiro, "%dº lugar: %s com %d pontos de recorde\n", 
               posicaoNoRanking + 1, 
               listaDeClientes[posicaoNoRanking].username, 
               listaDeClientes[posicaoNoRanking].recordes);
    }

    fclose(ficheiro);
    printf("Ranking de recordes guardado com sucesso em 'leaderboard.txt'!\n");
}
int carregarClientesDoFicheiro(StructCliente listaDeClientes[]) {
    // Agora apontamos para o teu ficheiro "leaderboard.txt"
    FILE *ficheiro = fopen("leaderboard.txt", "r"); 
    int quantidadeDeClientes = 0;

    if (ficheiro == NULL) {
        printf("Ficheiro 'leaderboard.txt' nao encontrado. A comecar do zero.\n");
        return 0; 
    }

    // Nota: O fscanf precisa de ser compatível com o formato que escreves no ficheiro.
    // Se no ficheiro escreveste texto fixo como "Nome: Eduardo", 
    // o fscanf precisa de ser ajustado. 
    // Se o ficheiro contiver apenas os dados puros (Ex: Eduardo 10 50), o código abaixo funciona:
    
    while (fscanf(ficheiro, "%s %d %d", 
           listaDeClientes[quantidadeDeClientes].username, 
           &listaDeClientes[quantidadeDeClientes].JogadasTotais, 
           &listaDeClientes[quantidadeDeClientes].recordes) == 3) {
        
        quantidadeDeClientes++;
    }

    fclose(ficheiro);
    printf("Carregados %d clientes do ficheiro 'leaderboard.txt' com sucesso!\n", quantidadeDeClientes);
    return quantidadeDeClientes; 
}