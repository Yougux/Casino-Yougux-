#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fun.h"
#include <time.h>

void menu()
{
    printf("=================================\n");
    printf("         YOUGUX ROYALE\n");
    printf("=================================\n");
    printf("       Bem-vindo ao casino\n");
    printf("=================================\n");
    printf("1- Jogar Carta Maior/Menor\n");
    printf("2- Opção CLI 2\n");
    printf("3- Fichas\n");
    printf("4- Dinheiro\n");
    printf("5- Consultar Saldos Rápidos\n");
    printf("6- Informações extra\n");
    printf("7- Configurar casino\n");
    printf("0- Sair...\n");
    printf("Escolha uma das opções: ");
}

void menuDinheiro()
{
    printf("1- Depositar dinheiro\n");
    printf("2- Retirar dinheiro\n");
}

void menuFichas()
{
    printf("1- Trocar dinheiro por fichas\n");
    printf("2- Trocar fichas por dinheiro\n");
}

void menuGerador()
{
    printf("=== SISTEMA DE ACESSO ===\n");
    printf("Já tem conta?\n");
    printf("1- Logar\n");
    printf("2- Criar conta\n");
    printf("0- Sair...\n");
    printf("Escolha uma opção: ");
}

void menuAdm(StructCasino *casino, StructCliente *cliente, int *apontadorCerto, int *apontadorAvaliacao, char *apontadorFeedback, int *apontadorNaoQueroResponderAvaliacao, int *apontadorNaoQueroResponderFeedback)
{
    int avisosADM = 0;
    int escolha = 0;
    int inicioADM = 0;
    int baseDadosCliente = 0;

    printf("\n\n-----Menú ultra secreto ADM---\n\n");
    if (inicioADM == 0)
    {
        printf("Atenção!!!!\n");
        printf("Antes de escolher 3(Dinheiro/fichas) tem de escolher 9(Guardar e sair)\n");
        printf("Ao escolher 9 pela primeira vez está a criar o ficheiro do casino!!!\n");
        printf("Crie todas as bases de dados que  casino pedir\n");
        printf("Esta regra só se aplica na primeira vez que entra no 9\n");
    }

    printf("Bem-vindo ao menú do ADM\n");
    printf("1-Cuidados a ter\n");
    printf("2- fichas\n");
    printf("3- Dinheiro/fichas\n");
    printf("4- Estatísticas\n");
    printf("5- Leaderboard\n");
    printf("6- Diário do programador\n");
    printf("7-Ajuda\n");
    printf("8-Ações necessárias\n");
    printf("9-Guardar e sair\n");
    printf("10-Configuracoes\n");

    if (baseDadosCliente == 0)
    {
        int escolhaInner = 0;

        void menuAdministrador(StructCasino * casino, StructCliente * cliente, int *apontadorAvisosADM, int *apontadorCerto, int *apontadorAvaliacao, char *apontadorFeedback,int *apontadorAvisosADM, )
        {
            int escolhaInner = 0;
            int escolha = 0;
            int estadoInicialBaseDados = casino->BaseDados;

            if (estadoInicialBaseDados == 0)
            {
                printf("\n======================================================================\n");
                printf("   SISTEMA CENTRAL DE INICIALIZACAO - BASE DE DADOS DO CASINO (%d)   \n", casino->anoAtual);
                printf("======================================================================\n");
                printf("ESTADO ATUAL: As bases de dados do casino estao inativas ou vazias.\n");
                printf("E obrigatorio estruturar o sistema para permitir o fluxo de transacoes.\n\n");
                printf("O que sera criado nesta operacao:\n");
                printf("- Base de dados financeira (Dinheiro e Fichas dos Clientes)\n");
                printf("- Base de dados de Contas Pessoais (Logins e Passwords)\n");
                printf("- Base de dados de Seguranca Administrativa (Conta ADM)\n");
                printf("- Base de dados de Analise de Desempenho do Casino\n");
                printf("- Base de dados de Estatisticas Individuais dos Clientes\n\n");
                printf("1 - SIM, INICIALIZAR TODAS AS BASES DE DADOS IMEDIATAMENTE\n");
                printf("2 - NAO, EXPLICAR A IMPORTANCIA DESTA OPERACAO\n");
                printf("3 - ADIAR OPERACAO (SAIR DO ASSISTENTE DE CONFIGURACAO)\n");
                printf("======================================================================\n");
                printf("Indique a sua decisao de Administrador: ");

                if (scanf("%d", &escolhaInner) != 1)
                {
                    printf("\n[ERRO DE SEGURANCA] O sistema detetou caracteres invalidos! Registo de aviso incrementado.\n");
                    printf("Digite números não letras!!!\n");
                    scanf("%*s");
                    (*apontadorAvisosADM)++;
                    return;
                }

                if (escolhaInner == 1)
                {
                    FILE *fptr1 = fopen("dinheiroClientes.txt", "w");
                    if (fptr1 == NULL)
                    {
                        printf("\n[FALHA CRITICA] O sistema operativo bloqueou a criacao do ficheiro principal!\n");
                        (*apontadorAvisosADM)++;
                        return;
                    }
                    else{

                    
                    fprintf(fptr1, "%d\n", cliente->codigoCliente);
                    fprintf(fptr1, "%s\n", cliente->username[0] == '\0' ? "sem_user" : cliente->username);
                    fprintf(fptr1, "%s\n", cliente->nomeClienteMain[0] == '\0' ? "sem_nome" : cliente->nomeClienteMain);
                    fprintf(fptr1, "%d\n", cliente->dinheiroTotal);
                    fprintf(fptr1, "%d\n", cliente->dinheiroAtual);
                    fprintf(fptr1, "%d\n", cliente->fichasTotais);
                    fprintf(fptr1, "%d\n", cliente->fichasAtuais);
                    fprintf(fptr1, "%d\n", cliente->dinheiroDepositado);
                    fprintf(fptr1, "%d\n", cliente->dinheiroRetirado);
                    fprintf(fptr1, "%d\n", cliente->fichasDepositadas);
                    fprintf(fptr1, "%d\n", cliente->fichasRetiradas);
                    fprintf(fptr1, "%d\n", cliente->lucroClienteDiario);
                    fprintf(fptr1, "%d\n", cliente->prejuizoClienteTotal);
                    fclose(fptr1);

                    FILE *fptr2 = fopen("contasClientes.txt", "w");
                    if (fptr2 != NULL)
                    {
                        fclose(fptr2);
                    }

                    FILE *fptr3 = fopen("contaADM.txt", "w");
                    if (fptr3 != NULL)
                    {
                        fclose(fptr3);
                    }

                    FILE *fptr4 = fopen("estatisticasCasino.txt", "w");
                    if (fptr4 != NULL)
                    {
                        fclose(fptr4);
                    }

                    FILE *fptr5 = fopen("estatisticasClientes.txt", "w");
                    if (fptr5 != NULL)
                    {
                        fclose(fptr5);
                    }
}
                    casino->BaseDados++;
                    (*apontadorCerto)++;
                    printf("\n[SUCESSO ABSOLUTO] Todas as estruturas de dados foram formatadas e estao prontas!\n");
                    printf("[SISTEMA] O Casino esta agora autorizado a receber jogadores e gerir fundos.\n");
                }
                if (escolhaInner == 2)
                {
                    printf("\n[DIRETRIZ ADM] Sem a construcao das estruturas de ficheiros, todos os registos\n");
                    printf("de dinheiro, fichas ganhas, lucros e logins serao perdidos ao fechar o programa.\n");
                    printf("A base de dados e o coracao do sistema do seu casino.\n");
                }
                if (escolhaInner == 3)
                {
                    printf("\n[ALERTA DE SISTEMA] Operacao adiada. Certifique-se de configurar a base antes de abrir portas.\n");
                }
                if (escolhaInner < 1 || escolhaInner > 3)
                {
                    printf("\n[ERRO DE COMANDO] Opcao nao reconhecida. Tentativa registada.\n");
                    (*apontadorAvisosADM)++;
                }
            }

            if (estadoInicialBaseDados > 0)
            {
                printf("\n======================================================================\n");
                printf("   ZONA DE PERIGO - PURGA DE DADOS DO CASINO (NIVEL DE ACESSO MAXIMO) \n");
                printf("======================================================================\n");
                printf("ESTADO ATUAL: Bases de dados ATIVAS. (Nivel de BaseDados: %d)\n", casino->BaseDados);
                printf("AVISO: Esvaziar os ficheiros apagará o dinheiro, as contas e todo o \n");
                printf("historico de transacoes de forma IRREVERSIVEL.\n\n");
                printf("1 - CONFIRMAR PURGA TOTAL (Limpar o conteudo de todos os ficheiros)\n");
                printf("2 - CANCELAR OPERACAO E MANTER DADOS SEGUROS\n");
                printf("======================================================================\n");
                printf("Insira a confirmacao: ");

                if (scanf("%d", &escolhaInner) != 1)
                {
                    printf("\n[ERRO DE SEGURANCA] Entrada invalida detetada no modulo de purga!\n");
                    scanf("%*s");
                    (*apontadorAvisosADM)++;
                    return;
                }

                if (escolhaInner == 1)
                {
                    FILE *f1 = fopen("dinheiroClientes.txt", "w");
                    if (f1 != NULL)
                    {
                        fclose(f1);
                    }
                    FILE *f2 = fopen("contasClientes.txt", "w");
                    if (f2 != NULL)
                    {
                        fclose(f2);
                    }
                    FILE *f3 = fopen("contaADM.txt", "w");
                    if (f3 != NULL)
                    {
                        fclose(f3);
                    }
                    FILE *f4 = fopen("estatisticasCasino.txt", "w");
                    if (f4 != NULL)
                    {
                        fclose(f4);
                    }
                    FILE *f5 = fopen("estatisticasClientes.txt", "w");
                    if (f5 != NULL)
                    {
                        fclose(f5);
                    }

                    casino->BaseDados = 0;
                    (*apontadorCerto)++;
                    printf("\n[PURGA CONCLUIDA] Todo o historico foi limpo com sucesso. Os ficheiros estao vazios.\n");
                    printf("O sistema retornou ao estado original de fabrica.\n");
                }
                if (escolhaInner < 1 || escolhaInner > 2)
                {
                    printf("\n[AVISO] Escolha invalida no menu de purga de dados.\n");
                    (*apontadorAvisosADM)++;
                }
            }

            printf("\n======================================================================\n");
            printf("   PAINEL DE CONTROLO OPERACIONAL DO ADMINISTRADOR\n");
            printf("======================================================================\n");
            printf(" [RESUMO FINANCEIRO DO CASINO]\n");
            printf(" Fichas em Caixa: %d | Fichas Totais Registadas: %d\n", casino->fichasCasinoAtual, casino->fichasCasinoTotal);
            printf(" Dinheiro Real: %d | Lucro Historico: %d\n", casino->dinheiroCasinoAtual, casino->lucroCasinoTotal);
            printf(" Total de Transacoes Processadas: %d | Total de Logins: %d\n", casino->transacoes, casino->logins);
            printf(" Avisos ADM Acumulados: %d\n", *apontadorAvisosADM);
            printf("======================================================================\n\n");

            printf("1 - Opcao de Manutencao Livre 1\n");
            printf("2 - Gestao da Tesouraria (Gerar ou Retirar Fichas de Jogo)\n");
            printf("3 - Sincronizar Sistema (Carregar dinheiroCasino.txt)\n");
            printf("4 - Inspecionar Relatorios e Estatisticas Profundas\n");
            printf("5 - Modificar Parametros Extras de Seguranca e Modo Silencioso\n");
            printf("6 - Consultar Logins de Utilizadores e Auditoria de Contas\n");
            printf("7 - Verificar Pontuacao Geral das Leaderboards do Sistema\n");
            printf("8 - Realizar Calculo de Auditoria de Lucro e Prejuizo Total\n");
            printf("9 - Forcar Guardar Dados Atuais do Casino (Backup Manual)\n");
            printf("10 - Encerrar Sessao Administrativa\n");
            printf("======================================================================\n");
            printf("Aguardando comando de operacao: ");

            if (scanf("%d", &escolha) != 1)
            {
                printf("\n[FALHA] Comando inaceitavel. Utilizacao de caracteres bloqueada.\n");
                scanf("%*s");
                (*apontadorAvisosADM)++;
                return;
            }

            if (escolha == 1)
            {
                printf("\n[INFO] Opcao de Manutencao Livre 1 selecionada. Nenhuma tarefa atribuida.\n");
            }
            if (escolha == 2)
            {
                int escolhaFichas = 0;
                printf("\n[TESOURARIA] O Casino tem atualmente %d fichas prontas para uso.\n", casino->fichasCasinoAtual);
                printf("Operacoes Disponiveis:\n");
                printf("1 - Imprimir Novas Fichas (Aumenta o volume total e atual do casino)\n");
                printf("2 - Incinerar Fichas (Retira de circulacao do cofre do casino)\n");
                printf("Defina a operacao de tesouraria: ");

                if (scanf("%d", &escolhaFichas) != 1)
                {
                    printf("\n[ERRO] Operacao cancelada devido a formato de dados incorreto!\n");
                    scanf("%*s");
                    (*apontadorAvisosADM)++;
                }

                if (escolhaFichas == 1)
                {
                    int fichasGeradas = 0;
                    printf("\nQuantas unidades de fichas pretende introduzir no sistema? ");
                    if (scanf("%d", &fichasGeradas) != 1)
                    {
                        printf("\n[ERRO] Quantidade recusada. Apenas numeros sao validos.\n");
                        scanf("%*s");
                        (*apontadorAvisosADM)++;
                    }
                    if (fichasGeradas > (casino->limiteSegurancaMedio / 100))
                    {
                        printf("\n[ALERTA DE INFLACAO] Gerar %d fichas subitamente pode desestabilizar a economia!\n", fichasGeradas);
                        printf("Os sistemas de seguranca irao monitorizar esta transacao atentamente.\n");
                    }
                    if (fichasGeradas > 0)
                    {
                        casino->fichasCasinoTotal = casino->fichasCasinoTotal + fichasGeradas;
                        casino->fichasCasinoAtual = casino->fichasCasinoAtual + fichasGeradas;
                        (*apontadorCerto)++;
                        printf("\n[TESOURARIA CONCLUIDA] %d novas fichas foram impressas.\n", fichasGeradas);
                        printf("Novo total em cofre pronto a ser entregue a jogadores: %d fichas.\n", casino->fichasCasinoAtual);
                    }
                }
                if (escolhaFichas == 2)
                {
                    int fichasRetiradas = 0;
                    printf("\nQuantas unidades de fichas pretende retirar e destruir da caixa atual? ");
                    if (scanf("%d", &fichasRetiradas) != 1)
                    {
                        printf("\n[ERRO] Quantidade recusada. O cofre trancou automaticamente.\n");
                        scanf("%*s");
                        (*apontadorAvisosADM)++;
                    }
                    if (fichasRetiradas > casino->fichasCasinoAtual)
                    {
                        printf("\n[FALTA DE LIQUIDEZ] Impossivel retirar %d fichas!\n", fichasRetiradas);
                        printf("O casino apenas tem %d fichas no cofre neste momento.\n", casino->fichasCasinoAtual);

                        if (cliente->semIncomodo == 1)
                        {
                            printf("[MODO SILENCIOSO] O modo nao chatear esta ativo. Pedido cancelado sem perguntas adicionais.\n");
                            (*apontadorAvisosADM)++;
                        }
                        if (cliente->semIncomodo == 0)
                        {
                            int decisaoForcar = 0;
                            printf("Pretende retirar TODAS as fichas remanescentes em caixa (%d fichas)?\n", casino->fichasCasinoAtual);
                            printf("1 - Sim, limpar o cofre por completo\n");
                            printf("2 - Nao, cancelar totalmente a accao\n");
                            printf("Escolha: ");
                            if (scanf("%d", &decisaoForcar) != 1)
                            {
                                scanf("%*s");
                                (*apontadorAvisosADM)++;
                            }
                            if (decisaoForcar == 1)
                            {
                                fichasRetiradas = casino->fichasCasinoAtual;
                                casino->fichasCasinoAtual = casino->fichasCasinoAtual - fichasRetiradas;
                                casino->fichasCasinoTotal = casino->fichasCasinoTotal - fichasRetiradas;
                                (*apontadorCerto)++;
                                printf("\n[SUCESSO COMPLETO] O cofre do casino foi totalmente rapado. Retiradas %d fichas.\n", fichasRetiradas);
                            }
                            if (decisaoForcar == 2)
                            {
                                printf("\n[INFO] Operacao de contingencia cancelada pelo administrador.\n");
                            }
                            if (decisaoForcar < 1 || decisaoForcar > 2)
                            {
                                printf("\n[AVISO] Escolha invalida no menu de contingencia.\n");
                                (*apontadorAvisosADM)++;
                            }
                        }
                    }
                    if (fichasRetiradas <= casino->fichasCasinoAtual)
                    {
                        if (fichasRetiradas > 0)
                        {
                            casino->fichasCasinoAtual = casino->fichasCasinoAtual - fichasRetiradas;
                            casino->fichasCasinoTotal = casino->fichasCasinoTotal - fichasRetiradas;
                            (*apontadorCerto)++;
                            printf("\n[TESOURARIA CONCLUIDA] %d fichas foram retiradas e destruidas com sucesso.\n", fichasRetiradas);
                            printf("Volume restante seguro no cofre do casino: %d fichas.\n", casino->fichasCasinoAtual);
                        }
                    }
                }
                if (escolhaFichas < 1 || escolhaFichas > 2)
                {
                    printf("\n[ERRO] Operacao de tesouraria inexistente.\n");
                    (*apontadorAvisosADM)++;
                }
            }
            if (escolha == 3)
            {
                FILE *fptr = fopen("dinheiroCasino.txt", "r");

                if (fptr == NULL)
                {
                    printf("\n[AVISO CRITICO] O sistema tentou localizar dinheiroCasino.txt mas falhou.\n");
                    printf("Verifique se o ficheiro foi apagado ou se nunca chegou a ser guardado.\n");
                    (*apontadorAvisosADM)++;
                }
                if (fptr != NULL)
                {
                    fscanf(fptr, "%d\n", &casino->lucroCasinoTotal);
                    fscanf(fptr, "%d\n", &casino->prejuizoCasinoTotal);
                    fscanf(fptr, "%d\n", &casino->avisoFaltaDinheiroCasino);
                    fscanf(fptr, "%d\n", &casino->avisoFaltaFichasCasino);
                    fscanf(fptr, "%d\n", &casino->transacoes);
                    fscanf(fptr, "%d\n", &casino->dinheiroCasinoTroca);
                    fscanf(fptr, "%d\n", &casino->dinheiroCasinoTotal);
                    fscanf(fptr, "%d\n", &casino->dinheiroCasinoAtual);
                    fscanf(fptr, "%d\n", &casino->fichasCasinoTotal);
                    fscanf(fptr, "%d\n", &casino->fichasCasinoAtual);
                    fscanf(fptr, "%d\n", &casino->fichasCasinoTrocadas);
                    fscanf(fptr, "%d\n", &casino->fichasCasinoTroca);
                    fscanf(fptr, "%d\n", &casino->dinheiroRetiradoTotalClientes);
                    fscanf(fptr, "%d\n", &casino->dinheiroDepositadoTotalClientes);
                    fscanf(fptr, "%d\n", &casino->pinNumero);
                    fscanf(fptr, "%d\n", &casino->anoAtual);
                    fscanf(fptr, "%s\n", casino->password);

                    fclose(fptr);
                    (*apontadorCerto)++;
                    printf("\n[SINCRONIZACAO CONCLUIDA] Dados vitais do Casino foram importados para a memoria principal!\n");
                    printf("A base de estatisticas internas encontra-se agora totalmente atualizada.\n");
                }
            }
            if (escolha == 4)
            {
                menuEstatisticaADM(casino, cliente, apontadorAvisosADM, apontadorAvaliacao, apontadorFeedback);
            }
            if (escolha == 5)
            {
                int decisaoSeguranca = 0;
                int estadoSilenciosoAtual = cliente->semIncomodo;
                printf("\n======================================================================\n");
                printf("   MODULO DE CONFIGURACAO DE PARAMETROS EXTRAS DE SEGURANCA           \n");
                printf("======================================================================\n");
                printf(" MODO NAO CHATEAR (SILENCIOSO) ATUAL: %s\n", estadoSilenciosoAtual == 1 ? "ATIVO" : "INATIVO");
                printf(" Limite de Seguranca Muito Baixo: %d EUR\n", casino->limiteSegurancaMuitoBaixo);
                printf(" Limite de Seguranca Baixo: %d EUR\n", casino->limiteSegurancaBaixo);
                printf(" Limite de Seguranca Medio: %d EUR\n", casino->limiteSegurancaMedio);
                printf(" Limite de Seguranca Alto: %d EUR\n", casino->limiteSegurancaAlto);
                printf("======================================================================\n");
                printf("1 - Alternar Estado do Modo Nao Chatear (Silencioso)\n");
                printf("2 - Manter Configuracoes Atuais e Sair\n");
                printf("Insira a sua escolha de seguranca: ");
                if (scanf("%d", &decisaoSeguranca) != 1)
                {
                    scanf("%*s");
                    (*apontadorAvisosADM)++;
                }
                if (decisaoSeguranca == 1)
                {
                    if (estadoSilenciosoAtual == 0)
                    {
                        cliente->semIncomodo = 1;
                        printf("\n[SISTEMA] Modo Nao Chatear ACTIVADO. O administrador nao sera perturbado.\n");
                    }
                    if (estadoSilenciosoAtual == 1)
                    {
                        cliente->semIncomodo = 0;
                        printf("\n[SISTEMA] Modo Nao Chatear DESACTIVADO. Confirmacoes de seguranca reativadas.\n");
                    }
                    (*apontadorCerto)++;
                }
                if (decisaoSeguranca == 2)
                {
                    printf("\n[SISTEMA] Parametros mantidos sem alteracoes na estrutura.\n");
                }
                if (decisaoSeguranca < 1 || decisaoSeguranca > 2)
                {
                    printf("\n[AVISO] Opcao inexistente no menu de seguranca.\n");
                    (*apontadorAvisosADM)++;
                }
            }
            if (escolha == 6)
            {
                printf("\n======================================================================\n");
                printf("   AUDITORIA GERAL DE ACESSOS, CONTA E LOGINS REGISTADOS              \n");
                printf("======================================================================\n");
                printf(" Total de Inicios de Sessao Administrativos (Logins): %d\n", casino->logins);
                printf(" Total de Vezes que Contas de Utilizadores foram Geradas: %d\n", casino->criarContaVezes);
                printf(" Indicador de Sessao Administrativa Inicial (InicioADM): %d\n", casino->inicioADM);
                printf(" Codigo Identificador do Cliente de Teste Atual: %d\n", cliente->codigoCliente);
                printf(" Nome Completo do Utilizador em Foco: %s\n", cliente->nomeClienteMain[0] == '\0' ? "Nenhum" : cliente->nomeClienteMain);
                printf("======================================================================\n");
                (*apontadorCerto)++;
                printf("[SUCESSO] Relatorio de acessos gerado com estabilidade.\n");
            }
            if (escolha == 7)
            {
                printf("\n======================================================================\n");
                printf("   INSPECCAO DE LEADERBOARDS INTERNAS E CONTROLO DE PONTOS            \n");
                printf("======================================================================\n");
                printf(" Pontos Totais Computados no Sistema do Casino: %d\n", casino->pontosTotaisCasino);
                printf(" Pontos Ativos em Circulacao e Custodia: %d\n", casino->pontosAtuaisCasino);
                printf(" Pontos Alocados para Processamento de Trocas Comerciais: %d\n", casino->pontosTrocaCasino);
                printf(" Metricas de Generosidade de Doadores Cadastrados:\n");
                printf(" - Classificacao Doador Fraco: %d utilizadores\n", casino->doadorFraco);
                printf(" - Classificacao Doador Medio: %d utilizadores\n", casino->doadorMedio);
                printf(" - Classificacao Doador Forte: %d utilizadores\n", casino->doadorForte);
                printf(" - Classificacao Doador Heroi: %d utilizadores\n", casino->doadorHeroi);
                printf("======================================================================\n");
                (*apontadorCerto)++;
                printf("[SUCESSO] Varredura de tabelas de liderança executada.\n");
            }
            if (escolha == 8)
            {
                int balancoResultanteGeral = casino->lucroCasinoTotal - casino->prejuizoCasinoTotal;
                printf("\n======================================================================\n");
                printf("   RELATORIO ROBUSTO DE METRICAS OPERACIONAIS DE LUCRO E PREJUIZO     \n");
                printf("======================================================================\n");
                printf(" FATURAMENTO OPERACIONAL (LUCRO BRUTO): %d EUR\n", casino->lucroCasinoTotal);
                printf(" CUSTOS FINANCEIROS (PREJUIZO CONTABIL): %d EUR\n", casino->prejuizoCasinoTotal);
                printf("----------------------------------------------------------------------\n");
                printf(" BALANCO FINANCEIRO NET OPERACIONAL: %d EUR\n", balancoResultanteGeral);
                printf("----------------------------------------------------------------------\n");

                if (balancoResultanteGeral > 0)
                {
                    printf(" ANÁLISE DE RENTABILIDADE: O CASINO ENCONTRA-SE EM SUPERAVIT FINANCEIRO!\n");
                }
                if (balancoResultanteGeral < 0)
                {
                    printf(" ANÁLISE DE RENTABILIDADE: O CASINO DETECTOU DEFICIT LIQUIDO NEGATIVO!\n");
                }
                if (balancoResultanteGeral == 0)
                {
                    printf(" ANÁLISE DE RENTABILIDADE: O CASINO ENCONTRA-SE EM PERFEITO EQUILIBRIO FINANCEIRO.\n");
                }

                printf("\n FLUXO COMPLEMENTAR DE TRANSACOES DOS CLIENTES:\n");
                printf(" - Dinheiro Total Recebido por Depositos de Clientes: %d EUR\n", casino->dinheiroDepositadoTotalClientes);
                printf(" - Dinheiro Total Despendido por Levantamentos de Clientes: %d EUR\n", casino->dinheiroRetiradoTotalClientes);
                printf(" - Volume Absoluto de Registos de Transacoes no Ficheiro: %d\n", casino->transacoes);
                printf("======================================================================\n");
                (*apontadorCerto)++;
            }
            if (escolha == 9)
            {
                guardarDadosCasino(casino);
                (*apontadorCerto)++;
                printf("\n[BACKUP CONCLUIDO] Os dados atuais do Casino foram gravados de forma segura!\n");
            }
            if (escolha == 10)
            {
                printf("\n[SISTEMA] Encerrando o painel de administracao em seguranca. Adeus, ADM!\n");
            }
            if (escolha < 1 || escolha > 10)
            {
                printf("\n[VIOLACAO DE MENU] Tentativa de aceder a um setor restrito ou inexistente.\n");
                (*apontadorAvisosADM)++;
            }
        }
    }
}
void menuEstatisticaADM(StructCasino *casino, StructCliente *cliente, int *apontadorAvisosCliente, int *apontadorAvaliacao, char *apontadorFeedback)
{
    int opcao;

    do
    {
        system("cls");
        printf("==================================================\n");
        printf("           PAINEL DE ESTATISTICAS DO ADM           \n");
        printf("==================================================\n");
        printf(" [1] Ver Recordes e Maiores Transacoes\n");
        printf(" [2] Ver Alertas e Avisos do Cliente\n");
        printf(" [3] Ver Avaliacao e Feedback do Casino\n");
        printf(" [0] Voltar ao Menu Anterior\n");
        printf("==================================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            system("cls");
            printf("=== RECORDES E MAIORES TRANSACOES ===\n\n");
            printf(" Maior Transacao (Geral):     %d\n", cliente->maiorTransacao);
            printf(" Maior Transacao em Dinheiro: %d EUR\n", cliente->maiorTransacaoDinheiro);
            printf(" Maior Transacao em Fichas:   %d\n", cliente->maiorTransacaoFichas);
            printf("--------------------------------------------------\n");
            printf(" Maior Compra de Fichas:      %d\n", cliente->maiorCompraFichas);
            printf(" Maior Venda de Fichas:       %d\n", cliente->maiorVendaFichas);
            printf("--------------------------------------------------\n");
            printf(" Recordes Ativados (Total):   %d\n", cliente->recordes);
            printf(" Recorde de Compra de Fichas: %d\n", cliente->recordeCompraFichas);
            printf(" Recorde de Venda de Fichas:  %d\n", cliente->recordeVendeFichas);
            printf("\n==================================================\n");
            system("pause");
        }
        if (opcao == 2)
        {
            system("cls");
            printf("=== ALERTAS E AVISOS DO CLIENTE ===\n\n");
            printf(" Cliente Atual:               %s\n", cliente->nomeClienteMain);
            printf(" Codigo do Cliente:           %d\n", cliente->codigoCliente);
            printf("--------------------------------------------------\n");
            printf(" Total de Avisos ao Cliente:  %d\n", *apontadorAvisosCliente);
            printf(" Erros de Deposito do Casino: %d\n", casino->avisoFaltaDinheiroCasino);
            printf("\n==================================================\n");
            system("pause");
        }
        if (opcao == 3)
        {
            system("cls");
            printf("=== AVALIACAO E FEEDBACK DO CASINO ===\n\n");
            printf(" Nota Atual do Casino (0-5):  %d/5\n", *apontadorAvaliacao);
            printf("--------------------------------------------------\n");
            printf(" Depoimento/Feedback Escrito:\n");
            if (apontadorFeedback[0] == '\0')
            {
                printf(" [Nenhum feedback enviado nesta sessao]\n");
            }
            if (apontadorFeedback[0] != '\0')
            {
                printf(" \"%s\"\n", apontadorFeedback);
            }
            printf("\n==================================================\n");
            system("pause");
        }
        if (opcao == 0)
        {
            printf("\nA sair do menu de estatisticas...\n");
        }
        if (opcao < 0)
        {
            printf("\nOpcao Invalida! Tente novamente.\n");
            system("pause");
        }
        if (opcao > 3)
        {
            printf("\nOpcao Invalida! Tente novamente.\n");
            system("pause");
        }
    } while (opcao != 0);
}

