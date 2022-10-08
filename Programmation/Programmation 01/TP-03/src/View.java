import javax.swing.*;
import java.awt.*;

/**
 * Auteur : Félix-Olivier Latulippe
 * DA : 2173242
 * Session A2021
 */

public class View extends JFrame {
    JFrame frame;
    JPanel panNorth;
    JPanel panEast;
    JPanel panSouth;
    JPanel panCenter;
    JButton btnRecherche, btnExtraireMots, btnViderMots, btnExtraireNb, btnViderNb,
            btnTriMots, btnTriNb, btnInfoMots, btnInfoNb, btnExit;
    JTextArea txaText, txaMots, txaNb;
    JTextField txfZoneRecherche;
    JCheckBox chbDoublons;
    JRadioButton radTriCrois, radTriDecrois;
    JLabel labFouille, labNbMots, labNbNb, labResultMots, labResultNb;
    ButtonGroup radGroup;
    JScrollPane scrText, scrMots, scrNb;

    Dimension btnDim = new Dimension(125, 30);
    Dimension labDim = new Dimension(50, 25);
    Dimension txfDim = new Dimension(125, 25);

    public View() {
        frame = new JFrame("TP3 Félix-Olivier Latulippe, 2173242");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(new Dimension(1500, 600));
        frame.setMinimumSize(new Dimension(500, 700));
        frame.setLocationRelativeTo(null);


        //------------Boutons-------------
        btnRecherche = new JButton("Recherche");
        btnRecherche.setPreferredSize(btnDim);
        btnRecherche.addActionListener(e -> btnRechercheAction());

        btnExtraireMots = new JButton("Extraire Mots");
        btnExtraireMots.setMaximumSize(btnDim);
        btnExtraireMots.addActionListener(e -> btnExtraireMotsAction());

        btnViderMots = new JButton("Vider Mots");
        btnViderMots.setMaximumSize(btnDim);
        btnViderMots.addActionListener(e -> btnViderMotsAction());

        btnExtraireNb = new JButton("Extraire Nombres");
        btnExtraireNb.setMaximumSize(btnDim);
        btnExtraireNb.addActionListener(e -> btnExtraireNbAction());

        btnViderNb = new JButton("Vider Nombres");
        btnViderNb.setMaximumSize(btnDim);
        btnViderNb.addActionListener(e -> btnViderNbAction());

        btnTriMots = new JButton("Trier Mots");
        btnTriMots.setMaximumSize(btnDim);
        btnTriMots.addActionListener(e -> btnTriMotsAction());

        btnTriNb = new JButton("Trier Nombres");
        btnTriNb.setMaximumSize(btnDim);
        btnTriNb.addActionListener(e -> btnTriNbAction());

        btnInfoMots = new JButton("Info Mots");
        btnInfoMots.setMaximumSize(btnDim);
        btnInfoMots.addActionListener(e -> btnInfoMotsAction());

        btnInfoNb = new JButton("Info Nombres");
        btnInfoNb.setMaximumSize(btnDim);
        btnInfoNb.addActionListener(e -> btnInfoNbAction());

        btnExit = new JButton("Quitter");
        btnExit.setMaximumSize(btnDim);
        btnExit.addActionListener(e -> btnExitAction());

        //------------Text area------------
        txaText = new JTextArea();
        txaText.setLineWrap(true);
        txaText.setWrapStyleWord(true);

        txaMots = new JTextArea();
        txaMots.setEditable(false);
        txaMots.setLineWrap(true);
        txaMots.setWrapStyleWord(true);

        txaNb = new JTextArea();
        txaNb.setEditable(false);
        txaNb.setLineWrap(true);
        txaNb.setWrapStyleWord(true);

        scrText = new JScrollPane(txaText);
        scrMots = new JScrollPane(txaMots);
        scrNb = new JScrollPane(txaNb);

        //------------Text field-----------
        txfZoneRecherche = new JTextField();
        txfZoneRecherche.setPreferredSize(txfDim);

        //------------Check box------------
        chbDoublons = new JCheckBox("Permettre doublons");
        chbDoublons.setSelected(true);

        //------------Radios---------------
        radTriCrois = new JRadioButton("Tri croissant");
        radTriCrois.setSelected(true);
        radTriDecrois = new JRadioButton("Tri decroissant");

        radGroup = new ButtonGroup();
        radGroup.add(radTriCrois);
        radGroup.add(radTriDecrois);

        //------------Label----------------
        labFouille = new JLabel();
        labNbMots = new JLabel("Mots: ");

        labResultMots = new JLabel("0");
        labResultMots.setPreferredSize(labDim);

        labNbNb = new JLabel("Nombres: ");

        labResultNb = new JLabel("0");
        labResultNb.setPreferredSize(labDim);

        //------------Panels-------------
        // North
        panNorth = new JPanel(new FlowLayout(FlowLayout.LEFT));
        panNorth.add(txfZoneRecherche);
        panNorth.add(btnRecherche);
        panNorth.add(labFouille);

        // East
        panEast = new JPanel();
        panEast.setLayout(new BoxLayout(panEast, BoxLayout.Y_AXIS));

        panEast.add(chbDoublons);
        panEast.add(btnExtraireMots);
        panEast.add(btnViderMots);
        panEast.add(Box.createRigidArea(new Dimension(5, 25)));

        panEast.add(btnExtraireNb);
        panEast.add(btnViderNb);
        panEast.add(Box.createRigidArea(new Dimension(5, 25)));

        panEast.add(radTriCrois);
        panEast.add(radTriDecrois);
        panEast.add(btnTriMots);
        panEast.add(btnTriNb);
        panEast.add(Box.createRigidArea(new Dimension(5, 25)));

        panEast.add(btnInfoMots);
        panEast.add(btnInfoNb);
        panEast.add(Box.createRigidArea(new Dimension(5, 15)));

        panEast.add(btnExit);

        // South
        panSouth = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panSouth.add(labNbMots);
        panSouth.add(labResultMots);
        panSouth.add(labNbNb);
        panSouth.add(labResultNb);

        // Center
        panCenter = new JPanel();
        panCenter.setLayout(new GridLayout(1, 3, 4, 4));
        panCenter.add(scrText);
        panCenter.add(scrMots);
        panCenter.add(scrNb);

        frame.add(panNorth, BorderLayout.NORTH);
        frame.add(panCenter, BorderLayout.CENTER);
        frame.add(panSouth, BorderLayout.SOUTH);
        frame.add(panEast, BorderLayout.EAST);

        frame.getRootPane().setDefaultButton(btnRecherche);
        frame.setVisible(true);
    }


