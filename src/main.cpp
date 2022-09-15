#include <iostream>
#include "raylib.h"

/*
TODO:
Producto cruz para el tercer vector.
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

Camera3D camera;

// -- Funciones. --

void CreateThirdVector();
void CreateSecondVector();
void CreateFirstVector();
void InitVectors();

void Close();
void Draw();
void Update();
void Loop();
void Init();

// -- Main. --
int main() {

	Init();
	Loop();
	Close();

	return 0;
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
	vA.end.x = GetRandomValue(1, 5);
	vA.end.y = GetRandomValue(1, 5);
	vA.end.z = GetRandomValue(1, 5);
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
}

// --

void Close() {
	CloseWindow();
}

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

	EndMode3D();
	EndDrawing();
}

void Update() {

}

void Loop() {
	while (!WindowShouldClose()) {
		Update();
		Draw();
	}
}

void Init() {
	// Init ventana.
	InitWindow(windowWidth, windowHeight, "Algebra EJ2");

	// Init camara.
	camera.position = Vector3{ 0.0f, 0.0f, 10.0f }; // Posicionada apuntando al angulo YX.
	camera.target = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	InitVectors();
}