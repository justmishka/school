#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//*** Deklarace uzivatelske funkce Prumery ***
int Prumery(int n, float a[], float *ar_pr, float *ge_pr, float *ha_pr)
  {
    int   i;
    float suma, soucin;
    
//**aritmeticky prumer***
    suma = 0;
    for(i=0; i<n; i++)
      {         
        suma = suma + a[i];      
      }   
    *ar_pr = suma/n;

//**geometricky prumer***
    soucin = 1;
    for(i=0; i<n; i++)
      {             
        soucin = soucin * a[i];  
      }
    *ge_pr = pow(soucin, 1./n);
    
//**harmonicky prumer***
    suma = 0;
    for(i=0; i<n; i++)
      {           
        suma = suma + (1/a[i]);  
      }
    *ha_pr = n/suma;
    
    return 1;
  }  


int main()
  {
    int   i, n, info = 1, ipr;
    float suma, x[10], soucin, ar_pr, ge_pr, ha_pr;
    
    printf("\n Zadej pocet cisel: ");
    scanf("%i", &n);

    for(i=0; i<n; i++)
      {  
        printf("\n Zadej %i. cislo: ", i+1);
        scanf("%f", &x[i]);
    
        if(x[i] == 0)
        info = 0;
      }
//**volani uzivatelske funkce Prumerz***********
    ipr = Prumery(n, x, &ar_pr, &ge_pr, &ha_pr);
    
    printf("\n Aritmeticky prumer %i cisel je:  %3.2f ", n, ar_pr);
    
    if (info == 0)
      {
        printf("\n\n\n Nelze spocitat harmonicky ani geometricky prumer!!! \n" );
        goto konec;
      }

    printf("\n Geometricky prumer %i cisel je:  %3.2f ", n, ge_pr);
         
    printf("\n Harmonicky  prumer %i cisel je:  %3.2f \n\n", n, ha_pr);
    printf("\n\n");

 konec:
    
    system("PAUSE");
    return (0);   
  }





