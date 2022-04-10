# include <stdio.h>
# include <string.h>
# include <time.h>

int test(){
    int decimal1 = 0;
    int decimal2 = 0;
    int resposta = 0;
    int operacao = 0;

    int entradasB1[14] = {0, 0, 1, 1, 2, -2, 3, 4, -3, -4, 3, -3, 4, -4};
    int entradasB2[14] = {0, 1, 0, 1, 2, -2, 4, 3, -4, -3, -4, 4, -3, 3};

    int entradasB1Div[14] = {0, 0, 1, 1, 2, -2, -2, 4, 4, -4, 5, 5, -5, -5};
    int entradasB2Div[14] = {0, 1, 0, 1, 4, 4, -4, 2, -2, -2, 2, -2, 2, -2};

    printf("\nDigite a operacao que deseja testar:");
    printf("\n1 - Adicao");
    printf("\n2 - Subtracao");
    printf("\n3 - Multiplicacao");
    printf("\n4 - Divisao");
    printf("\nResposta: ");
    scanf("%d", &operacao);

    int resultado[16] = {0};
    int resto[16] = {0};
    if(operacao == 1){
        for(int i = 0; i < 14; i++){
            #define formatBool(b) ((b) ? "true" : "false")
            decimal1 = entradasB1[i];
            decimal2 = entradasB2[i];
            printf("\n---> %d + %d", decimal1, decimal2);
            resposta = somaBinario(decimal1, decimal2, resultado);
            printf("\nResultado da soma: ");
            for(int i = 15; i >= 0; i--){
                printf("%d", resultado[i]);
            }
            printf("\nResposta esperada %d veio %d ----> %s", decimal1 + decimal2, resposta, formatBool(decimal1 + decimal2 == resposta));
        }
    }else if(operacao == 2){
        for(int i = 0; i < 14; i++){
            #define formatBool(b) ((b) ? "true" : "false")
            decimal1 = entradasB1[i];
            decimal2 = entradasB2[i];
            printf("\n---> %d - %d", decimal1, decimal2);
            resposta = subtracaoBinario(decimal1, decimal2, resultado);
            printf("\nResultado da subtracao: ");
            for(int i = 15; i >= 0; i--){
                printf("%d", resultado[i]);
            }
            printf("\nResposta esperada %d veio %d ----> %s", decimal1 - decimal2, resposta, formatBool(decimal1 - decimal2 == resposta));
        }
    }else if(operacao == 3){
        
    }else if(operacao == 4){
        for(int i = 0; i < 14; i++){
            #define formatBool(b) ((b) ? "true" : "false")
            decimal1 = entradasB1Div[i];
            decimal2 = entradasB2Div[i];
            printf("\n---> %d / %d", decimal1, decimal2);
            resposta = divisaoBinario(decimal1, decimal2, resultado, resto);
            printf("\nResultado da divisao: ");
            for(int i = 15; i >= 0; i--){
                printf("%d", resultado[i]);
            }
            printf("\nResto da divisao: ");
            for(int i = 15; i >= 0; i--){
                printf("%d", resto[i]);
            }
            if(decimal2 == 0){
                printf("\nDivisao por 0");
            }else{
                printf("\nResposta esperada %d + %d veio %d + %d ----> %s", decimal1/decimal2, decimal1%decimal2, resposta, binarioVetorDecimal(resto), formatBool((decimal1/decimal2)+decimal1%decimal2 == resposta + binarioVetorDecimal(resto)));
            }
        }
    }

    return 0;

}