    //--------------------Méthodes utilisateur--------------------

    // Boutons extraction et vider

    /**
     * Ce bouton sert à extraire les mots du premier text field area et les ajoutes à celui du milieu
     */
    private void btnExtraireMotsAction() {
        int compteur = 0; // Compteur de mots

        txaMots.setText("");
        try {
            if (chbDoublons.isSelected()) {
                String[] monTabTexte = extraireString(txaText.getText()); // texte extrait
                for (int i = 0; i < monTabTexte.length; i++) {
                    if (monTabTexte[i].equals("")) {
                        txaMots.append(monTabTexte[i]);
                    } else {
                        compteur++;
                        txaMots.append(monTabTexte[i] + "\n");
                    }
                }
            } else {
                String monTexteSansDoublons = txaText.getText().replaceAll("(\\b[a-zA-ZÀÇéàèçôî]+\\b)(?=[\\s\\S]*\\b\\1\\b)", "");  // texte sans doublons
                String[] monTabTexte = extraireString(monTexteSansDoublons); // texte extrait
                for (int i = 0; i < monTabTexte.length; i++) {
                    if (monTabTexte[i].equals("")) {
                        txaMots.append(monTabTexte[i]);
                    } else {
                        compteur++;
                        txaMots.append(monTabTexte[i] + "\n");
                    }
                }
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Une erreur est survenue!", "Message d'erreur", JOptionPane.PLAIN_MESSAGE);
        }
        labResultMots.setText(Integer.toString(compteur));
    }

    /**
     * Ce bouton sert à vider le text field area du milieu
     */
    private void btnViderMotsAction() {
        txaMots.setText("");
        labResultMots.setText("0");
    }

    /**
     * Ce bouton sert à extraire les nombres du premier text field area et les ajoutes au troisième
     */
    private void btnExtraireNbAction() {
        int compteur = 0; // compteur de mots

        txaNb.setText("");
        try {
            if (chbDoublons.isSelected()) {
                String[] monTabInt = txaText.getText().split("[^-?[0-9]\\d*(\\d+)?$]+"); // tableau d'entiers extrait
                for (int i = 0; i < monTabInt.length; i++) {
                    if (monTabInt[i].equals("")) {
                        txaNb.append(monTabInt[i]);
                    } else {
                        compteur++;
                        monTabInt[i] = monTabInt[i].replaceFirst("^0+(?!$)", "");
                        txaNb.append(monTabInt[i] + "\n");
                    }
                }
            } else {
                String monTabSansDoublons = txaText.getText().replaceAll("(\\b\\d+\\b)(?=[\\s\\S]*\\b\\1\\b)", ""); // texte sans doublons
                String[] monTabInt = monTabSansDoublons.split("[^-?[0-9]\\d*(\\d+)?$]+"); // tableau d'entiers extrait

                for (int i = 0; i < monTabInt.length; i++) {
                    if (monTabInt[i].equals("")) {
                        txaNb.append(monTabInt[i]);
                    } else {
                        monTabInt[i] = monTabInt[i].replaceFirst("^0+(?!$)", "");
                        compteur++;
                        txaNb.append(monTabInt[i] + "\n");
                    }
                }
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Une erreur est survenue!", "Message d'erreur", JOptionPane.PLAIN_MESSAGE);
        }
        labResultNb.setText(Integer.toString(compteur));
    }

    /**
     * Ce bouton sert à vider le troisième text field area
     */
    private void btnViderNbAction() {
        txaNb.setText("");
        labResultNb.setText("0");
    }

    //Boutons trier

    /**
     * Ce bouton sert à trier, de façon croissante ou décroissante, le troisième text field area
     */
    private void btnTriNbAction() {
        try {
            String[] monTabTriTemp = txaNb.getText().split("[^-?[0-9]\\d*(\\d+)?$]+"); // tableau d'entiers extraits
            int[] monTabTri = stringTableToIntTable(monTabTriTemp); // variable qui converti le tableau de string à entiers

            if (radTriCrois.isSelected()) {
                txaNb.setText("");
                triSSSUpInt(monTabTri);

                for (int i = 0; i < monTabTri.length; i++) {
                    if (Integer.toString(monTabTri[i]) != "")
                        txaNb.append(Integer.toString(monTabTri[i]) + "\n");
                }
            } else {
                txaNb.setText("");
                triSSSDownInt(monTabTri);
                for (int i = 0; i < monTabTri.length; i++)
                    if (Integer.toString(monTabTri[i]) != "")
                        txaNb.append(Integer.toString(monTabTri[i]) + "\n");
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Une erreur est survenue!", "Message d'erreur", JOptionPane.PLAIN_MESSAGE);
        }
    }

    /**
     * Ce bouton sert à trier, de façon croissante ou décroissante, le deuxième text field area
     */
    private void btnTriMotsAction() {
        String[] monTabTexte = extraireString(txaMots.getText()); // tableau d'entiers extrait

        txaMots.setText("");

        try {
            if (radTriCrois.isSelected()) {
                txaMots.setText("");
                triSSSUpString(monTabTexte);
                for (int i = 0; i < monTabTexte.length; i++) {
                    if (monTabTexte[i] != "")
                        txaMots.append(monTabTexte[i] + "\n");
                }
            } else {
                txaMots.setText("");
                triSSSDownString(monTabTexte);
                for (int i = 0; i < monTabTexte.length; i++) {
                    if (monTabTexte[i] != "")
                        txaMots.append(monTabTexte[i] + "\n");
                }
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Une erreur est survenue!", "Message d'erreur", JOptionPane.PLAIN_MESSAGE);
        }
    }

    /**
     * Ce bouton sert à faire une recherche dans le premier text field area
     */
    private void btnRechercheAction() {
        String maRecherche = txfZoneRecherche.getText().trim(); // string rechercher
        String[] monTabRecherche = extraireString(txaMots.getText()); // mon texte a rechercher
        int[] indexTrouve = {}; // tableau d'index de la recherche
        int nbTrouve = 0; // nombre de mots trouvés

        try {
            for (int i = 0; i < monTabRecherche.length; i++) {
                if (monTabRecherche[i].trim().equalsIgnoreCase(maRecherche)) {
                    indexTrouve = addElemTab(indexTrouve, nextIndexOf(monTabRecherche, maRecherche, i));
                    nbTrouve++;
                }
            }

            if (nbTrouve == 0)
                labFouille.setText(nbTrouve + " mots trouvé");
            else if (nbTrouve == 1)
                labFouille.setText(nbTrouve + " mot trouvé à l'indice " + indexTrouve[0]);
            else
                labFouille.setText(nbTrouve + " mots trouvés aux indices " + printAllTab(indexTrouve));
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Une erreur est survenue!", "Message d'erreur", JOptionPane.PLAIN_MESSAGE);
        }
    }

    // Boutons infos

    /**
     * Ce bouton sert à afficher en Option Pane le mot le plus court ainsi que le mot le plus long
     */
    private void btnInfoMotsAction() {
        try {
            String[] monTabTexte = extraireString(txaMots.getText()); // tableau string extrait
            String motCourt = sShorter(monTabTexte); // mot le plus court
            String motLong = sLonger(monTabTexte); // mot le plus long

            JOptionPane.showMessageDialog(frame, "Mot le plus court: " + motCourt + "\nMot le plus long: " + motLong, "Info mots", JOptionPane.PLAIN_MESSAGE);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Mot le plus court: " + "\nMot le plus long: ", "Info mots", JOptionPane.PLAIN_MESSAGE);
        }
    }

    /**
     * Ce bouton sert à afficher en Option Pane le nombre le plus court ainsi que le nombre le plus long
     */
    private void btnInfoNbAction() {
        try {
            int[] monTabInt = extraireInt(txaNb.getText()); // tableau d'entiers extrait
            int nbPetit = min(monTabInt); // nombre le plus petit
            int nbGrand = max(monTabInt); // nombre le plus grand

            JOptionPane.showMessageDialog(frame, "Nombre le plus petit: " + nbPetit + "\nNombre le plus grand: " + nbGrand, "Info nombres", JOptionPane.PLAIN_MESSAGE);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Nombre le plus petit: " + "\nNombre le plus grand: ", "Info nombres", JOptionPane.PLAIN_MESSAGE);
        }
    }

    // Bouton quitter

    /**
     * Ce bouton sert à quitter le programme et nous fait une confirmation de fermeture
     */
    private void btnExitAction() {
        int rep = JOptionPane.showConfirmDialog(frame, "Voulez-vous vraiment quitter?", "Confirmation",
                JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE); // Option Pane pour confirmer la fermeture du programme
        if (rep == 0)
            System.exit(0);
    }

    //--------------------Méthodes utilitaires--------------------

    /**
     * Fonction qui permet d'extraire des mots d'un texte à l'aide d'un regex
     *
     * @param monTexte le texte à extraire
     * @return retourne un tableau de string
     */
    public static String[] extraireString(String monTexte) {
        String[] monTabTexte = monTexte.split("[^[a-zA-ZÀÇéàèçôî]]+"); // tableau de string extrait

        return monTabTexte;
    }

    /**
     * Fonction qui permet d'extraire d'un texte des entiers à l'aide d'un regex
     *
     * @param monTexte le texte à extraire les entiers
     * @return retourne un tableau d"entiers
     */
    public static int[] extraireInt(String monTexte) {
        String[] monTabTexte = monTexte.split(("[^-?[0-9]\\d*(\\d+)?$]+")); // tableau d'entiers extrait

        return stringTableToIntTable(monTabTexte);
    }

    /**
     * Permet de determiner l'index d'une string recherché à partir d'un tableau
     *
     * @param tableau    mon tableau
     * @param sRecherche la string recherché
     * @param index      l'index de départ
     * @return retourne l'index de la string recherché
     */
    public static int nextIndexOf(String[] tableau, String sRecherche, int index) {
        int i = index; // Index
        boolean trouve = false; // Boolean pour savoir si la fouille est trouvé

        while (!trouve && i < tableau.length) {
            if (sRecherche.equalsIgnoreCase(tableau[i].trim()))
                trouve = true;
            else
                i++;
        }

        if (trouve)
            return i;
        else
            return -1;
    }

    /**
     * Permet de permuter deux entiers
     *
     * @param tab  le tableau
     * @param ind1 entier un
     * @param ind2 entier deux
     */
    public static void permutationInt(int[] tab, int ind1, int ind2) {
        int transit = tab[ind1]; // variable de transit
        tab[ind1] = tab[ind2];
        tab[ind2] = transit;
    }

    /**
     * Fonction qui permet de trier, de façon croissante, un tableau de string avec la méthode SSS
     *
     * @param tableau le tableau choisi
     */
    public static void triSSSUpString(String[] tableau) {
        int imin; // Index minimum

        for (int i = 0; i < tableau.length - 1; i++) {
            imin = i;

            for (int j = i + 1; j < tableau.length; j++) {
                if (tableau[j].charAt(0) < tableau[imin].charAt(0))
                    imin = j;
            }

            if (imin != i) {
                String temp = tableau[i]; // variable temporaire pour le transit
                tableau[i] = tableau[imin];
                tableau[imin] = temp;
            }
        }
    }

    /**
     * Fonction qui permet de trier, de façon décroissante, un tableau de string avec la méthode SSS
     *
     * @param tableau le tableau de string
     */
    public static void triSSSDownString(String[] tableau) {
        int imin; // Index minimum

        for (int i = 0; i < tableau.length - 1; i++) {
            imin = i;

            for (int j = i + 1; j < tableau.length; j++) {
                if (tableau[j].charAt(0) > tableau[imin].charAt(0))
                    imin = j;
            }

            if (imin != i) {
                String temp = tableau[i];
                tableau[i] = tableau[imin];
                tableau[imin] = temp;
            }
        }
    }

    /**
     * Permet de faire un tri croissant d'entiers avec la méthode SSS
     *
     * @param tableau le tableau dont nous voulons trier
     */
    public static void triSSSUpInt(int[] tableau) {
        int imin; // Index minimum

        for (int i = 0; i < tableau.length - 1; i++) {
            imin = i;

            for (int j = i + 1; j < tableau.length; j++) {
                if (tableau[j] < tableau[imin])
                    imin = j;
            }

            if (imin != i)
                permutationInt(tableau, i, imin);
        }
    }

    /**
     * Permet de faire un tri décroissant d'entiers avec la méthode SSS
     *
     * @param tableau le tableau dont nous voulons trier
     */
    public static void triSSSDownInt(int[] tableau) {
        int imin; // Index minimum

        for (int i = 0; i < tableau.length - 1; i++) {
            imin = i;

            for (int j = i + 1; j < tableau.length; j++) {
                if (tableau[j] > tableau[imin])
                    imin = j;
            }

            if (imin != i)
                permutationInt(tableau, i, imin);
        }
    }

    /**
     * Permet d'avoir la valeur maximale d'un tableau d'entiers
     *
     * @param tab le tableau d'entiers
     * @return retourne la valeur maximale du tableau d'entiers
     */
    public static int max(int[] tab) {
        triSSSUpInt(tab);

        return tab[tab.length - 1];
    }

    /**
     * Permet d'avoir la valeur minimale d'un tableau d'entiers
     *
     * @param tab le tableau d'entiers
     * @return retourne la valeur minimale du tableau d'entiers
     */
    public static int min(int[] tab) {
        triSSSUpInt(tab);

        return tab[0];
    }

    /**
     * Fonction qui permet de transformer un tableau d'entiers en un tableau de string
     *
     * @param tableau tableau d'entiers choisi
     * @return retourne un tableau de string fait à partir du tableau d'entiers
     */
    public static int[] stringTableToIntTable(String[] tableau) {
        int[] result = new int[tableau.length]; // Tableau pour stocker les int transformé

        for (int i = 0; i < tableau.length; i++) {
            result[i] = Integer.parseInt(tableau[i]);
        }
        return result;
    }

    /**
     * Fonction qui permet de déterminer la string la plus grande dans un tableau de string
     *
     * @param tab le tableau de string
     * @return retourne la string d'un tableau la plus grande
     */
    public static String sLonger(String[] tab) {
        for (int i = 0; i < tab.length - 1; i++) {
            for (int j = 0; j < tab.length; j++) {
                if (tab[j].toCharArray().length < tab[i].toCharArray().length) {
                    String temp = tab[i]; // variable temporaire pour le transit
                    tab[i] = tab[j];
                    tab[j] = temp;
                }
            }
        }

        return tab[0];
    }

    /**
     * Fonction qui permet de déterminer la string la plus petite dans un tableau de string
     *
     * @param tab le tableau de string
     * @return retourne la string d'un tableau la plus petite
     */
    public static String sShorter(String[] tab) {
        for (int i = 0; i < tab.length - 1; i++) {
            for (int j = 0; j < tab.length; j++) {
                if (tab[j].toCharArray().length > tab[i].toCharArray().length) {
                    String temp = tab[i]; // variable temporaire pour le transit
                    tab[i] = tab[j];
                    tab[j] = temp;
                }
            }
        }

        return tab[0];
    }

    /**
     * Fonction qui permet de copier deux un tableau dans un autre tableau
     *
     * @param tableau le tableau dont nous voulons copier
     * @return retourne la copie du tableau
     */
    public static int[] copieTab(int[] tableau) {
        int[] newTab = new int[tableau.length + 1]; //tableau temporaire pour le return

        for (int i = 0; i < tableau.length; i++) {
            newTab[i] = tableau[i];
        }

        return newTab;
    }

    /**
     * Fonction qui permet d'ajouter un entier dans un tableau déjà existant
     *
     * @param tableau le tableau dont nous voulons ajouter l'entier
     * @param ajout   l'entier dont nous voulons ajouter
     * @return retourne le tableau avec l'ajout de l'entier
     */
    public static int[] addElemTab(int[] tableau, int ajout) {
        int[] newTab; //tableau temporaire pour le return
        int taille = tableau.length; //taille du tableau

        newTab = copieTab(tableau);
        newTab[taille] = ajout;

        return newTab;
    }

    /**
     * Fonction qui permet de copier deux un tableau dans un autre tableau (version String)
     *
     * @param tableau le tableau string dont nous voulons copier
     * @return retourne la copie du tableau string
     */
    public static String[] copieTabString(String[] tableau) {
        String[] newTab = new String[tableau.length + 1]; //tableau temporaire pour le return

        for (int i = 0; i < tableau.length; i++) {
            newTab[i] = tableau[i];
        }

        return newTab;
    }

    /**
     * Fonction qui permet d'ajouter un String dans un tableau déjà existant
     *
     * @param tableau le tableau dont nous voulons ajouter le string
     * @param ajout   le String dont nous voulons ajouter
     * @return retourne le tableau avec l'ajout de la string
     */
    public static String[] addElemTabString(String[] tableau, String ajout) {
        String[] newTab; //tableau temporaire pour le return
        int taille = tableau.length; //taille du tableau

        newTab = copieTabString(tableau);
        newTab[taille] = ajout;

        return newTab;
    }

    /**
     * Fonction qui permet de rendre un tableau d'entiers en une seule string
     *
     * @param tableau le tableau
     * @return retourne tout les entiers du tableau en une seule string
     */
    public static String printAllTab(int[] tableau) {
        String[] tabStringTemp = {}; // tableau de string temporaire

        for (int i = 0; i < tableau.length; i++) {
            tabStringTemp = addElemTabString(tabStringTemp, Integer.toString(tableau[i]));
        }
        return String.join(" ", tabStringTemp);
    }

    public static void main(String[] args) {

        View vue = new View();
    }
}