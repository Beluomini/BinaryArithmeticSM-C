# include <stdio.h>
# include <string.h>
# include <time.h>

#define TAM_BINARIO 16

int decimalBinarioVetor(int decimal, int *binario, int tamanho){
    if(decimal < 0){
        binario[tamanho-1] = 1;
        decimal = decimal * -1;
    }else if(decimal == 0){
        return 0;
    }

    int resto = decimal;
    int posicao = 0;

    while(resto > 1){
        binario[posicao] = resto % 2;
        resto = resto / 2;
        posicao++;
    }
    binario[posicao] = resto;

    // printf("\nO decimal %d eh: ", decimal);
    // for(int i = tamanho-1; i >= 0; i--){
    //     printf("%d", binario[i]);
    // }

    return 0;
}

int binarioVetorDecimal(int *binario, int tamanho){
    int posicao = 0;
    int decimal = 0;

    for(int i = 0; i < tamanho-1; i++){
        if(binario[i] == 1){
            decimal = decimal + pow(2, i);
        }
    }
    
    if(binario[tamanho-1] == 1){
        decimal = decimal * -1;
    }

    // printf("\nO binario ");
    // for(int i = tamanho-1; i >= 0; i--){
    //     printf("%d", binario[i]);
    // }
    // printf(" eh: %d\n", decimal);
    
    return decimal;
}


int zerarBinario(int *binario, int tamanho){
    for(int i = 0; i < tamanho; i++){
        binario[i] = 0;
    }
    return 0;
}

int verificaIgualMaior(int *binario1, int *binario2){
    int maior = 0;
    for(int i = 14; i >= 0; i--){
        if(binario1[i] > binario2[i]){
            return 1;
        }else if(binario1[i] == binario2[i]){
            maior = 1;
        }else{
            return 0;
        }
    }
    return maior;
}

int copiaBinario(int *binario1, int *binario2){
    for(int i = 0; i < 16; i++){
        binario1[i] = binario2[i];
    }
    return 0;
}

int imprimeBinario(int *binario, int tamanho){
    for(int i = tamanho-1; i >= 0; i--){
        printf("%d", binario[i]);
    }
}

int imprimeBinarioSM(int *binario, int tamanho){
    for(int i = tamanho-1; i >= 0; i--){
        if(i == tamanho-1){
            printf("(%d)", binario[i]);
        }else{
            printf("%d", binario[i]);
        }
    }
}