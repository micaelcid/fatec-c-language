#include <stdio.h>
#include <stdlib.h>
#define ex10

#ifdef ex1
int main()
{
int a,b,c;
do{
    printf("\nDigite 2 numeros inteiros: ");
    scanf("%d %d",&a,&b);
    printf("\nSoma: %d",a+b);
    printf("\nSubitracao: %d",a-b);
    printf("\nMultiplicacao: %d",a*b);
    printf("\nDivisao: %d",a/b);
    printf("\nQuer continuar no programa: \n\t1 para continuar! \t2 para sair!");
    scanf("%d",&c);
}while(c==1);
}
#endif
#ifdef ex2
int main()
{
int a,b,c;
do{
    printf("\nDigite 2 numeros inteiros: ");
    scanf("%d %d",&a,&b);
    printf("\nSoma: %d",sizeof(a+b));
    printf("\nSubitracao: %d",sizeof(a-b));
    printf("\nMultiplicacao: %d",sizeof(a*b));
    printf("\nDivisao: %d",sizeof(a/b));
    printf("\nQuer continuar no programa: \n\t1 para continuar! \t2 para sair!");
    scanf("%d",&c);
}while(c==1);
}
#endif // ex2

#ifdef ex3
float main()
{
float a,b;
int c;
do{
    printf("\nDigite 2 numeros Reais: ");
    scanf("%f %f",&a,&b);
    printf("\nSoma: %.2f",sizeof(a+b));
    printf("\nSubitracao: %.2f",sizeof(a-b));
    printf("\nMultiplicacao: %.2f",sizeof(a*b));
    printf("\nDivisao: %.2f",sizeof(a/b));
    printf("\nQuer continuar no programa: \n\t1 para continuar! \t2 para sair!");
    scanf("%d",&c);
}while(c==1);
}
#endif // ex3

#ifdef ex4
main()
{
int a,b;
printf("\nDigite 2 numeros: ");
scanf("%d %d",&a,&b);

printf(" Operadores bit-a-bit\n");
printf(" AND   a & b --> %3d  0x%x\n",a & b,a & b);
printf(" OU   a | b --> %3d  0x%x\n",a | b,a | b);
printf(" OU EXCLUSIVO a ^ b --> %3d  0x%x\n",a ^ b,a ^ b);
}
#endif // ex4

#ifdef ex5
main()
{
int a;
printf("\nDigite um numero inteiro: ");
scanf("%d",&a);
printf("numero div %d \t\t numero mult %d\n",a >> 3 ,a << 3);
}
#endif // ex5
#ifdef ex6
int main(){
int a,b;
printf("\nDigite dois numeros: ");
scanf("%d %d",&a,&b);
if (a >= 120 && b < 240)
    printf("\n1");
else
    printf("\n2");
if (a != 60  || b == 120)
    printf("\n1");
else
     printf("\n2");
if ((a*25) == 100 && (b+10) >= 100)
    printf("\n1");
else
    printf("\n2");
if (((a + 300)/5) >= 100 || (b - 200) <= 200)
    printf("\n1");
else
    printf("\n2");
}
#endif // ex6
#ifdef ex7
int main(){
float a;
int b;
printf("\n1 - transforma graus Celsius em Fahrenheit e Kelvin\n2 - transforma graus Fahrenheit e Celsius e Kelvin\n3 - transforma graus Kelvin e Celsius e Fahrenheit\n");
scanf("%d",&b);
switch (b){
case 1 :
    printf("\nDigite o temperatura Celsius: ");
    scanf("%f",&a);
    printf("\n%.1f F\t%.2f K",(a*9/5)+32,a+273.15);
    break;
case 2 :
    printf("\nDigite o temperatura Fahrenheit: ");
    scanf("%f",&a);
    printf("\n%.1f C\t%.2f K",((a-32)*(5/9)),((a-32)*(5/9))+273.15);
    break;
case 3 :
    printf("\nDigite a temperatura Kelvin: ");
    scanf("%f",&a);
    printf("\n%.1f C\t%.2f F",a-273.15, (a-273,15)*9/5+32);
}
}
#endif // ex7

#ifdef ex8
int main(){
int a,b,c,d,e,f,ano,dia,mes;
do{
do{
printf("\nDigite o ano que vc nasceu: ");
scanf("%d",&a);}while(a<=0);
do{
printf("\nDigite o mes que vc nasceu: ");
scanf("%d",&b);}while(b<=0 || b>12);
do{
printf("\nDigite o dia que vc nasceu: ");
scanf("%d",&c);}while(c<=0||c>31);
do{
printf("\nDigite o ano atual: ");
scanf("%d",&d);}while(d<=0);
do{
printf("\nDigite o mes atual: ");
scanf("%d",&e);}while(e<=0 || e>12);
do{
printf("\nDigite o dia atual: ");
scanf("%d",&f);}while(f<=0 || f>31);
}while(d<a);
ano=d-a;
mes=e-b;
if (mes<0)
    ano-=1;
dia=f-c;
if (dia<0){
    dia+=31;
    mes-=1;}
    printf("\nSua idade dia %d Mes %d Ano %d",dia,mes,ano);
}
#endif // ex8
#ifdef ex9
int main(){
int dia,mes,ano,a,b,d,res;
do{
printf("\nDigite o ano: ");
scanf("%d",&ano);}while(ano<=0);
do{
printf("\nDigite o mes: ");
scanf("%d",&mes);}while(mes<=0 || mes>12);
do{
printf("\nDigite o dia: ");
scanf("%d",&dia);}while(dia<=0 || dia>31);
a=ano-1900;
b=a/4;
if (a%4==0)
    b-=1;
if (mes==1 || mes==10)
    mes=0;
else if (mes==2 || mes==3 || mes==11)
        mes=3;
else if (mes==4 || mes==7)
        mes=6;
else if (mes==5)
        mes=1;
else if (mes==6)
        mes=4;
else if (mes==8)
    mes=2;
else if (mes==9 || mes==12)
    mes=5;

d=dia-1;
res=a+b+mes+d;
printf("teste mes %d",res);
res=(res%7);
printf("teste mes %d",res);
if (res==0)
    printf("\nSegunda-Feira!");
else if (res==1)
    printf("\nTerca-Feira!");
else if (res==2)
    printf("\nQuarta-Feira!");
else if (res==3)
    printf("\nQuinta-Feira!");
else if (res==4)
    printf("\nSexta-Feira!");
else if (res==5)
    printf("\nSabado!");
else if (res==6)
    printf("\nDomingo!");
}
#endif // ex9

#ifdef ex10
int main(){
float valor;
float taxa;
char a[3];
do{
printf("\nValor do produto: ");
scanf("%f",&valor);}while(valor<=0);
do{
    printf("Qual estado: \n\tMG 7%\t SP 12%\t RJ 15%\t MS 8% \n");
    scanf("%s",&a);
    getchar();
    printf("\nteste %s",a);
    } while (a!="MG\o" || "mg\o");}
#endif // ex10
