#include <iostream>
#include <cmath>
#include "raylib.h"

/*
TODO:
Calcular la posicion de los puntos en los demas vectores dependiendo de cual se ecuentra mas bajo en y.

*/

using namespace std;

// -- Structs/Enums. --

struct Vector {
	Vector3 start;
	Vector3 end;
};

// -- Variables. --

const int windowWidth = 800;
const int windowHeight = 450;

Vector x; // Ilustra el vector X default.

Vector vA;
Vector vB;
Vector vC;

Vector3 p1;
Vector3 p2;
Vector3 p3;

Camera3D camera;

// -- Funciones. --
float GetDistance();

void CalculateArea();
void SliceVectors();

void CreateThirdVector();
void CreateSecondVector();
void CreateFirstVector();
void InitVectors();

void Draw();
void Update();
void Loop();
void Init();

// -- Main. --
int main() {
	InitWindow(windowWidth, windowHeight, "Algebra EJ2");
	Init();
	while (!WindowShouldClose()) {
		Loop();
	}
	CloseWindow();

	return 0;
}

float GetDistance(Vector3 point1, Vector3 point2) {
	
	return (pow((point2.x - point1.x), 2) + (y2 - y1)2 + (z2 - z1)2) 1 / 2
}

void CalculateArea() {
	/*
	p1
	p3
	(0, 0, 0)
	*/
	Vector3 p0 = { 0, 0, 0 };


	float d1 = GetDistance(p1, p3);
	float d2 = GetDistance(p3, p0);
	float d3 = GetDistance(p0, p1);
	cout << "Distances: (" << d1 << ", " << d2 << ", " << d3 << ")\n";
}

void SliceVectors() {
	if (vA.end.y < vB.end.y) {
		p1 = vA.end;

		p2.y = p1.y;
		p2.x = (vB.end.x / vB.end.y) * p2.y;
		p2.z = (vB.end.z / vB.end.y) * p2.y;

		p3.y = p1.y;
		p3.x = (vC.end.x / vC.end.y) * p2.y;
		p3.z = (vC.end.z / vC.end.y) * p2.y;
	}
	else if (vB.end.y < vA.end.y) {
		p1 = vB.end;

		p2.y = p1.y;
		p2.x = (vA.end.x / vA.end.y) * p2.y;
		p2.z = (vA.end.z / vA.end.y) * p2.y;

		p3.y = p1.y;
		p3.x = (vC.end.x / vC.end.y) * p2.y;
		p3.z = (vC.end.z / vC.end.y) * p2.y;
	}
}

void CreateThirdVector() {
	vC.end.x = ((vA.end.y * vB.end.z) - (vA.end.z * vB.end.y));
	vC.end.y = ((vA.end.z * vB.end.x) - (vA.end.x * vB.end.z));
	vC.end.z = ((vA.end.x * vB.end.y) - (vA.end.y * vB.end.x));
}

void CreateSecondVector() {
	vB.start.x = 0;
	vB.start.y = 0;
	vB.start.z = 0;
	vB.end.x = -vA.end.y;
	vB.end.y = vA.end.x;
	vB.end.z = vA.end.z;
}

void CreateFirstVector() {
	vA.start.x = 0;
	vA.start.y = 0;
	vA.start.z = 0;
	vA.end.x = 5;
	vA.end.y = 4;
	vA.end.z = -2;
}

void InitVectors() {
	x.start.x = -10;
	x.start.y = 0;
	x.start.z = 0;

	x.end.x = 10;
	x.end.y = 0;
	x.end.z = 0;

	CreateFirstVector();
	cout << "Vector A: (X: " << vA.end.x << ", Y: " << vA.end.y << ", Z: " << vA.end.z << ")\n";
	CreateSecondVector();
	cout << "Vector B: (X: " << vB.end.x << ", Y: " << vB.end.y << ", Z: " << vB.end.z << ")\n";
	CreateThirdVector();
	cout << "Vector C: (X: " << vC.end.x << ", Y: " << vC.end.y << ", Z: " << vC.end.z << ")\n";
	
	SliceVectors();
	cout << "Point 1: (X: " << p1.x << ", Y: " << p1.y << ", Z: " << p1.z << ")\n";
	cout << "Point 2: (X: " << p2.x << ", Y: " << p2.y << ", Z: " << p2.z << ")\n";
	cout << "Point 3: (X: " << p3.x << ", Y: " << p3.y << ", Z: " << p3.z << ")\n";

	CalculateArea();
}

// --

void Draw() {
	BeginDrawing();
	ClearBackground(BLACK);

	BeginMode3D(camera); // 3D

	// Ilustracion de X.
	DrawLine3D(x.start, x.end, RED);

	// Mis tres vectores generados random.
	DrawLine3D(vA.start, vA.end, ORANGE);
	DrawLine3D(vB.start, vB.end, PURPLE);
	DrawLine3D(vC.start, vC.end, YELLOW);

	if (p1.x > 0) {
		DrawSphere(p1, 0.2, BLUE);
		DrawSphere(p2, 0.2, BLUE);
		DrawSphere(p3, 0.2, BLUE);
	}

	EndMode3D();
	EndDrawing();
}

void Update() {

}

void Loop() {
	Update();
	Draw();
}

void Init() {
	// Init camara.
	camera.position = Vector3{ 0.0f, 0.0f, 20.0f }; // Posicionada apuntando al angulo YX.
	camera.target = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	InitVectors();
}