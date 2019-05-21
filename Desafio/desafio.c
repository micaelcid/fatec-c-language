#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "model/user.h"
#include "controller/user.h"
#include "helpers/compareStrings.h"
#include "helpers/endProgram.h"
FILE *p;

main(){
    struct User user;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir usuario | 2 - Listar usuarios | 3 - Procurar usuario | 4 - Alterar usuario | 5 - Deletar usuario | 9 - Sair\n");        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertUser(&user);
                break;
            case 2:
                getUsers(&user);
                break;
            case 3:
                getUserByName(&user);
                break;
            case 4:
                updateUser(&user);
                break;
            case 5:
                removeUser(&user);
                break;
            case 9:
                break;
            default:
                printf("Desculpe, nao entendi.\n\n");
                break;
        }
        if(menuOption == 9 && endProgram()){
            break;
        }
    }
}






