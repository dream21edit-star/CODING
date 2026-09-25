package games.Java.Console_Down;

import java.awt.*;
import java.util.Random;
import javax.swing.*;

class ZoneDeJeu extends JPanel {
    int hpJoueur = 0;
    int hpEnnemi = 0;
    int hpMaxJoueur = 1;
    int hpMaxEnnemi = 1;

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLUE); 
        g.fillRect(100, 200, 80, 120);
        
        g.setColor(Color.RED); 
        g.fillRect(620, 200, 80, 120);
        
        g.setColor(Color.BLACK);
        g.drawString("PV: " + hpJoueur, 100, 180);
        g.drawString("PV: " + hpEnnemi, 620, 180);
        
        int hpJ_pos = Math.max(0, hpJoueur);
        int hpE_pos = Math.max(0, hpEnnemi);
        int largeurBarreJoueur = (hpJ_pos * 80) / hpMaxJoueur;
        int largeurBarreEnnemi = (hpE_pos * 80) / hpMaxEnnemi;
        
        g.setColor(Color.GREEN);
        g.fillRect(100, 160, largeurBarreJoueur, 10);
        g.fillRect(620, 160, largeurBarreEnnemi, 10);
    }

    public void mettreAjourHP(int hpJ, int hpE, int maxJ, int maxE) {
        this.hpJoueur = hpJ;
        this.hpEnnemi = hpE;
        this.hpMaxJoueur = maxJ;
        this.hpMaxEnnemi = maxE;
        repaint();
    }
}

public class test {
    static int playerHP = 0, playerDamage = 0, playerMaxHP = 1;
    static int enemyHP = 0, enemyDamage = 0, enemyMaxHP = 1;
    static ZoneDeJeu maToile;
    static Timer chrono;

    public static void main(String[] args) {
        JFrame fenetre = new JFrame("CONSOLE DOWN");
        fenetre.setSize(800, 600);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setLayout(new BorderLayout());

        maToile = new ZoneDeJeu();
        fenetre.add(maToile, BorderLayout.CENTER);

        JPanel panneauBoutons = new JPanel();
        JButton btnTank = new JButton("Tank");
        JButton btnAssassin = new JButton("Assassin");
        JButton btnKnight = new JButton("Knight");

        panneauBoutons.add(btnTank);
        panneauBoutons.add(btnAssassin);
        panneauBoutons.add(btnKnight);
        fenetre.add(panneauBoutons, BorderLayout.SOUTH);

        // --- 1. INITIALISATION DU CHRONOMÈTRE DE COMBAT ---
        chrono = new Timer(1000, e -> {
            playerHP -= enemyDamage;
            enemyHP -= playerDamage;

            maToile.mettreAjourHP(playerHP, enemyHP, playerMaxHP, enemyMaxHP);

            if (playerHP <= 0 || enemyHP <= 0) {
                chrono.stop();

                if (playerHP <= 0 && enemyHP <= 0 && playerHP==enemyHP) {
                    JOptionPane.showMessageDialog(null, "Égalité ! Round suivant");
                    activerBoutons(true);
                } else if (playerHP > 0) {
                    JOptionPane.showMessageDialog(null, "Victoire !");
                } else {
                    JOptionPane.showMessageDialog(null, "Défaite !");
                }
            }
        });

        // --- 2. GESTION DES CLICS BOUTONS ---
        btnTank.addActionListener(e -> {
            playerHP = 30; playerDamage = 5; playerMaxHP = 30;
            configurerEnnemiEtLancer(btnTank, btnAssassin, btnKnight);
        });

        btnAssassin.addActionListener(e -> {
            playerHP = 15; playerDamage = 12; playerMaxHP = 15;
            configurerEnnemiEtLancer(btnTank, btnAssassin, btnKnight);
        });

        btnKnight.addActionListener(e -> {
            playerHP = 10; playerDamage = 10; playerMaxHP = 10;
            configurerEnnemiEtLancer(btnTank, btnAssassin, btnKnight);
        });

        // --- 3. AFFICHAGE DE LA FENÊTRE UNE FOIS TOUT CHARGÉ ---
        fenetre.setVisible(true);
    }

    private static void configurerEnnemiEtLancer(JButton b1, JButton b2, JButton b3) {
        Random rand = new Random();
        int enemyChoice = rand.nextInt(3) + 1;
        if (enemyChoice == 1) { enemyHP = 30; enemyDamage = 5; enemyMaxHP = 30; }
        else if (enemyChoice == 2) { enemyHP = 15; enemyDamage = 12; enemyMaxHP = 15; }
        else { enemyHP = 10; enemyDamage = 10; enemyMaxHP = 10; }

        maToile.mettreAjourHP(playerHP, enemyHP, playerMaxHP, enemyMaxHP);
        chrono.start();

        b1.setEnabled(false);
        b2.setEnabled(false);
        b3.setEnabled(false);
    }
}