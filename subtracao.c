# include <stdio.h>
# include <string.h>
# include <time.h>
# include <math.h>

int subtracaoBinario(int decimal1, int decimal2, int *subtracao){
    int binario1[TAM_BINARIO] = {0};
    int binario2[TAM_BINARIO] = {0};
    zerarBinario(subtracao, TAM_BINARIO);
    int resto = 0;
    int posicao = 0;
    int carry = 0;

    if((decimal1 < 0 && decimal2 < 0) || (decimal1 > 0 && decimal2 > 0)){

        printf("\nSubtracao entre valores de sinais iguais %d e %d (Subtrai o maior do menor e mantem o sinal do maior)\n\n", decimal1, decimal2);

        int maior = decimal1;
        int menor = decimal2;
        if(abs(decimal1) < abs(decimal2)){
            printf("(maior valor esta em baixo, eh passado para cima e inverte o sinal da resposta)\n");
            maior = decimal2;
            menor = decimal1;
            if(decimal2 > 0){
                subtracao[TAM_BINARIO-1] = 1;
            }
        }else{
            if(decimal1 < 0){
                subtracao[TAM_BINARIO-1] = 1;
            }
        }

        decimalBinarioVetor(maior, binario1, TAM_BINARIO);
        decimalBinarioVetor(menor, binario2, TAM_BINARIO);

        for(int i = 0; i < TAM_BINARIO-1; i++){
            subtracao[i] = carry + binario1[i] - binario2[i];
            // printf("\n%d - %d = %d carry = %d", binario1[i], binario2[i], subtracao[i], carry);
            if(subtracao[i] == -1){
                carry = -1;
                subtracao[i] = 1;
            }else if(subtracao[i] == -2){
                carry = -1;
                subtracao[i] = 0;
            }else{
                carry = 0;
            }
        }

        imprimeBinarioSM(binario1, TAM_BINARIO);
        printf(" -> Binario 1\n - \n");
        imprimeBinarioSM(binario2, TAM_BINARIO);
        printf(" -> Binario 2\n   ");
        printf("\n -------------------------\n");
        imprimeBinarioSM(subtracao, TAM_BINARIO);
        
        return binarioVetorDecimal(subtracao, TAM_BINARIO);

    }else{

        printf("\nSubtracao entre valores de sinais diferentes %d e %d (Soma os modulos e mantem o sinal do primeiro)\n\n", decimal1, decimal2);

        int maior = decimal1;
        int menor = decimal2;
        if(abs(decimal1) < abs(decimal2)){
            maior = decimal2;
            menor = decimal1;
            maior = maior * -1;
            return somaBinario(maior, menor, subtracao);
        }else{
            menor = menor * -1;
            return somaBinario(maior, menor, subtracao);
        }

    }
}