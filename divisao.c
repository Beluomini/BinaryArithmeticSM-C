# include <stdio.h>
# include <string.h>
# include <time.h>

int divisaoBinario(int decimal1, int decimal2, int *quociente, int *resto){
    int binario1[TAM_BINARIO] = {0};
    int binario2[TAM_BINARIO] = {0};
    decimalBinarioVetor(decimal1, binario1, TAM_BINARIO);
    decimalBinarioVetor(decimal2, binario2, TAM_BINARIO);
    zerarBinario(quociente, TAM_BINARIO);
    zerarBinario(resto, TAM_BINARIO);

    if(abs(decimal1) < abs(decimal2)){
        decimalBinarioVetor(decimal1, resto, TAM_BINARIO);
    }else if(decimal2 == 0){
        return 0;   
    }else{
        
        if((decimal1 < 0 && decimal2 > 0) || (decimal1 > 0 && decimal2 < 0)){
            quociente[TAM_BINARIO-1] = 1;
        }

        binario1[TAM_BINARIO-1] = 0;
        binario2[TAM_BINARIO-1] = 0;
        copiaBinario(resto, binario1);

        int quocienteDecimal = 0;

        while(verificaIgualMaior(resto, binario2) == 1){
            subtracaoBinario(binarioVetorDecimal(resto, TAM_BINARIO), binarioVetorDecimal(binario2, TAM_BINARIO), resto);
            quocienteDecimal++;
        }
        
        if(decimal1 < 0){
            resto[TAM_BINARIO-1] = 1;
        }
        decimalBinarioVetor(quocienteDecimal, quociente, TAM_BINARIO);

    }

    return binarioVetorDecimal(quociente, TAM_BINARIO);


}