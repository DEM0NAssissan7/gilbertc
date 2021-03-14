#include <GLFW/glfw3.h>
#include <stdio.h>
#include "config.h"

float pointsx[pointCount][pointLength];
float pointsy[pointCount][pointLength];
int arrayLengths[pointCount];
int objcount = 0;

float lightsx[pointCount];
float lightsy[pointCount];
int lightscount = 0;

float halfWidth = width/2;
float halfHeight = height/2;

void gbAddPoint(int x[pointLength],int y[pointLength], int arrayLength){	
	
	//The function to add points
	for(int i = 0; i < arrayLength;i++){

		pointsx[objcount][i]=(x[i] - halfWidth) / halfWidth;
		pointsy[objcount][i]=(y[i] - halfHeight) / halfHeight;
	}
	arrayLengths[objcount] = arrayLength;
	objcount++;
}

void gbAddLight(int x, int y){
	lightsx[lightscount] = (x - halfWidth) / halfWidth;
	lightsy[lightscount] = (y - halfHeight) / halfHeight;
	lightscount++;
}

void gbRun(){
	
	for(int i = 0; i < lightscount; i++){
		
		float lightX = lightsx[i];
		float lightY = lightsy[i];
		
		for(int l = 0; l < objcount; l++){
			int objectLength = arrayLengths[l];
			
			for(int a = 0; a < objectLength; a++){

				//Calculate next a

				int na = a + 1;
				if(na >= objectLength){
					na = a;
				}
				float pointX = pointsx[l][a];
				float pointY = pointsy[l][a];
				float pointX2 = pointsx[l][na];
				float pointY2 = pointsy[l][na];

				//Render shadows
				
				float shadeX[5];
				float shadeY[5];
				
				shadeX[0] = pointX;
				shadeX[1] = (pointX - lightX) * 2;
				shadeX[2] = (pointX2 - lightX) * 2;
				shadeX[3] = pointX2;
				shadeX[4] = pointX;

				shadeY[0] = pointY;
				shadeY[1] = (pointY - lightY) * 2;
				shadeY[2] = (pointY2 - lightY) * 2;
				shadeY[3] = pointY2;
				shadeY[4] = pointY;


				glColor4f(0.0, 0.0, 0.0, 0.3);
				glBegin(6);
				for(int o = 0; o < 5; o++){
					glVertex2f(shadeX[o],-shadeY[o]);
				}
				glEnd();
				glFlush();
				
			}
			
		}


	}

	if(renderObjects){
		glColor3f(1.0, 0.0, 0.0);
		for(int i = 0; i < objcount; i++){
			int dimensionLength = arrayLengths[i];

			glBegin(dimensionLength);
			for(int l = 0; l < dimensionLength; l++){
				glVertex2f(pointsx[i][l],-pointsy[i][l]);
			}
			glEnd();
		}
		glFlush();
	}
	
	if(drawBox){
		glColor4f(0.0, 0.0, 0.0, 0.3);
		for(int i = 0; i < objcount; i++){
			int dimensionLength = arrayLengths[i];

			glBegin(dimensionLength);
			for(int l = 0; l < dimensionLength; l++){
				glVertex2f(pointsx[i][l], -pointsy[i][l]);
			}
			glEnd();
		}
		glFlush();
	}
}
