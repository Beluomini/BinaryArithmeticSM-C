int decimalBinarioVetor(int decimal, int *binario){
    if(decimal < 0){
        binario[15] = 1;
        decimal = decimal * -1;
    }

    int resto = decimal;
    int posicao = 0;
    while(resto > 1){
        binario[posicao] = resto % 2;
        resto = resto / 2;
        posicao++;
    }
    binario[posicao] = resto;

    printf("\nO decimal %d eh: ", decimal);
    for(int i = 15; i >= 0; i--){
        printf("%d", binario[i]);
    }

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

    printf("\nO binario ");
    for(int i = 15; i >= 0; i--){
        printf("%d", binario[i]);
    }
    printf(" eh: %d\n", decimal);
    
    return decimal;
}