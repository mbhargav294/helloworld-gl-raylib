#include <cstdio>
#include <string>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"

int main() {
    int width{ 1600 };
    int height{ 1600 };

    InitWindow(width, height, "Circle");

    // Circle measurements
    int circle_x = width / 2;
    int circle_y = height / 2;
    int circle_radius = 10;
    int circle_min_radius = circle_radius;
    int circle_max_radius = 200;
    int circle_radius_step = 5;

    srand(time(NULL));

    // Rectangle measurements
    int rectangle_x = rand() % (width - 100) + 100;
    int rectangle_y = rand() % (width - 100) + 100;
    float rectangle_width = 25;
    float rectangle_height = 25;
    float rectangle_rotation = 0;

    // UI prompt text
    std::string prompt = "Key Pressed: ";
    std::string key = "None";
    std::string score_text = "Score: ";
    int score = 0;
    int score_increment = 10;

    SetTargetFPS(30);
    while (!WindowShouldClose()) {
        BeginDrawing();

        // Tracking circle's hit boxes
        int l_circle_x{ circle_x - circle_radius };
        int r_circle_x{ circle_x + circle_radius };
        int u_circle_y{ circle_y - circle_radius };
        int b_circle_y{ circle_y + circle_radius };

        // Tracking rectangle's hit boxes
        int l_rectangle_x{ rectangle_x };
        int r_rectangle_x{ rectangle_x + (int)rectangle_width };
        int u_rectangle_y{ rectangle_y };
        int b_rectangle_y{ rectangle_y + (int)rectangle_height };

        ClearBackground(BLACK);

        // Detect if the collision is detected between circle and rectangle
        bool collision_detected = b_rectangle_y >= u_circle_y &&
            u_rectangle_y <= b_circle_y &&
            l_rectangle_x <= r_circle_x &&
            r_rectangle_x >= l_circle_x;
        if (collision_detected) {
            // Increment the score
            score += score_increment;

            // Respawn the rectangle at a different location
            rectangle_x = rand() % (width - 100) + 100;
            rectangle_y = rand() % (width - 100) + 100;

            // Increment the circle radius and cap it at a max radius
            circle_radius += circle_radius_step;
        }
        key = "None";

        // Player intended to move right
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            circle_x += 10 + (circle_radius * 0.3);
            key = IsKeyDown(KEY_RIGHT) ? "Right" : "D";
        }

        // Player intended to move left
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            circle_x -= 10 + (circle_radius * 0.3);;
            key = IsKeyDown(KEY_LEFT) ? "Left" : "A";
        }

        // Player intended to move up
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            circle_y -= 10 + (circle_radius * 0.3);;
            key = IsKeyDown(KEY_UP) ? "Up" : "W";
        }

        // Player intended to move down
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            circle_y += 10 + (circle_radius * 0.3);;
            key = IsKeyDown(KEY_DOWN) ? "Down" : "S";
        }

        // Make sure the circle stays within the window.
        if (circle_x + circle_radius > width) {
            circle_x = width - circle_radius;
        }

        if (circle_y + circle_radius > height) {
            circle_y = height - circle_radius;
        }

        if (circle_x - circle_radius < 0) {
            circle_x = circle_radius;
        }

        if (circle_y - circle_radius < 0) {
            circle_y = circle_radius;
        }

        if (circle_radius > circle_max_radius) {
            circle_radius = circle_max_radius;
        }

        if (circle_radius <= circle_min_radius) {
            circle_radius = circle_min_radius;
        }

        // Render the circle on screen
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);

        // Construct the Rectangle
        Rectangle r = {
            (float)rectangle_x,
            (float)rectangle_y,
            rectangle_width,
            rectangle_height
        };
        rectangle_rotation = (int)(rectangle_rotation + 10) % 360;

        // Render Rectangle on screen
        DrawRectanglePro(r, { rectangle_width / 2, rectangle_height / 2 },
                         rectangle_rotation, GREEN);

        // UI elements
        std::string debug_statement = prompt + key;
        DrawText(debug_statement.c_str(), 100, height - 100, 48, RED);

        std::string score_ui_text = score_text + std::to_string(score);
        DrawText(score_ui_text.c_str(), width / 2 - 100, height / 10, 48, YELLOW);
        DrawFPS(width - 100, 0);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
