#include <stdio.h>
#include <string.h>
#include <math.h>
// nivel mestre
// Estrutura que guarda informações da carta
struct SuperTrunfoNov {
    char Estado[50];   // Estado da cidade, ex: SP, RJ
    char Codigo[50];   // Código único da carta
    char Nome[50];     // Nome da cidade
    int Populacao;     // População total da cidade
    float Area;        // Área total da cidade em km²
    float PIB;         // Produto Interno Bruto em bilhões
    int Pontos;        // Número de pontos turísticos
    float densidade;   // Densidade demográfica (população / área)
    float percapita;   // PIB per capita calculado
    float superpoder;  // Soma de vários atributos para pontuação geral
};

// Função para remover o caractere '\n' que fgets adiciona no final da string
void removerNovaLinha(char* str) {
    str[strcspn(str, "\n")] = 0; // Remove o '\n' da string
}

// Função para comparar e exibir resultado de dois atributos escolhidos
void exibirComparacao(struct SuperTrunfoNov c1, struct SuperTrunfoNov c2, int atributo1, int atributo2) {
    const char* atributoNome1;
    const char* atributoNome2;
    float val1_a1, val2_a1, val1_a2, val2_a2;
    const char* vencedor1;
    const char* vencedor2;
    float soma1, soma2;

    // Obter nomes e valores do primeiro atributo
    switch (atributo1) {
        case 1:
            atributoNome1 = "Populacao";
            val1_a1 = c1.Populacao;
            val2_a1 = c2.Populacao;
            vencedor1 = (val1_a1 > val2_a1) ? "Carta 1" : (val1_a1 < val2_a1) ? "Carta 2" : "Empate";
            break;
        case 2:
            atributoNome1 = "Área";
            val1_a1 = c1.Area;
            val2_a1 = c2.Area;
            vencedor1 = (val1_a1 > val2_a1) ? "Carta 1" : (val1_a1 < val2_a1) ? "Carta 2" : "Empate";
            break;
        case 3:
            atributoNome1 = "PIB";
            val1_a1 = c1.PIB;
            val2_a1 = c2.PIB;
            vencedor1 = (val1_a1 > val2_a1) ? "Carta 1" : (val1_a1 < val2_a1) ? "Carta 2" : "Empate";
            break;
        case 4:
            atributoNome1 = "Pontos Turisticos";
            val1_a1 = c1.Pontos;
            val2_a1 = c2.Pontos;
            vencedor1 = (val1_a1 > val2_a1) ? "Carta 1" : (val1_a1 < val2_a1) ? "Carta 2" : "Empate";
            break;
        case 5:
            atributoNome1 = "Densidade Demografica";
            val1_a1 = c1.densidade;
            val2_a1 = c2.densidade;
            vencedor1 = (val1_a1 < val2_a1) ? "Carta 1" : (val1_a1 > val2_a1) ? "Carta 2" : "Empate"; // regra invertida
            break;
        default:
            printf("Atributo 1 invalido\n");
            return;
    }

    // Obter nomes e valores do segundo atributo
    switch (atributo2) {
        case 1:
            atributoNome2 = "Populacao";
            val1_a2 = c1.Populacao;
            val2_a2 = c2.Populacao;
            vencedor2 = (val1_a2 > val2_a2) ? "Carta 1" : (val1_a2 < val2_a2) ? "Carta 2" : "Empate";
            break;
        case 2:
            atributoNome2 = "Area";
            val1_a2 = c1.Area;
            val2_a2 = c2.Area;
            vencedor2 = (val1_a2 > val2_a2) ? "Carta 1" : (val1_a2 < val2_a2) ? "Carta 2" : "Empate";
            break;
        case 3:
            atributoNome2 = "PIB";
            val1_a2 = c1.PIB;
            val2_a2 = c2.PIB;
            vencedor2 = (val1_a2 > val2_a2) ? "Carta 1" : (val1_a2 < val2_a2) ? "Carta 2" : "Empate";
            break;
        case 4:
            atributoNome2 = "Pontos Turisticos";
            val1_a2 = c1.Pontos;
            val2_a2 = c2.Pontos;
            vencedor2 = (val1_a2 > val2_a2) ? "Carta 1" : (val1_a2 < val2_a2) ? "Carta 2" : "Empate";
            break;
        case 5:
            atributoNome2 = "Densidade Demografica";
            val1_a2 = c1.densidade;
            val2_a2 = c2.densidade;
            vencedor2 = (val1_a2 < val2_a2) ? "Carta 1" : (val1_a2 > val2_a2) ? "Carta 2" : "Empate"; // regra invertida
            break;
        default:
            printf("Atributo 2 invalido\n");
            return;
    }

    // Exibir resultado do primeiro atributo
    printf("\nComparacao de cartas (Atributo: %s):\n", atributoNome1);
    printf("Carta 1 - %s (%s): %.2f\n", c1.Nome, c1.Estado, val1_a1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.Nome, c2.Estado, val2_a1);
    printf("Resultado Atributo 1: %s venceu!\n", vencedor1);

    // Exibir resultado do segundo atributo
    printf("\nComparacao de cartas (Atributo: %s):\n", atributoNome2);
    printf("Carta 1 - %s (%s): %.2f\n", c1.Nome, c1.Estado, val1_a2);
    printf("Carta 2 - %s (%s): %.2f\n", c2.Nome, c2.Estado, val2_a2);
    printf("Resultado Atributo 2: %s venceu!\n", vencedor2);

    // Calcular soma dos atributos escolhidos para cada carta
    soma1 = val1_a1 + val1_a2;
    soma2 = val2_a1 + val2_a2;

    printf("\nSoma dos Atributos:\n");
    printf("Carta 1 - %s: %.2f\n", c1.Nome, soma1);
    printf("Carta 2 - %s: %.2f\n", c2.Nome, soma2);

    // Mostrar resultado final baseado na soma
    if (soma1 > soma2) {
        printf("Resultado Final: Carta 1 (%s) venceu!\n", c1.Nome);
    }
    else if (soma2 > soma1) {
        printf("Resultado Final: Carta 2 (%s) venceu!\n", c2.Nome);
    }
    else {
        printf("Resultado Final: Empate!\n");
    }
}

