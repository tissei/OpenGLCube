#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Variáveis Globais
double rotate_y=0; 
double rotate_x=0;

// Declarações de Funções
void display(){
     
    // Limpar a tela e o Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    // Lado multicolorido - FRENTE
    glBegin(GL_POLYGON);
     
    // Os vértices serão adicionados na próxima etapa
    glEnd();
    
    // Reinicializar transformações
    glLoadIdentity();
     
    // Rotacionar quando o usuário mudar as variáveis rotate_x e rotate_y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    
    // Lado multicolorido - FRENTE
    glBegin(GL_POLYGON);
     
    glVertex3f( -0.5, -0.5, -0.5);       // P1
    glVertex3f( -0.5,  0.5, -0.5);       // P2
    glVertex3f(  0.5,  0.5, -0.5);       // P3
    glVertex3f(  0.5, -0.5, -0.5);       // P4
     
    glEnd();
    
    //Lado multicolorido - Frente
    glBegin(GL_POLYGON);
     
    glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 é vermelho
    glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 é verde
    glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 é azul
    glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 é roxo
     
    glEnd();

    // Lado branco - TRASEIRA
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
     
    // Lado roxo - DIREITA
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();
     
    // Lado verde - ESQUERDA
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
     
    // Lado azul - TOPO
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();
     
    // Lado vermelho - BASE
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
     
    glFlush();
    glutSwapBuffers();
     
}

void specialKeys( int key, int x, int y ) {
 
// Seta para direita - aumenta a rotação em 5 graus
if (key == GLUT_KEY_RIGHT)
  rotate_y += 5;
 
//  Seta para esquerda - diminui a rotação em 5 graus
else if (key == GLUT_KEY_LEFT)
  rotate_y -= 5;
 
else if (key == GLUT_KEY_UP)
  rotate_x += 5;
 
else if (key == GLUT_KEY_DOWN)
  rotate_x -= 5;
 
// Requisitar atualização da tela
glutPostRedisplay();
 
}

int main(int argc, char* argv[]){
 
    // Inicializa o GLUT e processa os parâmetros do usuário
    glutInit(&argc,argv);
     
    //  Requisita uma janela true color de buffer duplo com o Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // Criar a janela
    glutCreateWindow("Super Cubo");
    
    // Habilite o teste de profundidade do Z-buffer
    glEnable(GL_DEPTH_TEST);
    
    // Funções callback
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    
    // Passando o controle para os eventos GLUT
    glutMainLoop();
     
    // Voltar para o SO
    return 0;
 
}
