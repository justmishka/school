/*UKOL2: suma ciselne rady
vyvojak viz sesit

for(vyraz zacatek;vyraz konec;vyraz krok) prikaz

*/


#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>  

int main()
  {
    int n, k, i;                         
    float suma, a[100];                         //dimenze pro a
    
    printf("\n Zadej pocet cisel v posloupnosti: ");                     
    scanf ("%i", &n);                            
    printf("\t Budeme scitat %i prvku posloupnosti ", n);
    
    for(k = 0; k < n; k++)
        {
          printf("\n Zadej %i. cislo posloupnosti: ", k+1);                      //i - konverze nesouvisi s cyklem
          scanf ("%f", &a[k]);                                                   //nacti float a pro kazdy k-cyklus 
        }
            

    suma = 0;
    
    for(i = 0; i < n; i++)
      {    
        suma = suma + a[i];
       // pouze pro vypis hodnot prubezne lze pouzit napriklad pro kontrolu: printf("\n Suma pro i je: %100.1f ", suma);
      }
        
        
    printf("\n Suma je: %10.1f ", suma);   
         
          
        
    system("pause");
      
      }

