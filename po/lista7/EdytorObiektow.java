/*
 * Katrzyna Trzos
 * Lista 7  
 */

import javax.swing.*;
import java.io.IOException;

public class EdytorObiektow {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Użycie: java EdytorObiektow <nazwa pliku> <nazwa klasy>");
            return;
        }

        String nazwaPliku = args[0];
        String nazwaKlasy = args[1];

        try {
            Object obj = Ksiazka.odczytajZPliku(nazwaPliku);

            if (obj != null && obj.getClass().getName().equals(nazwaKlasy)) {
          
                KsiazkaPanel panel = new KsiazkaPanel();
                panel.setKsiazka((Ksiazka) obj);

                int result = JOptionPane.showConfirmDialog(null, panel, "Edytuj obiekt",
                        JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

                if (result == JOptionPane.OK_OPTION) {
                    ((Ksiazka) obj).setTytul(panel.getKsiazka().getTytul());
                    ((Ksiazka) obj).setAutor(panel.getKsiazka().getAutor());
                    ((Ksiazka) obj).setLiczbaStron(panel.getKsiazka().getLiczbaStron());
                    ((Ksiazka) obj).zapiszDoPliku(nazwaPliku);
                }
            } else {
                Ksiazka ksiazka = new Ksiazka("", "", 0);
                ksiazka.zapiszDoPliku(nazwaPliku);
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
