/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy PrikazAportuj představují ...
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */

    public class PrikazAportuj implements IPrikaz {
        
    private static final String NAZEV = "aportuj";
    private Tlama tlama;
  
    /**
    *  Konstruktor třídy
    *  
    * 
    */     

    public PrikazAportuj(Tlama tlama) {
        this.tlama = tlama;
    }
    
    /**
     *  Provádí příkaz "aportuj". Zkouší aportovat a tím zvýšit zábavu pro pejska.
     *  Na provádění aportu musí mít pejsek v tlamě některou z těchto věcí: hracka, klacek, balonek, tenisak
     *  V jiném případě se vrátí chybová hláška, že není s čím si aportovat
     *
     
     *@return zpráva, kterou vypíše hra hráči
     */
    @Override

    public String provedPrikaz(String... parametry) {
             
        
        if (tlama.obsahujeVec("hracka") || tlama.obsahujeVec("micek") || tlama.obsahujeVec("klacek") || tlama.obsahujeVec("balonek")) {
                return "Ty jsi šikulka!";
        }        
        else {
         
            return "Nemáš nic, s čím by se dalo házet.";
        }
     }   
   
    
    public String getNazev() {
        return NAZEV;
    }
}