void imprimirBibliaDoProgramadorMundial(StructCasino *casino, StructCliente *cliente)
{
    // ======================================================================
    // CAPÍTULO I: O APOCALIPSE DOS BUGS E A CORRUPÇÃO DOS DADOS
    // ======================================================================
    printf("## CAPÍTULO I: O APOCALIPSE DOS BUGS\n");
    printf("----------------------------------------------------------------------\n");
    printf("Houve trevas no terminal. Nao era um inicio pacífico. O programador lembra-se\n");
    printf("perfeitamente do dia em que o ficheiro 'dinheiroClientes.txt' foi corrompido\n");
    printf("por um 'Segmentation Fault' impiedoso. O buffer do 'nomeClienteMain' estourou,\n");
    printf("derramando lixo de memoria sobre o saldo real do utilizador. O caos instalou-se.\n");
    printf("Os ponteiros apontavam para o infinito vazio e o 'scanf' consumia caracteres\n");
    printf("invalidos num loop infinito de destruicao, gerando milhares de avisos ADM.\n");
    printf("Ate as fichas do cofre evaporavam devido a operacoes aritmeticas sem controlo.\n");
    printf("Foi o ponto mais baixo da jornada. O desespero de ver o projeto colapsar...\n\n");

    // ESPAÇO PUBLICITÁRIO 1
    printf("======================== ESPACO PUBLICITARIO 1 ========================\n");
    printf("%s\n", casino->listaAnuncios[0]);
    casino->anunciosTotais++; // Incrementa o contador de visualizações
    printf("=======================================================================\n\n");

    // ======================================================================
    // CAPÍTULO II: A GRANDE CORREÇÃO E A PURIFICAÇÃO DO FPTR
    // ======================================================================
    printf("## CAPÍTULO II: A REFAÇÃO SAGRADA E A PURIFICAÇÃO DO FPTR\n");
    printf("----------------------------------------------------------------------\n");
    printf("Mas o programador nao se rendeu. Ele limpou as lagrimas, respirou fundo e\n");
    printf("iniciou a purificacao do sistema. A primeira grande correcao foi unificar\n");
    printf("todos os fluxos de escrita num unico ponteiro de ficheiro: o lendario 'fptr'.\n");
    printf("Substituiu-se a barafunda de variaveis locais por um ciclo vertical limpo.\n");
    printf("Sempre que um 'fclose(fptr)' e executado, a memoria e imediatamente devolvida\n");
    printf("ao sistema operativo, eliminando 'Memory Leaks' de uma vez por todas.\n");
    printf("Para os inputs corrompidos, introduziu-se o mecanismo de limpeza automatica\n");
    printf("usando 'scanf(\"%%*s\")', impedindo que o lixo trave a execucao do painel.\n\n");

    // ESPAÇO PUBLICITÁRIO 2
    printf("======================== ESPACO PUBLICITARIO 2 ========================\n");
    printf("%s\n", casino->listaAnuncios[1]);
    casino->anunciosTotais++;
    printf("=======================================================================\n\n");

    // ======================================================================
    // CAPÍTULO III: A FILOSOFIA DA FELICIDADE DO UTILIZADOR
    // ======================================================================
    printf("## CAPÍTULO III: O CASINO IMPERIAL IMPORTA-SE COMIGO?\n");
    printf("----------------------------------------------------------------------\n");
    printf("Apenas um deserto de silício seria um casino sem jogadores. O programador percebeu\n");
    printf("que o segredo do sucesso absoluto nao esta no lucro bruto, mas sim em\n");
    printf("NÃO IRRITAR O UTILIZADOR. Se o sistema for demasiado rígido, o jogador desiste.\n");
    printf("Por isso, o codigo foi humanizado. O casino agora importa-se verdadeiramente!\n");
    printf("Se o jogador tentar uma jogada invalida, o sistema nao o insulta, nao crasha,\n");
    printf("e nao fecha a aplicacao de forma abrupta. Em vez disso, envia uma mensagem\n");
    printf("pedagogica e reconfortante, oferecendo alternativas viaveis de jogo.\n\n");

    // ESPAÇO PUBLICITÁRIO 3
    printf("======================== ESPACO PUBLICITARIO 3 ========================\n");
    printf("%s\n", casino->listaAnuncios[2]);
    casino->anunciosTotais++;
    printf("=======================================================================\n\n");

    // ======================================================================
    // CAPÍTULO IV: A DINÂMICA DAS VARIÁVEIS DE ESCOLHA FINANCEIRA
    // ======================================================================
    printf("## CAPÍTULO IV: AS VARIÁVEIS DA PAZ ESPIRITUAL\n");
    printf("----------------------------------------------------------------------\n");
    printf("Para alcancar o estado de felicidade plena do cliente, foram criadas duas\n");
    printf("variaveis de controlo emocional profundo dentro das estruturas:\n");
    printf("1. 'cliente->semIncomodo': Se estiver ativa (1), silencia os alertas irritantes\n");
    printf("   de seguranca, permitindo uma navegacao fluida e sem interrupcoes burocraticas.\n");
    printf("2. 'casino->BaseDados': Controla o estado de maturidade do ecossistema.\n");
    printf("Gracas a isto, o Administrador tem o poder de moldar a experiencia do utilizador\n");
    printf("atraves de escolhas dinamicas no menu. O utilizador sente-se no controlo do seu destino.\n");
    printf("Valor atual da variavel 'semIncomodo': %d\n", cliente->semIncomodo);
    printf("Valor atual da variavel 'BaseDados' (Nivel de Maturidade): %d\n", casino->BaseDados);
    printf("Isto prova que cada decisao do utilizador altera o comportamento da maquina!\n\n");

    // ESPAÇO PUBLICITÁRIO 4
    printf("======================== ESPACO PUBLICITARIO 4 ========================\n");
    printf("%s\n", casino->listaAnuncios[3]);
    casino->anunciosTotais++;
    printf("=======================================================================\n\n");

    // ======================================================================
    // CAPÍTULO V: O BALANÇO PERFEITO ENTRE O COFRE E A CARTEIRA
    // ======================================================================
    printf("## CAPÍTULO V: A REDENÇÃO DO BALCÃO DE CÂMBIO\n");
    printf("----------------------------------------------------------------------\n");
    printf("A maior correcao estrutural deu-se no Balcao de Cambio. Antigamente, a troca de\n");
    printf("fichas gerava erros de arredondamento terriveis, onde o dinheiro desaparecia.\n");
    printf("O programador interveio emocionalmente. Agora, a equacao e exata e transparente.\n");
    printf("O utilizador sabe que se o Casino estiver prestes a ficar sem liquidez, o escudo\n");
    printf("antifalencia impede o desastre, mas mantem o cliente a salvo, com o seu dinheiro\n");
    printf("real guardado intacto na carteira local. Ha confianca mutua. Ha felicidade.\n");
    printf("E assim, a harmonia entre o programador, o ADM e o utilizador foi selada em C.\n");
    printf("======================================================================\n\n");

    // ESPAÇO PUBLICITÁRIO 5
    printf("======================== ESPACO PUBLICITARIO 5 ========================\n");
    printf("%s\n", casino->listaAnuncios[4]);
    casino->anunciosTotais++;
    printf("=======================================================================\n\n");

    // RELATÓRIO DE REVENUE
    printf("----------------------------------------------------------------------\n");
    printf("[ESTATÍSTICA DE MONETIZAÇÃO] Total de Anuncios Visualizados nesta sessao: %d\n", casino->anunciosTotais);
    printf("======================================================================\n");
}