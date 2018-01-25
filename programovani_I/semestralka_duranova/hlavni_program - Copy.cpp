/*zakladni knihovny potrebne k behu programu*/
#include <stdio.h>															
#include <conio.h>
#include <math.h>
#include <stdlib.h>

/*INICIALIYACE FUNKCI A KONSTANT, KTERE JSOU DALE VYUZIVANY*/
const int TEXT_LINE_MAX = 20;														//globalni konstanta vyuzivana pro nacitani matic ze souboru

/*definovani funkce pro vypocet euklidovske normy*/
double vypocet_e_normy(int *matice, int h) {							    		// matice.. pointer na prvni prvek matice, h... hodnost matice
	int i;																			//definovani promennych pouzitych ve funkci spolu s pocatecni hodnotou
	double suma = 0;
	double e_norma;															
	
	for(i=0;i<h*h;i++) {															//jednotlive prvky umocnime, secteme
		 suma+=(matice[i] * matice[i]);
		}
	e_norma=sqrt(suma); 															//odmocneni celkoveho souctu umocnenych prvku
	 
	return e_norma;																	//vysledna e_norma
}

/*pocitani cifer - stejne jako v programu nacteni_a_soucet_matic*/
int pocet_cifer(int cislo){
	int cifry = 0;																	//dosazeni prvni hodnoty, nez zacnou vypocty = 0
		while (cislo > 0) {															//opakovaci smycka, dokud je nase cislo vetsi nez 0
			cifry ++;																//zvetsovani cifry o 1
			cislo /= 10;															//deleni naseho cisla beze zbytku a navrat do podminky smycky
		}
	return cifry;																	//vysledne cifry
	}

