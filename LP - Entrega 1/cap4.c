#include <stdio.h>
#include <stdlib.h>
#define ex1

#ifdef ex1
int main()
{
    int a[3],count;
    long int b[3];
    unsigned c[3];
    float d[3];
    double e[3];
    for (count=0;count<3;count++){
        printf("\nDigite um numero inteiro: ");
        scanf("%d",&a[count]);
        printf("\nDigite um unsigned inteiro: ");
        scanf("%u",&c[count]);
        printf("\nDigite um Long inteiro: ");
        scanf("%ld",&b[count]);
        printf("\nDigite um numero real: ");
        scanf("%f",&d[count]);
        printf("\nDigite um numero real c ponto flutuante: ");
        scanf("%e",&e[count]);
    }
    printf("\n        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    for (count=0;count<3;count++){
    printf("  %-10d                %-10ld\t            %10u\n",a[count],b[count],c[count]);
    printf("            %-8.2f              %-8.2e\n",d[count],e[count]);
    }
}
#endif

#ifdef ex2
int main(){
int a[10],c,d=0;
for (c=0;c<10;c++){
    printf("\nDigite um valor inteiro: ");
    scanf("%d",&a[c]);
}
for (c=0;c<5;c++){
    if (a[c]==a[9-c])
        d++;
}
if (d==5)
    printf("\nO Vetor e um Palidromo");
    else
        printf("\nO vetor nao e um Palidromo!");
}
#endif // ex2

#ifdef ex3
main (){
    static int a[2][3][3]={
                         {{0, 0, 0,0, 0},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0}},

                          {{0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0}}
                                };
    int i,i2,i3;
    for(int i = 0; i < 2; i++){
    printf("\n");
    for(int i2 = 0; i2 < 2; i2++){
      for(int i3 = 0; i3 < 2; i3++){
        printf("Digite o %d° número, da %d° coluna e %d° escopo: ", i3+1,i2+1, i+1);
        scanf("%d", &a[i][i2][i3]);
      }
    }
  }
    for(int i = 0; i < 2; i++){
    printf("\nMatriz %d: ", i+1);
    for(int i2 = 0; i2 < 2; i2++){
      for(int i3 = 0; i3 < 2; i3++){
        printf("%d ", a[i][i2][i3]);
      }
    }
  }
}
#endif // ex3
#ifdef ex4
int main(){
  int a[2][3], b[2][3], c[2][3],i,i2;

  for(int i = 0; i < 2; i++){
    for(int i2 = 0; i2 < 3; i2++){
      printf("\nDigite o um numero inteiro para vetor 1: ", i2+1, i2+1, i+1);
      scanf("%d", &a[i][i2]);
      printf("\nDigite o um numero inteiro para vetor 2: ", i2+1, i2+1, i+1);
      scanf("%d", &b[i][i2]);
      c[i][i2]=a[i][i2]*b[i][i2];
      printf("\nO Mutiplicacao do vetor A pelo vetor B: %d",b[i][i2]);
    }
  }
}
#endif // ex4
#ifdef ex5
main(){
    int b,e,par=0,imp=0;
    do{printf("\nQual o tamanho do vetor: ");
    scanf("%d",&b);}while(b<=0);
    int a[b],c[b],d[b];
    for (e=0;e<b;e++){
        printf("\nDigite um valor: ");
        scanf("%d",&a[e]);
        if (e%2==0){
            c[par]=a[e];
            par++;}
        else {
            d[imp]=a[e];
            imp++;}
    }
    printf("\nA posicao par: ");
    for (e=0;e<par;e++){
        printf("%d,",c[e]);}
    printf("\nA posicao impar: ");
    for (e=0;e<imp;e++){
    printf("%d, ",d[e]);}
}
#endif // ex6
#ifdef ex6
main(){
    int b,e,par=0,imp=0;
    do{printf("\nQual o tamanho do vetor: ");
    scanf("%d",&b);}while(b<=0);
    int a[b],c[b],d[b];
    for (e=0;e<b;e++){
        printf("\nDigite um valor: ");
        scanf("%d",&a[e]);
    }
    for (e=0;e<b;e++){
        if (a[e]%2==0){
            c[par]=a[e];
            par++;}
    else {
        d[imp]=a[e];
        imp++;
    }}
    printf("\nOs Valores pares: ");
    for (e=0;e<par;e++){
        if (par==0)
            break;
        printf("%d,",c[e]);}
    printf("\nOs numeros impares: ");
    for (e=0;e<imp;e++){
    if (imp==0)
        break;
    printf("%d, ",d[e]);}

}
#endif // ex5

#ifdef ex7
int main(){
    int num[10];
    int maior = 0;
    int atual = 0;
    int men = 0;
    int rev[10];
    int countMenNum = 0;
    int countMaiorNum = 9;

    for(int i = 0; i < 10; i++){
        printf("Digite um numero: ");
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < 10; i++){
        if(num[i] >= maior){
            printf("%d", num[i]);
            maior = num[i];
            atual = maior;

        }
    }

    for(int i = 0; i < 10; i++){
        if(num[i] <= men){
            men = num[i];
            rev[countMenNum] = men;
            countMenNum = countMenNum + 1;
        }else if(num[i] >= maior){
            maior = num[i];
            atual = maior;
            rev[countMaiorNum] = maior;
            countMaiorNum = countMaiorNum - 1;

        }
    }

    printf("\n %d - %d", countMenNum, countMaiorNum);

    for(int a = countMenNum; a <= countMaiorNum; a++){
        for(int b = 0; b < 10; b++){
            if(num[b] == maior){
                printf("foi");
                rev[a] = num[b];
            }else if(num[b] > men && num[b] < maior){
                maior= num[b];
            }
        }
        rev[a] = maior;
        men = maior;
        maior= atual;
    }

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("\n%d", rev[i]);
    }
}

#endif // ex7

#ifdef ex8
main(){
    int c[5][5];
    int matriz= 0;
    int numusu = 0;
    int numusub = 0;

    for(int a = 0; a < 5; a++){
        for(int b = 0; b < 5; b++){
            c[a][b] = 0;
            matriz = matriz + 3;
            c[a][b] += matriz;
        }
        matriz += 2;
    }

    printf("Digite um numero que esteja entre os armazenados dentro da matriz: ");
    scanf("%d", &numusu);

    for(int a = 0; a < 5; a++){
        for(int b = 0; b < 5; b++){
            if(c[a][b] == numusu){
                numusub += 1;
                printf("\nO numero digitado esta na posicao: matriz[%d][%d]\n", a, b);
            }
        }
    }

    if(numusub > 0){
        printf("\nO numero digitado apareceu %d vezes na matriz.\n", numusub);
    }else{
        printf("\nO numero digitado n esta armazenado na matriz.\n", numusub);
    }
}
#endif // ex8
