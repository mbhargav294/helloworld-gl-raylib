#include <cstdio>

#include "raylib.h"
#include "glfw/deps/glad/gl.h"

int main() {
    int height{800};
    int width{800};
    InitWindow(height, width, "This is a graphics window");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Yay! This is a new Hello Wrold!", 50, 400, 48, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
