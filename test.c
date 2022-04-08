# include <stdio.h>
# include <string.h>
# include <time.h>

int test(){
    int decimal1 = 0;
    int decimal2 = 0;
    int resposta = 0;
    int operacao = 0;

    int entradasB1[10] = {2, -2, 3, 4, -3, -4, 3, -3, 4, -4};
    int entradasB2[10] = {2, -2, 4, 3, -4, -3, -4, 4, -3, 3};

    // int saidasSoma[10] = {4, -4, 7, 7, -7, -7, -1, 1, 1, -1};
    // int saidasSub[10] = {0, 0, -1, 1, 1, -1, 7, -7, 7, -7};

    printf("\nDigite a operacao que deseja testar:");
    printf("\n1 - Adicao");
    printf("\n2 - Subtracao");
    printf("\n3 - Multiplicacao");
    printf("\n4 - Divisao");
    printf("\nResposta: ");
    scanf("%d", &operacao);

    if(operacao == 1){
        for(int i = 0; i < 10; i++){
            #define formatBool(b) ((b) ? "true" : "false")
            decimal1 = entradasB1[i];
            decimal2 = entradasB2[i];
            printf("\n---> %d + %d", decimal1, decimal2);
            resposta = somaBinario(decimal1, decimal2);
            printf("\nResposta esperada %d veio %d ----> %s", decimal1 + decimal2, resposta, formatBool(decimal1 + decimal2 == resposta));
        }
    }else if(operacao == 2){
        for(int i = 0; i < 10; i++){
            #define formatBool(b) ((b) ? "true" : "false")
            decimal1 = entradasB1[i];
            decimal2 = entradasB2[i];
            printf("\n---> %d - %d", decimal1, decimal2);
            resposta = subtracaoBinario(decimal1, decimal2);
            printf("\nResposta esperada %d veio %d ----> %s", decimal1 - decimal2, resposta, formatBool(decimal1 - decimal2 == resposta));
        }
    }

    return 0;

}