package com.company;

import java.text.DecimalFormat;
import java.util.Random;
import java.util.Scanner;

/**
 * Objectif : Un jeu de multiplication qui permet au joueur de choisir une table de 2 à 12 (2 et 12 sont inclus) et de
 * tenter de trouver la réponse aux dix expressions générées aléatoirement par le programme. Le jeu
 * calcule des statistiques à la fin d’une partie. Le joueur peut jouer autant de parties qu’il le désire. Les
 * partie sont toujours de dix essais chacune.
 * <p>
 * Auteur Félix-Olivier Latulippe
 * DA 2173242
 * Session A2021
 */

public class Main {

    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_BLUE = "\u001B[34m";

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");
        Random rand = new Random();

        int multiRand; // Génere un nombre aléatoire entre 0 et 12
        int nbEssais = 1; // Nombre d'essais du joueur
        int choixTable; // Choix de table du joueur
        int userInput; // Entrer du joueur (réponse à la réponse)
        int bonneRep; // Calcule la bonne réponse
        int nbBonneRep = 0; // Calcule le nombre bonnes réponses
        int nbPartiesJoue = 0; // Nombre de parties jouées
        int nbPartiesReu = 0; // Nombre de parties gagnées
        int nbPartiesPerd = 0; // Nombre de parties perdues
        int[] tableauParties = {}; // Tableau des parties jouées
        double moyenneParties = 0; // Moyenne des parties jouées

        do {
            choixTable = choisirTable();

            do {
                multiRand = rand.nextInt(13-2)+2;
                System.out.print(ANSI_RESET + ("(Essais: " + nbEssais + "/10) " + choixTable + " * " + multiRand + " = "));

                try {
                    userInput = scan.nextInt();
                    bonneRep = choixTable * multiRand;

                    if (userInput == bonneRep) {
                        nbBonneRep++;
                    } else {
                        System.out.println(ANSI_RED + (choixTable + " * " + multiRand + " = " + bonneRep));
                    }
                    nbEssais++;
                } catch (Exception e) {
                    scan.next();
                }
            } while (nbEssais <= 10);

            if (nbBonneRep >= 9) {
                nbPartiesReu ++;
                System.out.println(ANSI_BLUE + ("-> Bravo vous avez gagné! " + nbBonneRep + "/10"));
            } else {
                nbPartiesPerd ++;
                System.out.println(ANSI_BLUE + ("-> Vous avez perdu! " + nbBonneRep + "/10"));
            }

            nbPartiesJoue ++;
            nbEssais = 1;
            tableauParties = addElemTab(tableauParties, nbBonneRep);
            moyenneParties = moyenneTaleau(tableauParties);
            nbBonneRep = 0;

            System.out.println();
            System.out.println(ANSI_BLUE + ("Nombre de parties jouées: " + nbPartiesJoue));
            System.out.println(ANSI_BLUE + ("Nombre de parties gagnées: " + nbPartiesReu));
            System.out.println(ANSI_BLUE + ("Nombre de parties perdues: " + nbPartiesPerd));
            System.out.print(ANSI_BLUE + ("Résultat de toutes les parties jouées: "));
            for (int i=0; i < tableauParties.length; i++)
                System.out.print(tableauParties[i] + "/10 ");
            System.out.println();
            System.out.println();
            System.out.println(ANSI_BLUE + ("Moyenne des résultats: " + df.format(moyenneParties) + "%"));
            System.out.println();
        } while (validerRejouer());
    }

    /**
     * Fonction qui permet au joueur de choisir la table de multiplication
     *
     * @return Retourne le choix de l'utilisateur (la table).
     */
    public static int choisirTable() {
        Scanner scan = new Scanner(System.in);
        int inputUser = 0; // Choix de l'utilisateur

        do {
            try {
                System.out.print("-> Choisir une table (2 à 12): ");
                inputUser = scan.nextInt();
            } catch (Exception e) {
                scan.next();
            }
        } while (!(inputUser >= 2 && inputUser <= 12));

        return inputUser;
    }

    /**
     * Fonction qui demande au joueur à la fin de la partie s'il veut rejouer
     *
     * @return retourne vrai ou faux (oui veut rejouer ou non ne veut pas rejouer, respectivement)
     */
    public static boolean validerRejouer() {
        Scanner scan = new Scanner(System.in);
        boolean rejouerValeur = false; // Determine si la valeur de rejouer est vrai (oui) ou fausse (non)
        char rejouer = 'b'; // Oui ou non si le joueur veut rejouer

        do {
            try {
                System.out.print(ANSI_RESET + ("Voulez-vous rejouer encore (o/n) ?"));
                rejouer = scan.next().toLowerCase().charAt(0);

                switch (rejouer) {
                    case 'o':
                        rejouerValeur = true;
                        break;
                    case 'n':
                        rejouerValeur = false;
                        break;
                }
            } catch (Exception e) {
                scan.next();
            }
        } while (!(rejouer == 'o' || rejouer == 'n'));
        return rejouerValeur;
    }

    /**
     * Fonction qui permet de calculer la moyenne d'un tableau d'entiers
     *
     * @param tableau le tableau dont nous voulons effectuer l'opération
     * @return retourne la moyenne
     */
    public static double moyenneTaleau(int[] tableau) {
        double moyenne = 0; // Moyenne du tableau
        double sommeTableau = 0; // Somme de tous les entiers du tableau

        for (int i = 0; i < tableau.length; i++) {
            sommeTableau += tableau[i];
        }
        moyenne = (sommeTableau / tableau.length) * 10;

        return moyenne;
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
     * @return
     */
    public static int[] addElemTab(int[] tableau, int ajout) {
        int[] newTab; //tableau temporaire pour le return
        int taille = tableau.length; //taille du tableau

        newTab = copieTab(tableau);
        newTab[taille] = ajout;

        return newTab;
    }

    public static void maFonction(){
        String[] monTab = {"dwaikb", "allo", "daiw", "fiajwb", "allo"};
        String recherche = "allo";
        int index = 0;

        for (int i = 0; i < monTab.length; i++) {
            if (monTab[i] == recherche)
                System.out.println(nextIndexOf(monTab, recherche, i));
        }
    }
}
