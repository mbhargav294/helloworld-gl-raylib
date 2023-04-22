#include <cstdio>

#include "raylib.h"
#include "glfw/deps/glad/gl.h"

int main() {
    int height{800};
    int width{800};
    InitWindow(height, width, "Circle");

    int circle_x = 400;
    int circle_y = 400;
    int circle_radius = 50;
    Color circle_color = {0, 255, 0, 255};

    SetTargetFPS(30);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                circle_x += circle_radius;
            }

            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                circle_x -= circle_radius;
            }

            if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
                circle_y -= circle_radius;
            }

            if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
                circle_y += circle_radius;
            }

            if (circle_x + circle_radius > 800) {
                circle_x = width - circle_radius;
            }

            if (circle_y + circle_radius > 800) {
                circle_y = height - circle_radius;
            }

            if (circle_x - circle_radius < 0) {
                circle_x = circle_radius;
            }

            if (circle_y - circle_radius < 0) {
                circle_y = circle_radius;
            }

            if (IsKeyDown(KEY_PAGE_UP)) {
                circle_radius += 50;
            }

            if (IsKeyDown(KEY_PAGE_DOWN)) {
                circle_radius -= 50;
            }

            if (circle_radius > 400) {
                circle_radius = 400;
            }

            if (circle_radius <= 0) {
                circle_radius = 50;
            }

            if (IsKeyDown(KEY_SPACE)) {
                circle_color.r = (circle_color.r + 10) % 255;
                circle_color.g = (circle_color.g + 20) % 255;
                circle_color.b = (circle_color.b + 30) % 255;
            }

            DrawCircle(circle_x, circle_y, circle_radius, circle_color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
