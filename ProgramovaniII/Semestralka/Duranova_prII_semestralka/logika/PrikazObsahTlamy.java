/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy PrikazObsahTlamy
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */
public class PrikazObsahTlamy implements IPrikaz
{
    //== Datové atributy (statické i instancí)======================================
     private static final String NAZEV = "obsahTlamy";
      private Tlama tlama;

    //== Konstruktory a tovární metody =============================================

    /***************************************************************************
     *  Konstruktor ....
     */
    public PrikazObsahTlamy(Tlama tlama)
    {
        this.tlama = tlama;
    }

    //== Nesoukromé metody (instancí i třídy) ======================================
    public String provedPrikaz(String... parametry) {
        
        
	     
            return tlama.nazvyVeci();
	
	}
   
    public String getNazev() {
        return NAZEV;
    }


    //== Soukromé metody (instancí i třídy) ========================================

}