int main() {
    struct SuperTrunfoNov cartas[2]; // Array para armazenar 2 cartas

    // Entrada dos dados para as duas cartas
    for (int i = 0; i < 2; i++) {
        printf("Digite os dados da carta %d:\n", i + 1);

        printf("Digite o estado (ex: SP, RJ):\n");
        fgets(cartas[i].Estado, sizeof(cartas[i].Estado), stdin);
        removerNovaLinha(cartas[i].Estado);

        printf("Digite o codigo da carta:\n");
        fgets(cartas[i].Codigo, sizeof(cartas[i].Codigo), stdin);
        removerNovaLinha(cartas[i].Codigo);

        printf("Digite o nome da cidade:\n");
        fgets(cartas[i].Nome, sizeof(cartas[i].Nome), stdin);
        removerNovaLinha(cartas[i].Nome);

        printf("Digite a populacao da cidade:\n");
        scanf("%d", &cartas[i].Populacao);
        getchar();

        printf("Digite a area da cidade:\n");
        scanf("%f", &cartas[i].Area);
        getchar();

        printf("Digite o PIB em bilhoes:\n");
        scanf("%f", &cartas[i].PIB);
        getchar();

        printf("Quantos pontos turisticos tem a cidade:\n");
        scanf("%d", &cartas[i].Pontos);
        getchar();

        // Cálculo da densidade populacional
        if (cartas[i].Area > 0)
            cartas[i].densidade = (float)cartas[i].Populacao / cartas[i].Area;
        else
            cartas[i].densidade = 0;

        // Cálculo do PIB per capita
        if (cartas[i].Populacao > 0)
            cartas[i].percapita = cartas[i].PIB * 1e9 / cartas[i].Populacao;
        else
            cartas[i].percapita = 0;

        // Cálculo do superpoder (não utilizado na comparação do menu)
        float densidadePeso;
        if (cartas[i].densidade > 0)
            densidadePeso = 1.0f / (cartas[i].densidade + 0.0001f);
        else
            densidadePeso = 1000000.0f;

        cartas[i].superpoder = (float)cartas[i].Populacao + cartas[i].Area + cartas[i].PIB + (float)cartas[i].Pontos + densidadePeso;
    }

    int opcao1 = -1, opcao2 = -1;

    // Loop menu interativo para escolher dois atributos distintos
    do {
        // Escolha do primeiro atributo
        printf("\nEscolha o primeiro atributo para comparacao:\n");
        printf("1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade Demografica\n0. Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao1);
        getchar();

        if (opcao1 == 0) break;

        if (opcao1 < 1 || opcao1 > 5) {
            printf("Opcao invalida. Tente novamente.\n");
            continue;
        }

        // Escolha do segundo atributo com exclusão do primeiro
        printf("\nEscolha o segundo atributo para comparacao (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != opcao1) {
                switch (i) {
                    case 1: printf("1. Populacao\n"); break;
                    case 2: printf("2. area\n"); break;
                    case 3: printf("3. PIB\n"); break;
                    case 4: printf("4. Pontos Turisticos\n"); break;
                    case 5: printf("5. Densidade Demografica\n"); break;
                }
            }
        }
        printf("Digite a opcao: ");
        scanf("%d", &opcao2);
        getchar();

        if (opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
            printf("Opcao invalida ou repetida. Tente novamente.\n");
            continue;
        }

        // Exibir comparação com os dois atributos escolhidos
        exibirComparacao(cartas[0], cartas[1], opcao1, opcao2);

    } while (1);

    printf("\nPrograma encerrado. Ate logo!\n");
    return 0;
}

