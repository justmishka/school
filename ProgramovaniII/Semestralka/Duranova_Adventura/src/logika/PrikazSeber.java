/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy PrikazSeber představují ...
 *
 * @author    Michaela Duranova
 * @version   duben 2018
 */
public class PrikazSeber implements IPrikaz    {
    private static final String NAZEV = "seber";
    private HerniPlan plan;
    private Tlama tlama;
    
    public PrikazSeber(HerniPlan plan, Tlama tlama) {
        this.plan = plan;
        this.tlama = tlama;
    }
    public String provedPrikaz(String... parametry) {
        if (parametry.length == 0) {
            // pokud chybí druhé slovo , tak ....
            return "Co mám sebrat? Musíš zadat jméno věci";
        }
        String jmenoVeci = parametry[0];
        // vybereme věc
        Vec vec = plan.getAktualniProstor().vyberVec(jmenoVeci);
        if (vec == null) {
            return "Taková věc tu není a nebo ji nesmíš vzít";
        }
        else {            
            // uložíme věc do Tlamy
            if (tlama.vlozVec(vec) == true) {	     
                return "Sebral jsi " + jmenoVeci;
            }
            else {
                plan.getAktualniProstor().vlozVec(vec);
                return "Nemas misto v tlame";
            }
	    }
	}
   
    public String getNazev() {
        return NAZEV;
    }
}

