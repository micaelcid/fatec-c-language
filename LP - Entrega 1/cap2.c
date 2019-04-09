#define ex2
#include "stdio.h"

#ifdef ex1
int main()
{
int a,med=0,cont=0;
    do{
    printf("\nDigite um numero qualquer: ");
    scanf ("%d",&a);
    if (a>=0){
        med+=a;
        cont++;
    }
    }while(a>=0);
    printf("\nA media dos valores digtados: %d",med/cont);
}
#endif

#ifdef ex2
int main()
{
    int med = 50, min = 1, max = 99;
    char digitado;
    printf("numero adivinhado eh %d ? Se sim '=', se for maior '>', se for menor '<' \n",med);
    do
       {digitado = getchar();
        getchar();
        if(digitado == '>')
           {min = med;
            med = max - (max - min)/2;
            printf("%d?\n",med);}
        else if(digitado == '<')
           {max = med;
            med = min - (min - max)/2;
            printf("%d?\n",med);}
        else if(digitado !='=')
           {printf("Valor invalido\n");}
       }while(digitado!='=');
    printf("O numero pensado foi %d \n",med);
}

#endif //Encerra ex2

#ifdef ex3
int main()
{
    int med = 50, min = 1, max = 99, cont=1;
    char digitado;
    printf("numero adivinhado eh %d ? Se sim '=', se for maior '>', se for menor '<' \n",med);
    do
       {digitado = getchar();
        getchar();
        switch(digitado)
           {case '>':
               {min = med;
                med = max - (max - min)/2;
                printf("%d?\n",med);
                cont=cont+1;
                break;                  }
            case '<':
               {max = med;
                med = min - (min - max)/2;
                printf("%d?\n",med);
                cont=cont+1;
                break;                  }
            case '=':
               {printf("O numero pensado foi %d e ele foi encontrado apos %d tentativas \n",med,cont);
                break;}
            default:
               {printf("Valor invalido\n");}
           }
       }while(digitado != '=');
}

#endif // Encerra ex3

#ifdef ex4
int main(){
int a[3],b[3],c,hor,min,seg;
for (c=0;c<3;c++){
    if (c==0){
        printf("\nDados do inicio da ligacao!");
            do{
        printf("\nDigite hora: ");
        scanf("%d",&a[c]);}while(a[c]<0||a[c]>=24);}
    else
    if (c==1){
        do{
            printf("\nDigite o min: ");
            scanf("%d",&a[c]);
        }while (a[c]<0||a[c]>=60);
    }
    else {
        do{
            printf("\nDigite o seg: ");
            scanf("%d",&a[c]);
        }while (a[c]<0||a[c]>=60);
    }
}
for (c=0;c<3;c++){
    if (c==0){
        printf("\nDados do termino da ligacao!");
            do{
        printf("\nDigite hora: ");
        scanf("%d",&b[c]);}while(b[c]<0||b[c]>=24);}
    else
    if (c==1){
        do{
            printf("\nDigite o min: ");
            scanf("%d",&b[c]);
        }while (b[c]<0||b[c]>=60);
    }
    else {
        do{
            printf("\nDigite o seg: ");
            scanf("%d",&b[c]);
        }while (b[c]<0||b[c]>=60);
    }
}
hor=b[0]-a[0];
if (hor<0){
    hor+=24;
}
min=b[1]-a[1];
if (min<0){
    min+=60;
    hor-=1;
}
seg=b[2]-a[2];
if(seg<0)
{
    seg+=60;
    min-=1;
}
printf("O tempo da Ligacao foi:\t %d : %d : %d",hor,min,seg);
}
#endif // ex1

#ifdef ex5
void main(){
    float a;
    int b;
    printf("\nDigite um valor Real: ");
    scanf("%f",&a);
    b=(int)a;
    a=a-b;
    if (a<0.25f){
        a=0;}
    else
        if (a>=0.25f && a<=0.74f)
            a=0.5;
    else
        a=1;
    printf("\nO valor arrendondado: %.2f", a+b);
}
#endif // ex2
#ifdef ex6
int main(){
    char a;
    float b,val2=3.88,val1=3.18;
    printf("\n A=Alcool \t G=Gazullina \n");
    scanf("%c",&a);
    do{
    printf("\nQuantos litros: ");
    scanf("%f",&b);}while(b<=0);
    if (a=='a'||a=='A'){
        if (b>20){
            val1*=b;
            val1-=(val1*0.05);}
        else{
            val1*=b;
            val1-=(val1*0.03);}
    printf("\nO valor a ser pago pelo cliente: RS %.2f",val1);
    }
    if (a=='g'||a=='G'){
    if (b>20){
        val2*=b;
        val2-=(val2*0.06);}
    else{
        val2*=b;
        val2-=(val2*0.04);}
    printf("\nO valor a ser pago pelo cliente: RS %.2f",val2);
    }
}
#endif

#ifdef ex7
int main(){
float a,b,c;
do{
    printf("\nQuantos KM: ");
    scanf("%f",&a);}while (a<0);
    do{
        printf("\nQuantidade de litros gastos: ");
        scanf("%f",&b);
    }while (b<0);
    c=a/b;
    printf("\nO consumo de KM/L %.2f",c);
    if (c<8)
        printf("\nVende o carro!!");
    else if (c>=8 && c<=14)
        printf("\nEconomico!");
    else
        printf("\nSuper economico!");
}
#endif // ex4

#ifdef ex8
int main(){
    float alt,pes,imc;
    do{
    printf("\nQual sua altura em cent: ");
    scanf("%f",&alt);}while(alt<=0);
    alt/=100;
    do {
    printf("\nSeu peso: ");
    scanf("%f",&pes);}while (pes<=0);
    imc=pes/(alt*alt);
    printf("\nSeu imc e: %.2f",imc);
    if (imc<=18.5f)
        printf("\tAbaixo do Peso!");
    else
    if (imc>=18.6f && imc<=24.9f)
        printf("\tSaudavel!");
    else
        if (imc>=25 && imc<=29.9f)
            printf("\tPeso em excesso!");
    else
        if (imc>=30 && imc<=34.9f)
            printf("\tObesidade Grau I!");
    else
        if (imc>=35 && imc<=39.9f)
            printf("\tObesidade Grau II(severa)!");
    else
        printf("Obesidade Grau III(morbida)");


}
#endif // ex5
