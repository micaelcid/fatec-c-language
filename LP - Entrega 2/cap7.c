#include "stdio.h"
#include "math.h"

#define ex1

#ifdef ex1
main(){
    while(1){
        printf("Programa iniciado.\n\n");
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

        struct Variables var;

        printf("Digite um char: ");
        var.c = getchar();
        printf("Digite um int: ");
        scanf("%d", &var.i);
        printf("Digite um long: ");
        scanf("%ld", &var.l);
        printf("Digite um float: ");
        scanf("%f", &var.f);
        printf("Digite um double: ");
        scanf("%lf", &var.d);
        printf("Digite um unsigned char: ");
        scanf("%u", &var.uc);
        printf("Digite um unsigned int: ");
        scanf("%u", &var.ui);
        printf("Digite um unsigned long: ");
        scanf("%u", &var.ul);

        printf("        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("%5c", var.c);
        printf("         %-10d", var.i);
        printf("%-20ld", var.l);
        printf("%-20.2f", var.f);
        printf("%-5.2lf\n", var.d);

        printf("          %-20u", var.uc);
        printf("%-20u", var.ui);
        printf("%-19u", var.ul);


        printf("\n");


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
                        printf("Usuario %d/4: %s, %s, %s, %s, %s \n", i+1, users[i].name, users[i].address, users[i].city, users[i].state, users[i].zipCode);
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
#endif  //ex2

#ifdef ex3

main()
{
    while(1){
        struct Coordinates{
            int x;
            int y;
        };

        struct Coordinates coordinates;
        float distance;

        printf("Digite a posicao de X: ");
        scanf("%d", &coordinates.x);
        printf("Digite a posicao de Y: ");
        scanf("%d", &coordinates.y);
        distance = sqrt( pow(coordinates.x - 0, 2) + pow(coordinates.y - 0, 2));
        printf("A distancia entre o ponto P(0,0) e o ponto Q(%d, %d) e: %f \n", coordinates.x, coordinates.y, distance);

        if(endProgram()){
            printf("\nPrograma finalizado. Obrigado.");
            break;
        }
    }
}

#endif // ex3

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
