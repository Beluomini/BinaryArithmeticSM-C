# include <stdio.h>
# include <string.h>
# include <time.h>
# include "tools.c"
# include "soma.c"
# include "subtracao.c"
# include "divisao.c"
# include "multiplicacao.c"
# include "test.c"

int main(){
    int decimal1 = 0;
    int decimal2 = 0;
    int operacao = 0;
    int binario1[TAM_BINARIO] = {0};
    int binario2[TAM_BINARIO] = {0};

    // return test();

    printf("\nDigite a operacao:");
    printf("\n1 - Adicao");
    printf("\n2 - Subtracao");
    printf("\n3 - Multiplicacao");
    printf("\n4 - Divisao");
    printf("\n>>> ");
    scanf("%d", &operacao);

    printf("\nDigite o primeiro numero decimal: ");
    scanf("%d", &decimal1);
    decimalBinarioVetor(decimal1, binario1, TAM_BINARIO);

    printf("\nDigite o segundo numero decimal: ");
    scanf("%d", &decimal2);
    decimalBinarioVetor(decimal2, binario2, TAM_BINARIO);

    int resultado[TAM_BINARIO] = {0};
    int resultadoMult[TAM_BINARIO*2] = {0};
    int resto[TAM_BINARIO] = {0};
    int resposta = 0;
    if(operacao == 1){
        resposta = somaBinario(decimal1, decimal2, resultado);
        printf("\n\nResultado da soma: %d -> ", resposta);
        imprimeBinario(resultado, TAM_BINARIO);
    }
    else if(operacao == 2){
         resposta = subtracaoBinario(decimal1, decimal2, resultado);
        printf("\n\nResultado da subtracao: %d -> ", resposta);
        imprimeBinario(resultado, TAM_BINARIO);
    }
    else if(operacao == 3){
        resposta = multiplicacaoBinario(decimal1, decimal2, resultadoMult);
        printf("\n\nResultado da multiplicacao: %d -> ", resposta);
        imprimeBinario(resultadoMult, TAM_BINARIO*2);
    }
    else if(operacao == 4){
        resposta = divisaoBinario(decimal1, decimal2, resultado, resto);
        printf("\n\nResultado da divisao: %d -> ", resposta);
        imprimeBinario(resultado, TAM_BINARIO);
        printf("\nResto da divisao: ");
        imprimeBinario(resto, TAM_BINARIO);
    }
    else{
        printf("\nOperacao invalida");
    }

    printf("\n\nPrograma finalizado :)");

}

