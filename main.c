# include <stdio.h>
# include <string.h>
# include <time.h>
# include "tools.c"
# include "soma.c"
# include "subtracao.c"
# include "test.c"

int main(){
    int decimal1 = 0;
    int decimal2 = 0;
    int operacao = 0;
    int binario1[16] = {0};
    int binario2[16];

    return test();

    printf("\nDigite o primeiro numero decimal: ");
    scanf("%d", &decimal1);
    decimalBinarioVetor(decimal1, binario1);

    printf("\nDigite a operacao:");
    printf("\n1 - Adicao");
    printf("\n2 - Subtracao");
    printf("\n3 - Multiplicacao");
    printf("\n4 - Divisao");
    printf("\nResposta: ");
    scanf("%d", &operacao);

    printf("\nDigite o segundo numero decimal: ");
    scanf("%d", &decimal2);

    if(operacao == 1){
        somaBinario(decimal1, decimal2);
    }
    else if(operacao == 2){
        subtracaoBinario(decimal1, decimal2);
    }
    else if(operacao == 3){
        printf("\nResultado: %d", decimal1 * decimal2);
    }
    else if(operacao == 4){
        printf("\nResultado: %d", decimal1 / decimal2);
    }
    else{
        printf("\nOperacao invalida");
    }

    printf("\n Programa finalizado :)");

}

