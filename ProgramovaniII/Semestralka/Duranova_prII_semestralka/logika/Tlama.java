/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package logika;
import java.util.Map;
import java.util.HashMap;

/*******************************************************************************
 * Instance třídy Tlama představují ...
 *
 * @author    Michaela Duranova
 * @version   brezen 2018
 */
public class Tlama
{
    //== Datové atributy (statické i instancí)======================================
    private int kapacita = 3;
    private Map<String, Vec> seznamVeci ;

    //== Konstruktory a tovární metody =============================================

    /***************************************************************************
     *  Konstruktor ....
     */
    public Tlama(int kapacita)
    {
        this.kapacita = kapacita;
        seznamVeci = new HashMap<>();
    }

    //== Nesoukromé metody (instancí i třídy) ======================================
    public int getKapacita() {
        return kapacita;
    }

    /*
    public void setKapacita(int kapacita) {
        this.kapacita = kapacita;

    }
    */

    public boolean vlozVec(Vec vec) {
        if (seznamVeci.keySet().size() < this.getKapacita()) {
            seznamVeci.put(vec.getJmeno(),vec);
            return true;
        }
        else {
            return false;
        }        
    }

    public String nazvyVeci() {
        String nazvy = "veci: ";
        for (String jmenoVeci : seznamVeci.keySet()){
            nazvy += jmenoVeci + " ";
        }
        return nazvy;
    }

    public boolean obsahujeVec(String vec) {
        return this.nazvyVeci().indexOf(vec) > -1;
    }

    /**
     * Vrací věc, která má jméno předané jako parametr 
     *
     * @param  jméno věci
     * @return věc
     */
    public Vec vyberVec (String jmeno) {
        Vec nalezenaVec = null;
        if (seznamVeci.containsKey(jmeno)) {
            nalezenaVec = seznamVeci.get(jmeno);

            seznamVeci.remove(jmeno);
        }
        return nalezenaVec;
    }

    //== Soukromé metody (instancí i třídy) ========================================
}
