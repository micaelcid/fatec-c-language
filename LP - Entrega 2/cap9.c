#include "stdio.h"

#define ex6

#ifdef ex1
struct Variables{
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

main(){
    printf("Programa iniciado!\n\n");
    while(1){

        struct Variables var;

        getVariables(&var);
        printVariables(&var);

        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }
}


void getVariables(struct Variables *var){
    printf("Digite um char: ");
    var->c = getchar();
    printf("Digite um int: ");
    scanf("%d", &var->i);
    printf("Digite um long: ");
    scanf("%ld", &var->l);
    printf("Digite um float: ");
    scanf("%f", &var->f);
    printf("Digite um double: ");
    scanf("%lf", &var->d);
    printf("Digite um unsigned char: ");
    scanf("%u", &var->uc);
    printf("Digite um unsigned int: ");
    scanf("%u", &var->ui);
    printf("Digite um unsigned long: ");
    scanf("%u", &var->ul);
}

void printVariables(struct Variables *var){
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("%5c", var->c);
    printf("         %-10d", var->i);
    printf("%-20ld", var->l);
    printf("%-20.2f", var->f);
    printf("%-5.2lf\n", var->d);

    printf("          %-20u", var->uc);
    printf("%-20u", var->ui);
    printf("%-19u", var->ul);

    printf("\n");
}


#endif // ex1

#ifdef ex2

int receiveValues(int *value, char *operation){
    printf("Escolha a operacao: +, -, /, * ou = :");
    *operation = getchar();

    if(*operation == '='){
        return 0;
    }
    getchar();
    printf("Digite um valor:" );
    scanf("%d", value);
    return 1;
}

int calculateValues(int *value, char *operation, int *sum){
    switch(*operation){
        case '+':
            *sum += *value;
            break;
        case '-':
            *sum -= *value;
            break;
        case '/':
            *sum = *sum / *value;
            break;
        case '*':
            *sum = *sum * *value;
            break;
        default:
            break;
    }
    getchar();
}
main(){
    printf("Programa iniciado!\n\n");
    while(1){

        int value = 0;
        char operation;
        int sum = 0;

        while(1){
            if(receiveValues(&value, &operation)){gets
                calculateValues(&value, &operation, &sum);
            }
            else{
                break;
            }
        }

        printf("O valor acumulado é : %d \n", sum);

        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }
}
#endif // ex2

#ifdef ex3

int findLetter(char *letters, char *letter){
    for(int i = 0; letters[i] != '\0'; i++){
        if(letters[i] == *letter){
            return 1;
        }
    }
    return 0;
}
main(){
    char letters[] = "bdfhjkmoqsuwv";
    char letter;
    printf("Programa iniciado!\n\n");
    while(1){
        printf("Digite uma letra: ");
        letter = getchar();
        if(findLetter(&letters, &letter)){
            printf("Letra encontrada\n");
        }
        else{
            printf("Letra nao encontrada\n");
        }

        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }
}

#endif // ex3

#ifdef ex4

int areEqual(char *firstString, char *secondString){
    int result = 0;
    int i = 0;
    printf("Digite uma string: ");
    scanf("%s", firstString);
    printf("Digite uma string: ");
    scanf("%s", secondString);
    for(i; firstString[i] != '\0' ||secondString[i] != '\0'; i++){
        if(firstString[i] != secondString[i]){
            result = 4;
            if(firstString[i] == '\0' && secondString[i] != '\0'){
                result = 3;
                break;
            }
            else{
                if(firstString[i] != '\0' && secondString[i] == '\0'){
                    result = 2;
                    break;
                }
            }
        }
        else{
            result = 1;
        }
    }
    return result;
}


main(){
    while(1){
        int result;
        char strings[2][11];
        result = areEqual(&strings[0], &strings[1]);
        switch(result){
            case 1:
                printf("As strings sao iguais\n");
            break;
            case 2:
                printf("A primeira string e maior que a segunda\n");
            break;
            case 3:
                printf("A segunda string e maior que a primeira\n");
            break;
            case 4:
                printf("As strings sao diferentes, porem tem o mesmo tamanho\n");
            break;
        }

        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }
}

#endif // ex4

#ifdef ex5
struct User{
    char name[64];
    char address[255];
    char city[64];
    char state[64];
    char zipCode[64];
};
main(){
    int usersLimit = 4;
    struct User users[usersLimit];
    int usersInserted = 0;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir usuario | 2 - Listar usuarios | 9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertUsers(&users);
                usersInserted = 1;
                break;
            case 2:
                if(usersInserted == 0){
                    printf("Voce ainda nao inseriu nenhum usuario\n");
                }
                else{
                    getUsers(&users);
                }
                break;
            case 9:
                break;
            default:
                printf("Desculpe, nao entendi.\n\n");
                break;
        }
        if(menuOption == 9){
            break;
        }
    }
}
void insertUsers(struct User *users){
    getchar();
    for(int usersCount = 0; usersCount < 4; usersCount++){
        printf("Digite o nome do usuario: ");
        gets(users[usersCount].name);
        printf("Digite o endereco do usuario: ");
        gets(users[usersCount].address);
        printf("Digite a cidade do usuario: ");
        gets(users[usersCount].city);
        printf("Digite o estado do usuario: ");
        gets(users[usersCount].state);
        printf("Digite o CEP do usuario: ");
        gets(users[usersCount].zipCode);
        printf("Usuario %d/4 inserido: \n", usersCount + 1);
        printf("%s, %s, %s, %s, %s \n", users[usersCount].name, users[usersCount].address, users[usersCount].city, users[usersCount].state, users[usersCount].zipCode);
    }
}
void getUsers(struct User *users){
    for(int i = 0; i < 4; i++){
        printf("Usuario %d/4: %s, %s, %s, %s, %s \n", i+1, users[i].name, users[i].address, users[i].city, users[i].state, users[i].zipCode);
    }
}

