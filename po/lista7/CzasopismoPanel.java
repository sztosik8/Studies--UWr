/*
 * Katrzyna Trzos
 * Lista 7  
 */
import javax.swing.*;

public class CzasopismoPanel extends KsiazkaPanel {
    private JTextField wydawcaField;

    public CzasopismoPanel() {
        super();
        add(new JLabel("Wydawca:"));
        wydawcaField = new JTextField();
        add(wydawcaField);
    }

    public void setCzasopismo(Czasopismo czasopismo) {
        super.setKsiazka(czasopismo);
        wydawcaField.setText(czasopismo.getWydawca());
    }

    public Czasopismo getCzasopismo() {
        return new Czasopismo(super.getKsiazka().getTytul(),
                super.getKsiazka().getAutor(),
                super.getKsiazka().getLiczbaStron(),
                wydawcaField.getText());
    }
}