/*Hlavni program*/
int main()
{ 
	/*INICIALIZACE, DEFINOVANI PROMENNYCH, ALOKACE PAMETI, PRIPRAVA NA OTEVRENI A ZAPIS DO SOUBORU*/	
	int *matice_a, *matice_b, *soucet_ab, n, max_cifra, max_radek, j, preskoc_znaky;	//definovani promennych (nazvy koresponduji se souborem nacteni_a_soucet_matice pro prehlednost)
	char text[TEXT_LINE_MAX];
	char *misto_pro_matici;
	
	//priprava na otevreni souboru s vstupnimi daty
	FILE * vstupni_file = fopen( "matice.txt" , "r");								
		if (vstupni_file == NULL) { 											    //zadani kontroly v pripade chyby pri otevirani souboru
    	printf("Chyba v otevirani souboru s daty!\n");
   		exit(1);
		}	  
		
	//priprava na zapis do souboru
	FILE *vystupni_file = fopen("vystup.txt", "w");
		if (vystupni_file == NULL) { 											    //zadani kontroly v pripade chyby pri otevirani souboru
    	printf("Chyba v otevirani souboru pro vystupni data!\n");
   		exit(1);
		}
	
	/*CTENI DAT ZE SOUBORU*/
	printf("KONTROLNI VYPIS HODNOT:\n");		
	//zjistime maximalni cifru a podle ni zvolime potrebnou alokaci pro promenne    //Poznamka: zde by slo usetrit jeste misto, pokud bychom velikost cifry zjistovali zvlast pro kazdou promennou					            
	fseek(vstupni_file, -1, SEEK_END); 												/*otevre soubor se vstupnimi daty a jde na jeho konec - 1 znak (jak jsem zminila v souboru nacteni_a_soucet_matice - 
																					  - uloha je psana pro maximalni pocet cifer 9 a tomu odpovida i hodnota -1 v tomto kroku */
	fscanf(vstupni_file, "%d", &max_cifra);											//precte hodnotu cisla (odpovida maximalni cifre) a ulozi do promenne max_cifra
	printf("Maximalni cifra: %d\n", max_cifra);										//kontrolni vypis hodnoty maximalni cifry na konzoli
	
	//zjistime hodnotu dimenze n a vyuzijeme pro potrebnou alokaci pameti      
	fseek(vstupni_file, 0, SEEK_SET); 												//najede na zacatek souboru
	fgets(text, TEXT_LINE_MAX, vstupni_file);										//vynecha cely radek, kolik pameti potrebuje a kolik ma vynechat je definovano promennymi
	fscanf(vstupni_file, "%d", &n);													//nacte hodnotu dimenze
	printf("Dimenze: %d\n", n);														//kontrolni vypis hodnoty dimenze na konzoli
	
	//alokace pameti pro matice
	matice_a  = (int*)malloc(n * n * sizeof(int));							
	matice_b  = (int*)malloc(n * n * sizeof(int));
	soucet_ab = (int*)malloc(n * n * sizeof(int));
	
	//alokace pameti pro maximalni radek souboru
	max_radek = (max_cifra + 1) * n * n * sizeof(char);								//prvne musime zjistit maximalni velikost radku, ve kterem se nachazi matice ulozena jako string
	misto_pro_matici = (char*)malloc(max_radek);									//alokace pameti pro matici ulozenou jako pole znaku
	
	//zjisteni prvku matice a ulozeni do promenne matice_a  
	//1.krok - nacteni ze souboru	
	fgets(text, TEXT_LINE_MAX, vstupni_file);										//navazuje na posledni ukazatel v souboru a pokracuje preskakovanim dalsich radku az k nasi pozadovane hodnote
	fgets(text, TEXT_LINE_MAX, vstupni_file);
	fgets(misto_pro_matici, max_radek, vstupni_file);								//jsme na radku matice
	printf("Puvodni matice A jako text: %s", misto_pro_matici);						//kontrolni vypis radku, stale se jedna o pole znaku	
	
	//2.krok - prevedeni na integer a ulozeni do promenne matice_a
	printf("Puvodni matice A jako pole integeru: ");								//zapis na konzoli
	preskoc_znaky = 0;																//inicializace promenne, kterou vyuzijeme pro preskakovani znaku po nacteni
	for(j=0;j<n*n;j++) {
		matice_a[j] = atoi(misto_pro_matici + preskoc_znaky);						//postupny prevod z pole znaku a ukladani do matice_a
		preskoc_znaky += pocet_cifer(matice_a[j]) + sizeof('\t');					//preskakovani znaku
		printf("%d\t", matice_a[j]);												//kontrolni vypis na konzoli
	}
	
	//zjisteni prvku matice a ulozeni do promenne matice_b  						//analogie s matici A	
	//1.krok - nacteni ze souboru
	fgets(text, TEXT_LINE_MAX, vstupni_file);
	fgets(misto_pro_matici, max_radek, vstupni_file);								  					
	printf("\nPuvodni matice B jako text: %s", misto_pro_matici);										
	
	//2.krok - prevedeni na integer a ulozeni do promenne matice_b
	printf("Puvodni matice B jako pole integeru: ");
	preskoc_znaky = 0;
	for(j=0;j<n*n;j++) {
		matice_b[j] = atoi(misto_pro_matici + preskoc_znaky);
		preskoc_znaky += pocet_cifer(matice_b[j]) + sizeof('\t');	
		printf("%d\t", matice_b[j]);	
	}
	
	//zjisteni prvku matice a ulozeni do promenne soucet_ab  						//analogie s matici A
	//1.krok - nacteni ze souboru
	fgets(text, TEXT_LINE_MAX, vstupni_file);
	fgets(misto_pro_matici, max_radek, vstupni_file);								  					
	printf("\nPuvodni soucet AB jako text: %s", misto_pro_matici);											
	
	//2.krok - prevedeni na integer a ulozeni do promenne soucet_ab
	printf("Puvodni soucet AB jako pole integeru: ");
	preskoc_znaky = 0;
	for(j=0;j<n*n;j++) {
		soucet_ab[j] = atoi(misto_pro_matici + preskoc_znaky);
		preskoc_znaky += pocet_cifer(soucet_ab[j]) + sizeof('\t');	
		printf("%d\t", soucet_ab[j]);	
	}
	
	free(misto_pro_matici);															//uvolneni pameti pro promenne, ktere jiz nebudeme vyuzivat
	fclose(vstupni_file);															//zavreni vstupniho filu
	
	/*VYPOCET EUKLIDOVSKE NORMY PRO JEDNOTLIVE MATICE SE ZOBRAZENI NA KONZOLI A ZAPIS DO SOUBORU*/
	printf("\n\nVYSLEDKY:\n");														//vytvoreni hlavicky do konzole
	fprintf(vystupni_file,"VYSLEDKY:\n"); 											//vytvoreni hlavicky do souboru
	
	//Euklidovska norma pro matici A
	double e_norma_A = vypocet_e_normy(matice_a, n);								//vlozeni parametru do funkce definovane na zacatku souboru
	free(matice_a);																	//uvolneni pameti pro matice_a
	printf("Euklidovska norma A: %lf", e_norma_A);  								//zapis hodnoty euklidovske normy na konzoli
	fprintf(vystupni_file,"Euklidovská norma matice A: %lf", e_norma_A); 			//zapis hodnoty euklidovske normy do souboru
	
	//Euklidovska norma pro matici B												//analogie s A
	double e_norma_B = vypocet_e_normy(matice_b, n);
	free(matice_b);																	
	printf("\nEuklidovska norma B: %lf", e_norma_B);  
	fprintf(vystupni_file,"\nEuklidovská norma matice B: %lf", e_norma_B); 
	
	//Euklidovska norma pro soucet matic A a B										//analogie s A
	double e_norma_soucetAB = vypocet_e_normy(soucet_ab, n);
	free(soucet_ab);																
	printf("\nEuklidovska norma pro soucet AB: %lf", e_norma_soucetAB);  
	fprintf(vystupni_file,"\nEuklidovská norma pro soucet matic AB: %lf", e_norma_soucetAB); 
	
	/*OTESTOVANI PLATNOSTI: e_norma_soucetAB je mensi nebo rovna e_norma_A + e_norma_B*/
	printf("\n\nZAVER:\n");															//vytvoreni hlavicky do konzole
	fprintf(vystupni_file,"\n\nZAVER:\n");											//vytvoreni hlavicky do souboru
	
	if (e_norma_soucetAB > (e_norma_A + e_norma_B)) {								//otestovani platnosti zadaneho vyroku, zapis na konzoli a do souboru
		printf("Napsala jsem program spatne! :(");
		fprintf(vystupni_file, "Autorka udelala v programu chybu!:(");
		}
	else{
		printf("Euklidovska norma souctu obou matic je mensi nebo rovna souctu jendotlivych euklidovych norem!:)");
		fprintf(vystupni_file, "Euklidovska norma souctu obou matic je mensi nebo rovna souctu jendotlivych euklidovych norem!");
		}
	fclose(vystupni_file);															//zavreni souboru s vystupnimi daty
	
	return 0;
}
