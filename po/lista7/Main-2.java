/*
 * Katrzyna Trzos
 * Lista 7  
 */

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException, IOException {
        Ksiazka ksiazka = new Ksiazka("Pan Tadeusz", "Adam Mickiewicz", 326);
        ksiazka.zapiszDoPliku("pan-tadeusz.ser");

        Ksiazka odczytanaKsiazka = Ksiazka.odczytajZPliku("pan-tadeusz.ser");
        System.out.println(odczytanaKsiazka);
    }

}
