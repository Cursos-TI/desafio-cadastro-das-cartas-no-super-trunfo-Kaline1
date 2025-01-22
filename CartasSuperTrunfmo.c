#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float populacao;
    float area;
    float pib;
    int pontos_turisticos;
    char nome[64];
} Cidade;
void exibir_carta(Cidade carta) {
    printf("Carta: %s\n", carta.nome);
    printf("População: %.2f mil\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}
int escolher_característica() {
    int escolha;
    printf("\nEscolha uma característica para comparar:\n");
    printf("1 - População:\n");
    printf("2 - Área:\n");
    printf("3 - PIB:\n");
    printf("4 - Pontos turísticos:\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}
int comparar_característica(Cidade carta_jogador, Cidade carta_computador, int característica) {
    switch (característica) {
        case 1:  
            return carta_jogador.populacao > carta_computador.populacao;
        case 2:  
            return carta_jogador.area > carta_computador.area;
        case 3:  
            return carta_jogador.pib > carta_computador.pib;
        case 4:  
            return carta_jogador.pontos_turisticos > carta_computador.pontos_turisticos;
        default:
            return 0;
    }
}
int main() {
    srand(time(0));  
    Cidade cartas[] = {
        // Cartas do Brasil.
        {2279.686, 11.401, 103.281, 10, "Manaus A01"},
        {96.372, 5.952333, 12.255, 6, "Parintins A02"},
        {101.883, 7.336579, 15.506, 4, "Manacapuru A03"},
        {112.520, 8.891906, 2.350463, 5, "Itacoatiara A04"},
        {1139.047, 794.571, 72.946774, 9, "Campinas B01"},
        {11895.578, 1.521, 2719.751231, 20, "São Paulo B02"},
        {423.323, 1.378069, 34.555723, 9, "Piracicaba B03"},
        {728.615, 64.935, 76.311813, 6, "Osasco B04"},
        {460.434, 34.082, 20.059522, 6, "Porto Velho C01"},
        {86.887, 3.792, 32.313, 4, "Cacoal C02"},
        {108.528, 11.699, 2.000000, 4, "Vilhena C03"},
        {39.387, 24.855724, 740.159, 4, "Guajará Mirim C04"},
        {2417.678, 693.442, 62.954487, 15, "Salvador D01"},
        {237.821, 6.721, 5.181529, 5, "Juazeiro D02"},
        {178.649, 1.588555, 5.163622, 7, "Ilheus D03"},
        {300.372, 785421, 33.971705, 4, "Camaçari D04"},
        {754954, 4.115206, 43.129284, 5, "Uberlândia E01"},
        {411859, 343884, 33.132919131, 7, "Betim E02"},
        {621865, 195045, 36.479764, 8, "Contagem E03"},
        {227731, 164884, 17.609176, 6, "Ipatinga E04"},
        {203023, 2068474, 4.774446, 8, "Sobral F01"},
        {286120, 258788, 5.110056, 5, "Zuazero do Norte F02"},
        {2428.678, 312353, 73.436128, 12, "Fortaleza F03"},
        {131123, 1.614682, 1.190000000, 4, "Itapipoca F04"},
        {481749, 133757, 46.553203, 10, "Niterói G01"},
        {68088, 1.300767, 3.122611, 6, "Valença G02"},
        {197277, 361572, 5.856874, 9, "Maricá G03"},
        {228127, 390775, 4.765844, 7, "Magé G04"},
        {336131, 1.609708, 9.494825, 6, "Pelotas H01"},
        {40134, 239341, 2.658017, 16, "Gramado H02"},
        {463338, 1.652308, 25.965161, 8, "Caxias do Sul H03"},
        {1332570, 495, 76.074563, 10, "Porto Alegre H04"},
        // Cartas do Estados Unidos.
        {706.799, 400.74, 311.876, 13, "Denver I01"},
        {395.052, 423.691, 211.192596, 9, "Aurora I02"},
        {155.961, 64.95, 211.192596, 5, "Lakewood I03"},
        {488.664, 507.019, 36.241661, 7, "Colorado Springs I04"},
        {403.364, 455.40, 158.044077, 7, "Tampa J01"},
        {320.742, 286.50, 141.200311, 15, "Orlando J02"},
        {455.924, 145.23, 359.852689, 14, "Miami J03"},
        {224.455, 312.40, 32.564768, 8, "Cape Coral J04"},
        {913.175, 585.07, 131.537720, 10, "Columbus K01"},
        {270.871, 217.87, 35.981768, 6, "Toledo K02"},
        {135.512, 146.7, 43.183270, 8, "Dayton K03"},
        {47.711, 80.01, 4.591106, 6, "Mansfield K04"},
        {979.882, 845.66, 149.306992, 9, "Austin L01"},
        {1304.379, 993.10, 506.219605, 11, "Dallas L02"},
        {678.958, 671.41, 31.352307, 13, "El Paso L03"},
        {2304.580, 1.73964, 491.166782, 14, "Houston L04"},
        {3822.238, 1.29901, 991.254189, 18, "Los Angeles M01"},
        {1381.162, 964.57, 230.518588, 10, "San Diego M02"},
        {542.107, 301.43, 43.779278, 8, "Fresno M03"},
        {66.224, 40.90, 6.027876, 8, "Madera M04"},
        {641.903, 367.46, 122.721414, 20, "Las Vegas N01"},
        {58.639, 406.94, 3.474293, 7, "Carson City N02"},
        {225.221, 288.98, 28.776037, 11, "Reno N03"},
        {317.610, 279.02, 122.721414, 16, "Henderson N04"},
        {498.715, 353.04, 413.028, 17, "Atlanta O01"},
        {147.780, 281.61, 21.468332, 12, "Savannah O02"},
        {115.452, 306.01, 10.330759, 11, "Athens O03"},
        {195.844, 794.27, 27.499759, 4, "Augusta O04"},
        {1608.139, 1.34453, 257.410455, 13, "Phoenix P01"},
        {542.629, 624.99, 43.891349, 9, "Tucson P02"},
        {43.888, 395.08, 4.589727, 4, "Sierra Vista P03"},
        {504.258, 361.07, 257.410455, 7, "Mesa P04"}
    };
    int num_cartas = sizeof(cartas) / sizeof(cartas[0]);
    int pontos_jogador = 0, pontos_computador = 0;

    while (1) {
        Cidade carta_jogador = cartas[rand() % num_cartas];
        Cidade carta_computador = cartas[rand() % num_cartas];

        printf("\nEsta é a sua carta:\n");
        exibir_carta(carta_jogador);

        printf("\nEsta é a carta do computador:\n");
        exibir_carta(carta_computador);

        int característica = escolher_característica();

        if (comparar_característica(carta_jogador, carta_computador, característica)) {
            printf("\nVocê ganhou.\n");
            pontos_jogador++;
        } else {
            printf("\nO computador ganhou.\n");
            pontos_computador++;
        }
        printf("\nPlacar:\n");
        printf("Você: %d pontos\n", pontos_jogador);
        printf("Computador: %d pontos\n", pontos_computador);

        char continuar;
        printf("\nQuer continuar o jogo? (s/n): ");
        scanf(" %c", &continuar);

        if (continuar == 'n' || continuar == 'N') {
            break;
        }
    }
    if (pontos_jogador > pontos_computador) {
        printf("\nVocê ganhou.\n");
    } else if (pontos_jogador < pontos_computador) {
        printf("\nO computador ganhou.\n");
    } else {
        printf("\nO jogo empatou.\n");
    }

    return 0;
}