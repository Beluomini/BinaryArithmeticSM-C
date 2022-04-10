int decimalBinarioVetor(int decimal, int *binario){
    if(decimal < 0){
        binario[15] = 1;
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
    // for(int i = 15; i >= 0; i--){
    //     printf("%d", binario[i]);
    // }

    return 0;
}

int binarioVetorDecimal(int *binario){
    int posicao = 0;
    int decimal = 0;

    for(int i = 0; i < 15; i++){
        if(binario[i] == 1){
            decimal = decimal + pow(2, i);
        }
    }
    
    if(binario[15] == 1){
        decimal = decimal * -1;
    }

    // printf("\nO binario ");
    // for(int i = 15; i >= 0; i--){
    //     printf("%d", binario[i]);
    // }
    // printf(" eh: %d\n", decimal);
    
    return decimal;
}

int zerarBinario(int *binario){
    for(int i = 0; i < 16; i++){
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