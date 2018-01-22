/*UKOL2: suma ciselne rady
vyvojak viz sesit

for(vyraz zacatek;vyraz konec;vyraz krok) 
      prikaz

*/


#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>  

int main()
  {
    int n, i;                                                       // kroky pro cykly jsou tez znaceny jako vstupni promenne                
    float cislo, suma;
    
    printf("\n Zadej pocet cisel v posloupnosti: ");                     
    scanf ("%i", &n);                            
    printf("\t Budeme scitat %i prvku posloupnosti.", n);
    
    suma = 0;
    
    for(i = 0; i < n; i++)
          {
          printf("\n Zadej %i. cislo: ", i+1);                        //zadej i-te cislo. i+1 = prepocet na cislovani od 1 pro lidske cteni
          scanf ("%f", &cislo);                                       //cti i-te cislo        
          
          suma = suma + cislo;
          }
          
      printf("\n Suma je: %100.1f ", suma);       
          
          
      system("pause");
      
  }      
       


