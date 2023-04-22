#include <cstdio>

#include "raylib.h"
#include "glfw/deps/glad/gl.h"

int main() {
    int height{1200};
    int width{1600};

    InitWindow(height, width, "Circle");

    int circle_x = height / 2;
    int circle_y = width / 2;
    int circle_radius = 50;
    int circle_min_radius = circle_radius;
    int circle_max_radius = height < width ? height / 2 : width / 2;
    int circle_radius_step = 50;
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

            if (circle_x + circle_radius > height) {
                circle_x = height - circle_radius;
            }

            if (circle_y + circle_radius > width) {
                circle_y = width - circle_radius;
            }

            if (circle_x - circle_radius < 0) {
                circle_x = circle_radius;
            }

            if (circle_y - circle_radius < 0) {
                circle_y = circle_radius;
            }

            if (IsKeyDown(KEY_PAGE_UP)) {
                circle_radius += circle_radius_step;
            }

            if (IsKeyDown(KEY_PAGE_DOWN)) {
                circle_radius -= circle_radius_step;
            }

            if (circle_radius > circle_max_radius) {
                circle_radius = circle_max_radius;
            }

            if (circle_radius <= circle_min_radius) {
                circle_radius = circle_min_radius;
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
