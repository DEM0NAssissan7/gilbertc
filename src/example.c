#include <GLFW/glfw3.h>
#include "gilbert.h"
#include <stdio.h>

void exinit(){

	gbAddLight(1000, 10);
	//*
	gbAddLight(10, 10);
	gbAddLight(10, 1000);
	gbAddLight(1000, 1000);
	//*/
	gbAddPoint((int[5]) {200,400,400,200,200}, (int[5]) {200,200,400,400,200}, 5);

	gbAddPoint((int[4]) {400,500,500,400}, (int[4]) {450,550,450,450},4);

}

void exloop(){

	gbRun();

}
