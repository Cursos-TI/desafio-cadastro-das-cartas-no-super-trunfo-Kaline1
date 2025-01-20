#include <stdlib.h>
#include <time.h>

typedef struct {
    float populacao;
    float area;
    float pib;
    int pontos_turisticos;
    char nome[50];
} Cidade;

Cidade cartas_brasil[8][4] = {
    {{2.279686, 11.401, 103.281, 7, "Manaus A01"}, {96.372, 5.952333, 12.255, 6, "Parintins A02"}, {101.883, 7.336579, 15.506, 4, "Manacapuru A03"}, {112.520, 8.891906, 2.350463, 5, "Itacoatiara A04"}},
    {{1.139047, 794.571, 72.946774, 7, "Campinas B01"}, {11.895578, 1.521, 2.719751231, 18, "São Paulo B02"}, {423.323, 1.378069, 34.555723, 7, "Piracicaba B03"}, {728.615, 64.935, 76.311813, 6, "Osasco B04"}},
    {{460.434, 34.082, 20.059522, 6, "Porto Velho C01"}, {86.887, 3.792, 32.313, 2, "Cacoal C02"}, {108.528, 11.699, 2.000000, 3, "Vilhena C03"}, {39.387, 24.855724, 740.159, 5, "Guajará Mirim C04"}},
    {{2.417678, 693.442, 62.954487, 11, "Salvador D01"}, {237.821, 6.721, 5.181529, 5, "Juazeiro D02"}, {178.649, 1.588555, 5.163622, 7, "Ilheus D03"}, {300.372, 785421, 33.971705, 3, "Camaçari D04"}},
    {{754954, 4.115206, 43.129284, 5, "Uberlândia E01"}, {411859, 343884, 33.132919131, 3, "Betim E02"}, {621865, 195045, 36.479764, 5, "Contagem E03"}, {227731, 164884, 17.609176, 4, "Ipatinga E04"}},
    {{203023, 2068474, 4.774446, 5, "Sobral F01"}, {286120, 258788, 5.110056, 2, "Zuazero do Norte F02"}, {2.428678, 312353, 73.436128, 6, "Fortaleza F03"}, {131123, 1.614682, 1.190000000, 4, "Itapipoca F04"}},
    {{481749, 133757, 46.553203, 9, "Niterói G01"}, {68088, 1.300767, 3.122611, 3, "Valença G02"}, {197277, 361572, 5.856874, 9, "Maricá G03"}, {228127, 390775, 4.765844, 7, "Magé G04"}},
    {{336131, 1.609708, 9.494825, 6, "Pelotas H01"}, {40134, 239341, 2.658017, 10, "Gramado H02"}, {463338, 1.652308, 25.965161, 2, "Caxias do Sul H03"}, {1.332570, 495, 76.074563, 7, "Porto Alegre H04"}}
};
Cidade cartas_eua[8][4] = {
    {{706.799, 400.74, 311.876, 13, "Denver I01"}, {395.052, 423.691, 211.192596, 9, "Aurora I02"}, {155.961, 64.95, 211.192596, 5, "Lakewood I03"}, {488.664, 507.019, 36.241661, 7, "Colorado Springs I04"}},
    {{403.364, 455.40, 158.044077, 7, "Tampa J01"}, {320.742, 286.50, 141.200311, 15, "Orlando J02"}, {455.924, 145.23, 359.852689, 14, "Miami J03"}, {224.455, 312.40, 32.564768, 8, "Cape Coral J04"}},
    {{913.175, 585.07, 131.537720, 10, "Columbus K01"}, {270.871, 217.87, 35.981768, 6, "Toledo K02"}, {135.512, 146.7, 43.183270, 8, "Dayton K03"}, {47.711, 80.01, 4.591106, 6, "Mansfield K04"}},
    {{979.882, 845.66, 149.306992, 9, "Austin L01"}, {1.304379, 993.10, 506.219605, 11, "Dallas L02"}, {678.958, 671.41, 31.352307, 13, "El Paso L03"}, {2.304580, 1.73964, 491.166782, 14, "Houston L04"}},
    {{3.822238, 1.29901, 991.254189, 18, "Los Angeles M01"}, {1.381162, 964.57, 230.518588, 10, "San Diego M02"}, {542.107, 301.43, 43.779278, 8, "Fresno M03"}, {66.224, 40.90, 6.027876, 8, "Madera M04"}},
    {{641.903, 367.46, 122.721414, 20, "Las Vegas N01"}, {58.639, 406.94, 3.474293, 7, "Carson City N02"}, {225.221, 288.98, 28.776037, 11, "Reno N03"}, {317.610, 279.02, 122.721414, 16, "Henderson N04"}},
    {{498.715, 353.04, 413.028, 17, "Atlanta O01"}, {147.780, 281.61, 21.468332, 12, "Savannah O02"}, {115.452, 306.01, 10.330759, 11, "Athens O03"}, {195.844, 794.27, 27.499759, 4, "Augusta O04"}},
    {{1.608139, 1.34453, 257.410455, 13, "Phoenix P01"}, {542.629, 624.99, 43.891349, 9, "Tucson P02"}, {43.888, 395.08, 4.589727, 4, "Sierra Vista P03"}, {504.258, 361.07, 257.410455, 7, "Mesa P04"}}
};
int gerar_numero_aleatorio(int max) {
    return rand() % max;
}
void jogar_rodada(Cidade* carta_jogador, Cidade* carta_computador, int criterio, int* vitorias_jogador, int* vitorias_computador) {
    float valor_jogador, valor_computador;
    char* criterio_nome;

 switch (criterio) {
   case 0:
      valor_jogador = carta_jogador->populacao;
      valor_computador = carta_computador->populacao;
      criterio_nome = "População";
      break;
   case 1:
        valor_jogador = carta_jogador->area;
        valor_computador = carta_computador->area;
        criterio_nome = "Área";
        break;
     case 2:
        valor_jogador = carta_jogador->pib;
        valor_computador = carta_computador->pib;
        criterio_nome = "PIB";
        break;
    case 3:
       valor_jogador = carta_jogador->pontos_turisticos;
        valor_computador = carta_computador->pontos_turisticos;
        criterio_nome = "Pontos Turísticos";
       break;
  }

    printf("Critério: %s\n", criterio_nome);
    printf("Jogador escolheu: %s\n", carta_jogador->nome);
    printf("Computador escolheu: %s\n", carta_computador->nome);

    if (valor_jogador > valor_computador) {
        printf("Você ganhou a rodada!\n");
        (*vitorias_jogador)++;
    } else if (valor_computador > valor_jogador) {
        printf("O computador ganhou a rodada!\n");
        (*vitorias_computador)++;
    } else {
        printf("Empate!\n");
    }
}
int main() {
    srand(time(NULL));

    int criterio;
    int vitorias_jogador = 0, vitorias_computador = 0;

    for (int rodada = 1; rodada <= 3; rodada++) {
        printf("\n--- Rodada %d ---\n", rodada);

        printf("Escolha o critério para a comparação:\n");
        printf("0 - População\n");
        printf("1 - Área\n");
        printf("2 - PIB\n");
        printf("3 - Pontos Turísticos\n");
        printf("Digite o número do critério: ");
        scanf("%d", &criterio);

        int estado_brasil = gerar_numero_aleatorio(8);
        int cidade_brasil = gerar_numero_aleatorio(4);
        int estado_eua = gerar_numero_aleatorio(8);
        int cidade_eua = gerar_numero_aleatorio(4);

        int cidade_jogador = gerar_numero_aleatorio(4);
        
        printf("\nRodada %d:\n", rodada);
        jogar_rodada(&cartas_brasil[estado_brasil][cidade_jogador], &cartas_eua[estado_eua][cidade_eua], criterio, &vitorias_jogador, &vitorias_computador);
    }
    printf("\n--- Resultado Final ---\n");
    printf("Vitórias do jogador: %d\n", vitorias_jogador);
    printf("Vitórias do computador: %d\n", vitorias_computador);

    if (vitorias_jogador > vitorias_computador) {
        printf("Você ganhou!\n");
    } else if (vitorias_computador > vitorias_jogador) {
        printf("O computador ganhou!\n");
    } else {
        printf("Terminou em empate!\n");
    }
    return 0;
}