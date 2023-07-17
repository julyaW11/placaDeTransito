#include <GL/glut.h>


//Controles(DE BAIXO PRA CIMA):
//OBS, pode ativar CAPS LOCK
// 'z' & 'c' move a base
// 'a' & 'd' move 1° bastao branco
// 'q' & 'e' move bastão vermelho
// '1' & '3' move 2° bastão branco
// '5' & '7' move o bola
//Qualquer duvida olhar entre as linhas 166 e 226



float rotateAnguloBastaoBranco1 = 0;
float rotateAnguloBastaoVermelho = 0;
float rotateAnguloBastaoBranco2 = 0;
float rotateAnguloBola = 0;


float baseX = 20.0f;
float baseY = 1.0f;

//BastaoBranco1
float perna1X = baseX;
float perna1Y = baseY + 2.0f;

//BastaoVermelho
float perna2X = 0.0f;
float perna2Y = 4.0f;

//BastaoBranco2
float perna3X = 0.0f;
float perna3Y = 4.0f;

//Bola
float bolaX = 0.0f;
float bolaY = 5.0f;

void drawBola() {
    // Desenha o círculo vermelho
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(14.0f, 14.0f, 1.0f);
    glutSolidSphere(0.20, 50, 10);
    glPopMatrix();

    // Desenha o retângulo branco
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f); // Aplica a mesma translação do círculo
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f); // Rotação de 30 graus em torno do eixo Z
    glScalef(3.0f, 0.5f, 1.0f); // Ajusta a escala do retângulo

    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.5f); 
    glVertex2f(-1.0f, 0.5f); 
    glVertex2f(0.3f, 0.5f); 
    glVertex2f(0.3f, -0.5f);
    glEnd();

    glPopMatrix();

    // Desenha a seta
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(1.5f, 0.5f, 0.0f); // Aplica a mesma translação do círculo
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f); // Rotação de 30 graus em torno do eixo Z
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f); 
    glVertex2f(-0.5f, -0.866f); 
    glVertex2f(0.5f, -0.866f); 
    glEnd();
    glPopMatrix();
}



void drawPerna3(){
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 3.5f);
    glVertex2f(-0.5f, 3.5f);
    glEnd();

    // Posicionar e desenhar a bola
    glPushMatrix();
    glTranslatef(bolaX, bolaY, 0.0f); 
    glRotatef(rotateAnguloBola, 0.0f, 0.0f, 1.0f);
    drawBola();
    glPopMatrix();
}

void drawPerna2(){
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 3.5f);
    glVertex2f(-0.5f, 3.5f);
    glEnd();

    
    glPushMatrix();
    glTranslatef(perna3X, perna3Y, 0.0f); 
    glRotatef(rotateAnguloBastaoBranco2, 0.0f, 0.0f, 1.0f);
    drawPerna3();
    glPopMatrix();
}

void drawPerna1(){
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 3.5f);
    glVertex2f(-0.5f, 3.5f);
    glEnd();

    
    glPushMatrix();
    glTranslatef(perna2X, perna2Y, 0.0f); 
    glRotatef(rotateAnguloBastaoVermelho, 0.0f, 0.0f, 1.0f);
    drawPerna2();
    glPopMatrix();
}

void drawBase(){
    glColor3f(0.5f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-3.5f, -0.5f);
    glVertex2f(3.5f, -0.5f);
    glVertex2f(3.5f, 2.5f);
    glVertex2f(-3.5f, 2.5f);
    glEnd();
}

void display() {

    glClearColor(0.0f, 0.0f, 0.0f, 0.8f); // Define cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    
    glPushMatrix();
    glTranslatef(baseX, baseY, 0.0f); 
    drawBase();
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(perna1X, perna1Y, 0.0f); 
    glRotatef(rotateAnguloBastaoBranco1, 0.0f, 0.0f, 1.0f);
    drawPerna1();
    glPopMatrix();

    glFlush();
}


void keyboard(unsigned char key, int x, int y) {
    // Manipulação via teclado
    switch (key) {

        case 'Z':
        case 'z':
            baseX -= 0.1f;

            
            perna1X = baseX;

            break;

        case 'C':
        case 'c':
            baseX += 0.1f;

            perna1X = baseX;

            break;

        
        case 'A':
        case 'a':	
            rotateAnguloBastaoBranco1 -= 5.0f;
            break;
        case 'D':
        case 'd':
            rotateAnguloBastaoBranco1 += 5.0f;
            break;

        case 'Q':
        case 'q':
            rotateAnguloBastaoVermelho -= 5.0f;
            break;
        
        case 'E':
        case 'e':
            rotateAnguloBastaoVermelho += 5.0f;
            break;


        
        case '1':
            rotateAnguloBastaoBranco2 -= 5.0f;
            break;
        case '3':
            rotateAnguloBastaoBranco2 += 5.0f;
            break;

                    
        case '5':
            rotateAnguloBola -= 5.0f;
            break;
        case '7':
            rotateAnguloBola += 5.0f;
            break;
    }

    glutPostRedisplay();
}


//Dimensionamento da Tela
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 40.0f, 0.0f, 20.0f, -1.0f, 1.0f); 

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1300, 700);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Hierarquia no OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); 
    glutMainLoop();
}
