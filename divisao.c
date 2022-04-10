# include <stdio.h>
# include <string.h>
# include <time.h>

int divisaoBinario(int decimal1, int decimal2, int *quociente, int *resto){
    int binario1[16] = {0};
    int binario2[16] = {0};
    decimalBinarioVetor(decimal1, binario1);
    decimalBinarioVetor(decimal2, binario2);
    zerarBinario(quociente);
    zerarBinario(resto);

    if(abs(decimal1) < abs(decimal2)){
        decimalBinarioVetor(decimal1, resto);
    }else if(decimal2 == 0){
        return 0;   
    }else{
        
        if((decimal1 < 0 && decimal2 > 0) || (decimal1 > 0 && decimal2 < 0)){
            quociente[15] = 1;
        }

        binario1[15] = 0;
        binario2[15] = 0;
        copiaBinario(resto, binario1);

        int quocienteDecimal = 0;

        while(verificaIgualMaior(resto, binario2) == 1){
            subtracaoBinario(binarioVetorDecimal(resto), binarioVetorDecimal(binario2), resto);
            quocienteDecimal++;
        }
        
        if(decimal1 < 0){
            resto[15] = 1;
        }
        decimalBinarioVetor(quocienteDecimal, quociente);

    }

    return binarioVetorDecimal(quociente);


}