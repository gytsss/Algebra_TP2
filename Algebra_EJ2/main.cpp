#include <iostream>
#include "raylib.h"

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

Vector v1;
Vector v2;
Vector v3;

Camera3D camera;

// -- Funciones. --

void RandomXYVector(Vector& v);
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

void RandomXYVector(Vector& v) {
	int setX = GetRandomValue(1, 5);
	int setY = GetRandomValue(1, 5);

	v.start.x = 0;
	v.start.y = 0;
	v.start.z = 0;
	v.end.x = setX;
	v.end.y = setY;
	v.end.z = 0;
}

void InitVectors() {
	x.start.x = -10;
	x.start.y = 0;
	x.start.z = 0;

	x.end.x = 10;
	x.end.y = 0;
	x.end.z = 0;

	RandomXYVector(v1);
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
	DrawLine3D(v1.start, v1.end, ORANGE);
	DrawLine3D(v2.start, v2.end, PURPLE);
	DrawLine3D(v3.start, v3.end, YELLOW);

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
	camera.position = Vector3{ 0.0f, 2.0f, 10.0f }; // Posicionada apuntando al angulo YX.
	camera.target = Vector3{ 0.0f, 2.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	InitVectors();
}