#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float populacao;
    float area;
    float densidade_populacional;
    float pib;
    float pib_per_capita;
    int pontos_turisticos;
    char nome[64];
} Cidade;
void exibir_carta(Cidade carta) {
    printf("Carta: %s\n", carta.nome);
    printf("População: %.2f mil\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("Densidade Populacional: %.2f mil\n", carta.densidade_populacional);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("PIB per Capita: %.2f milhões\n", carta.pib_per_capita);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}
int escolher_característica() {
    int escolha;
    printf("\nEscolha a característica para comparar:\n");
    printf("1 - População:\n");
    printf("2 - Área:\n");
    printf("3 - Densidade Populacional:\n");
    printf("4 - PIB:\n");
    printf("5 - PIB per Capita:\n");
    printf("6 - Pontos turísticos:\n");
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
            return carta_jogador.densidade_populacional > carta_computador.densidade_populacional;
        case 4:  
            return carta_jogador.pib > carta_computador.pib;
        case 5:
            return carta_jogador.pib_per_capita > carta_computador.pib_per_capita;
        case 6:  
            return carta_jogador.pontos_turisticos > carta_computador.pontos_turisticos;
        default:
            return 0;
    }
}
int main() {
    srand(time(0));  
    Cidade cartas[] = {
        // Cartas do Brasil.
        {2279.686, 11.401, 200, 103.281, 45782, 10, "Manaus A01"},
        {96.372, 5.952333, 17, 12.255, 9092, 6, "Parintins A02"},
        {101.883, 7.336579, 13, 15.506, 13027, 4, "Manacapuru A03"},
        {112.520, 8.891906, 12, 2.350463, 22590, 5, "Itacoatiara A04"},
        {1139.047, 794.571, 1433, 72.946774, 59634, 9, "Campinas B01"},
        {11895.578, 1.521, 7528, 2719.751231, 66872, 20, "São Paulo B02"},
        {423.323, 1.378069, 318, 34.555723, 84225, 9, "Piracicaba B03"},
        {728.615, 64.935, 11220, 76.311813, 109025, 6, "Osasco B04"},
        {460.434, 34.082, 13, 20.059522, 36059, 6, "Porto Velho C01"},
        {86.887, 3.792, 22, 32.313, 29331, 4, "Cacoal C02"},
        {108.528, 11.699, 9, 2.000000, 28420, 4, "Vilhena C03"},
        {39.387, 24.855724, 1, 740.159, 15732, 4, "Guajará Mirim C04"},
        {2417.678, 693.442, 3486, 62.954487, 21706, 15, "Salvador D01"},
        {237.821, 6.721, 35, 5.181529, 23601, 5, "Juazeiro D02"},
        {178.649, 1.588555, 112, 5.163622, 32756, 7, "Ilheus D03"},
        {300.372, 785421, 382, 33.971705, 109866, 4, "Camaçari D04"},
        {754954, 4.115206, 183, 43.129284, 61038, 5, "Uberlândia E01"},
        {411859, 343884, 1197, 33.132919131, 73624, 7, "Betim E02"},
        {621865, 195045, 3188, 36.479764, 59136, 8, "Contagem E03"},
        {227731, 164884, 1381, 17.609176, 65869, 6, "Ipatinga E04"},
        {203023, 2068474, 98, 4.774446, 21679, 8, "Sobral F01"},
        {286120, 258788, 1105, 5.110056, 18381, 5, "Zuazeiro do Norte F02"},
        {2428.678, 312353, 7775, 73.436128, 27164, 12, "Fortaleza F03"},
        {131123, 1.614682, 81, 1.190000000, 3271, 4, "Itapipoca F04"},
        {481749, 133757, 3601, 46.553203, 90643, 10, "Niterói G01"},
        {68088, 1.300767, 52, 3.122611, 40447, 6, "Valença G02"},
        {197277, 361572, 0.5, 5.856874, 232761, 9, "Maricá G03"},
        {228127, 390775, 583, 4.765844, 19237, 7, "Magé G04"},
        {336131, 1.609708, 208, 9.494825, 27671, 6, "Pelotas H01"},
        {40134, 239341, 167, 2.658017, 55322, 16, "Gramado H02"},
        {463338, 1.652308, 280, 25.965161, 50178, 8, "Caxias do Sul H03"},
        {1332570, 495, 2689, 76.074563, 51116, 10, "Porto Alegre H04"},
        // Cartas do Estados Unidos.
        {706.799, 400.74, 1785, 311.876, 116530, 13, "Denver I01"},
        {395.052, 423.691, 928, 211.192596, 30000, 9, "Aurora I02"},
        {155.961, 64.95, 1287, 211.192596, 38000, 5, "Lakewood I03"},
        {488.664, 507.019, 24000, 36.241661, 65775, 7, "Colorado Springs I04"},
        {403.364, 455.40, 845, 158.044077, 32000, 7, "Tampa J01"},
        {320.742, 286.50, 898, 141.200311, 45807, 15, "Orlando J02"},
        {455.924, 145.23, 3045, 359.852689, 68477, 14, "Miami J03"},
        {224.455, 312.40, 563, 32.564768, 39603, 8, "Cape Coral J04"},
        {913.175, 585.07, 1548, 131.537720, 71831, 10, "Columbus K01"},
        {270.871, 217.87, 1374, 35.981768, 58180, 6, "Toledo K02"},
        {135.512, 146.7, 959, 43.183270, 22000, 8, "Dayton K03"},
        {47.711, 80.01, 597, 4.591106, 23000, 6, "Mansfield K04"},
        {979.882, 845.66, 1137, 149.306992, 24163, 9, "Austin L01"},
        {1304.379, 993.10, 1313, 506.219605, 22183, 11, "Dallas L02"},
        {678.958, 671.41, 1011, 31.352307, 46732, 13, "El Paso L03"},
        {2304.580, 1.73964, 1324, 491.166782, 60122, 14, "Houston L04"},
        {3822.238, 1.29901, 3001, 991.254189, 68355, 18, "Los Angeles M01"},
        {1381.162, 964.57, 1437, 230.518588, 79122, 10, "San Diego M02"},
        {542.107, 301.43, 1798, 43.779278, 52728, 8, "Fresno M03"},
        {66.224, 40.90, 1501, 6.027876, 29698, 8, "Madera M04"},
        {641.903, 367.46, 1746, 122.721414, 54445, 20, "Las Vegas N01"},
        {58.639, 406.94, 144, 3.474293, 38222, 7, "Carson City N02"},
        {225.221, 288.98, 779, 28.776037, 35000, 11, "Reno N03"},
        {317.610, 279.02, 1152, 122.721414, 54445, 16, "Henderson N04"},
        {498.715, 353.04, 1412, 413.028, 77119, 17, "Atlanta O01"},
        {147.780, 281.61, 524, 21.468332, 29452, 12, "Savannah O02"},
        {115.452, 306.01, 383, 10.330759, 53095, 11, "Athens O03"},
        {195.844, 794.27, 249, 27.499759, 34185, 4, "Augusta O04"},
        {1608.139, 1.34453, 1196, 257.410455, 63906, 13, "Phoenix P01"},
        {542.629, 624.99, 868, 43.891349, 47747, 9, "Tucson P02"},
        {43.888, 395.08, 111, 4.589727, 38109, 4, "Sierra Vista P03"},
        {504.258, 361.07, 1396, 257.410455, 40051, 7, "Mesa P04"}
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
        printf(" \n Quer continuar o jogo? (s/n): ");
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