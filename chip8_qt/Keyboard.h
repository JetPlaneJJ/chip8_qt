#ifndef Keyboard_h
#define Keyboard_h

#include <unordered_map>

class Keyboard
{
public:
    /**
     * @brief Construct a new Keyboard object, mapping Chip8 controls to a modern keyboard input
     *
     */
    Keyboard();
    ~Keyboard();

    /**
     * @param keyCode representing key pressed on keyboard
     * @return true if keyCode was pressed
     */
    bool isKeyPressed(int keyCode);

    /**
     * @brief onKeyDown will be called upon key pressed event
     *
     */
    void onKeyDown(); // TODO: event

    // void onKeyUp(event);

private:
    std::unordered_map<int, bool> keysPressed_;
    const std::unordered_map<int, int> keymap_ = {
        {49, 0x1}, // 1
        {50, 0x2}, // 2
        {51, 0x3}, // 3
        {52, 0xc}, // 4
        {81, 0x4}, // Q
        {87, 0x5}, // W
        {69, 0x6}, // E
        {82, 0xD}, // R
        {65, 0x7}, // A
        {83, 0x8}, // S
        {68, 0x9}, // D
        {70, 0xE}, // F
        {90, 0xA}, // Z
        {88, 0x0}, // X
        {67, 0xB}, // C
        {86, 0xF}  // V
    };
};

#endif /* Keyboard_h */
