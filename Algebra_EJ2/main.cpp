#include <iostream>
#include "raylib.h"

using namespace std;

const int windowWidth = 800;
const int windowHeight = 450;

struct Vector {
	Vector3 start;
	Vector3 end;
};

Vector v1;
Vector v2;
Vector v3;

int main() {

	// Init
	InitWindow(windowWidth, windowHeight, "Algebra Ej2");

	Camera3D camera = {};
	camera.position = Vector3{ 10.0f, 10.0f, 10.0f};
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	SetCameraMode(camera, CAMERA_FREE);

	cout << "Grupo 3\n";

	v1.start.x = 0;
	v1.start.y = 0;
	v1.start.z = 0;

	v2.start.x = 0;
	v2.start.y = 0;
	v2.start.z = 0;

	v3.start.x = 0;
	v3.start.y = 0;
	v3.start.z = 0;

	v1.end.x = 5;
	v1.end.y = 0;
	v1.end.z = 0;

	v2.end.x = 0;
	v2.end.y = 5;
	v2.end.z = 0;

	v3.end.x = 0;
	v3.end.y = 0;
	v3.end.z = 5;
	// Loop
	while (!WindowShouldClose()) {
		// Update
		UpdateCamera(&camera);

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);

		DrawLine(0, GetScreenHeight() * .9, GetScreenWidth(), GetScreenHeight() * .9, ORANGE);

		BeginMode3D(camera); // 3D

		DrawLine3D(v1.start, v1.end, RED);
		DrawLine3D(v2.start, v2.end, BLUE);
		DrawLine3D(v3.start, v3.end, GREEN);

		EndMode3D();


		EndDrawing();
	}
	
	// Close
	CloseWindow();
	return 0;
}