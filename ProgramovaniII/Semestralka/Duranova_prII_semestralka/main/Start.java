/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */
package main;



import logika.*;
import uiText.TextoveRozhrani;

/*******************************************************************************
 * Třída  Start je hlavní třídou projektu,
 * který představuje jednoduchou textovou adventuru
 *
 * @author    Jarmila Pavlíčková, Michaela Duranova
 * @version   brezen 2018
 */
public class Start
{
    /***************************************************************************
     * Metoda, prostřednictvím níž se spouští celá aplikace.
     *
     * @param args Parametry příkazového řádku
     */
    public static void main(String[] args)
    {
        
        IHra hra = new Hra();
        TextoveRozhrani ui = new TextoveRozhrani(hra);
        ui.hraj();
    }
}
