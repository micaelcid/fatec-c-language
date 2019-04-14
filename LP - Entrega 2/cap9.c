#include "stdio.h"

#define ex2

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
    while(1){
        printf("Programa iniciado!\n\n");

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
main(){
    
    while(1){
        printf("Programa iniciado!\n\n");

        int value = 0;
        char operation;
        int sum = 0;
        while(1){
            printf("Escolha a operacao: +, -, /, * ou = :");
            scanf("%c", &operation);
            getchar();
            if(operation == '='){
                break;
            }

            printf("Digite um valor:" );
            scanf("%d", &value);

            switch (operation)
            {
                case '+':
                        sum += value;
                    break;
                case '-':
                        sum -= value;
                    break;
                case '/':
                        sum = sum / value;
                    break;
                case '*':
                        sum *= value;
                    break;
                default:
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
