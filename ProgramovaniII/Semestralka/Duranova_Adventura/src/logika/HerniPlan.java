package logika;

import java.util.HashSet;
import java.util.Set;

/**
 *  Class HerniPlan - třída představující mapu a stav adventury.
 * 
 *  Tato třída inicializuje prvky ze kterých se hra skládá:
 *  vytváří všechny prostory,
 *  propojuje je vzájemně pomocí východů 
 *  a pamatuje si aktuální prostor, ve kterém se hráč právě nachází.
 *
 *@author     Michael Kolling, Lubos Pavlicek, Jarmila Pavlickova, Michaela Duranova
 *@version    brezen 2018
 */
public class HerniPlan {

    private Prostor aktualniProstor;
    private Prostor viteznyProstor;

    private Set<IPrikaz> provedenePrikazy = new HashSet<IPrikaz>();
   
    /**
     *  Konstruktor který vytváří jednotlivé prostory a propojuje je pomocí východů.
     *  Jako výchozí aktuální prostor nastaví halu.
     */
    public HerniPlan() {
        zalozProstoryHry();

    }

    /**
     *  Vytváří jednotlivé prostory a propojuje je pomocí východů.
     *  Jako výchozí aktuální prostor nastaví domecek.
     */
    private void zalozProstoryHry() {

        // vytvářejí se jednotlivé prostory
        Prostor domecek = new Prostor("domecek","domeček, ve kterém bydlí pejsek");
        Prostor chodba = new Prostor("chodba", "chodba v domě");
        Prostor park_vstup = new Prostor("park","vstup do parku");
        Prostor les = new Prostor("les","les se stromy, klacky, keřy");
        Prostor rybnik = new Prostor("rybnik","rybník s kachnami");
        Prostor louka = new Prostor("louka","louka se zelenou trávou");

        // přiřazují se průchody mezi prostory (sousedící prostory)
        domecek.setVychod(chodba);

        chodba.setVychod(domecek);
        chodba.setVychod(park_vstup);

        park_vstup.setVychod(chodba);
        park_vstup.setVychod(rybnik);
        park_vstup.setVychod(louka);

        rybnik.setVychod(park_vstup);
        rybnik.setVychod(les);
        rybnik.setVychod(louka);
        
        les.setVychod(rybnik);
        les.setVychod(louka);

        louka.setVychod(park_vstup);
        louka.setVychod(rybnik);
        louka.setVychod(les);
        
        
        // vložení věcí do prostoru
        domecek.vlozVec(new Vec("hracka", true));
        domecek.vlozVec(new Vec("jidlo", false));
        
        chodba.vlozVec(new Vec("odpadky", false));

        park_vstup.vlozVec(new Vec("klacek", true));

        rybnik.vlozVec(new Vec("kachna", false));
        rybnik.vlozVec(new Vec("balonek", true));

        les.vlozVec(new Vec("klacek", true));

        louka.vlozVec(new Vec("piknik", false));
        louka.vlozVec(new Vec("tenisak", true));
        

        //nastaveni defaultniho a vitezneho prostoru
        aktualniProstor = domecek;  // hra začíná v domečku      
        this.setViteznyProstor(domecek);    // hra konci v domecku + zaroven pro uspesny konec musi byt naplneny parametry postavy
    }

    /**
     *  Metoda vrací odkaz na aktuální prostor, ve ktetém se hráč právě nachází.
     *
     *@return     aktuální prostor
     */

    public Prostor getAktualniProstor() {
        return aktualniProstor;
    }

    /**
     *  Metoda nastaví aktuální prostor, používá se nejčastěji při přechodu mezi prostory
     *
     *@param  prostor nový aktuální prostor
     */
    public void setAktualniProstor(Prostor prostor) {
        aktualniProstor = prostor;
    }

    /**
     *  Metoda vrací odkaz na vitezny prostor, ve ktetém se hráč právě nachází.
     *
     *@return     vitezny prostor
     */

    public Prostor getViteznyProstor() {
        return viteznyProstor;
    }

    /**
     *  Metoda nastaví vitezny prostor, 
     *
     *@param  prostor nový vitezny prostor
     */
    public void setViteznyProstor(Prostor prostor) {
        viteznyProstor = prostor;
    }

    public void ulozPrikaz(IPrikaz prikaz) {
        this.provedenePrikazy.add(prikaz);
    }    
    
    public boolean jeVseSplneno() {
        return this.splneno("aportuj") && this.splneno("behej") && this.splneno("vyvenciSe") && this.splneno("zaplavSi");
    }
    
    private boolean splneno(String prikaz) {
        for (IPrikaz p : this.provedenePrikazy) {
            if (p.getNazev().equals(prikaz)) {
                return true;
            }
        }
        return false;
    }

}
