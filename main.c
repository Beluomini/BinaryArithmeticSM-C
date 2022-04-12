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
    int binario2[TAM_BINARIO];

    return test();

    printf("\nDigite o primeiro numero decimal: ");
    scanf("%d", &decimal1);
    decimalBinarioVetor(decimal1, binario1, TAM_BINARIO);

    printf("\nDigite a operacao:");
    printf("\n1 - Adicao");
    printf("\n2 - Subtracao");
    printf("\n3 - Multiplicacao");
    printf("\n4 - Divisao");
    printf("\nResposta: ");
    scanf("%d", &operacao);

    printf("\nDigite o segundo numero decimal: ");
    scanf("%d", &decimal2);

    int resultado[TAM_BINARIO] = {0};
    int resultadoMult[TAM_BINARIO*2] = {0};
    int resto[TAM_BINARIO] = {0};
    if(operacao == 1){
        somaBinario(decimal1, decimal2, resultado);
        printf("\nResultado da soma: ");
        imprimeBinario(resultado, TAM_BINARIO);
    }
    else if(operacao == 2){
        subtracaoBinario(decimal1, decimal2, resultado);
        printf("\nResultado da subtracao: ");
        imprimeBinario(resultado, TAM_BINARIO);
    }
    else if(operacao == 3){
        multiplicacaoBinario(decimal1, decimal2, resultadoMult);
        printf("\nResultado da multiplicacao: ");
        imprimeBinario(resultadoMult, TAM_BINARIO*2);
    }
    else if(operacao == 4){
        divisaoBinario(decimal1, decimal2, resultado, resto);
        printf("\nResultado da divisao: ");
        imprimeBinario(resultado, TAM_BINARIO);
        printf("\nResto da divisao: ");
        imprimeBinario(resto, TAM_BINARIO);
    }
    else{
        printf("\nOperacao invalida");
    }

    printf("\n Programa finalizado :)");

}

