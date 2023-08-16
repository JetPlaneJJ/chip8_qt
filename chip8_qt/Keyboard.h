#ifndef Keyboard_h
#define Keyboard_h

#include <unordered_map>
#include <QKeyEvent>

/**
 * @brief The Keyboard class handles keyboard state.
 */
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
     * @param key
     * @return true if key is currently pressed
     */
    bool isKeyPressed(Qt::Key key) const;

    /**
     * @brief setKeyPressed
     * @param key of type Qt Key pressed
     * @param pressed - true if key is currently pressed
     * @return false if key not supported
     */
    bool setKeyPressed(Qt::Key key, bool pressed);

    /**
     * @brief clearKeysPressed Sets all keys to unpressed
     */
    void clearKeysPressed();

private:
    std::unordered_map<int, bool> keysPressed_ = {
        {Qt::Key_1, false}, // 1
        {Qt::Key_2, false}, // 2
        {Qt::Key_3, false}, // 3
        {Qt::Key_4, false}, // 4
        {Qt::Key_Q, false}, // Q
        {Qt::Key_W, false}, // W
        {Qt::Key_E, false}, // E
        {Qt::Key_R, false}, // R
        {Qt::Key_A, false}, // A
        {Qt::Key_S, false}, // S
        {Qt::Key_D, false}, // D
        {Qt::Key_F, false}, // F
        {Qt::Key_Z, false}, // Z
        {Qt::Key_X, false}, // X
        {Qt::Key_C, false}, // C
        {Qt::Key_V, false}  // V
    };

    // Chip-8 uses a 16-key hex keypad
    const std::unordered_map<int, int> keymap_ = {
        {Qt::Key_1, 0x1}, // 1
        {Qt::Key_2, 0x2}, // 2
        {Qt::Key_3, 0x3}, // 3
        {Qt::Key_4, 0xc}, // 4
        {Qt::Key_Q, 0x4}, // Q
        {Qt::Key_W, 0x5}, // W
        {Qt::Key_E, 0x6}, // E
        {Qt::Key_R, 0xD}, // R
        {Qt::Key_A, 0x7}, // A
        {Qt::Key_S, 0x8}, // S
        {Qt::Key_D, 0x9}, // D
        {Qt::Key_F, 0xE}, // F
        {Qt::Key_Z, 0xA}, // Z
        {Qt::Key_X, 0x0}, // X
        {Qt::Key_C, 0xB}, // C
        {Qt::Key_V, 0xF}  // V
    };
};

#endif /* Keyboard_h */
