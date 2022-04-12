# include <stdio.h>
# include <string.h>
# include <time.h>

int somaBinario(int decimal1, int decimal2, int *soma){
    int binario1[TAM_BINARIO] = {0};
    int binario2[TAM_BINARIO] = {0};
    int carryVet[TAM_BINARIO] = {0};
    zerarBinario(soma, TAM_BINARIO);
    int resto = 0;
    int posicao = 0;
    int carry = 0;

    if((decimal1 <= 0 && decimal2 <= 0) || (decimal1 >= 0 && decimal2 >= 0)){

        printf("\nSoma entre valores do mesmo sinal %d e %d (soma e mantem o sinal)\n", decimal1, decimal2);
        
        decimalBinarioVetor(decimal1, binario1, TAM_BINARIO);
        decimalBinarioVetor(decimal2, binario2, TAM_BINARIO);

        for(int i = 0; i <= TAM_BINARIO-1; i++){
            soma[i] = carry + binario1[i] + binario2[i];
            if(soma[i] == 2){
                carry = 1;
                soma[i] = 0;
            }else if(soma[i] == 3){
                carry = 1;
                soma[i] = 1;
            }else{
                carry = 0;
            }
            carryVet[i+1] = carry;
        }
        printf("   ");
        imprimeBinario(carryVet, TAM_BINARIO-1);
        printf(" -> Carry\n");
        imprimeBinarioSM(binario1, TAM_BINARIO);
        printf(" -> Binario 1\n + \n");
        imprimeBinarioSM(binario2, TAM_BINARIO);
        printf(" -> Binario 2\n -------------------------\n");
        imprimeBinarioSM(soma, TAM_BINARIO);

        if(carryVet[TAM_BINARIO-1] == 1){
            printf("\n\nOverflow");
        }

        soma[TAM_BINARIO-1] = binario1[TAM_BINARIO-1];

        return binarioVetorDecimal(soma, TAM_BINARIO);

    }else{

        printf("\nSoma entre valores de sinal diferente %d e %d (subtrai os modulos e mantem o sinal do maior)\n", decimal1, decimal2);
        if(abs(decimal1) < abs(decimal2)){ // verifica quem tem maior magnitude
            if(decimal2 < 0){
                decimal2 = decimal2 * -1;
                return subtracaoBinario(decimal1, decimal2, soma);
            }else{
                decimal1 = decimal1 * -1;
                return subtracaoBinario(decimal2, decimal1, soma);
            }
        }else{
            if(decimal1 < 0){
                decimal1 = decimal1 * -1;
                return subtracaoBinario(decimal2, decimal1, soma);
            }else{
                decimal2 = decimal2 * -1;
                return subtracaoBinario(decimal1, decimal2, soma);
            }
        }

    }
}