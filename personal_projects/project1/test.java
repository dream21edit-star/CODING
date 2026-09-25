package personal_projects.project1;

import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Color;
import java.util.Random;
import javax.swing.JFrame;

import javax.swing.Timer;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import java.awt.Dimension;
import java.awt.BorderLayout;




class monPanneau extends JPanel {
    Cercle CercleAleat;
    public monPanneau(Cercle e) {
        this.CercleAleat = e;
        Timer chrono = new Timer(4500, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //jcrois qu'ici le cercle disparait on fait apparaitre un nouveau cercle dans un endroit aléatoire...
                Random generateur = new Random();
                Color[] listeCouleurs = {Color.RED, Color.GREEN, Color.YELLOW};
                int nouvX = generateur.nextInt(getWidth()-50);
                int nouvY = generateur.nextInt(getHeight()-50);
                int indexAleat = generateur.nextInt(3);
                Color couleurChoisie = listeCouleurs[indexAleat];
                CercleAleat = new Cercle(nouvX, nouvY, couleurChoisie );
                repaint();
            }
        });
        chrono.start();
    }
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(CercleAleat.couleur);
        g.fillOval(CercleAleat.x, CercleAleat.y, 50, 50); // ici y a probleme: le cercle est trop grand
    }
}
class PanneauDroit extends JPanel {
    public PanneauDroit() {
        this.setPreferredSize(new Dimension(300, 600));
    }
    @Override
    protected void paintComponent(Graphics f) {
        super.paintComponent(f);
        f.setColor(Color.DARK_GRAY);
        f.fillRect(0, 0, getWidth(), getHeight());
    }
}
class Cercle {
    int x, y;
    Color couleur;
    public Cercle(int posX, int posY, Color saCouleur) {
        this.x = posX;
        this.y = posY;
        this.couleur = saCouleur;
    }       
}
public class test {
    public static void main(String[] args) {
        PanneauDroit pD = new PanneauDroit();
        Color[] listeCouleurs = {Color.RED, Color.GREEN, Color.YELLOW};
        Random generateur = new Random();
        int indexAleat = generateur.nextInt(3);
        Color couleurChoisie = listeCouleurs[indexAleat];
        int xAleat = generateur.nextInt(200);
        int yAleat = generateur.nextInt(300);
        Cercle nouvCercle = new Cercle(xAleat, yAleat, couleurChoisie);
        JFrame fenetre = new JFrame("test");
        fenetre.setSize(800, 600);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        monPanneau panneau = new monPanneau(nouvCercle);
        fenetre.add(panneau, BorderLayout.CENTER);
        fenetre.add(pD, BorderLayout.EAST);
        fenetre.setVisible(true);
    }
}