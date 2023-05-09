#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include "Cube.h"

using namespace std;

Camera cam; // global camera object
float points[8][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
float newpoints[8][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
float Oxy[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 0}};
float Oyz[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 1}};
float Oxz[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
float canh, option0, option1;
Point3 eye2, center;
Vector3 up2;

void inputPoint(float a, float i)
{
    points[0][0] = i;
    points[0][1] = i;
    points[0][2] = i;
   
    points[1][0] = i;
    points[1][1] = a + i;
    points[1][2] = i;
   
    points[2][0] = i;
    points[2][1] = a + i;
    points[2][2] = a + i;
   
    points[3][0] = i;
    points[3][1] = i;
    points[3][2] = a + i;
 
    points[4][0] = a + i;
    points[4][1] = i;
    points[4][2] = a + i;
   
    points[5][0] = a + i;
    points[5][1] = a + i;
    points[5][2] = a + i;
   
    points[6][0] = a + i;
    points[6][1] = a + i;
    points[6][2] = i;
   
    points[7][0] = a + i;
    points[7][1] = i;
    points[7][2] = i;
}

void printPoint(float a[8][3])
{ 
  	for (int i=0; i<8; i++)
	{
//        cout << fixed;
//        cout << setprecision(2);
        cout << setw(10) << "Dinh " << (i) << ": ";
        cout << "(" << setw(3);
        for (int j=0; j<3; j++)
		{
            cout << setw(10);
            cout << a[i][j];
            if( j==2 ) cout << setw(3)<< ")" << endl;
            else cout << ",";
        }
  	}
    cout << endl;
}

void Draw(float a[8][3])
{	
	//printPoint(points);
	
	glColor3f(1.0, 0.6, 0.6); // 0,1,2,3
    glBegin(GL_POLYGON);    
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glVertex3f(a[1][0], a[1][1], a[1][2]);
    glVertex3f(a[2][0], a[2][1], a[2][2]);
    glVertex3f(a[3][0], a[3][1], a[3][2]);    
    glEnd(); 
    
    glColor3f(0.7, 0.3, 0.4); // 3,4,7,0
    glBegin(GL_POLYGON);
    glVertex3f(a[3][0], a[3][1], a[3][2]);
    glVertex3f(a[4][0], a[4][1], a[4][2]);
    glVertex3f(a[7][0], a[7][1], a[7][2]);
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glEnd();
    
    glColor3f(1.0, 1.0, 0.5); // 6,7,0,1
    glBegin(GL_POLYGON);
    glVertex3f(a[6][0], a[6][1], a[6][2]);
    glVertex3f(a[7][0], a[7][1], a[7][2]); 
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glVertex3f(a[1][0], a[1][1], a[1][2]);
    glEnd();   
    
     glColor3f(2.52, 2.53, 2.44); // 2,3,4,5
    glBegin(GL_POLYGON);
    glVertex3f(a[2][0], a[2][1], a[2][2]);
    glVertex3f(a[3][0], a[3][1], a[3][2]);
    glVertex3f(a[4][0], a[4][1], a[4][2]);
    glVertex3f(a[5][0], a[5][1], a[5][2]);    
    glEnd();
    
	glColor3f(0.43, 0.52, 1.03); // 1,2,5,6
    glBegin(GL_POLYGON);
    glVertex3f(a[1][0], a[1][1], a[1][2]);
    glVertex3f(a[2][0], a[2][1], a[2][2]);
    glVertex3f(a[5][0], a[5][1], a[5][2]);
    glVertex3f(a[6][0], a[6][1], a[6][2]);
    glEnd();

    glColor3f(2.33, 0.68, 0.94); // 4,5,6,7
    glBegin(GL_POLYGON);
    glVertex3f(a[4][0], a[4][1], a[4][2]);
    glVertex3f(a[5][0], a[5][1], a[5][2]);
    glVertex3f(a[6][0], a[6][1], a[6][2]);
    glVertex3f(a[7][0], a[7][1], a[7][2]);    
    glEnd();    
}

 void drawCoordinateAxisZ()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2000.0f);
    glEnd();    
    glLineWidth(1.0f);
}

void drawCoordinateAxisX()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(2000.0f, 0.0f, 0.0f);
    glEnd();
    glLineWidth(1.0f);
}

void drawCoordinateAxisY()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2000.0f, 0.0f);
    glEnd();
    glLineWidth(1.0f);
}

void drawCoordinateAxis()
{
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCoordinateAxisZ();
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCoordinateAxisY();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCoordinateAxisX();
}

void nhan2MaTran(float a[1][3], float b[3][3], float c[1][3])
{
    for (int j = 0; j < 3; ++j) 
	{
        c[0][j] = 0;
        for (int k = 0; k < 3; ++k) 
		{
            c[0][j] += a[0][k] * b[k][j];
        }
    }
}

void output(float a[][100])
{
    int i,j;
    for(i=0; i<4; i++)
	{
        for(j=0; j<4; j++) 
		{
        	if(j == 0) cout << "[" << setw(10) << a[i][j];			
            else cout << setw(10) << a[i][j] << setw(10);
        }
        cout << "]" << endl;
    }
}
 
void tichMaTran(float a[][100], float b[][100])
{
    float c[100][100];
    int i, j, k;
    for(i = 0; i <= 3; i++)
	{
	 	for(j = 0; j < 4; j++) 
		{
         	float tt = 0;
           	for(k = 0; k < 4; k++)
            	{
                  tt = tt + (a[i][k] * b[k][j]); 
            	}
            c[i][j] = tt;
        }
	}      
    printf("\nTRANSFER MATRIX\n");
    output(c);
}

