/*
 * Katrzyna Trzos
 * Lista 7  
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KsiazkaPanel extends JPanel {
    private JTextField tytulField, autorField, liczbaStronField;

    public KsiazkaPanel() {

        setLayout(new GridLayout(3, 2));

        add(new JLabel("Tytuł:"));
        tytulField = new JTextField();
        add(tytulField);

        add(new JLabel("Autor:"));
        autorField = new JTextField();
        add(autorField);

        add(new JLabel("Liczba stron:"));
        liczbaStronField = new JTextField();
        add(liczbaStronField);
    }

    public void setKsiazka(Ksiazka ksiazka) {
        tytulField.setText(ksiazka.getTytul());
        autorField.setText(ksiazka.getAutor());
        liczbaStronField.setText(Integer.toString(ksiazka.getLiczbaStron()));
    }

    public Ksiazka getKsiazka() {
        return new Ksiazka(tytulField.getText(), autorField.getText(), Integer.parseInt(liczbaStronField.getText()));
    }
}

