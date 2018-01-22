/*UKOL 1: secti dve celociselna cisla
          dano a,b 
          vysledek c=a+b
          vyvojak viz sesit
1. reseni ukolu pres integer - ten ma omezenou delku znaku
2. reseni ukolu pres float


FUNKCE, ktere vyuzivajeme     
   Printf() ... vysledek na obrazovku
   scanf()  ...cti vstup   
   
   pro uhlednost na konzoli:
   \n new line (nov� ��dka)
   \r carriage return (n�vrat na za�. �.) 
   \f formfeed (nov� ��dka) 
   \t tabul�tor 
   \b backspace (posun doleva) 
   \a BELL (p�sknut�)    
   \\ backslash (zp�tn� lom�tko)
   \� single quote (apostrof)
   \0 nul ...pozor neni NULL! 
   
   
*/

/*IMPORT KNIHOVEN
1.VZDY MUSI SAMOSTATNY SOUBOR OBSAHOVAT IMPORT KNIHOVEN - PRVNI TRI KNIHOVNY MUSI BYT VZDY!*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>                              //standardni knihovna - napriklad v vyuziti funkce system(pause)


/* VLASTNI PROGRAM - VERZE S INTEGEREM */

/*int main()                                     //zahlavi funknce        

  {                                              //zacatek tela hlavni funknce          
    int a, b, soucet;                            //deklarace promennych
  
  
    printf("\n Zadej prvniho scitance: ");       //uvozovky jsou retezec v C! nelze nahradit '' ; vyzva na vystup
    scanf ("%i", &a);                            //precte integer = cteni hodnoty a
    printf("\t Prvni scitanec je a = %i", a);    //a = %i"..znaci jaky bude vystup pro lidske cteni, a definujeme, co ma vyhodit na vystup "promennou a" 
    
    printf("\n\n Zadej druheho scitance: ");     //to stejne pro druhy scitanec
    scanf ("%i", &b);                         
    printf("\t Druhy scitanec je a = %i", b);
    
    
    soucet = a + b ;                             //vlastni pocitani        
  
  
    printf("\n\n Nas prvni program!");           //vystup po vypoctu
    printf("\n Tedy: %i + %i = %i \n\n", a, b, soucet);
    
    
    system("pause");
      
  }
*/  

/*VLASTNI PROGRAM - VERZE S FLOATEM*/
//staci zmenit datove typy
//defaultne se float zobrazuje na 6 desetinych mist
  
int main()                                                   //zahlavi funknce        

  {                                                          //zacatek tela hlavni funknce          
    float a, b, soucet;                                      //deklarace promennych
  
  
    printf("\n Zadej prvniho scitance: ");                   
    scanf ("%f", &a);                                                                         
    printf("\t Prvni scitanec je a = %100.1f", a);          //%1000.1f ... prvni cislo je pocet znaku pred desetinnou radkou, a za desetinnou carkou decimal precision  
                                                         
    printf("\n\n Zadej druheho scitance: ");                
    scanf ("%f", &b);                         
    printf("\t Druhy scitanec je a = %100.1f", b);
    
    
    soucet = a + b ;          
  
  
    printf("\n\n Nas prvni program!");
    printf("\n Tedy: %f + %f = %100.1f \n\n", a, b, soucet);
    
    
    system("pause");
      
  }  
  
  
  
