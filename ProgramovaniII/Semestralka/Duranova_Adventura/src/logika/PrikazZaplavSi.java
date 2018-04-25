/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy PrikazZaplavSi představují ...
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */

    class PrikazZaplavSi implements IPrikaz {
    private static final String NAZEV = "zaplavSi";
    private HerniPlan plan;
  
    /**
    *  Konstruktor třídy
    *  
    * 
    */     

    public PrikazZaplavSi(HerniPlan plan) {
        this.plan = plan;
    }
    
    /**
     *  Provádí příkaz "zaplavSi". Zkouší se si zaplavat v zadaném prostoru. Pokud prostor
     *  je jiný než rybník uživateli se objeví chybová hláška, že zde se nedá koupat. Pokud aktuální prostor
     *  je prostor rybník pejsek si zaplave.
     *
     
     *@return zpráva, kterou vypíše hra hráči
     */ 
   

    @Override
    public String provedPrikaz(String... parametry) {

        Prostor misto = plan.getAktualniProstor();
        

         if (misto.getNazev().equals("rybnik")) {
            
            // doplnit: Pes.(vec);
         
            return "To bylo osvěžení!";
        }
        
        else {
         
            return "Není tu žádná voda, v které by sis mohl zaplavat";
        }
     }   
   
    
    public String getNazev() {
        return NAZEV;
    }
}

