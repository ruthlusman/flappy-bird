#include <raylib.h>
#include <raymath.h>

// variables
const int screenWidth = 800;
const int screenHeight = 600;
bool gameOver = false;
bool start = false;

const int playerJump = -400;
Vector2 playerPos = {75, screenHeight/2};

const double gravity = 1200;
double velocity;
const int maxFallSpeed = 900;


// function
void playerGravity(float dt) {
    if (IsKeyPressed(KEY_SPACE)){
        velocity = playerJump;
        start = true;
    }
    if (start) {
        velocity += gravity * dt;
        if (velocity > maxFallSpeed) {velocity = maxFallSpeed;}
        playerPos.y += velocity * dt;
    }
}

// main window
int main()
{
    InitWindow(screenWidth, screenHeight, "flappy bird");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if ((playerPos.y + 50) >= screenHeight) {gameOver = true;}

        if (!gameOver) {
            playerGravity(dt);

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(playerPos.x, playerPos.y, 50, 50, BLUE);
            EndDrawing();
        }
        else {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("game over :(", screenWidth/2, screenHeight/2, 50, BLACK);
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}
