#include <stdio.h>
#include <stdlib.h>
#define ex9
#ifdef ex1 //Ex 1 lista 1
char A=127;
int B =32767;
short C=32767;
long D=2147483647;
float E=3.4E+38;
double J=1.7E+308;
unsigned char f=255;
unsigned int g=65535;
unsigned short h=65535;
unsigned long i=65535;

int main()
{
char a=-127;
int b =-32767;
short c=-32767;
long d=-2147483647;
float e=-3.4E+38;
float j=-1.7E+308;
printf("\nValor maior de int: %d e o menor: %d ",B,b);
printf("\nValor maior de Char: %c e o menor: %c ",A,a);
printf("\nValor maior de Short: %hd e o menor: %hd ",C,c);
printf("\nValor maior de Long: %ld e o menor: %ld ",D,d);
printf("\nValor maior de Float: %f e o menor: %f ",E,e);
printf("\nValor maior de Double: %e e o menor: %e ",J,j);

printf("\n O maior unsigned char: %u %c e o menor: 0",f,f);
printf("\n O maior unsigned int: %u e o menor: 0",g);
printf("\n O maior unsigned short: %hu %c e o menor: 0",h);
printf("\n O maior unsigned long: %lu %c e o menor: 0",i);
}
#endif

#ifdef ex2 // ex2

int main(){
unsigned int a;
short b;
char c;
float d;
double e;
long int la;
	printf("Digite um valor do tipo short: ");
	scanf("%d",&b);

	printf("Digite um valor do tipo float: ");
	scanf("%f",&d);

	printf("Digite um valor do tipo long: ");
	scanf("%ld",&la);

	printf("Digite um valor do tipo double: ");
	scanf("%lf",&e);

	printf("Digite um valor do tipo unsigned int: ");
	scanf("%d",&a);

	printf("Digite um valor do tipo char: ");
	scanf("%u",&c);

    printf("\n\t 10 \t 20 \t 30 \t 40 \t 60 \n12345678901234567890123456789012345678901234567890123456789012345");
	printf("\n%-10d\t\t%-10d\t\t%-10u\n", b, la, a);
	printf("%10f\t\t%10lf\t\t%10d\n", d, e, c);
	}
#endif

#ifdef ex3
int main(){
unsigned int a;
short b;
char c;
float d;
double e;
long int la;

int	f;
unsigned char g;
unsigned long h;
	printf("\nDigite um valor do tipo short: ");
	scanf("%d",&b);
	printf("\nDigite um valor do tipo float: ");
	scanf("%f",&d);
	printf("\nDigite um valor do tipo long: ");
	scanf("%ld",&la);
	printf("\nDigite um valor do tipo double: ");
	scanf("%lf",&e);
	printf("\nDigite um valor do tipo unsigned int: ");
	scanf("%d",&a);
	printf("\nDigite um valor do tipo char: ");
	scanf("%u",&c);
	printf("\nDigite um valor do tipo int: ");
	scanf("%d",&f);
	printf("\nDigite um valor do tipo unsigned char: ");
	scanf("%d",&g);
	printf("\nDigite um valor do tipo unsigned long: ");
	scanf("%lu",&h);

    printf("\n\t 10 \t 20 \t 30 \t 40 \t 60 \n12345678901234567890123456789012345678901234567890123456789012345");
	printf("\n%-10d\t\t%-10d\t\t%-10u\n", b, la, a);
	printf("%10f\t\t%10lf\t\t%10d\n", d, e, c);
	printf("\n%-10d\t\t%-10d\t\t%-10lu\n", f, g,h);

	return 0;
}
#endif // ex3

#ifdef ex4 //ex4
int x,y;
int main (){
x = 20;
y = 10;
y= x+y;
x= y-x;
y= y-x;
printf("o valor Y e = %d e o de X e: %d",y,x);
}
#endif // ex3

#ifdef ex5
int main(){
    int a,b,c;
    do{
    printf("\nDigite um numero natural positivo maior q 0: ");
    scanf("%d",&a);
    if(a<=0)
        printf("\nNumero invalido, digite outro numero!");
    }while(a<=0);
    do{
        printf("Digite um limite minimo posi e maior q 0: ");
        scanf("%d",&b);
        if(b<=0)
            printf("\nNumero invalido, digite outro numero!");
    }while(b<=0);
    c=++b;
    while(c%a!=0){
        c++;
    }
    printf("\n Menor multiplo de: %d Maior que: %d Resultado: %d",a,b,c);
}
#endif // ex4

#ifdef ex6
int main(){
    int a;
    do{
    printf("\nDigite a quantidade de Seg: ");
    scanf("%d",&a);}while(a<=0);
    int seg = a % 60;
    int mins= a / 60;
    int min = mins % 60;
    int hr = mins / 60;
    printf("A quantidade de segundo: %d E igual a: %02dhr:%02dmin:%02dseg",a,hr,min,seg);
}
#endif
#ifdef ex7
int main(){
    int a,b,cen,dez,uni;
    do{
    printf("Digite um numero inteiro positivo de tres digitos: ");
    scanf("%d",&a);}while (a<100 || a>999);
    b=a;
    cen=a/100;
    a=a%100;
    dez=a/10;
    uni=a%10;
    printf("\nNumero lindo: %d Numero Gerado: %d%d%d",b,uni,dez,cen);

}
#endif // ex6

#ifdef ex8
int main(){
long int a;
    do{
        printf("\nDigite sua idade: ");
        scanf("%ld",&a);
        if (a<=0)
            printf("\nDigite um Valor vaido!");
    }while(a<=0);
    printf("\nSeu coracao bateu aproximadamente %ld em sua vida!",a);
}
#endif // ex7
#ifdef ex9
main (){
 int a = 0;
  int notas = 0;

  while(a <= 0){
    printf("Digite o numero que sera calculado: ");
    scanf("%d", &a);
    if(a <= 0){
      printf("Digite apenas numeros maiores que 0!\n\n");
    }
  }

  while(a >= 100){
    notas = notas + 1;
    a = a - 100;
  }
  printf("Serao necessarias %d notas de 100, ", notas);
  notas = 0;

  while(a >= 50){
    notas = notas + 1;
    a = a - 50;
  }
  printf(" %d notas de 50, ", notas);
  notas = 0;

  while(a >= 10){
    notas = notas + 1;
    a = a - 10;
  }
  printf("%d notas de 10 ", notas);
  notas = 0;

  while(a >= 1){
    notas = notas + 1;
    a = a - 1;
  }
  printf("e %d moedas de 1.", notas);
}
#endif // ex9
