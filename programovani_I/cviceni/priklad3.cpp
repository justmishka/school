/*
  Name: scitani2
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


float Aritmetika(float cislo_1, float cislo_2, int info)   //v kazdym modulu muzu mit stejny promenny
      {
        float vysledek;
         if (info == 0) vysledek = cislo_1 + cislo_2;
             else
             vysledek = cislo_1 * cislo_2;
             
         /*GOTO Zacatek... napriklad pokud se chci nekam vratit... v tom pripade musim mit nekde napsano 
         zacatek:    */
         
         return vysledek;
                       
                       
      }
                       


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
    int info;
    float a, b, apb, ab, vysledek;                  //deklarace promenych
     
    printf("\n Zadej dve cisla: ");                 //vystup - vyzva
    scanf ("%f%f", &a, &b);                         //cteni hodnoty

    printf("\n Jakou operaci budeme provadet? Scitani = 0, soucin = 1 \n");
    scanf("%i", &info);
    
    
    
 //   apb = Secti(a, b);                              //dosazeni bez datoveho typu pri volani funkce, pouze skutecne parametry
    
 //   ab = Vynasob(a, b);
    
    vysledek = Aritmetika(a, b, info);
    
    
             

    printf("\n\n Vysledky: \n\n");     

    if (info == 0) printf("\n Soucet %f + %f = %f", a, b, vysledek);
        else  
                   printf("\n Soucin %f * %f = %f", a, b, vysledek);

 
      
    printf("\n");
    system("pause");                                //pauza a cekan ni lib.klavesu
    return(0);
  } 
