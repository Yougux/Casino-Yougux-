#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "contas.c"
#include "jogos.c"
#include "ficheiros.c"
#include "textao.c"

int main()
{
    system("chcp 65001");
    system("cls");

    StructCasino casino;
    casino.pontosAtuaisCasino = 0;
    casino.pontosTotaisCasino = 0;
    casino.pontosTrocaCasino = 0;

    casino.avisoFaltaDinheiroCasino = 0;
    casino.avisoFaltaFichasCasino = 0;
    casino.transacoes = 0;
    casino.dinheiroCasinoTroca = 0;
    casino.dinheiroCasinoTotal = 0;
    casino.dinheiroCasinoAtual = 0;
    casino.fichasCasinoTotal = 0;
    casino.fichasCasinoAtual = 0;
    casino.fichasCasinoTrocadas = 0;
    casino.fichasCasinoTroca = 0;
    casino.doadorFraco = 0;
    casino.doadorMedio = 0;
    casino.BaseDados = 0;
    casino.inicioADM = 0;
    casino.doadorForte = 0;
    casino.doadorHeroi = 0;
    casino.pinNumero = 7129;
    casino.anoAtual = 2026;
    casino.limiteSegurancaMuitoBaixo = 88888;
    casino.limiteSegurancaBaixo = 99999;
    casino.limiteSegurancaMedio = 1000000000;
    casino.limiteSegurancaAlto = 2000000000;
    strcpy(casino.password, "Yougux.2010");
    casino.logins = 0;
    casino.criarContaVezes = 0;
    casino.lucroCasinoTotal = 0;
    casino.prejuizoCasinoTotal = 0;
    casino.dinheiroRetiradoTotalClientes = 0;
    casino.dinheiroDepositadoTotalClientes = 0;
    casino.vezesJogouBolsa=0;

    StructCliente cliente;
    cliente.codigoCliente = 0;
    cliente.pontosAtuais = 0;
    cliente.pontosTotais = 0;
    cliente.pontosTroca = 0;
    cliente.idadeClienteMain = 0;
    cliente.aniversarioClienteMain = 0;
    cliente.mesNascimentoClienteMain = 0;
    cliente.anoNascimentoClienteMain = 0;
    cliente.avisosCliente = 0;
    cliente.pets = 0;
    cliente.fichasTotais = 0;
    cliente.dinheiroTotal = 0;
    cliente.dinheiroAtual = 0;
    cliente.fichasAtuais = 0;
    cliente.dinheiroRetirado = 0;
    cliente.dinheiroDepositado = 0;
    cliente.fichasRetiradas = 0;
    cliente.fichasDepositadas = 0;
    cliente.dinheiroTrocado = 0;
    cliente.fichasTrocadas = 0;
    cliente.dinheiroDoado = 0;
    cliente.fichasDoadas = 0;
    cliente.maiorTransacaoDinheiro = 0;
    cliente.maiorTransacaoFichas = 0;
    cliente.maiorCompraFichas = 0;
    cliente.maiorVendaFichas = 0;
    cliente.JogadasTotais = 0;
    cliente.recordes = 0;
    cliente.recordeCompraFichas = 0;
    cliente.recordeVendeFichas = 0;
    cliente.maiorTransacao = 0;
    cliente.TransacaoFichas = 0;
    cliente.transacaoDinheiro = 0;
    cliente.lucroClienteDiario = 0;
    cliente.prejuizoClienteTotal = 0;
    strcpy(cliente.username, "");
    strcpy(cliente.password, ""); // Corrigido para corresponder à struct unificada
    strcpy(cliente.nomeClienteMain, "");
    cliente.semIncomodo = 0;

    // =================================================================
    // 2. VARIÁVEIS SOLTAS NO MAIN (Sem Struct)
    // =================================================================
    int escolha = 0;
    int respostaDiferenca = 0;
    int permissaoAvaliacao = 0;
    int permissaoFeedback = 0;
    int dIferenciaAno = 0;
    int certo = 0;
    int erroDepositoCliente = 0;
    int avaliacao = 0;
    int avaliacaoSingular = 0;
    int avaliacaoSingularFeedback = 0;
    int naoQueroResponderAvaliacao = 0;
    int naoQueroResponderFeedback = 0;
    int dIferencia = 0;

    // --- STRINGS SOLTAS QUE MUDAM A CADA SESSÃO ---
    char feedback[200] = "";
    char respostaAvaliacao[200] = "";

    // =================================================================
    // 3. OS TEUS APONTADORES ANTIGOS
    // =================================================================
    int *apontadorFichasCasinoTotal = &casino.fichasCasinoTotal;
    int *apontadorFichasCasinoAtuais = &casino.fichasCasinoAtual;
    int *apontadorDinheiroCasinoTotal = &casino.dinheiroCasinoTotal;
    int *apontadorDinheiroCasinoAtual = &casino.dinheiroCasinoAtual;

    int *apontadorFichas = &cliente.fichasTotais;
    int *apontadorDinheiro = &cliente.dinheiroTotal;
    int *apontadorAvisosCliente = &cliente.avisosCliente;
    int *apontadorInIcioAdm = &casino.inicioADM;
    int *apontadorAnoAtual = &casino.anoAtual;
    int *apontadorCerto = &certo;
    int *apontadorAvaliacao = &avaliacao;
    int *apontadorAvaliacaoSingular = &avaliacaoSingular;
    int *apontadorNaoQueroResponderAvaliacao = &naoQueroResponderAvaliacao;
    int *apontadorNaoQueroResponderFeedback = &naoQueroResponderFeedback;
    int *apontadorAvaliacaoSingularFeedback = &avaliacaoSingularFeedback;
    char *apontadorFeedback = feedback;
    char *apontadorRespostaAvaliacao = respostaAvaliacao;

    do
    {
        carregarDinheiroFichasCasino(&casino);
        carregarDinheiroFichasCliente(&cliente);
        carregarEstatisticasCliente(&cliente);
        carregarEstatisticasCasino(&casino);
        carregarContasSeguranca(&casino, &cliente);

        carregarFeedbackAvaliacoes(&cliente, &avaliacao, &avaliacaoSingular, feedback, &naoQueroResponderAvaliacao, &naoQueroResponderFeedback, respostaAvaliacao);
        menu();

        if (scanf("%d", &escolha) != 1)
        {
            printf("Digite números não letras!!!\n");
            fflush(stdin);
            break;
        }

        switch (escolha)
        {
        case 1:
            jogoCartasSorte(&cliente.fichasAtuais);
            break;

        case 2:
            break;

        case 3:
        {
            int escolhaMenuFichas = 0;
            int erroTroca = 0;

            menuFichas();
            scanf("%d", &escolhaMenuFichas);

            if (escolhaMenuFichas == 1)
            {
                erroTroca = 0;
                printf("Quanto dinheiro pretende trocar?\n");
                if (scanf("%d", &cliente.dinheiroTrocado) != 1)
                {
                    fflush(stdin);
                    printf("Digite números não letras\n");
                    erroTroca = 1;
                    cliente.avisosCliente++;
                }
                if (cliente.dinheiroTrocado <= 0)
                {
                    printf("Não pode trocar dinheiro negativo ou nulo!!!\n");
                    erroTroca = 1;
                    cliente.avisosCliente++;
                }
                if (cliente.dinheiroTrocado > cliente.dinheiroAtual)
                {
                    erroTroca = 1;
                    cliente.avisosCliente++;
                    printf("Não tem dinheiro suficiente na conta\n");
                    printf("O seu saldo é:%d", cliente.dinheiroTotal);
                    if (cliente.semIncomodo <= 0)
                    {
                        printf("Pretende trocar todo o dinheiro que depositou no casino?\n");
                        printf("1-Sim\n");
                        printf("2-Não\n");
                        scanf("%d", &respostaDiferenca);
                        if (respostaDiferenca == 1)
                        {
                            dIferencia = cliente.dinheiroTotal;
                            cliente.dinheiroTotal = cliente.dinheiroAtual - dIferencia;
                            cliente.dinheiroAtual = cliente.dinheiroTotal;

                            casino.dinheiroCasinoTotal = casino.dinheiroCasinoAtual + dIferencia;
                            casino.dinheiroCasinoAtual = casino.dinheiroCasinoTotal;

                            cliente.fichasTotais = cliente.fichasAtuais + dIferencia;
                            cliente.fichasAtuais = cliente.fichasTotais;

                            casino.fichasCasinoTotal = casino.fichasCasinoAtual - cliente.dinheiroTrocado;
                            casino.fichasCasinoAtual = casino.fichasCasinoTotal;

                            casino.transacoes++;

                            guardarDadosEstatistica(&cliente);
                            guardarDinheiroFichasClientes(&cliente);
                            guardarDinheiroFichasCasino(&casino);
                            guardarEstatisticaCasino(&casino);
                        }
                        if (respostaDiferenca == 2)
                        {
                            printf("Deposite mais dinheiro na conta ou baixe o valor que pretende trocar!!!\n");
                        }
                        else
                        {
                            cliente.avisosCliente++;
                        }
                    }
                }

                if (cliente.dinheiroTrocado > casino.fichasCasinoAtual)
                {
                    printf("O casino não tem fichas suficientes\n");
                    printf("Aguarde que o casino receba novas fichas ou baixe o número de fichas que pretende comprar!!!\n\n");
                    guardarEstatisticaCasino(&casino);
                    cliente.avisosCliente++;
                    continue;
                    if (cliente.semIncomodo <= 0)
                    {
                        escolha = 0;

                        printf("Pretende trocar por todas as fichas do casino?\n");
                        printf("1-Sim\n");
                        printf("2-Não\n");

                        scanf("%d", &escolha);
                        if (escolha == 1)
                        {
                            cliente.fichasTotais = cliente.fichasAtuais + casino.fichasCasinoTotal;
                            casino.dinheiroCasinoTotal = casino.dinheiroCasinoAtual + casino.fichasCasinoTotal;

                            cliente.fichasAtuais = cliente.fichasTotais;
                            casino.fichasCasinoTotal = 0;
                            casino.fichasCasinoAtual = 0;
                            printf("Mais uma vez pedimos desculpa por não ser possível realizar a troca como gostaria\n");
                            printf("Desfrute das suas fichas!!!\n");
                            guardarDinheiroFichasClientes(&cliente);
                            guardarDinheiroFichasCasino(&casino);
                        }
                    }

                    casino.avisoFaltaFichasCasino++;
                    erroTroca = 1;
                    cliente.avisosCliente++;
                }

                if (erroTroca == 0)
                {
                    cliente.dinheiroTotal = cliente.dinheiroAtual - cliente.dinheiroTrocado;
                    cliente.dinheiroAtual = cliente.dinheiroTotal;

                    casino.dinheiroCasinoTotal = casino.dinheiroCasinoAtual + cliente.dinheiroTrocado;
                    casino.dinheiroCasinoAtual = casino.dinheiroCasinoTotal;

                    cliente.fichasTotais = cliente.fichasAtuais + cliente.dinheiroTrocado;
                    cliente.fichasAtuais = cliente.fichasTotais;

                    casino.fichasCasinoTotal = casino.fichasCasinoAtual - cliente.dinheiroTrocado;
                    casino.fichasCasinoAtual = casino.fichasCasinoTotal;

                    casino.transacoes++;
                    certo++;
                    if (casino.transacoes >= 18)
                    {
                        if (avaliacaoSingular == 0)
                        {
                            if (naoQueroResponderAvaliacao == 0)
                            {
                                if (naoQueroResponderFeedback == 0)
                                {
                                    if (avaliacaoSingularFeedback == 0)
                                    {
                                        avaliacaoCasino(apontadorAvaliacao, apontadorAvaliacaoSingular, apontadorFeedback, apontadorNaoQueroResponderAvaliacao, apontadorNaoQueroResponderFeedback, apontadorCerto, apontadorAvisosCliente, apontadorRespostaAvaliacao);
                                    }
                                }
                            }
                        }

                        if (cliente.dinheiroTrocado > cliente.maiorCompraFichas)
                        {
                            cliente.maiorCompraFichas = cliente.dinheiroTrocado;
                            printf("Parabéns!!! Detem o recorde de maior compra de fichas deste casino até agora!!!!\n\n");
                            cliente.recordes++;
                            cliente.recordeCompraFichas++;
                            cliente.maiorTransacaoFichas++;
                        }
                        guardarItens(cliente.dinheiroAtual, cliente.fichasAtuais);
                    }
                }
            }

            if (escolhaMenuFichas == 2)
            {
                erroTroca = 0;
                printf("Quantas fichas pretende trocar por dinheiro?\n");
                if (scanf("%d", &cliente.fichasTrocadas) != 1)
                {
                    fflush(stdin);
                    printf("Digite números não letras!!!\n\n");
                    cliente.avisosCliente++;
                }

                if (cliente.fichasTrocadas <= 0)
                {
                    printf("Não pode trocar fichas necessárias ou nulas!!!\n");
                    erroTroca = 1;
                    cliente.avisosCliente++;
                }
                if (cliente.fichasTrocadas > cliente.fichasAtuais)
                {
                    printf("Não tem fichas suficientes\n");
                    erroTroca = 1;
                    cliente.avisosCliente++;
                }
                if (cliente.fichasTrocadas > casino.dinheiroCasinoAtual)
                {
                    printf("O casino não tem dinheiro suficiente!!!\n");
                    printf("Pedimos desculpa pelo incomodo\n");
                    printf("Aguarde que seja injetado dinheiro no casino ou baixe o número de fichas que pretende vender!!!\n\n ");
                    casino.avisoFaltaDinheiroCasino++;
                    erroTroca = 1;
                    cliente.avisosCliente++;
                }
                if (erroTroca == 0)
                {
                    cliente.fichasTotais = cliente.fichasAtuais - cliente.fichasTrocadas;
                    cliente.fichasAtuais = cliente.fichasTotais;
                    casino.fichasCasinoTotal = casino.fichasCasinoAtual + casino.fichasCasinoTroca;
                    casino.fichasCasinoAtual = casino.fichasCasinoTotal;
                    cliente.dinheiroTotal = cliente.dinheiroAtual + cliente.fichasTrocadas;
                    cliente.dinheiroAtual = cliente.dinheiroTotal;
                    casino.dinheiroCasinoTotal = casino.dinheiroCasinoAtual - casino.dinheiroCasinoTroca;
                    casino.dinheiroCasinoAtual = casino.dinheiroCasinoTotal;
                    certo++;
                    casino.transacoes++;
                    printf("Troca realizada com sucesso!\n");
                }
            }
            break;
        }
        case 4:
        {
            int escolhaInterna = 0;
            menuDinheiro();
            if (scanf("%d", &escolhaInterna) != 1)
            {
                fflush(stdin);
                printf("Digite números não letras!!!\n\n");
                cliente.avisosCliente++;
            }
            if (escolhaInterna == 1)
            {
                printf("Digite a quantia de dinheiro que pretende depositar\n");
                if (scanf("%d", &cliente.dinheiroDepositado) != 1)
                {
                    fflush(stdin);
                    printf("Digite números não letras!!!\n");
                    cliente.avisosCliente++;
                }
                if (cliente.dinheiroDepositado <= 0)
                {
                    printf("Não depositar dinheiro negativo ou nulo(0)!!!\n");
                    cliente.avisosCliente++;
                    erroDepositoCliente++;
                }
                else
                {
                    cliente.dinheiroTotal = cliente.dinheiroAtual + cliente.dinheiroDepositado;
                    cliente.dinheiroAtual = cliente.dinheiroTotal;
                    casino.dinheiroDepositadoTotalClientes += cliente.dinheiroDepositado;
                    certo++;
                }
            }
            if (escolhaInterna == 2)
            {
                printf("Quanto dinheiro pretende retirar?\n");
                if (scanf("%d", &cliente.dinheiroRetirado) != 1)
                {
                    fflush(stdin);
                    printf("Digite números não letras!!!\n");
                    cliente.avisosCliente++;
                }
                if (cliente.dinheiroRetirado > cliente.dinheiroAtual)
                {
                    printf("Não tem saldo suficiente!!!\n");
                    printf("O seu saldo é:%d\n", cliente.dinheiroAtual);
                    printf("Deposite mais dinheiro no casino ou retire no máximo:%d\n", cliente.dinheiroAtual);
                }
                else
                {
                    cliente.dinheiroTotal = cliente.dinheiroAtual - cliente.dinheiroRetirado;
                    cliente.dinheiroAtual = cliente.dinheiroTotal;
                    casino.dinheiroRetiradoTotalClientes += cliente.dinheiroRetirado;
                    certo++;
                }
            }
            break;
        }
        case 5:
            printf("%d€ | %d\n", cliente.dinheiroAtual, cliente.fichasAtuais);
            break;

        case 6:
            menuInformacoesExtra();
            break;

        case 7:
        {
            int escolhaConfig = 0;
            system("cls");
            printf("--- MENU DE CONFIGURACOES ---\n");
            printf("1. Alterar password\n");
            printf("2. Mudar username\n");
            printf("3. Mudar permissoes\n");
            printf("4. Escrever feedback\n");
            printf("5. Creditos\n");
            printf("6-Eliminar conta\n");
            printf("7-Doar dinheiro/fichas\n");
            printf("0. Voltar ao menu principal\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &escolhaConfig);

            if (escolhaConfig == 1)
            {
                printf("Digite a nova password: ");
                scanf("%s", cliente.password);
                printf("Password alterada com sucesso!\n");
            }
            if (escolhaConfig == 2)
            {
                printf("Digite o novo username: ");
                scanf("%s", cliente.username);
                printf("Username alterado para: %s\n", cliente.username);
            }
            if (escolhaConfig == 3)
            {
                printf("Podemos perguntar se quer dar feedback ou avaliar o casino?\n");
                printf("1-Sim(ambos)\n");
                printf("2-Não(ambos)\n");
                printf("3-Sim(ao feedback) e não a avaliação\n");
                printf("4-Sim(a avaliacão e não (ao feedback)\n");
                int respostaPermissao = 0;
                scanf("%d", &respostaPermissao);
                if (respostaPermissao == 1)
                {
                    printf("Obrigado por permitir\n");
                }
                if (respostaPermissao == 2)
                {
                    printf("Entendido!!! Não faremos mais perguntas destas!!!\n");
                    naoQueroResponderAvaliacao++;
                    naoQueroResponderFeedback++;
                }
            }
            if (escolhaConfig == 4)
            {
                printf("Escreva o seu feedback: ");
                fflush(stdin);
                fgets(feedback, 200, stdin);
                printf("Feedback guardado. Obrigado!\n");
            }
            if (escolhaConfig == 5)
            {
                printf("\n========================================\n");
                printf("        CREDITOS DO SISTEMA             \n");
                printf("========================================\n");
            }
            if (escolhaConfig == 7)
            {
                printf("Pretende doar dinheiro, fichas ou ambos?\n");
                printf("1-Dinheiro\n2-Fichas\n3-Misto(Ambos)\n");
                int escolhaDoacao = 0;
                scanf("%d", &escolhaDoacao);
                if (escolhaDoacao == 1)
                {
                    printf("Quanto dinheiro pretende doar?\n");
                    scanf("%d", &cliente.dinheiroDoado);
                    if (cliente.dinheiroDoado > cliente.dinheiroAtual)
                    {
                        printf("Não tem dinheiro suficiente para doar!\n");
                    }
                    else
                    {
                        cliente.dinheiroAtual -= cliente.dinheiroDoado;
                        casino.dinheiroCasinoAtual += cliente.dinheiroDoado;
                        printf("Obrigado pelo donativo de %d€!\n", cliente.dinheiroDoado);
                    }
                }
            }
            break;
        }

        case 0:
            break;

        default:
            printf("Essa opção não existe no menú!!! Digite um número entre 0(sair) e 7!!!\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}