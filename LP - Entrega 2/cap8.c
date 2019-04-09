#include "stdio.h"

#define ex1

#ifdef ex1
main(){
    while(1){

        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }
}

#endif // ex1

int endProgram(){
    int exitOption = 0;
    printf("Voce deseja finalizar o programa? Digite 1 para sim e qualquer numero para nao: ");
    scanf("%d", &exitOption);
    if(exitOption == 1){
        return 1;
    }
    else{
        return 0;
    }
}
