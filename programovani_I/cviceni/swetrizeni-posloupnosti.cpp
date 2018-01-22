/*
  Name: scotani
  Copyright: AMBIS 
  Author: MV
  Date: 11.11.17 12:34
  Description: 
*/
 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
 
int main() //hlavni funkce                          //zahlavi hlavni funkce
  {                                                 //zacatek tela hlavni funkce
    int i, n, LR, PR;                                    //deklarace promenych
    float a[10], pom;                           //deklarace promenych
     
    printf("\n Zadej pocet cisel v posloupnosti: ");                  //vystup - vyzva
    scanf ("%i", &n);                                                 //cteni hodnoty
    printf("\n Budeme porovnavat %i prvku posloupnosti.\n", n);           //tisk hodnoty
     
    for(i=0; i<n; i++)
    {
     printf("\n Zadej prvek a(%i) = ", i+1);                          //vystup - zadej cisla posloupnosti
     scanf ("%f", &a[i]);                                            //cteni hodnoty
    }
    
    printf("\n Posloupnost zdrojova:\n");           //tisk hodnoty     
    for(i=0; i<n; i++)
     printf(" %1.0f ", a[i]);
     
     for(LR=0; LR<n-1; LR++)
      for(PR=LR+1; PR<n; PR++)
      {
                   if(a[LR] <= a[PR])
                   {
                            pom = a[LR];
                            a[LR] = a[PR];
                            a[PR] = pom;
                    }
                   
      }
      printf("\n Posloupnost setridena:\n");           //tisk hodnoty 
      for (i=0; i<n; i++)
      printf(" %1.0f ", a[i]);
      
      printf("\n");
      system("pause");                                //pauza a cekan ni lib.klavesu
     return(0);
  } 
