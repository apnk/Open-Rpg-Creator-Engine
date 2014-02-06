#ifndef _COMMON_HPP_
#define _COMMON_HPP_

const static int TILE_DIMENSION = 32;
const static int CHARSET_WIDTH = 32;
const static int CHARSET_HEIGHT = 32;
const static int CHARSET_ANIMATION_COLUMNS = 3;
const static int CHARSET_ANIMATION_ROWS = 4;
const static int SCREEN_WIDTH = 1000;
const static int SCREEN_HEIGHT = 600;
const static int SCREEN_BPP = 32;
const static int FRAMES_PER_SECONDS = 15;

enum Mode {
    RANDOM = 0, PATH = 1, PATHCIR = 2
};

enum Direction {
    DOWN = 0, LEFT = 1, RIGHT = 2, UP = 3
};

enum NPC {
    NORMAL, QUEST, SELLER
};

#endif
