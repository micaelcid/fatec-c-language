#include "stdio.h"

#define ex6

#ifdef ex1
main(){
    int i;
    long l;
    unsigned u;
    float f;
    double d;
    char c;
    unsigned long ul;
    unsigned char uc;

    int *pi;
    long *pl;
    unsigned *pu;
    float *pf;
    double *pd;
    char *pc;
    unsigned long *pul;
    unsigned char *puc;

    printf("Digite um int: ");
    scanf("%d", &i);
    printf("Digite um long: ");
    scanf("%ld", &l);
    printf("Digite um unsigned: ");
    scanf("%u", &u);
    printf("Digite um float: ");
    scanf("%f", &f);
    printf("Digite um double: ");
    scanf("%lf", &d);
    getchar();
    printf("Digite um char: ");
    scanf("%c", &c);
    printf("Digite um unsigned long: ");
    scanf("%lu", &ul);
    getchar();
    printf("Digite um unsigned char: ");
    scanf("%hhc", &uc);



    pi = &i;
    pl = &l;
    pu = &u;
    pf = &f;
    pd = &d;
    pc = &c;
    pul = &ul;
    puc = &uc;

    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-20d", *pi);
    printf("%-20ld", *pl);
    printf("%-15u\n", *pu);
    printf("              %-20f", *pf);
    printf("%-20f", *pd);
    printf("%c\n", *pc);
    printf("         %-20lu", *pul);
    printf("%hhc\n", *puc);

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

#ifdef ex2

main(){
    while(1){
        struct User{
            char name[64];
            char address[255];
            char city[64];
            char state[64];
            char zipCode[64];
        };

        int usersLimit = 4;
        struct User users[usersLimit];
        struct User *pUsers;
        pUsers = &users;
        int menuOption = 0;
        int usersCount = 0;
        int usersLeft = usersLimit;
        while(1){
            printf("1 - Inserir usuario | 2 - Listar usuarios | 9 - Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &menuOption);
            switch(menuOption){
                case 1:
                    if(usersLeft == 0){
                        printf("Voce nao pode mais inserir usuarios\n\n");
                        break;
                    }
                    getchar();
                    printf("Digite o nome do usuario: ");
                    gets(pUsers[usersCount].name);
                    printf("Digite o endereco do usuario: ");
                    gets(pUsers[usersCount].address);
                    printf("Digite a cidade do usuario: ");
                    gets(pUsers[usersCount].city);
                    printf("Digite o estado do usuario: ");
                    gets(pUsers[usersCount].state);
                    printf("Digite o CEP do usuario: ");
                    gets(pUsers[usersCount].zipCode);
                    printf("Usuario %d/4 inserido: \n", usersCount + 1);
                    printf("%s, %s, %s, %s, %s \n", pUsers[usersCount].name, pUsers[usersCount].address, pUsers[usersCount].city, pUsers[usersCount].state, pUsers[usersCount].zipCode);
                    usersCount++;
                    usersLeft--;
                    if(usersLeft == 1){
                        printf("Voce ainda pode adicionar %d usuario \n\n", usersLeft);
                    }
                    else{
                        if(usersLeft == 0){
                            printf("Voce nao pode mais inserir usuarios\n\n");
                        }
                        else{
                            printf("Voce ainda pode adicionar %d usuarios \n\n", usersLeft);
                        }
                    }

                    break;
                case 2:
                    if(usersCount == 0){
                        printf("Voce nao tem usuarios para listar\n\n");
                        break;
                    }
                    for(int i = 0; i < usersCount; i++){
                        printf("Usuario %d/4: %s, %s, %s, %s, %s \n", i+1, pUsers[i].name, pUsers[i].address, pUsers[i].city, pUsers[i].state, pUsers[i].zipCode);
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

        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
    }
}

#endif // ex2

#ifdef ex3

main(){
    while(1){

        char array[14] = "bdfhjlmoqsuwy";
        int equal = 0;
        char letter;
        char *p = &letter;
        printf("Digite um caractere: ");
        scanf("%c", p);

        for(int i = 0; i < 14; i++){
            if(*p == array[i]){
                equal = 1;
                break;
            }
        }

        if(equal){
            printf("Iguais\n");
        }
        else{
            printf("Diferentes\n");
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

main(){
    while(1){
        char firstString[11];
        char secondString[11];
        int different = 0;
        char *firstPointer[11];
        char *secondPointer[11];

        printf("Digite a primeira string: ");
        gets(firstString);
        for(int i = 0; i < 11; i++){
            firstPointer[i] = &firstString[i];
        }

        printf("Digite a segunda string: ");
        gets(secondString);
        for(int i = 0; i < 11; i++){
            secondPointer[i] = &secondString[i];
        }

        for(int i = 0; *firstPointer[i] != '\0'; i++){
            if(*firstPointer[i] != *secondPointer[i]){
                different = 1;
                break;
            }
        }

        if(!different){
            printf("Iguais\n");
        }
        else{
            printf("Diferentes\n");
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
main(){
    while(1){
        int number = 0;
        int sum = 0;
        float average = 0;
        int quantity = 0;
        int *pNumber = &number;

        while(1){
            printf("Digite um numero: ");
            scanf("%d", pNumber);
            if(*pNumber < 0){
                break;
            }
            sum += *pNumber;
            quantity++;
        }
        if(quantity == 0){
            average = 0;
        }
        else{
            average = sum / quantity;
        }

        printf("A media dos numeros e: %.2f\n", average);
        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }

}
#endif

#ifdef ex6
main(){
    while(1){
        struct Date {
            int day;
            int month;
            int year;
        };

        struct Date dates[2];
        struct Date *pDates = &dates;
        long diffInDays = 0;
        long *pDiffInDays = &diffInDays;
        for(int i = 0; i < 2; i++){
            do{
                printf("Digite o %do dia: ", i+1);
                scanf("%d", &pDates[i].day);
            }while(pDates[i].day <= 0 || pDates[i].day > 31);
            do{
                printf("Digite o %do mes: ", i+1);
                scanf("%d", &pDates[i].month);
            }while(pDates[i].month <= 0 || pDates[i].month > 12);
            do{
                printf("Digite o %do ano: ", i+1);
                scanf("%d", &pDates[i].year);
            }while(pDates[i].year <= 0 || pDates[i].year > 3000);
            printf("Data %d: %d/%d/%d \n", i+1, pDates[i].day, pDates[i].month, pDates[i].year);
        }

        if(pDates[0].year > pDates[1].year){
            if(pDates[0].month > pDates[1].month){
                if(pDates[0].day > pDates[1].day) //Ex 1: 20/4/2018 - 10/3/2017 = 405
                {
                    diffInDays += pDates[0].day - pDates[1].day;
                    diffInDays += 30 * (pDates[0].month - pDates[1].month);
                    diffInDays += 365 * (pDates[0].year - pDates[1].year);
                }
                else{
                    if(pDates[0].day < pDates[1].day){ //Ex 2: 10/4/2018 - 20/3/2017 = 385
                        diffInDays += (pDates[0].day + 30) - pDates[1].day;
                        diffInDays += 30 * (pDates[0].month - pDates[1].month - 1);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year);
                    }
                    else{ //Ex 3: 10/4/2018 - 10/3/2017 = 395
                        diffInDays += 30 * (pDates[0].month - pDates[1].month);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year);
                    }
                }
            }
            else{
                if(pDates[0].day > pDates[1].day) //Ex 4: 20/3/2018 - 10/4/2017 = 340
                {
                    diffInDays += pDates[0].day - pDates[1].day;
                    diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                    diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                }
                else{
                    if(pDates[0].day < pDates[1].day){ //Ex 5: 10/3/2018 - 20/4/2017 = 320
                        diffInDays += (pDates[0].day + 30) - pDates[1].day;
                        diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month - 1);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                    }
                    else{ //Ex 6: 10/3/2018 - 10/4/2017 = 330
                        diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                    }
                }
            }
        }
        else{
            if(pDates[0].year < pDates[1].year){
                if(pDates[0].month < pDates[1].month){
                    if(pDates[0].day < pDates[1].day) //Ex 7: 10/3/2018 - 20/4/2019 = 405
                    {
                        diffInDays += pDates[1].day - pDates[0].day;
                        diffInDays += 30 * (pDates[1].month - pDates[0].month);
                        diffInDays += 365 * (pDates[1].year - pDates[0].year);
                    }
                    // Falta terminar a partir daqui
                    else{
                        if(pDates[0].day > pDates[1].day){ //Ex 8: 20/3/2018 - 10/4/2019 = 385
                            diffInDays += (pDates[1].day + 30) - pDates[0].day;
                            diffInDays += 30 * (pDates[1].month - pDates[0].month - 1);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year);
                        }
                        else{ //Ex 3: 10/4/2018 - 10/3/2017 = 395
                            diffInDays += 30 * (pDates[0].month - pDates[1].month);
                            diffInDays += 365 * (pDates[0].year - pDates[1].year);
                        }
                    }
                }
                else{
                    if(pDates[0].day > pDates[1].day) //Ex 4: 20/3/2018 - 10/4/2017 = 340
                    {
                        diffInDays += pDates[0].day - pDates[1].day;
                        diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                    }
                    else{
                        if(pDates[0].day < pDates[1].day){ //Ex 5: 10/3/2018 - 20/4/2017 = 320
                            diffInDays += (pDates[0].day + 30) - pDates[1].day;
                            diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month - 1);
                            diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                        }
                        else{ //Ex 6: 10/3/2018 - 10/4/2017 = 330
                            diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                            diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                        }
                    }
                }
            }
            else{

            }
        }


        printf("Diferenca entre datas em dias: %ld\n", *pDiffInDays);
        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
        else{
            getchar();
        }
    }
}
#endif
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
