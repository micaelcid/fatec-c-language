#ifndef END_PROGRAM_H_INCLUDED
#define END_PROGRAM_H_INCLUDED
int endProgram(){
    int exitOption = 0;
    printf("Voce deseja finalizar o programa? Digite 1 para sim e qualquer numero para nao: ");
    scanf("%d", &exitOption);
    return exitOption == 1 ? 1 : 0;
}
#endif // END_PROGRAM_H_INCLUDED
