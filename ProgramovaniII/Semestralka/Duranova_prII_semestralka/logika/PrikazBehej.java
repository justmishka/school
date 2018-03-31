/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy PrikazBehej představují ...
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */

    class PrikazBehej implements IPrikaz {
    private static final String NAZEV = "behej";
    private HerniPlan plan;
  
    /**
    *  Konstruktor třídy
    *  
    * 
    */     

    public PrikazBehej(HerniPlan plan) {
        this.plan = plan;
    }
    
    /**
     *  Provádí příkaz "behej". Zkouší běhat v zadaném prostoru. Pokud prostor
     *  je jiný než les, park_vstup,louka uživateli se objeví chybová hláška, že zde se nesmí. Pokud aktuální prostor
     *  je prostor les nebo louka pejsek se vyvenčí.
     *
     
     *@return zpráva, kterou vypíše hra hráči
     */ 
   

    @Override
    public String provedPrikaz(String... parametry) {

        Prostor misto = plan.getAktualniProstor();
        

         if ( misto.getNazev().equals("les") || misto.getNazev().equals("louka") || misto.getNazev().equals("park_vstup")) {
            
            // doplnit: Pes.();
         
            return "No to byla paráda!";
        }
        
        else {
         
            return "Tady nesmíš běhat!";
        }
     }   
   
    
    public String getNazev() {
        return NAZEV;
    }
}

