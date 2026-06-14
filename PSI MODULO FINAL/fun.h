typedef struct
{
    int BaseDados;
    int anoAtual;
    char password[50];

    int anunciosTotais;           
    char listaAnuncios[5][250];    
    int lucroCasinoTotal;
    int prejuizoCasinoTotal;
    int avisoFaltaDinheiroCasino;
    int avisoFaltaFichasCasino;
    int transacoes;
    int dinheiroCasinoTroca;
    int dinheiroCasinoTotal;
    int dinheiroCasinoAtual;
    int fichasCasinoTotal;
    int fichasCasinoAtual;
    int fichasCasinoTrocadas;
    int fichasCasinoTroca;
    int dinheiroRetiradoTotalClientes;
    int dinheiroDepositadoTotalClientes;
    int doadorFraco;
    int doadorMedio;
    int doadorForte;
    int doadorHeroi;
    int pinNumero;
    int anoAtual;
    int limiteSegurancaMuitoBaixo;
    int limiteSegurancaBaixo;
    int limiteSegurancaMedio;
    int limiteSegurancaAlto;
    int criarContaVezes;
    int logins;
    int inicioADM;
    int pontosTotaisCasino;
    int pontosTrocaCasino;
    int pontosAtuaisCasino;
    int BaseDados;
    char password[30]; 
    int vezesJogouBolsa;
} StructCasino;

typedef struct
{
    int codigoCliente;
    int idadeClienteMain;
    int aniversarioClienteMain;
    int mesNascimentoClienteMain;
    int anoNascimentoClienteMain;
    int avisosCliente;
    int pets;
    char username[67];
    char password[20]; // Padronizado para 'password'
    char nomeClienteMain[50];
    int fichasTotais;
    int pontosTotais;
    int pontosAtuais;
    int pontosTroca;
    int dinheiroTotal;
    int dinheiroAtual;
    int fichasAtuais;
    int dinheiroRetirado;
    int dinheiroDepositado;
    int fichasRetiradas;
    int fichasDepositadas;
    int dinheiroTrocado;
    int fichasTrocadas;
    int dinheiroDoado;
    int fichasDoadas;
    int maiorTransacaoDinheiro;
    int maiorTransacaoFichas;
    int maiorCompraFichas;
    int maiorVendaFichas;
    int JogadasTotais;
    int recordes;
    int recordeCompraFichas;
    int recordeVendeFichas;
    int maiorTransacao;
    int TransacaoFichas;
    int transacaoDinheiro;
    int lucroClienteDiario;
    int prejuizoClienteTotal;
    int semIncomodo;
} StructCliente;

void menu();
void menuAdm(StructCasino *casino, StructCliente *cliente, int *apontadorCerto, int *apontadorAvaliacao, char *apontadorFeedback, int *apontadorNaoQueroResponderAvaliacao, int *apontadorNaoQueroResponderFeedback);
void menuDinheiro();
void menuFichas();
void menuGerador();
void menuInformacoesExtra();
void menuInformacoesExtraADM();
void diarioProgramador(int lucroCliente);
void menuEstatisticaADM(StructCasino *casino, StructCliente *cliente, int *apontadorAvisosCliente, int *apontadorAvaliacao, char *apontadorFeedback);

// Gestão de Contas e Segurança
void geradorCodigo(StructCliente *cliente, StructCasino *casino);
void criarConta(StructCliente *cliente, StructCasino *casino);
void novaContaCodigo(StructCliente *cliente, int tamanhoNomeCliente);

// Mecânica de Jogo
void jogoCartasSorte(int *fichasAtuais);

// Sistema de Persistência (Ficheiros)
void guardarDadosCasino(StructCasino *casino);
void carregarDadosCasino(StructCasino *casino);
void registarFeedbackCliente(StructCliente *cliente, char *feedback, char *respostaAvaliacao, int avaliacao);
void lerTodosOsFeedbacksADM();

// Estatísticas e Feedback
void avaliacaoCasino(StructCasino *casino, StructCliente *cliente, int *apontadorCerto, int *apontadorAvaliacao, int *apontadorNaoQueroResponderAvaliacao, int *apontadorNaoQueroResponderFeedback, char *feedback, char *respostaAvaliacao);
void carregarDinheiroFichasCasino(StructCasino *casino);
void carregarDinheiroFichasCliente(StructCliente *cliente);
void carregarEstatisticasCliente(StructCliente *cliente);
void carregarEstatisticasCasino(StructCasino *casino);
void carregarFeedbackAvaliacoes(StructCliente *cliente, int *avaliacao, int *avaliacaoSingular, char *feedback, int *naoQueroResponderAvaliacao, int *naoQueroResponderFeedback, char *respostaAvaliacao);
void carregarContasSeguranca(StructCasino *casino, StructCliente *cliente);
void imprimirBibliaDoProgramadorMundial(StructCasino *casino, StructCliente *cliente);