void printTransferMatrix(Point3 eye, Point3 center, Vector3 up)
{
	float M[100][100], K[100][100];
	Point3 n, u, v;
	float mau1, mau2;
	mau1 = fabs(sqrt(pow(eye.x-center.x, 2)+pow(eye.y-center.y, 2)+pow(eye.z-center.z, 2)));
	n.set((eye.x-center.x)/mau1, (eye.y-center.y)/mau1, (eye.z-center.z)/mau1);
	mau2 = fabs(sqrt(pow(up.x-n.x, 2)+pow(up.y-n.y, 2)+pow(up.z-n.z, 2)));
	u.set((up.x-n.x)/mau2, (up.y-n.y)/mau2, (up.z-n.z)/mau2);
	v.set(n.y*u.z - n.z*u.y, n.z*u.x - n.x*u.z, n.x*u.y - n.y*u.x);
	
	M[0][0] = u.x;  M[0][1] = u.y;  M[0][2] = u.z;  M[0][3] = 0; 
	M[1][0] = v.x;  M[1][1] = v.y;  M[1][2] = v.z;  M[1][3] = 0;  
	M[2][0] = n.x;  M[2][1] = n.y;  M[2][2] = n.z;  M[2][3] = 0;
	M[3][0] = 0;    M[3][1] = 0;    M[3][2] = 0;    M[3][3] = 1;
	
	K[0][0] = 1;  K[0][1] = 0;  K[0][2] = 0;  K[0][3] = -eye.x; 
	K[1][0] = 0;  K[1][1] = 1;  K[1][2] = 0;  K[1][3] = -eye.y;  
	K[2][0] = 0;  K[2][1] = 0;  K[2][2] = 1;  K[2][3] = -eye.z;
	K[3][0] = 0;  K[3][1] = 0;  K[3][2] = 0;  K[3][3] = 1;
	
	tichMaTran(M, K);
}
 
void PhepChieuTrucGiao()
{
	cout <<"Phep chieu truc giao" <<endl;
	float p1[1][3], p2[1][3];
	//Oxy
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			p1[0][j] = points[i][j];
		}
		nhan2MaTran(p1, Oxy, p2);
		for(int j = 0; j < 3; j++)
		{
			newpoints[i][j] = p2[0][j];
		}
	}
	Draw(newpoints);
	cout<<"Chieu len Oxy:\n";
    printPoint(newpoints);
    
	//Oxz
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			p1[0][j] = points[i][j];
		}
		nhan2MaTran(p1, Oxz, p2);
		for(int j = 0; j < 3; j++)
		{
			newpoints[i][j] = p2[0][j];
		}
	}
	Draw(newpoints);
	cout<<"Chieu len Oxz:\n";
    printPoint(newpoints);
    
	//Oyz
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			p1[0][j] = points[i][j];
		}
		nhan2MaTran(p1, Oyz, p2);
		for(int j = 0; j < 3; j++)
		{
			newpoints[i][j] = p2[0][j];
		}
	}
    Draw(newpoints);
	cout<<"Chieu len Oyz:\n";
    printPoint(newpoints);

} 

//fabs(sqrt(pow(arr[0]-arr[3], 2)+pow(arr[1]-arr[4], 2)+pow(arr[2]-arr[5], 2))))

void myKeyboard(unsigned char key, int x, int y)

{
  switch(key)
  {
    case 'F': cam.zoom(0, 0, 0.2);
              break; 
    case 'F'-64: cam.zoom(0,0,-0.2);
                break; 

    case 'A': cam.rotate(-1.0);
              break;
    case 'A' - 64: cam.rotate( 1.0);
                break;

  }
  glutPostRedisplay();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

    inputPoint(canh, 0.3);
    drawCoordinateAxis();
    if(option1 == 1)
    {
    	PhepChieuTrucGiao();
	}

    Draw(points);
    
    if(option0 == 0)
    {
    	gluLookAt(eye2.x, eye2.y, eye2.z, center.x, center.y, center.z, up2.x, up2.y, up2.z);
    	printTransferMatrix(eye2, center, up2);
	}
	
    glFlush();
    glutSwapBuffers(); 
}

 

void myMouse(int button, int state, int x, int y)
{
  switch (button) 
  {
     case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
           exit (-1);
        break;
     default:
        break;
  }
}

int main(int argc, char **argv)
{
	
	cout << "Nhap canh a (recommend: 0.5): ";
	cin >> canh;
	cout << "Nhap 0 neu ban muon thay doi goc nhin: ";
	cin >> option0;
	cout << "Nhap 1 neu ban muon thuc hien phep chieu truc giao: ";
	cin >> option1;
	if(option0 == 0)
	{
		cout << "Nhap vecto eye (recommend: 0.3, 0.6, 0.4): " << endl;
		cin >> eye2.x;
		cin >> eye2.y;
		cin >> eye2.z;
		cout << "Nhap vecto center (recommend: 0.2, 0.4, -0.3): " << endl;
		cin >> center.x;
		cin >> center.y;
		cin >> center.z;
		cout << "Nhap vecto up (recommend: 0.2, 0.0, 0.1): " << endl;
		cin >> up2.x;
		cin >> up2.y;
		cin >> up2.z;
		//printTransferMatrix(eye2, center, up2);
	}	
	cout << "---------------------------------------------\n";    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // double buffering
    glutInitWindowSize(1362, 750);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("CUBE");
    glColor3f(0.0f,0.0f,0.0f);             
    Point3 eye1(6, 6, 6);
	Point3 look(0, 0, 0);
	Vector3 up1(0, 1, 0);
    cam.set(eye1, look, up1);                      // make the initial camera
    cam.setShape(30.0f, 64.0f/48.0f, 0.5f, 50.0f);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);                      // register myMouse function
    glutDisplayFunc(myDisplay);
    glutMainLoop();

}//main
