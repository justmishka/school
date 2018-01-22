/*
  Name: scotani2
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

float Secti(float scitanec_1, float scitanec_2)      //identifikatory nesmeji zacinat cislem!
  {                                                 
    float soucet;
    soucet = scitanec_1 + scitanec_2;
    return soucet;                                                    
                                                    
  }

float Vynasob(float cinitel_1, float cinitel_2)
  {                                                 
    float soucin;
    soucin = cinitel_1 * cinitel_2;
    return soucin;                                                    
                                                    
  }
 
int main() //hlavni funkce                          //zahlavi hlavni funkce
  {                                                 //zacatek tela hlavni funkce
     float a, b, apb, ab;                           //deklarace promenych
     
    printf("\n Zadej dve cisla: ");                  //vystup - vyzva
    scanf ("%f%f", &a, &b);                                                 //cteni hodnoty

    apb = Secti(a, b);                                                      //dosazeni bez datoveho typu pri volani funkce, pouze skutecne parametry
    
    ab = Vynasob(a, b);
    
             

    printf("\n\n Vysledky: \n\n");     

    printf("\n Soucet %f + %f = %f", a, b, apb);
    printf("\n Soucin %f * %f = %f", a, b, ab);
             
     
 /*    
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
*/
      
      printf("\n");
      system("pause");                                //pauza a cekan ni lib.klavesu
     return(0);
  } 
