
/**
 * @author Félix-Olivier Latulippe
 * @DA 2173242
 * @session HV2022
 * 
 * Ce fichier contient le frame de modification de l'inventaire
 */
import javax.swing.*;
import java.awt.*;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.Date;

import com.toedter.calendar.JDateChooser;

public class ViewModifInv {
    JDialog dialog;
    JLabel labNom, labNumSerie, labCategorie, labPrix, labDate, labDescription;
    JTextField txfNom, txfNumSerie, txfPrix;
    JTextArea txaDescription;
    JButton btnModif, btnCancel;
    JDateChooser dateChooser;
    JComboBox cmbCategorie;
    JPanel panCenter, panBtn;

    String[] categories = { "Jeux", "Cameras", "Tripod", "Autres" }; // Les catégories disponibles
    Dimension dimTf = new Dimension(250, 25); // Dimension textfield et textarea
    Dimension dimLab = new Dimension(100, 25); // Dimension labels
    Dimension dimBtn = new Dimension(100, 25); // Dimension boutons

    private int selectedRow = ViewInv.tabInv.getSelectedRow(); // Ligne sélectionner tableau inventaire

    public ViewModifInv() {
        // DIALOG
        dialog = new JDialog((JDialog) null, "Modification inventaire", true);
        dialog.setTitle("Modifier");
        dialog.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        dialog.setSize(400, 525);
        dialog.setLocationRelativeTo(null);
        dialog.setLayout(new BorderLayout());
        dialog.setResizable(false);

        // LABEL
        labNom = new JLabel("*Nom:");
        labNom.setPreferredSize(dimLab);
        labNumSerie = new JLabel("No série:");
        labNumSerie.setPreferredSize(dimLab);
        labCategorie = new JLabel("Catégorie:");
        labCategorie.setPreferredSize(dimLab);
        labPrix = new JLabel("*Prix:");
        labPrix.setPreferredSize(dimLab);
        labDate = new JLabel("*Date achat:");
        labDate.setPreferredSize(dimLab);
        labDescription = new JLabel("Description:");
        labDescription.setPreferredSize(dimLab);

        // TEXTFIELD
        String nom = ViewInv.listInventaire.get(selectedRow).getNom(); // Nom objet
        String noSerie = String.valueOf(ViewInv.listInventaire.get(selectedRow).getNumSerie()); // numéro série objet
        String prix = String.valueOf(ViewInv.listInventaire.get(selectedRow).getPrix()); // Prix objet

        if (noSerie.equals("null"))
            noSerie = "";

        txfNom = new JTextField(nom);
        txfNom.setPreferredSize(dimTf);
        txfNumSerie = new JTextField(noSerie);
        txfNumSerie.setPreferredSize(dimTf);
        txfPrix = new JTextField(prix);
        txfPrix.setPreferredSize(dimTf);

        // COMBOBOX
        String categorie = ViewInv.listInventaire.get(selectedRow).getCategorie(); // Catégorie objet
        cmbCategorie = new JComboBox(categories);
        cmbCategorie.setSelectedItem(categorie);
        cmbCategorie.setPreferredSize(dimTf);

        // DATE CHOOSER
        LocalDate dateRaw = ViewInv.listInventaire.get(selectedRow).getDateAchat(); // Date complète
        Date date = Date.from(dateRaw.atStartOfDay(ZoneId.systemDefault()).toInstant()); // Date raffinée et au bon
                                                                                         // format

        dateChooser = new JDateChooser(date);
        dateChooser.setPreferredSize(dimTf);

        // TEXTAREA
        String description = ViewInv.listInventaire.get(selectedRow).getDescription(); // Description objet
        txaDescription = new JTextArea(description);
        txaDescription.setPreferredSize(new Dimension(250, 250));

        // BOUTONS
        btnModif = new JButton("Modifier");
        btnModif.setPreferredSize(dimBtn);
        btnModif.addActionListener(e -> btnModifAction());

        btnCancel = new JButton("Annuler");
        btnCancel.setPreferredSize(dimBtn);
        btnCancel.addActionListener(e -> btnCancelAction());

        // PANEL
        panCenter = new JPanel();
        panCenter.setLayout(new FlowLayout(0, 15, 15));
        panCenter.add(labNom);
        panCenter.add(txfNom);
        panCenter.add(labNumSerie);
        panCenter.add(txfNumSerie);
        panCenter.add(labCategorie);
        panCenter.add(cmbCategorie);
        panCenter.add(labPrix);
        panCenter.add(txfPrix);
        panCenter.add(labDate);
        panCenter.add(dateChooser);
        panCenter.add(labDescription);
        panCenter.add(txaDescription);

        panBtn = new JPanel();
        panBtn.add(btnModif);
        panBtn.add(btnCancel);

        // DIALOG
        dialog.add(panCenter, BorderLayout.CENTER);
        dialog.add(panBtn, BorderLayout.SOUTH);
        dialog.setVisible(true);
    }

    /**
     * Bouton qui sert à modifier un objet dans l'inventaire
     */
    private void btnModifAction() {
        try {
            if (isValide()) {
                try {
                    String nom = txfNom.getText(); // Nom objet
                    String description = txaDescription.getText(); // Description objet
                    String categorie = cmbCategorie.getSelectedItem().toString(); // Catégorie objet
                    String noSerie = txfNumSerie.getText(); // Numéro série objet
                    double prix = Double.parseDouble(txfPrix.getText()); // Prix objet
                    Date dateRaw = dateChooser.getDate(); // Date complète objet
                    LocalDate date = dateRaw.toInstant().atZone(ZoneId.systemDefault()).toLocalDate(); // Date raffinée
                                                                                                       // et au bon
                                                                                                       // format

                    Inventaire item = ViewInv.listInventaire.get(selectedRow);

                    item.setNom(nom);

                    if (!(description.equals("null")))
                        item.setDescription(description);

                    item.setCategorie(categorie);

                    if (!(noSerie.equals("null")))
                        item.setNumSerie(noSerie);

                    item.setPrix(prix);
                    item.setDateAchat(date);

                    dialog.dispose();
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(dialog, "Erreur de donnée");
                }
            } else {
                JOptionPane.showMessageDialog(dialog, "Donnée(s) manquante(s)");
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(dialog, "Donnée(s) manquante(s)");
        }
    }

    /**
     * Fonction qui permet de vérifier si tout les champs requis sont remplis
     * 
     * @return Retourne true si valide, false si non
     */
    private boolean isValide() {
        String nom = txfNom.getText(); // Nom objet
        String prix = txfPrix.getText(); // Prix objet
        Date date = dateChooser.getDate(); // Date objet

        if (!(nom.equals("") || prix.equals("") || date.equals("") || Double.parseDouble(prix) < 0)) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Bouton qui annule l'opération
     */
    private void btnCancelAction() {
        dialog.dispose();
    }

    public static void main(String[] args) {
        new ViewModifInv();
    }
}
