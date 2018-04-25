package logika;

/**
 *  Třída implementující toto rozhraní bude ve hře zpracovávat jeden konkrétní příkaz.
 *  Toto rozhraní je součástí jednoduché textové hry.
 *  
 *@author     Jarmila Pavlickova, Michaela Duranova
 *@version    brezen 2018
 *  
 */
interface IPrikaz {
	
	/**
     *  Metoda pro provedení příkazu ve hře.
     *  Počet parametrů je závislý na konkrétním příkazu,
     *  např. příkazy konec a napoveda nemají parametry
     *  příkazy jdi má jeden parametr
     *  
     *  
     *  @param parametry počet parametrů závisí na konkrétním příkazu.
     *  
     */
    public String provedPrikaz(String... parametry);
    
    /**
     *  Metoda vrací název příkazu (slovo které používá hráč pro jeho vyvolání)
     *  
     *  @return nazev prikazu
     */
	public String getNazev();
	
}
