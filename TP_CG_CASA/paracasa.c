#include <GL/glut.h>    // Header File For The GLUT Library
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // Header File for sleeping.
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

void draw_circle(float R, float G, float B, int x, int y, float raio){

    float theta;

    glColor3f(R,G,B);

    glBegin(GL_POLYGON);

    for (int i = 1; i < 360; i++){
        theta = i*3.142/180;
        glVertex2f(x+raio*cos(theta),y+raio*sin(theta));
    }
    glEnd();
    glFlush();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a cor de fundo como amarelo claro
    //         R     G     B
    glColor3f(0.9f, 0.9f, 0.75f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(1200,800);
    glVertex2i(1200,0);
    glVertex2i(0,0);
    glVertex2i(0,800);

    glEnd();
    glFlush();

    // CAMADA 1

    draw_circle(0.9f,0.90f,0.85f,1200,800,1000.0);

    // CAMADA 2

    draw_circle(0.9f,0.90f,0.90f,1200,800,600.0);

    // CAMADA 3

    draw_circle(0.9f,0.90f,0.92f,1200,800,400.0);

    // SOL

    draw_circle(0.9f,0.90f,0.99f,1200,800,250.0);

    // Define a cor do telhado como laranja
    //         R     G     B
    glColor3f(1.0f, 0.5f, 0.0f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(450,550);
    glVertex2i(650,550);
    glVertex2i(750,450);
    glVertex2i(550,450);

    glEnd();
    glFlush();

    // Define a cor da parede lateral como cinza
    //         R     G     B
    glColor3f(0.7f, 0.7f, 0.7f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(550,450);
    glVertex2i(750,450);
    glVertex2i(750,300);
    glVertex2i(550,300);

    glEnd();
    glFlush();

    
    // Define a cor da parede principal como branco
    //         R     G     B
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(350,450);
    glVertex2i(550,450);
    glVertex2i(550,300);
    glVertex2i(350,300);

    glEnd();
    glFlush();

    // Define a cor do chao como verde
    //         R     G     B
    glColor3f(0.15f, 0.4f, 0.015);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(0,300);
    glVertex2i(1200,300);
    glVertex2i(1200,0);
    glVertex2i(0,0);

    glEnd();
    glFlush();

    // Define a cor da parede acima como branco
    //         R     G     B
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);
    //          x   y
    glVertex2i(350,450);
    glVertex2i(450,550);
    glVertex2i(550,450);

    glEnd();
    glFlush();

    // PORTA

    // Define a cor da porta como marrom
    //         R     G     B
    glColor3f(0.73f, 0.57f, 0.4f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(400,375);
    glVertex2i(475,375);
    glVertex2i(475,300);
    glVertex2i(400,300);

    glEnd();
    glFlush();

    // JANELA

    // Define a cor da janela como azul
    //         R     G     B
    glColor3f(0.25f, 0.77f, 1.0f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(590,425);
    glVertex2i(720,425);
    glVertex2i(720,375);
    glVertex2i(590,375);

    glEnd();
    glFlush();

    // CHAMINE1

    // Define a cor da chamine como cinza escuro
    //         R     G     B
    glColor3f(0.7f, 0.7f, 0.7f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(550,570);
    glVertex2i(570,570);
    glVertex2i(570,550);
    glVertex2i(550,550);

    glEnd();
    glFlush();

    // CHAMINE2

    // Define a cor da lateral da chamine como cinza escuro
    //         R     G     B
    glColor3f(0.8f, 0.8f, 0.8f);

    glBegin(GL_POLYGON);
    //          x   y
    glVertex2i(540,580);
    glVertex2i(580,580);
    glVertex2i(580,570);
    glVertex2i(540,570);

    glEnd();
    glFlush();

    // MACANETA DA PORTA
    //            R    G    B   X   Y   RAIO
    draw_circle(0.0f,0.0f,0.0f,425,330,10.0);

    // JANELA REDONDA
    //            R     G    B    X   Y   RAIO
    draw_circle(0.25f,0.77f,1.0f,450,470,30.0);


    // FUMACA CHAMINE

    float j = 0.6f;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 500; i++){
        j = j + 0.001f;
        if (j >= 0.9f) j = 0.5f;
        float raio = 1.0;           // raio da fumaca
        x = x + 1;    // efeito vento pro lado
        y = y + 1;    // efeito vento pra cima
        int randraio = 1 + (rand()%25);
        raio = randraio; // tamanho aleatorio do raio da fumaca
        int randx = 1 + (rand()%x);  // valor aleatorio de x 
        int randy = 1 + (rand()%y); // valor aleatorio de y 
        int cx = 560 + randx;   // coordenada aleatoria de x da fumaca
        int cy = 600 + randy;   // coordenada aleatoria de y da fumaca
      //            R G B  X  Y RAIO
        draw_circle(j,j,j,cx,cy,raio);
    }

}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.00f, 0.0f, 1.0f);
    // glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,1200,0.0,800);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
     // Evita a divisao por zero
     if(h == 0) h = 1;
                           
     // Especifica as dimensões da Viewport
     glViewport(0, 0, w, h);

     // Inicializa o sistema de coordenadas
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     // Estabelece a janela de seleção (left, right, bottom, top)     
     if (w <= h)  {
		windowHeight = 250.0f*h/w;
		windowWidth = 250.0f;
     }
     else  { 
		windowWidth = 250.0f*w/h;
		windowHeight = 250.0f;
     }
     
     gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal 


int main(int argc, char **argv){
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Marlinhos house");
    Inicializa();
    glutDisplayFunc(Desenha);
    glutMainLoop();

    return 0;
}