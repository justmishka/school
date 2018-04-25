/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;



/*******************************************************************************
 * Instance třídy Vec představují ...
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */
public class Vec
{
    //== Datové atributy (statické i instancí)======================================
    private String jmeno;
	private boolean prenositelna;


    //== Konstruktory a tovární metody =============================================

    /***************************************************************************
     *  Konstruktor ....
     */
    public Vec()
    {
    }
    
    public Vec (String jmeno, boolean prenositelna) {
        this.jmeno = jmeno ;
        this. prenositelna = prenositelna ;
    }

    //== Nesoukromé metody (instancí i třídy) ======================================
    public String getJmeno () {
		return jmeno;
	}
	public boolean jePrenositelna() {
		return prenositelna;
	}



    //== Soukromé metody (instancí i třídy) ========================================

}
