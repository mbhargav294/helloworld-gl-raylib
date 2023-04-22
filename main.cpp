#include <cstdio>
#include <string>

#include "raylib.h"

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
    std::string prompt = "Key Pressed: ";
    std::string key = "None";

    SetTargetFPS(30);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            key = "None";

            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                circle_x += circle_radius;
                key = "Right";
            }

            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                circle_x -= circle_radius;
                key = "Left";
            }

            if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
                circle_y -= circle_radius;
                key = "Up";
            }

            if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
                circle_y += circle_radius;
                key = "Down";
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
                key = "PgUp";
            }

            if (IsKeyDown(KEY_PAGE_DOWN)) {
                circle_radius -= circle_radius_step;
                key = "PgDown";
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
                key = "Space";
            }

            DrawCircle(circle_x, circle_y, circle_radius, circle_color);

            std::string debug_statement = prompt + key;
            DrawText(debug_statement.c_str(), height / 10, width / 10, 48, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
