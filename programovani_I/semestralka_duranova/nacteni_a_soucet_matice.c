/*Tento soubor slouzi k:
  - zadani matice A, 
  - zadani matice B 
  - k vypoctu souctu obou matic A a B, ktery budeme vyuzivat dale v uloze
  - k vypoctu a zapisu do souboru maximalni cifry, pro alokaci pameti, kterou budeme vyuzivat dale v uloze
 
 Do vysledneho souboru se zapisi:
 - zadaná dimenze matice
 - vstupy A a B
 - soucet A + B
 - maximalni cifra
 
 POZNÁMKY:
 - program je definovan pro prirozena cisla
 - pro vice nez 9-ti ciferna cisla jiz nebude vporadku alokace pameti v druhem programu (nazev: hlavni_program)
 - program nam matici o n-dimenzich preulozi (a i vysledny soucet zobrazi) do jednoho radku, 
   coz nam v pripade vypoctu euklidovske normy nevadi a tak nemusime brat v potaz fakt, o ktery radek se originalne jednalo (tudiz tuto cast jsem v programu neosetrovala) 
*/

/*zakladni knihovny potrebne k behu programu*/
#include <stdio.h>															
#include <conio.h>
#include <math.h>
#include <stdlib.h>

/*definovani funkce pro vypocet cifer, ktery budeme potrebovat pro alokaci pameti v hlavnim_programu*/
int pocet_cifer(int cislo){
	int cifry = 0;															//dosazeni prvni hodnoty, nez zacnou vypocty = 0
		while (cislo > 0) {													//opakovaci smycka, dokud je nase cislo vetsi nez 0
			cifry ++;														//zvetsovani cifry o 1
			cislo /= 10;													//deleni naseho cisla beze zbytku a navrat do podminky smycky
		}
	return cifry;
	}
	

//vlastni program pro zadani matic a jejich souctu
int main()																	
{
	/*INICIALIZACE PROGRAMU, DEFINOVANI PROMENNYCH, ALOKACE PAMETI, PRIPRAVA NA ZAPIS DO SOUBORU*/
	int n, c, d, max_cifra;													//definovani promennych pro dimenzi matice (n), opakovani(c,d), maximalni cifru(max_cifra)
	int *matice_a, *matice_b, *soucet_ab;										//definováni promennych vcetne pointeru pro dynamickou alokaci pro prvky matice A,B a souctu matic
   	max_cifra = 0;															//definovani pocatecni hodnoty pro promennou max_cifra
   	
	//priprava na ukladani do souboru
	FILE *f = fopen("matice.txt", "w");
		if (f == NULL) { 											        //zadani kontroly v pripade chyby pri otevirani souboru
    	printf("Chyba v otevirani souboru!\n");
   		exit(1);
		}	   
   
	//zadani, precteni a zapis dimenze matice
	printf("Zadej dimenzi matic\n");							            //vyzve uzivatele k akci - zadani dimenze pro matice
    scanf("%d", &n);														//precte hodnoty a ulozi do n
    fprintf(f, "Dimenze matic:\n%d\n", n);  								//ulozi do souboru
 
   //alokace pameti pro promenne matice_a,matice_b,soucet
	matice_a  = (int*)malloc(n * n * sizeof(int));							
	matice_b  = (int*)malloc(n * n * sizeof(int));
	soucet_ab = (int*)malloc(n * n * sizeof(int));
   
   
	/*ZPRACOVANI MATIC*/
	
	//zadani, precteni a zapis matice A 										
	printf("Zadej prvky matice A\n");										//vyzve uzivatele k akci - zadani prvku matice
	fprintf(f, "Matice A:\n");												//zapise text do souboru a odradkuje
	for (c = 0; c < n; c++)
      for (d = 0; d < n; d++) 	{
    	 scanf("%d", &(matice_a[n*c+d]));									//postupne nacitani matice
    	 fprintf(f, "%d\t", matice_a[n*c+d]);                    			//postupny zapis do souboru
      } 
    
	fprintf(f,"\n");  														//do souboru vlozi novy radek
    printf("\n");  															//na obrazovku vlozi novy radek
    
    //zadani a zpracovani matice B:  
	printf("Zadej prvky matice B\n");										//vyzve uzivatele k akci - zadani prvku matice
 	fprintf(f, "Matice B:\n");												//zapise text do souboru a odradkuje
	for (c = 0; c < n; c++)
      for (d = 0 ; d < n; d++) {
        scanf("%d", &(matice_b[n*c+d]));									//postupne nacitani matice
        fprintf(f, "%d\t", matice_b[n*c+d]);								//postupny zapis do souboru
    	}
		
    fprintf(f,"\n");														//do souboru vlozi novy radek
    printf("\n");															//na obrazovku vlozi novy radek
	
 	//zpracovani a kontrolni zobrazeni souctu matic
    printf("soucet zadanych matic:\n");										//zobrazeni souctu pro kontrolu spravnosti vypoctu - 1.cast
	fprintf(f, "Soucet A+B:\n");											//zapise text do souboru a odradkuje
	for (c = 0; c < n; c++) {
      for (d = 0 ; d < n; d++) {
        soucet_ab[n*c+d] = matice_a[n*c+d] + matice_b[n*c+d];					//zpracovani vypoctu souctu matic, vysledkem je opet matice
        printf("%d\t", soucet_ab[n*c+d]);                                  	//zobrazeni souctu pro kontrolu spravnosti vypoctu - 2.cast
        fprintf(f, "%d\t", soucet_ab[n*c+d]);								 	//postupny zapis do souboru
        
        if (max_cifra < pocet_cifer(soucet_ab[n*c+d]))	 						//vypocet maximalni cifry, ktera se v matici objevuje
		 	max_cifra = pocet_cifer(soucet_ab[n*c+d]);
      }
    }  
    free(matice_a);															//uvolneni alokace pameti pro promennou matice_a
	free(matice_b);															//uvolneni alokace pameti pro promennou matice_b
    free(soucet_ab);  															//uvolneni alokace pameti pro promennou matice_b
												
	fprintf(f, "\nMax cifra:\n");											//zapise text do spouboru a odradkuje
	fprintf(f, "%d", max_cifra);											//zapise hodnotu maximalni cifrz do spouboru
	fclose(f);																//zavreni souboru
   
	printf("\n\nMatice byli uspesne ulozeny do souboru matice.txt!");      	//validace o uspesnem zapsani do souboru pro uzivatele
   
   return 0;
}
