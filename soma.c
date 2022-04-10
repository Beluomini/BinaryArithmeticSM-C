# include <stdio.h>
# include <string.h>
# include <time.h>

int somaBinario(int decimal1, int decimal2, int *soma){
    int binario1[16] = {0};
    int binario2[16] = {0};
    zerarBinario(soma);
    int resto = 0;
    int posicao = 0;
    int carry = 0;

    if((decimal1 <= 0 && decimal2 <= 0) || (decimal1 >= 0 && decimal2 >= 0)){

        printf("\nSoma entre valores do mesmo sinal %d e %d (soma e mantem o sinal)\n", decimal1, decimal2);
        
        decimalBinarioVetor(decimal1, binario1);
        decimalBinarioVetor(decimal2, binario2);

        for(int i = 0; i <= 15; i++){
            soma[i] = carry + binario1[i] + binario2[i];
            // printf("\n%d + %d = %d carry = %d", binario1[i], binario2[i], soma[i], carry);
            if(soma[i] == 2){
                carry = 1;
                soma[i] = 0;
            }else if(soma[i] == 3){
                carry = 1;
                soma[i] = 1;
            }else{
                carry = 0;
            }
        }

        soma[15] = binario1[15];

        return binarioVetorDecimal(soma);

    }else{

        printf("\nSoma entre valores de sinal diferente %d e %d (subtrai os modulos e mantem o sinal do maior)\n", decimal1, decimal2);
        int resultado[16] = {0};
        if(abs(decimal1) < abs(decimal2)){ // verifica quem tem maior magnitude
            if(decimal2 < 0){
                decimal2 = decimal2 * -1;
                return subtracaoBinario(decimal1, decimal2, resultado);
            }else{
                decimal1 = decimal1 * -1;
                return subtracaoBinario(decimal2, decimal1, resultado);
            }
        }else{
            if(decimal1 < 0){
                decimal1 = decimal1 * -1;
                return subtracaoBinario(decimal2, decimal1, resultado);
            }else{
                decimal2 = decimal2 * -1;
                return subtracaoBinario(decimal1, decimal2, resultado);
            }
        }

    }
}