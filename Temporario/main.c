#include <stdio.h>
#include <stdlib.h>

int main(){

int n;
char *p;
int x = 0;

printf("Quantas letras possui?\n");
    scanf("%d",&n);

    p = (char *) malloc(n * sizeof(char));

    printf("Digite a palavra:");
      scanf("%s",p);


      for(int i =0;i<n;i++){
      if ((p[i] != 'a')|| (p[i] !=  'e') || (p[i] !=  'i') || (p[i] !=  'o')  ||  (p[i] !=  'u') ){
          p[x] = p[i];
          x++;
      }
      }
     p[x] = '\0';


    printf("\n Sem vogais, sua palavra sera: %s",p);

    free(p);

    }

