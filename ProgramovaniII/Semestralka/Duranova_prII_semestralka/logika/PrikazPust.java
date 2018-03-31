/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy PrikazPust představují ...
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */
public class PrikazPust implements IPrikaz    {
    private static final String NAZEV = "pust";
    private Tlama Tlama;
    
    public PrikazPust(Tlama tlama) {
       
        this.Tlama = tlama;
    }
    public String provedPrikaz(String... parametry) {
        if (parametry.length == 0) {
            // pokud chybí druhé slovo , tak ....
            return "Co mám pustit? Musíš zadat jméno věci";
        }
        String jmenoVeci = parametry[0];
        // vybereme věc
        Vec vec = Tlama.vyberVec(jmenoVeci);
        if (vec == null) {
            return "Takovou věc v tlamě nemáš!/n";
        }
        else {            
            // pustíme věc z Tlamy
            	     
                return "Pustil si " + jmenoVeci;
            
            
            }
	    
        }
   
    public String getNazev() {
        return NAZEV;
    }
}

