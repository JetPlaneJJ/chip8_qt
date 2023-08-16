#include "Keyboard.h"

Keyboard::Keyboard()
{
    // Some Chip-8 instructions require waiting for the next keypress.
    // this.onNextKeyPress = null;
}

Keyboard::~Keyboard() {}

/**
 * @param keyCode representing key pressed on keyboard
 * @return true if key is currently pressed
 */
bool Keyboard::isKeyPressed(Qt::Key key) const
{
    auto pos = keysPressed_.find(key);
    return (pos != keysPressed_.end() && pos->second);
}

/**
* @brief setKeyPressed
* @param key of type Qt Key pressed
* @param pressed - true if key is currently pressed
* @return false if key not supported
*/
bool Keyboard::setKeyPressed(Qt::Key key, bool pressed)
{
    auto pos = keysPressed_.find(key);
    if (pos != keysPressed_.end())
    {
        pos->second = pressed;
        return true;
    }
    return false;
}

/**
* @brief clearKeysPressed Sets all keys to unpressed
*/
void Keyboard::clearKeysPressed()
{
    for (auto& [_, v] : keysPressed_) v = false;
}