#endif // ex5


#ifdef ex6
struct User{
    char name[64];
    char address[255];
    char city[64];
    char state[64];
    char zipCode[64];
};
main(){
    int usersLimit = 4;
    struct User users[usersLimit];
    int usersInserted = 0;
    int menuOption = 0;
    while(1){
        printf("1 - Inserir usuario | 2 - Listar usuarios | 3 - Procurar usuario | 4 - Alterar usuario | 5 - Deletar usuario | 9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menuOption);
        switch(menuOption){
            case 1:
                insertUsers(&users);
                usersInserted = 1;
                break;
            case 2:
                if(usersInserted == 0){
                    printf("Voce ainda nao inseriu nenhum usuario\n");
                }
                else{
                    getUsers(&users);
                }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 9:
                break;
            default:
                printf("Desculpe, nao entendi.\n\n");
                break;
        }
        if(menuOption == 9){
            break;
        }
    }
}
void insertUsers(struct User *users){
    getchar();
    for(int usersCount = 0; usersCount < 4; usersCount++){
        printf("Digite o nome do usuario: ");
        gets(users[usersCount].name);
        printf("Digite o endereco do usuario: ");
        gets(users[usersCount].address);
        printf("Digite a cidade do usuario: ");
        gets(users[usersCount].city);
        printf("Digite o estado do usuario: ");
        gets(users[usersCount].state);
        printf("Digite o CEP do usuario: ");
        gets(users[usersCount].zipCode);
        printf("Usuario %d/4 inserido: \n", usersCount + 1);
        printf("%s, %s, %s, %s, %s \n", users[usersCount].name, users[usersCount].address, users[usersCount].city, users[usersCount].state, users[usersCount].zipCode);
    }
}
void getUsers(struct User *users){
    for(int i = 0; i < 4; i++){
        printf("Usuario %d/4: %s, %s, %s, %s, %s \n", i+1, users[i].name, users[i].address, users[i].city, users[i].state, users[i].zipCode);
    }
}

#endif // ex6

int endProgram(){
    int exitOption = 0;
    printf("Voce deseja finalizar o programa? Digite 1 para sim e qualquer numero para nao: ");
    scanf("%d", &exitOption);
    return exitOption == 1 ? 1 : 0;
}
