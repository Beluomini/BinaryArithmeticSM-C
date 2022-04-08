# include <stdio.h>
# include <string.h>
# include <time.h>
# include <math.h>

int subtracaoBinario(int decimal1, int decimal2){
    int binario1[16] = {0};
    int binario2[16] = {0};
    int subtracao[16] = {0};
    int resto = 0;
    int posicao = 0;
    int carry = 0;

    if((decimal1 < 0 && decimal2 < 0) || (decimal1 > 0 && decimal2 > 0)){

        int maior = decimal1;
        int menor = decimal2;
        if(abs(decimal1) < abs(decimal2)){
            maior = decimal2;
            menor = decimal1;
            if(decimal2 > 0){
                subtracao[15] = 1;
            }
        }else{
            if(decimal1 < 0){
                subtracao[15] = 1;
            }
        }

        decimalBinarioVetor(maior, binario1);
        decimalBinarioVetor(menor, binario2);

        for(int i = 0; i < 15; i++){
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

        printf("\nResultado da subtracao: ");
        for(int i = 15; i >= 0; i--){
            printf("%d", subtracao[i]);
        }
        
        return binarioVetorDecimal(subtracao);

    }else{

        int maior = decimal1;
        int menor = decimal2;
        if(abs(decimal1) < abs(decimal2)){
            maior = decimal2;
            menor = decimal1;
            maior = maior * -1;
            return somaBinario(maior, menor);
        }else{
            menor = menor * -1;
            return somaBinario(maior, menor);
        }

    }
}