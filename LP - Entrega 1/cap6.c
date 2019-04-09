#include <stdio.h>
#include <stdlib.h>
#define ex8


#ifdef ex1
char vetor(char b);

int main(){
char b,d;
printf("\nDigite uma letra: ");
b=getchar();
d=vetor(b);
}
char vetor(char b){
    int count,c=0;
static char a[]={'b','d','f','h','j','k','m','o','q','s','u','w','y'};
char j;
    for (count=0;count<13;count++){
        if (b==a[count]){
            printf("\nA letra pertence a o Vetor!\t A Letra digitada e: ");
            putchar(a[count]);
            j=a[count];
            c++;
        }}

            if (c==0)
                printf("\nA letra digitada nao pertence ao vetor!");
    return (j);
}
#endif

#ifdef ex2
int soma(a,b){
    int c;
    c=a+b;
    return (c);
}
int subt(a,b){
    int d;
    d=a-b;
    return (d);
}
int mult(a,b){
    int e;
    e=a*b;
    return (e);
}
float divi(a,b){
    float f;
    f=a/b;
    return (f);
}
int main(){
    int a,b;
    printf("\nDigite o valor A: ");
    scanf("%d",&a);
    printf("\nDigite o valor B: ");
    scanf("%d",&b);
    printf("\nA soma dos valores: %d",soma(a,b));
    printf("\nA diferenca dos valores: %d",subt(a,b));
    printf("\nA multiplicacao dos valores: %d",mult(a,b));
    printf("\nA divi dos valores: %.2f",divi(a,b));
}
#endif // ex2

#ifdef ex3
int soma(a,b){
    int c;
    c=a+b;
    return (c);
}
int subt(a,b){
    int d;
    d=a-b;
    return (d);
}
int mult(a,b){
    int e;
    e=a*b;
    return (e);
}
float divi(a,b){
    float f;
    f=a/b;
    return (f);
}
int main(){
    int a,b,count,x;
    do{
    printf("\nDigite uma quantidade: ");
    scanf("%d",&x);
    }while (x<=0);

    for (count=0;count!=x;count++){
    printf("\nQuantidade de vezes: %d\n",count+1);
    printf("\nDigite o valor A: ");
    scanf("%d",&a);
    printf("\nDigite o valor B: ");
    scanf("%d",&b);
    printf("\nA soma dos valores: %d",soma(a,b));
    printf("\nA diferenca dos valores: %d",subt(a,b));
    printf("\nA multiplicacao dos valores: %d",mult(a,b));
    printf("\nA divi dos valores: %.2f",divi(a,b));
    }
}
#endif // ex3

#ifdef ex4
int soma(a,b){
    int c;
    c=a+b;
    return (c);
}
int subt(a,b){
    int d;
    d=a-b;
    return (d);
}
int mult(a,b){
    int e;
    e=a*b;
    return (e);
}
float divi(a,b){
    float f;
    f=a/b;
    return (f);
}
int main(){
    int a,b,count,x,n;
    do{
    printf("\nDigite uma quantidade: ");
    scanf("%d",&x);
    }while (x<=0);

    for (count=0;count!=x;count++){
    printf("\n\nQuantidade de vezes: %d\n",count+1);

    printf("\n\t1: Soma \n\t2:Subtracao \n\t3:Divisao \n\t4:Multiplicacao\n");
    printf("\nDigite uma das opcoes: ");
    scanf("%d",&n);
    switch (n){
        case 1 :{
            printf("\nDigite o valor A: ");
            scanf("%d",&a);
            printf("\nDigite o valor B: ");
            scanf("%d",&b);
            printf("\nA soma dos valores: %d",soma(a,b));
            break;}
        case 2 :{
            printf("\nDigite o valor A: ");
            scanf("%d",&a);
            printf("\nDigite o valor B: ");
            scanf("%d",&b);
            printf("\nA diferenca dos valores: %d",subt(a,b));
            break;}
        case 3 :{
            printf("\nDigite o valor A: ");
            scanf("%d",&a);
            printf("\nDigite o valor B: ");
            scanf("%d",&b);
            printf("\nA divisao dos valores: %.2f",divi(a,b));
            break;}
        case 4 :{
            printf("\nDigite o valor A: ");
            scanf("%d",&a);
            printf("\nDigite o valor B: ");
            scanf("%d",&b);
            printf("\nA multiplicacao dos valores: %d",mult(a,b));
            break;}
    }
}}
#endif // ex4

#ifdef ex5
char a,b;
int teste(a,b){
    if (a==b){
        printf("\nIGUAIS 1");
    }
    else{
        printf("\nDIFERENTES 0");
        if (a>b)
            return(2);
        else
            return (3);
}}

int main(){
    int c;
    printf("\nDigite uma string A de ate 10 caracteres: ");
    scanf("%10s",&a);
    printf("\nDigite uma string B de ate 10 caracteres: ");
    scanf("%10s",&b);
    c=teste(a,b);
    printf("\n%d",c);
}
#endif // ex5

#ifdef ex6
void soma(n){
    int a,c;
    for (c=0;c<n;c++){
        a+=(n-c);
    }
    printf("\nO valor da soma e: %d",a);
    return;
}
int main(){
int n;
    printf("\nDigite um numero: ");
    scanf("%d",&n);
    soma(n);
}
#endif // ex6

#ifdef ex7
int potencia(x,z){
    int d;
    for (d=1;d<z;d++)
        x*=x;
    return (x);
}
int main(){
    int x,z;
    printf("\nDigite 2 valores: ");
    scanf("%d %d",&x,&z);
    printf("\nO Valor %d sobre a potencia de %d = %d",x,z,potencia(x,z));
}
#endif // ex7

#ifdef ex8
int soma(a,b){
int somas;
    somas=a+b;
    return (somas);
}
mult(a,b){
int multiplica;
    multiplica=a*b;
    return(multiplica);
}
int veri(a,b){
    if (a>0 && b>0)
        return(1);
    else if (a<0 && b<0)
        return(0);
    if (a<0 && b>0 || a>0 && b<0)
    if (a<0)
        printf("\nO numero A e negativo!");
    else if (a>0)
        printf("\nO numero A e positivo!");
    if (b<0)
        printf("\nO numero B e negativo!");
    else if (b>0)
        printf("\nO numero B e positivo!");
}
main(){
int a,b;
printf("\nDigite 2 numeros: ");
scanf("%d %d",&a,&b);
if (veri(a,b)==1){
    printf("\nOs 2 numeros sao positivos!\n A soma deles: %d",soma(a,b));
}
else if (veri(a,b)==0)
    printf("\nOs 2 numeros sao negativos!\nA multiplicacao deles: %d",mult(a,b));
}
#endif // ex8
