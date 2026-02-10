#include <raylib.h>

// variables
constexpr int screenWidth = 800;
constexpr int screenHeight = 600;
bool gameOver = false;
bool start = false;

constexpr int playerJump = -400;
Vector2 playerPos = {75, screenHeight/2.0f};

int currentFrame = 0;
float frameTimer = 0.0f;
constexpr float frameSpeed = 0.12f;
Rectangle frames[3] = {{0, 0, 17, 12},
    { 28, 0, 17, 12},
    { 56, 0, 17, 12 }
};

constexpr int gravity = 1200;
float velocity;
constexpr int maxFallSpeed = 900;


// function
void playerGravity(const float dt) {
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

void playerAnimation(const float dt) {
    frameTimer += dt;
    if (frameTimer >= frameSpeed) {
        frameTimer = 0.0f;
        currentFrame++;
        if (currentFrame >= 3) {currentFrame = 0;}
    }
}

// main window
int main()
{
    InitWindow(screenWidth, screenHeight, "flappy bird");
    SetTargetFPS(60);

    const Texture player = LoadTexture("../assets/player.png");

    while (!WindowShouldClose()) {
        const float dt = GetFrameTime();
        Rectangle playerDest = {playerPos.x, playerPos.y, 17*3, 12*3};

        if ((playerPos.y + 50) >= screenHeight) {gameOver = true;}

        if (!gameOver) {
            playerGravity(dt);
            playerAnimation(dt);

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexturePro(player, frames[currentFrame], playerDest, {0,0}, 0, WHITE);

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
    UnloadTexture(player);
    return 0;
}
