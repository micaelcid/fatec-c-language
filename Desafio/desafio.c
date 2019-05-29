#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "model/user.h"
#include "controller/user.h"
#include "helpers/compareStrings.h"
#include "helpers/endProgram.h"

main(){
    struct User user;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir usuario \n2 - Listar usuarios \n3 - Pesquisar usuario por nome\n");
        printf("4 - Pesquisar usuario por inicial \n5 - Pesquisar usuarios aniversariantes do mes \n6 - Pesquisar usuario por CEP\n");
        printf("7 - Alterar usuario \n8 - Deletar usuario \n9 - Sair\n");
        printf("Escolha uma opcao: ");
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
                getUserByInitial(&user);
                break;
            case 5:
                getUserByBirthMonth(&user);
                break;
            case 6:
                getUserByZipCode(&user);
                break;
            case 7:
                updateUser(&user);
                break;
            case 8:
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






