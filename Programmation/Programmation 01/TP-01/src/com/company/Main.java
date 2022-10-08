package com.company;

/**
 * Auteur Félix-Olivier Latulippe 2173242
 * Session A2021
 * Objetif: Faire deviner un nombre à l'utilisateur
 */

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Random rand = new Random();
        Scanner scan = new Scanner(System.in);

        int nbRandom = rand.nextInt(98) + 1; //Nombre généré aléatoirement.
        int nbPlusPetit = 0; //Numéro plus petit dans l'affichage.
        int nbPlusGrand = 99; //Numéro plus grand dans l'affichage.
        int userInput; // Entrer de l'utilisateur.
        int nbTentatives = 1; // Nombre de tentatives effectuées.
        boolean reussi = false; // Vérifie si le jeu est réussi.

        //System.out.println(nbRandom); // Permet de voir le nombre.
        System.out.println("Bienvenu au jeu du nombre mystère");
        System.out.println("----------------------------------");
        System.out.println("Entrer un nombre entre 0 et 99");

        do {
            System.out.print("(" + nbTentatives + "/5) " + nbPlusPetit + " < ? < " + nbPlusGrand + " : ");
            try{
                userInput = scan.nextInt();
                if (userInput == nbRandom){
                    System.out.println("Nombre exacte, bravo !");
                    reussi = true;
                    nbTentatives = 6;
                }
                else if (userInput < nbRandom){
                    nbPlusPetit = userInput;
                    nbTentatives ++;
                }
                else if (userInput > nbRandom){
                    nbPlusGrand = userInput;
                    nbTentatives ++;
                }
            } catch (InputMismatchException e){
                System.out.println("Erreur de frappe");
                scan.next();
            }
        } while (nbTentatives <= 5);

        if (!reussi) {
            System.out.println("Nombre d'essais épuisé");
            System.out.println("Le nombre était: " + nbRandom);
        }

    }
}
