#include <stdio.h>
#include <stdlib.h>
#define ex7

#ifdef ex1
int main()
{
char nome[5][8];
    printf("\nDigite 5 nomes de ate 7 caracteres cada: ");
    scanf("%s %s %s %s %s",&nome[0],&nome[1],&nome[2],&nome[3],&nome[4]);
    printf("          10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("%7s %37s\n",nome[0],nome[4]);
    printf("%17s %17s\n",nome[1],nome[3]);
    printf("%27s",nome[2]);
}
#endif

#ifdef ex2
main (){
char a[3][11];
    printf("\nDigite 3 strings de ate 10 cdaracteres cada: ");
    scanf("%s %s %s",&a[0],&a[1],&a[2]);
    printf("            10        20        30        40        50\n12345678901234567890123456789012345678901234567890\n");
    printf("%11s %16s %16s",a[0],a[1],a[2]);
}
#endif // ex2

#ifdef ex3
main (){
char b[11],c[11];
int a;
printf("\nDigite 2 strings de ate 10 caracteres: ");
scanf("%s %s",&b[0],&c[0]);

for (a=0;b[a]!='\0';a++){
    if (b[a]!=c[a]){
        break;
        }
}
if (b[a]=='\0' && c[a]=='\o')
    printf("\nStrings Iguais!");
else
    printf("\nDiferente!");
}
#endif // ex3

#ifdef ex4
char semana [7] [4] = { "seg" ,
                         "ter",
                         "qua",
                         "qui",
                         "sex",
                         "sab",
                         "dom",
                       };
main (){
    char a[4];
    int d,c=0;
    printf("\nEscolha um dia da semana: \nSeg\tTer\tQua\tQui\tsex\tsab\tdom: ");
    scanf("%s",&a[0]);
    for (d=0;a[d]!='\0';d++){
    if (a[d]==semana[0][d])
        c=1;
    else if (a[d]==semana[1][d])
        c=2;
    else if (a[d]==semana[2][d])
        c=3;
    else if (a[d]==semana[3][d])
        c=4;
    else if (a[d]==semana[4][d])
        c=5;
    else if (a[d]==semana[5][d])
        c=6;
    else if (a[d]==semana[6][d])
        c=7;
    }
    switch (c)
    {
    case 1:
        printf("\nsegunda-feira");
        break;
    case 2:
        printf("\nterca-feira");
        break;
    case 3:
        printf("\nquarta-feira");
        break;
    case 4:
        printf("\nquinta-feira");
        break;
    case 5:
        printf("\nsexta-feira");
        break;
    case 6:
        printf("\nsabado");
        break;
    case 7:
        printf("\ndomingo");
        break;
    case 0:
        printf("\nDados errados!");
        break;
    }
}
#endif // ex4

#ifdef ex5
main (){
char a[10];
int b;
for (b=0;b<10;b++){
    printf("\nDigite 10 letras em minusculas: ");
    scanf("%c",&a[b]);
    getchar();
}
printf("\nAs letras digitadas em maiusculo: ");
for (b=0;b<10;b++){
    a[b]-=32;
    printf("%c, ",a[b]);
}
getchar();
}
#endif // ex5

#ifdef ex6
main (){
char a[10];
int b;
for (b=0;b<10;b++){
    printf("\nDigite 10 letras maiusculas : ");
    scanf("%c",&a[b]);
    getchar();
}
printf("\nAs letras digitadas em minusculo: ");
for (b=0;b<10;b++){
    a[b]+=32;
    printf("%c, ",a[b]);
}
getchar();
}
#endif // ex6

#ifdef ex7
main (){
char a[51];

int b;

   printf("\nDigite uma palavra de ate 50 caracteres: ");
   scanf("%s",&a[0]);
   for(b=0;a[b]!='\0';b++){
    a[b]+=1;
   }
   printf("\nA string resultante: %s",a);
}
#endif // ex7

#ifdef ex8
main (){
   char a[21];
   int c;
   printf("\nDigite uma string de ate 20 caracteres: ");
   scanf("%s",&a[0]);
   for (c=0;a[c]!='\0';c++);
   printf("\nSua strint tem %d caracteres!",c);
}
#endif // ex8
