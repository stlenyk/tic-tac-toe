#ifndef TIC_TAC_TOE_SFML_CONSTANTS_H
#define TIC_TAC_TOE_SFML_CONSTANTS_H

// Window settings
#define SCREEN_WIDTH 850
#define SCREEN_HEIGHT 850
#define SCREEN_TITLE "Kolko i krzyzyk"

// Image paths
#define SPLASH_BG_PATH "res/splash_bg.png"
#define X_PATH "res/X.png"
#define O_PATH "res/O.png"
#define BOARD_PATH "res/board.png"
#define REPLAY_PATH "res/replay.png"
#define X_WIN_PATH "res/X_win.png"
#define O_WIN_PATH "res/O_win.png"

// Splash screen
#define SPLASH_SHOW_TIME 2

// GameLoop
#define FRAME_RATE 60.0f
#define MAX_FRAME_TIME 0.2f


// Game logic
#define X_PIECE 0
#define O_PIECE 1
#define BLANK_PIECE -1
#define HUMAN_PIECE X_PIECE
#define AI_PIECE O_PIECE


#endif //TIC_TAC_TOE_SFML_CONSTANTS_H
