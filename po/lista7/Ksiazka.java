/*
 * Katrzyna Trzos
 * Lista 7  
 */

import java.io.*;

public class Ksiazka implements Serializable {
    private String tytul;
    private String autor;
    private int liczbaStron;

    public Ksiazka(String tytul, String autor, int liczbaStron) {
        this.tytul = tytul;
        this.autor = autor;
        this.liczbaStron = liczbaStron;
    }

    public String getTytul() {
        return tytul;
    }

    public void setTytul(String tytul) {
        this.tytul = tytul;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getLiczbaStron() {
        return liczbaStron;
    }

    public void setLiczbaStron(int liczbaStron) {
        this.liczbaStron = liczbaStron;
    }

    @Override
    public String toString() {
        return "Książka: " + tytul + " (" + autor + "), " + liczbaStron + " stron";
    }

    // metoda zapisująca obiekt do pliku
    public void zapiszDoPliku(String nazwaPliku) throws IOException {
        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(nazwaPliku));
        out.writeObject(this);
        out.close();
    }

    // metoda odczytująca obiekt z pliku
    public static Ksiazka odczytajZPliku(String nazwaPliku) throws IOException, ClassNotFoundException {
        ObjectInputStream in = new ObjectInputStream(new FileInputStream(nazwaPliku));
        Ksiazka ksiazka = (Ksiazka) in.readObject();
        in.close();
        return ksiazka;
    }
}


class WydawnictwoCiagle extends Ksiazka {
  
    private int numer;

    public WydawnictwoCiagle(String tytul, String autor, int liczbaStron, int numer) {
        super(tytul, autor, liczbaStron);
        this.numer = numer;
    }

    public int getNumer() {
        return numer;
    }

    public void setNumer(int numer) {
        this.numer = numer;
    }

    @Override
    public String toString() {
        return "Wydawnictwo ciągłe: " + super.toString() + ", numer " + numer;
    }
}

class Czasopismo extends Ksiazka {
    private String wydawca;

    public Czasopismo(String tytul, String autor, int liczbaStron, String wydawca) {
        super(tytul, autor, liczbaStron);
        this.wydawca = wydawca;
    }

    public String getWydawca() {
        return wydawca;
    }

    public void setWydawca(String wydawca) {
        this.wydawca = wydawca;
    }

    @Override
    public String toString() {
        return "Czasopismo: " + super.toString() + ", wydawca " + wydawca;
    }
}

