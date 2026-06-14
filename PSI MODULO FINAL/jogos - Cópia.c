void jogoCartasSorte(int *fichasAtuais)
{
    if (*fichasAtuais <= 0)
    {
        printf("\nNão tens fichas suficientes para jogar! Troque dinheiro por fichas primeiro.\n");
        return;
    }

    int apostaFichas = 0;
    int escolhaPalpite = 0;

    srand(time(NULL));

    int cartaMesa = (rand() % 13) + 1;
    int proximaCarta = (rand() % 13) + 1;

    while (proximaCarta == cartaMesa)
    {
        proximaCarta = (rand() % 13) + 1;
    }

    printf("\n=== JOGO DA CARTA MAIOR OU MENOR ===\n");
    printf("Quantas fichas queres apostar? (Tens %d fichas): ", *fichasAtuais);
    scanf("%d", &apostaFichas);

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