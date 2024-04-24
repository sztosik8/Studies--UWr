/*
 * Katrzyna Trzos
 * Lista 7  
 */

import javax.swing.*;

public class WydawnictwoCiaglePanel extends KsiazkaPanel {
    private JTextField numerField;

    public WydawnictwoCiaglePanel() {
        super();
        add(new JLabel("Numer:"));
        numerField = new JTextField();
        add(numerField);
    }

    public void setWydawnictwoCiagle(WydawnictwoCiagle wydawnictwo) {
        super.setKsiazka(wydawnictwo);
        numerField.setText(Integer.toString(wydawnictwo.getNumer()));
    }

    public WydawnictwoCiagle getWydawnictwoCiagle() {
        return new WydawnictwoCiagle(super.getKsiazka().getTytul(),
                super.getKsiazka().getAutor(),
                super.getKsiazka().getLiczbaStron(),
                Integer.parseInt(numerField.getText()));
    }
}
