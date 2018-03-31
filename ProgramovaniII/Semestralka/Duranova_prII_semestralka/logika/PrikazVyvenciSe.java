/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy PrikazVyvenciSe představují ...
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */

    class PrikazVyvenciSe implements IPrikaz {
    private static final String NAZEV = "vyvenciSe";
    private HerniPlan plan;
  
    /**
    *  Konstruktor třídy
    *  
    * 
    */     

    public PrikazVyvenciSe(HerniPlan plan) {
        this.plan = plan;
    }
    
    /**
     *  Provádí příkaz "vyvenciSe". Zkouší se vyvenčit v zadaném prostoru. Pokud prostor
     *  je jiný než les nebo louka uživateli se objeví chybová hláška, že zde se nesmí. Pokud aktuální prostor
     *  je prostor les nebo louka pejsek se vyvenčí.
     *
     
     *@return zpráva, kterou vypíše hra hráči
     */ 
   

    @Override
    public String provedPrikaz(String... parametry) {

        Prostor misto = plan.getAktualniProstor();
        

         if ( misto.getNazev().equals("les") || misto.getNazev().equals("louka")) {
            
            // doplnit: Pes.(vec);
         
            return "Uff, to je lepší!";
        }
        
        else {
         
            return "Fuj, tady nesmíš!";
        }
     }   
   
    
    public String getNazev() {
        return NAZEV;
    }
}

