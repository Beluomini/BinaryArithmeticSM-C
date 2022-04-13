# include <stdio.h>
# include <string.h>
# include <time.h>

int multiplicacaoBinario(int decimal1, int decimal2, int *produto){
    int binario1[TAM_BINARIO] = {0};
    int binario2[TAM_BINARIO] = {0};
    int aux[TAM_BINARIO] = {0};
    zerarBinario(produto, TAM_BINARIO*2);
    int carry = 0;
    int posicao = TAM_BINARIO-1;

    decimalBinarioVetor(decimal1, binario1, TAM_BINARIO);
    binario1[TAM_BINARIO-1] = 0;
    decimalBinarioVetor(decimal2, binario2, TAM_BINARIO);
    binario2[TAM_BINARIO-1] = 0;

    while(posicao != 0){
        printf("\n----------------- CICLO %d ------------------\n", TAM_BINARIO-posicao);
        printf("\nC = %d | A = ", carry);
        imprimeBinario(aux, TAM_BINARIO-1);
        printf(" | Q = ");
        imprimeBinario(binario1, TAM_BINARIO-1);
        printf(" | M = ");
        imprimeBinario(binario2, TAM_BINARIO-1);

        if(binario1[0] == 1){
            if(binarioVetorDecimal(aux, TAM_BINARIO) + binarioVetorDecimal(binario2, TAM_BINARIO) > 32767){
                carry = 1;
            }
            somaBinario(binarioVetorDecimal(aux, TAM_BINARIO), binarioVetorDecimal(binario2, TAM_BINARIO), aux);
            printf("\nC = %d | A = ", carry);
            imprimeBinario(aux, TAM_BINARIO-1);
            printf(" | Q = ");
            imprimeBinario(binario1, TAM_BINARIO-1);
            printf(" | M = ");
            imprimeBinario(binario2, TAM_BINARIO-1);
        }
        for(int i = 0; i < TAM_BINARIO-1; i++){
            binario1[i] = binario1[i+1];
        }
        binario1[TAM_BINARIO-2] = aux[0];
        for(int i = 0; i < TAM_BINARIO-1; i++){
            aux[i] = aux[i+1];
        }
        aux[TAM_BINARIO-2] = carry;
        carry = 0;
        posicao--;
        printf("\n---------------------------------------------\n", posicao+1);
    }

    for(int i = 0; i < TAM_BINARIO*2; i++){
        if(i < TAM_BINARIO-1){
            produto[i] = binario1[i];
        }else{
            produto[i] = aux[i+1-TAM_BINARIO];
        }
    }

    if((decimal1 < 0 && decimal2 > 0) || (decimal1 > 0 && decimal2 < 0)){
        produto[TAM_BINARIO*2-1] = 1;
    }else{
        produto[TAM_BINARIO*2-1] = 0;
    }

    return binarioVetorDecimal(produto, TAM_BINARIO*2);
}