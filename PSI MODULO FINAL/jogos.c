#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fun.h"
#include <time.h>

void jogoCartasSorte(int *fichasAtuais)
{
    if (*fichasAtuais <= 0)
    {
        printf("\nNão tens fichas suficientes para jogar! Troque dinheiro por fichas primeiro.\n");
        return;
    }

    int apostaFichas = 0;
    int escolhaPalpite = 0;

    int cartaMesa = (rand() % 13) + 1;
    int proximaCarta = (rand() % 13) + 1;

    while (proximaCarta == cartaMesa)
    {
        proximaCarta = (rand() % 13) + 1;
    }

    printf("\n=== JOGO DA CARTA MAIOR OU MENOR ===\n");
    printf("Quantas fichas queres apostar? (Tens %d fichas): ", *fichasAtuais);
    if (scanf("%d", &apostaFichas) != 1)
        {
            printf("Quantidade de fichas inválida!\n");
            cliente->avisosCliente++;

            return;
        }


    if (apostaFichas <= 0)
    {
        printf("Quantidade de fichas inválida!\n");
        return;
    }
    if (apostaFichas > *fichasAtuais)
    {
        printf("Quantidade de fichas inválida!\n");
        return;
    }

    printf("\nA carta na mesa é um: [%d]\n", cartaMesa);
    printf("A achas que a próxima carta será:\n");
    printf("1 - Maior\n");
    printf("2 - Menor\n");
    printf("Escolha: ");
    scanf("%d", &escolhaPalpite);

    printf("\nA próxima carta virada foi um: [%d]\n", proximaCarta);

    if (escolhaPalpite == 1)
    {
        if (proximaCarta > cartaMesa)
        {
            printf("Parabéns, acertaste! Ganhaste %d fichas.\n", apostaFichas);
            *fichasAtuais = *fichasAtuais + apostaFichas;
        }
        if (proximaCarta <= cartaMesa)
        {
            printf("Infelizmente falhaste! Perdeste %d fichas.\n", apostaFichas);
            *fichasAtuais = *fichasAtuais - apostaFichas;
        }
    }
    if (escolhaPalpite == 2)
    {
        if (proximaCarta < cartaMesa)
        {
            printf("Parabéns, acertaste! Ganhaste %d fichas.\n", apostaFichas);
            *fichasAtuais = *fichasAtuais + apostaFichas;
        }
        if (proximaCarta >= cartaMesa)
        {
            printf("Infelizmente falhaste! Perdeste %d fichas.\n", apostaFichas);
            *fichasAtuais = *fichasAtuais - apostaFichas;
        }
    }
    if (escolhaPalpite < 1)
    {
        printf("Escolha inválida!\n");
    }
    if (escolhaPalpite > 2)
    {
        printf("Escolha inválida!\n");
    }
}
// ======================================================================
// SEGUNDO JOGO: DADOS DA SORTE (OPÇÃO 2 DO CASINO)
// ======================================================================
void jogarDadosSorte(StructCasino *casino, StructCliente *cliente)
{
    int aposta;
    int dado1, dado2, soma;
    int ponto;

    // Garante que os dados mudam de valor a cada execução
    srand(time(NULL));

    system("cls");
    printf("==================================================\n");
    printf("          BEM-VINDO AOS DADOS DA SORTE!           \n");
    printf("==================================================\n");
    printf(" Regras: \n");
    printf(" - Somas de 7 ou 11 no 1º lançamento -> GANHAS IMEDIATAMENTE!\n");
    printf(" - Somas de 2, 3 ou 12 no 1º lançamento -> O CASINO GANHA!\n");
    printf(" - Outro numero vira o teu 'PONTO'. Tens de rolar os dados\n");
    printf("   ate repetir esse numero para ganhar. Se sair um 7 antes, perdes!\n");
    printf("==================================================\n");
    printf(" As tuas Fichas Atuais: %d\n", cliente->fichasAtuais);
    printf(" Quanto desejas apostar? (0 para desistir): ");
    
    if (scanf("%d", &aposta) != 1)
    {
        printf("\n[ERRO] Introduz apenas numeros inteiros!\n");
        scanf("%*s"); // Limpa o buffer
        system("pause");
        return;
    }

    if (aposta <= 0)
    {
        printf("\nJogo cancelado. A voltar ao menu principal...\n");
        system("pause");
        return;
    }

    if (aposta > cliente->fichasAtuais)
    {
        printf("\n[ERRO] Nao tens fichas suficientes para essa aposta!\n");
        system("pause");
        return;
    }

    // Deduz a aposta das fichas do jogador e atualiza o histórico
    cliente->fichasAtuais -= aposta;

    // Primeiro Lançamento
    printf("\nA pressionar o copo e a lancar os dados...\n");
    system("pause");

    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;
    soma = dado1 + dado2;

    printf("\n> DADO 1: [%d]  |  > DADO 2: [%d]\n", dado1, dado2);
    printf(">>>> SOMA TOTAL: %d <<<<\n\n", soma);

    // Verificação da primeira ronda
    if (soma == 7 || soma == 11)
    {
        int ganho = aposta * 2;
        cliente->fichasAtuais += ganho;
        casino->fichasCasinoAtual -= aposta; // Casino paga o prémio
        printf("==================================================\n");
        printf("   PARABENS! Ganhaste o primeiro lancamento!\n");
        printf("   Recebeste: %d fichas!\n", ganho);
        printf("==================================================\n");
        
        // Atualiza estatísticas de maior transação se for o caso
        if (ganho > cliente->maiorTransacaoFichas) {
            cliente->maiorTransacaoFichas = ganho;
        }
    }
    else if (soma == 2 || soma == 3 || soma == 12)
    {
        casino->fichasCasinoAtual += aposta; // Casino arrecada a aposta
        printf("==================================================\n");
        printf("   CRAPS! O casino ganhou esta ronda.\n");
        printf("   Perbeste: %d fichas.\n", aposta);
        printf("==================================================\n");
    }
    else
    {
        // Fase do Ponto
        ponto = soma;
        printf("--------------------------------------------------\n");
        printf(" O teu PONTO foi estabelecido em: [ %d ]\n", ponto);
        printf(" Tens de conseguir outra soma %d antes que saia um 7!\n", ponto);
        printf("--------------------------------------------------\n");

        int jogoAtivo = 1;
        while (jogoAtivo == 1)
        {
            system("pause");
            dado1 = (rand() % 6) + 1;
            dado2 = (rand() % 6) + 1;
            soma = dado1 + dado2;

            printf("\n> Novo Lancamento -> DADO 1: [%d] | DADO 2: [%d] -> SOMA: %d\n", dado1, dado2, soma);

            if (soma == ponto)
            {
                int ganho = aposta * 2;
                cliente->fichasAtuais += ganho;
                casino->fichasCasinoAtual -= aposta;
                printf("\n==================================================\n");
                printf("   INCRIVEL! Acertaste no teu Ponto [%d]!\n", ponto);
                printf("   Ganhaste: %d fichas!\n", ganho);
                printf("==================================================\n");
                jogoAtivo = 0;

                if (ganho > cliente->maiorTransacaoFichas) {
                    cliente->maiorTransacaoFichas = ganho;
                }
            }
            else if (soma == 7)
            {
                casino->fichasCasinoAtual += aposta;
                printf("\n==================================================\n");
                printf("   AZAR! Saiu um 7 antes do teu ponto!\n");
                printf("   O casino ganha. Perdeste %d fichas.\n", aposta);
                printf("\n==================================================\n");
                jogoAtivo = 0;
            }
        }
    }

    // Incrementa o contador geral de transações/jogadas do casino
    casino->transacoes++;
    system("pause");
}
// ======================================================================
// TERCEIRO JOGO: ROLETA DE COMBATE (OPÇÃO 3 DO CASINO)
// ======================================================================
void jogarRoletaCombate(StructCasino *casino, StructCliente *cliente)
{
    int aposta;
    int escolhaFacao;
    int resultadoRoleta;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    system("cls");
    printf("==================================================\n");
    printf("          BEM-VINDO A ROLETA DE COMBATE!          \n");
    printf("==================================================\n");
    printf(" Escolha a sua facao e aposte nas chances de vitoria:\n");
    printf("  [1] Dragao    (Multiplicador: 3x)\n");
    printf("  [2] Cavaleiro (Multiplicador: 3x)\n");
    printf("  [3] Mago      (Multiplicador: 3x)\n");
    printf("==================================================\n");
    printf(" As tuas Fichas Atuais: %d\n", cliente->fichasAtuais);
    
    printf(" Escolha a sua facao (1-3) ou 0 para sair: ");
    if (scanf("%d", &escolhaFacao) != 1)
    {
        printf("\n[ERRO] Escolha invalida!\n");
        scanf("%*s");
        system("pause");
        return;
    }

    if (escolhaFacao == 0) return;

    if (escolhaFacao < 1 || escolhaFacao > 3)
    {
        printf("\n[AVISO] Facao nao reconhecida. A regressar ao menu...\n");
        system("pause");
        return;
    }

    printf(" Quanto desejas apostar?: ");
    if (scanf("%d", &aposta) != 1)
    {
        printf("\n[ERRO] Valor invalido!\n");
        scanf("%*s");
        system("pause");
        return;
    }

    if (aposta <= 0 || aposta > cliente->fichasAtuais)
    {
        printf("\n[ERRO] Saldo insuficiente ou aposta invalida!\n");
        system("pause");
        return;
    }

    // Deduz as fichas do jogador
    cliente->fichasAtuais -= aposta;

    printf("\n As facoes entram na arena...\n");
    printf(" A girar a roleta de combate...");
    system("pause");

    // Sorteia um número entre 1 e 3
    resultadoRoleta = (rand() % 3) + 1;

    printf("\n==================================================\n");
    if (resultadoRoleta == 1) printf(" >>>> VENCEDOR DA ARENA: [1] DRAGAO <<<<\n");
    if (resultadoRoleta == 2) printf(" >>>> VENCEDOR DA ARENA: [2] CAVALEIRO <<<<\n");
    if (resultadoRoleta == 3) printf(" >>>> VENCEDOR DA ARENA: [3] MAGO <<<<\n");
    printf("==================================================\n");

    if (escolhaFacao == resultadoRoleta)
    {
        int ganho = aposta * 3; // Paga 3x o valor apostado
        cliente->fichasAtuais += ganho;
        casino->fichasCasinoAtual -= (ganho - aposta); // Casino cobre o prejuízo do prémio
        
        printf(" PARABENS! A tua facao esmagou os adversarios!\n");
        printf(" Recebeste: %d fichas!\n", ganho);
        
        if (ganho > cliente->maiorTransacaoFichas) {
            cliente->maiorTransacaoFichas = ganho;
        }
    }
    else
    {
        casino->fichasCasinoAtual += aposta; // Casino fica com a aposta
        printf(" A tua facao caiu em combate. Mais sorte na proxima!\n");
        printf(" Perdeste: %d fichas.\n", aposta);
    }

    casino->transacoes++;
    printf("==================================================\n");
    system("pause");
}
// ======================================================================
// QUARTO JOGO: BLACKJACK TÁTICO (OPÇÃO 4 - MAIS ESTRATÉGIA)
// ======================================================================
void jogarBlackjackTatico(StructCasino *casino, StructCliente *cliente)
{
    int aposta;
    int totalJogador = 0, totalBanca = 0;
    int escolha;
    
    srand(time(NULL));

    system("cls");
    printf("==================================================\n");
    printf("          BEM-VINDO AO BLACKJACK TATICO!          \n");
    printf("==================================================\n");
    printf(" Regras e Estrategia:\n");
    printf(" - O teu objetivo e aproximar-te ao maximo de 21 sem passar.\n");
    printf(" - Podes pedir cartas ([1] Pedir) as vezes que quiseres.\n");
    printf(" - Se achares que ja tens o suficiente, podes parar ([2] Plantar).\n");
    printf(" - A Banca e obrigada a pedir cartas ate somar pelo menos 17.\n");
    printf("==================================================\n");
    printf(" As tuas Fichas Atuais: %d\n", cliente->fichasAtuais);
    printf(" Quanto desejas apostar? (0 para sair): ");

    if (scanf("%d", &aposta) != 1)
    {
        printf("\n[ERRO] Digite apenas numeros!\n");
        scanf("%*s");
        system("pause");
        return;
    }

    if (aposta <= 0) return;

    if (aposta > cliente->fichasAtuais)
    {
        printf("\n[ERRO] Nao tens fichas suficientes!\n");
        system("pause");
        return;
    }

    // Deduz a aposta
    cliente->fichasAtuais -= aposta;

    // Distribuição inicial (2 cartas para o jogador, 1 visível para a banca)
    totalJogador += (rand() % 10) + 2; // Cartas de 2 a 11
    totalJogador += (rand() % 10) + 2;
    totalBanca += (rand() % 10) + 2;

    // --- TURNO DO JOGADOR (ESTRATEGIA) ---
    int turnoJogador = 1;
    while (turnoJogador == 1 && totalJogador <= 21)
    {
        system("cls");
        printf("==================================================\n");
        printf("                EM JOGO - BLACKJACK               \n");
        printf("==================================================\n");
        printf(" Aposta na mesa: %d fichas\n\n", aposta);
        printf(" >> A tua pontuacao atual: [ %d ]\n", totalJogador);
        printf(" >> Carta visivel da Banca: [ %d ]\n", totalBanca);
        printf("==================================================\n");
        printf(" [1] Pedir Carta (Arriscar mais)\n");
        printf(" [2] Plantar       (Manter a pontuacao atual)\n");
        printf("==================================================\n");
        printf(" Escolha a sua jogada estrategica: ");
        
        if (scanf("%d", &escolha) != 1)
        {
            scanf("%*s");
            escolha = 2; // Força plantar se houver erro
        }

        if (escolha == 1)
        {
            int novaCarta = (rand() % 10) + 2;
            totalJogador += novaCarta;
            printf("\n Recebeste um: [%d]! Nova pontuacao: %d\n", novaCarta, totalJogador);
            system("pause");
        }
        else
        {
            turnoJogador = 0; // Jogador decidiu parar estrategicamente
        }
    }

    // Verifica se o jogador estourou logo de início
    if (totalJogador > 21)
    {
        casino->fichasCasinoAtual += aposta;
        printf("\n==================================================\n");
        printf("   ESTOURASTE! O teu total foi %d (Passou de 21).\n", totalJogador);
        printf("   O casino ganha. Perdeste %d fichas.\n", aposta);
        printf("==================================================\n");
        casino->transacoes++;
        system("pause");
        return;
    }

    // --- TURNO DA BANCA (INTELIGÊNCIA AUTOMÁTICA) ---
    printf("\n O jogador plantou com %d. Turno da Banca...\n", totalJogador);
    system("pause");

    while (totalBanca < 17)
    {
        int novaCartaBanca = (rand() % 10) + 2;
        totalBanca += novaCartaBanca;
        printf(" Banca tirou um [%d]. Total da Banca: %d\n", novaCartaBanca, totalBanca);
        system("pause");
    }

    // --- JULGAMENTO DOS RESULTADOS ---
    system("cls");
    printf("==================================================\n");
    printf("               RESULTADO DO CONFRONTO             \n");
    printf("==================================================\n");
    printf(" >> Pontuacao Final do Jogador: %d\n", totalJogador);
    printf(" >> Pontuacao Final da Banca:   %d\n", totalBanca);
    printf("==================================================\n\n");

    if (totalBanca > 21)
    {
        // Banca estourou, jogador ganha
        int ganho = aposta * 2;
        cliente->fichasAtuais += ganho;
        casino->fichasCasinoAtual -= aposta;
        printf(" A Banca estourou com %d! VITORIA DO JOGADOR!\n", totalBanca);
        printf(" Recebeste: %d fichas!\n", ganho);
        
        if (ganho > cliente->maiorTransacaoFichas) {
            cliente->maiorTransacaoFichas = ganho;
        }
    }
    else if (totalJogador > totalBanca)
    {
        // Jogador chegou mais perto de 21
        int ganho = aposta * 2;
        cliente->fichasAtuais += ganho;
        casino->fichasCasinoAtual -= aposta;
        printf(" Incrivel! Superaste a pontuacao da banca!\n");
        printf(" Recebeste: %d fichas!\n", ganho);

        if (ganho > cliente->maiorTransacaoFichas) {
            cliente->maiorTransacaoFichas = ganho;
        }
    }
    else if (totalJogador < totalBanca)
    {
        // Banca ganhou
        casino->fichasCasinoAtual += aposta;
        printf(" A Banca ganhou com uma pontuacao superior.\n");
        printf(" Perdeste: %d fichas.\n", aposta);
    }
    else
    {
        // Empate perfeito (Push) -> Devolve as fichas ao jogador
        cliente->fichasAtuais += aposta;
        printf(" EMPATE! As pontuacoes sao iguais.\n");
        printf(" As tuas %d fichas foram devolvidas.\n", aposta);
    }

    casino->transacoes++;
    printf("==================================================\n");
    system("pause");
}
// ======================================================================
// QUINTO JOGO V3: SIMULADOR EVOLUTIVO COM BLOQUEIO DE TENTATIVAS
// ======================================================================
void jogarInvestimentoInteligente(StructCasino *casino, StructCliente *cliente)
{
    // VERIFICAÇÃO DE SEGURANÇA: Se já jogou 4 ou mais vezes, o jogo fica INDISPONÍVEL
    if (cliente->vezesJogouBolsa >= 4)
    {
        system("cls");
        printf("======================================================================\n");
        printf(" [ALERTA CRITICO] OPERACAO BLOQUEADA PELO BANCO CENTRAL              \n");
        printf("======================================================================\n");
        printf(" Detetamos atividade suspeita de manipulacao de mercado e insider trading.\n");
        printf(" O seu perfil executou o limite maximo de 4 simulacoes semanais.\n\n");
        printf(" STATUS DO JOGO: INDISPONIVEL (Contacte o Administrador: Eduardo)\n");
        printf("======================================================================\n");
        system("pause");
        return; 
    }

    int precos[3] = {15, 30, 60}; 
    int acoesJogador[3] = {0, 0, 0}; 
    char nomes[3][20] = {"Yougux Tech", "Royale Mining", "Cyber Bet"};
    
    int capitalInicial = cliente->fichasAtuais;
    int escolha, empresa, qtd;
    int taxaCorretagem = 1; 
    int totalRondas = 10;   

    srand(time(NULL));

    system("cls");
    printf("======================================================================\n");
    printf("        BEM-VINDO AO SIMULADOR DE INVESTIMENTO - YOUGUX INVEST        \n");
    printf("======================================================================\n");
    printf(" [INFO] Esta e a sua TENTATIVA Numero: %d / 4\n", cliente->vezesJogouBolsa + 1);
    printf(" PREPARE A SUA ESTRATEGIA: Jogo longo de %d Rondas.\n", totalRondas);
    printf(" Os cenarios mudam dinamicamente a cada nova tentativa no Casino!\n");
    printf("======================================================================\n");
    system("pause");

    for (int ronda = 1; ronda <= totalRondas; ronda++)
    {
        // --- SISTEMA EVOLUTIVO DE CENÁRIOS (A partir do Dia 2) ---
        if (ronda > 1)
        {
            system("cls");
            printf("======================================================================\n");
            printf("               RELATORIO DO MERCADO FINANCEIRO - DIA %02d              \n", ronda);
            printf("======================================================================\n");
            
            int eventoGlobal = rand() % 15; 
            int oscilacao = 0;

            // ==================================================================
            // FASE 0 (PRIMEIRA VEZ QUE JOGA) - CENÁRIOS PADRÃO
            // ==================================================================
            if (cliente->vezesJogouBolsa == 0)
            {
                switch(eventoGlobal) {
                    case 0: precos[0] += 12; printf(" [FASE 1] Yougux Tech lanca uma nova placa grafica topo de gama! (+12 fichas)\n"); break;
                    case 1: precos[0] -= 10; printf(" [FASE 1] Bug critico nos sistemas operativos da Yougux Tech! (-10 fichas)\n"); break;
                    case 2: precos[1] += 20; printf(" [FASE 1] Nova veia de minerio de Ferro encontrada pela Royale Mining! (+20 fichas)\n"); break;
                    case 3: precos[1] -= 15; printf(" [FASE 1] Inundacao nas galerias subterraneas da Royale Mining! (-15 fichas)\n"); break;
                    case 4: precos[2] += 25; printf(" [FASE 1] Cyber Bet fecha parceria com streamers famosos de Gaming! (+25 fichas)\n"); break;
                    case 5: precos[2] -= 20; printf(" [FASE 1] Ataque DDoS deixa a plataforma Cyber Bet offline por horas! (-20 fichas)\n"); break;
                    case 6: precos[0]+=5; precos[1]+=5; precos[2]+=5; printf(" [FASE 1] Inflacao controlada! O mercado respira de forma geral (+5 fichas).\n"); break;
                    case 7: precos[0]-=5; precos[1]-=5; precos[2]-=5; printf(" [FASE 1] Queda das bolsas europeias afeta o mercado do casino (-5 fichas).\n"); break;
                    case 8: precos[0]+=15; precos[2]+=15; printf(" [FASE 1] Parceria Tech-Bet: Novo casino virtual em Realidade Virtual! (+15 fichas)\n"); break;
                    case 9: precos[1]+=18; precos[0]-=8; printf(" [FASE 1] Greve nos transportes de microchips. Mineracao sobe, Tech cai.\n"); break;
                    case 10: precos[0] += 8; printf(" [FASE 1] Elon Musk menciona o projeto Yougux no Twitter! (+8 fichas)\n"); break;
                    case 11: precos[2] -= 14; printf(" [FASE 1] Nova lei restringe publicidade de apostas desportivas. (-14 fichas)\n"); break;
                    case 12: precos[1] += 10; printf(" [FASE 1] Royale Mining assina contrato com a industria automovel (+10 fichas).\n"); break;
                    case 13: precos[2] += 30; printf(" [FASE 1] Jackpot recorde sorteado na Cyber Bet atrai milhoes de acessos! (+30)\n"); break;
                    default: printf(" [FASE 1] Dia sem grandes oscilacoes. Investidores estao cautelosos.\n"); break;
                }
            }
            // ==================================================================
            // FASE 1 (SEGUNDA VEZ QUE JOGA) - NOVOS CENÁRIOS (MUDOU TUDO!)
            // ==================================================================
            else if (cliente->vezesJogouBolsa == 1)
            {
                switch(eventoGlobal) {
                    case 0: precos[0] += 30; printf(" [FASE 2] BOOM! Yougux Tech desenvolve uma Inteligencia Artificial Senciente! (+30)\n"); break;
                    case 1: precos[0] -= 25; printf(" [FASE 2] Processo em tribunal por quebra de patentes afeta Yougux Tech! (-25)\n"); break;
                    case 2: precos[1] += 35; printf(" [FASE 2] Descobriu-se Litio nas terras da Royale Mining! Baterias eletricas (+35)\n"); break;
                    case 3: precos[1] -= 30; printf(" [FASE 2] Desabamento de terra obriga fecho de mina principal da Royale! (-30)\n"); break;
                    case 4: precos[2] += 40; printf(" [FASE 2] Cyber Bet compra os direitos de transmissao da Champions League! (+40)\n"); break;
                    case 5: precos[2] -= 35; printf(" [FASE 2] Escandalo de resultados combinados investigado na Cyber Bet! (-35)\n"); break;
                    case 6: precos[0]+=10; precos[1]-=10; printf(" [FASE 2] Corrida digital: Investidores fogem das minas para a tecnologia!\n"); break;
                    case 7: precos[0]-=12; precos[2]+=15; printf(" [FASE 2] Crise de energia desliga servidores Tech, mas aumenta apostas de tédio!\n"); break;
                    case 8: precos[1] += 15; printf(" [FASE 2] Ouro atinge valor recorde em tempo de crise! Royale Mining em alta.\n"); break;
                    case 9: precos[0] -= 15; precos[1] -= 15; precos[2] -= 15; printf(" [FASE 2] PANICO FINANCEIRO! Bancos congelam levantamentos (-15 fichas!)\n"); break;
                    case 10: precos[0] += 14; printf(" [FASE 2] Yougux Tech passa a aceitar criptomoedas como pagamento (+14).\n"); break;
                    case 11: precos[1] += 22; printf(" [FASE 2] Fusao aprovada entre a Royale Mining e uma petrolifera (+22).\n"); break;
                    case 12: precos[2] -= 18; printf(" [FASE 2] Hackers roubam saldo de contas VIP na Cyber Bet! (-18)\n"); break;
                    case 13: precos[0] += 20; printf(" [FASE 2] Governo subsidia investimentos em tecnologia da Yougux Tech (+20).\n"); break;
                    default: printf(" [FASE 2] Dia de estabilidades e pequenos ajustes tecnicos no mercado.\n"); break;
                }
            }
            // ==================================================================
            // FASE 2 (TERCEIRA VEZ QUE JOGA) - CENÁRIOS DE CRASH E EXTREMOS
            // ==================================================================
            else if (cliente->vezesJogouBolsa == 2)
            {
                switch(eventoGlobal) {
                    case 0: precos[0] -= 40; printf(" [FASE 3 - CRISE] CEO da Yougux Tech demite-se em direto na televisao! (-40)\n"); break;
                    case 1: precos[0] += 50; printf(" [FASE 3 - HYPE] Yougux Tech compra a Google! Monopolio mundial estabelecido (+50)\n"); break;
                    case 2: precos[1] -= 45; printf(" [FASE 3 - CRISE] Mineracao proibida devido a leis ambientais severas! (-45)\n"); break;
                    case 3: precos[1] += 45; printf(" [FASE 3 - HYPE] Robo-escaners encontram Urânio nas escavacoes da Royale! (+45)\n"); break;
                    case 4: precos[2] -= 50; printf(" [FASE 3 - CRISE] Cyber Bet perde a licenca de jogo no mercado europeu! (-50)\n"); break;
                    case 5: precos[2] += 60; printf(" [FASE 3 - HYPE] Cyber Bet lanca a roleta neuronal por telepatia! Sucesso total (+60)\n"); break;
                    case 6: precos[0]+=25; precos[1]+=25; precos[2]+=25; printf(" [FASE 3] MILAGRE ECONOMICO: Mercado sobe em frenezim coletivo (+25 fichas)!\n"); break;
                    case 7: precos[0]-=30; precos[1]-=30; precos[2]-=30; printf(" [FASE 3] CRASH DA BOLSA: Dia negro na historia do Casino (-30 fichas)!\n"); break;
                    case 8: precos[0] += 33; printf(" [FASE 3] Yougux Tech ganha contrato militar para criar drones autonomos (+33).\n"); break;
                    case 9: precos[1] -= 25; printf(" [FASE 3] Sindicato fecha todas as fabricas da Royale Mining por tempo indeterminado.\n"); break;
                    case 10: precos[2] += 35; printf(" [FASE 3] Cyber Bet regista lucros historicos em Macau e Las Vegas (+35).\n"); break;
                    case 11: precos[0] -= 20; printf(" [FASE 3] Satelite da Yougux Tech explode durante o lancamento orbital (-20).\n"); break;
                    case 12: precos[1] += 28; printf(" [FASE 3] Descoberta tecnica duplica a velocidade de extracao da Royale Mining (+28).\n"); break;
                    case 13: precos[2] -= 40; printf(" [FASE 3] Investigacao policial encerra servidores alternativos da Cyber Bet (-40).\n"); break;
                    default: printf(" [FASE 3] Volatilidade extrema! Precos tremem mas mantem-se estaveis.\n"); break;
                }
            }
            // ==================================================================
            // FASE 3 (QUARTA E ÚLTIMA VEZ ANTES DE BLOQUEAR) - APOCALIPSE FINANCEIRO
            // ==================================================================
            else if (cliente->vezesJogouBolsa == 3)
            {
                switch(eventoGlobal) {
                    case 0: precos[0] = 5; printf(" [FINAL GAME] Falência iminente! Rumores que a Yougux Tech escondeu dividas! (Preco cai para 5!)\n"); break;
                    case 1: precos[0] += 70; printf(" [FINAL GAME] Hiper-Inflacao! O dinheiro perde o valor e a Tech dispara (+70)\n"); break;
                    case 2: precos[1] = 5; printf(" [FINAL GAME] Nacionalizacao forcada! O Estado confiscou os bens da Royale Mining! (Preco cai para 5!)\n"); break;
                    case 3: precos[1] += 80; printf(" [FINAL GAME] Royale Mining descobre meteorito espacial rico em Platina (+80)\n"); break;
                    case 4: precos[2] = 5; printf(" [FINAL GAME] Proibicao Total! Jogo online passa a ser crime federal! (Preco cai para 5!)\n"); break;
                    case 5: precos[2] += 90; printf(" [FINAL GAME] Cyber Bet compra o Casino do Yougux Royale por completo (+90)\n"); break;
                    default: precos[0] -= 15; precos[1] -= 15; precos[2] -= 15; printf(" [FINAL GAME] O Mercado esta a colapsar a cada minuto! Tudo a desmoronar (-15)\n"); break;
                }
            }

            // Garante estabilidade de limites
            for(int i = 0; i < 3; i++) {
                if (precos[i] < 3) precos[i] = 3;
                if (precos[i] > 400) precos[i] = 400;
            }
            printf("======================================================================\n");
            system("pause");
        }

        // --- SUB-MENU OPERACIONAL DO DIA ---
        int mercadoAberto = 1;
        while (mercadoAberto == 1)
        {
            system("cls");
            printf("======================================================================\n");
            printf("     PAINEL CENTRAL DE NEGOCIACAO - DIA [ %02d / %02d ] (TENTATIVA %d/4)\n", ronda, totalRondas, cliente->vezesJogouBolsa + 1);
            printf("======================================================================\n");
            printf(" O seu Saldo Disponivel: %d fichas\n\n", cliente->fichasAtuais);
            printf(" COTACAO DOS ATIVOS:\n");
            
            for (int i = 0; i < 3; i++)
            {
                int valorAtualCarteira = acoesJogador[i] * precos[i];
                printf(" [%d] %-15s | Preco Atual: %3d Fichas | Em Carteira: %3d (Valem: %d)\n", 
                       i + 1, nomes[i], precos[i], acoesJogador[i], valorAtualCarteira);
            }
            
            printf("======================================================================\n");
            printf(" [1] COMPRAR ATIVOS  (Investir)\n");
            printf(" [2] VENDER ATIVOS   (Liquidar)\n");
            printf(" [3] TERMINAR DIA    (Avancar no tempo)\n");
            printf("======================================================================\n");
            printf(" Introduza a sua ordem de mercado: ");
            
            if (scanf("%d", &escolha) != 1) { scanf("%*s"); escolha = 3; }

            if (escolha == 1) 
            {
                printf("\n Selecione o ativo para compra (1-3): ");
                if (scanf("%d", &empresa) != 1) { scanf("%*s"); continue; }
                empresa--;
                if (empresa >= 0 && empresa <= 2)
                {
                    printf(" Quantidade de acoes a adquirir: ");
                    if (scanf("%d", &qtd) != 1) { scanf("%*s"); continue; }
                    int custoTotal = (precos[empresa] * qtd) + taxaCorretagem;
                    if (qtd > 0 && custoTotal <= cliente->fichasAtuais)
                    {
                        cliente->fichasAtuais -= custoTotal;
                        acoesJogador[empresa] += qtd;
                        printf("\n[ORDEM EXECUTADA] Adquiriu %d acoes. Taxa: %d ficha.\n", qtd, taxaCorretagem);
                    }
                    else printf("\n[ERRO] Saldo insuficiente!\n");
                }
                system("pause");
            }
            else if (escolha == 2) 
            {
                printf("\n Selecione o ativo para venda (1-3): ");
                if (scanf("%d", &empresa) != 1) { scanf("%*s"); continue; }
                empresa--;
                if (empresa >= 0 && empresa <= 2)
                {
                    printf(" Quantidade de acoes a liquidar: ");
                    if (scanf("%d", &qtd) != 1) { scanf("%*s"); continue; }
                    if (qtd > 0 && qtd <= acoesJogador[empresa])
                    {
                        int receitaLiquida = (precos[empresa] * qtd) - taxaCorretagem;
                        cliente->fichasAtuais += receitaLiquida;
                        acoesJogador[empresa] -= qtd;
                        printf("\n[ORDEM EXECUTADA] Vendeu %d acoes. Taxa aplicada.\n", qtd);
                    }
                    else printf("\n[ERRO] Carteira insuficiente!\n");
                }
                system("pause");
            }
            else if (escolha == 3) mercadoAberto = 0;
        }
    }

    // --- ENCERRAMENTO E HISTÓRICO ---
    system("cls");
    printf("======================================================================\n");
    printf("          ENCERRAMENTO DO MERCADO FISCAL - LIQUIDACAO TOTAL            \n");
    printf("======================================================================\n");
    
    int totalLiquidado = 0;
    for (int i = 0; i < 3; i++)
    {
        if (acoesJogador[i] > 0)
        {
            int valorVenda = acoesJogador[i] * precos[i];
            totalLiquidado += valorVenda;
            cliente->fichasAtuais += valorVenda;
            printf(" -> Liquidacao obrigatoria: %3d acoes de %-15s por %d fichas.\n", acoesJogador[i], nomes[i], valorVenda);
            acoesJogador[i] = 0;
        }
    }

    int balancoFinal = cliente->fichasAtuais - capitalInicial;
    
    if (balancoFinal > 0) {
        casino->fichasCasinoAtual -= balancoFinal;
        printf("\n [LUCRO] Teve um Lucro Liquido de [ +%d ] fichas!\n", balancoFinal);
    } else if (balancoFinal < 0) {
        casino->fichasCasinoAtual += (-balancoFinal);
        printf("\n [PREJUIZO] Perdeu [ %d ] fichas nesta simulacao.\n", balancoFinal);
    }

    // !! CRUCIAL: REGISTA QUE ESTA TENTATIVA TERMINOU E SOMA MAIS UMA !!
    cliente->vezesJogouBolsa++;

    if (cliente->vezesJogouBolsa >= 4) {
        printf("\n [SISTEMA] ATENCAO: Atingiu o limite de simulacoes. O mercado colapsou permanently!\n");
    } else {
        printf("\n [SISTEMA] O mercado vai mudar os cenarios todos para a proxima tentativa (Restam %d).\n", 4 - cliente->vezesJogouBolsa);
    }

    casino->transacoes++;
    printf("======================================================================\n");
    system("pause");
}