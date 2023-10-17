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
    return (isValidKey(key) && keysPressed_.find(key)->second);
}

/**
* @brief setKeyPressed
* @param key of type Qt Key pressed
* @param pressed - true if key is currently pressed
* @return false if key not supported
*/
bool Keyboard::setKeyPressed(Qt::Key key, bool pressed)
{
    if (!isValidKey(key))
    {
        return false;
    }
    keysPressed_.find(key)->second = pressed;
    return true;
}

/**
* @brief clearKeysPressed Sets all keys to unpressed
*/
void Keyboard::clearKeysPressed()
{
    for (auto& [_, v] : keysPressed_) v = false;
}

/**
* @brief isValidKey
* @return true if key is supported on Chip 8 system
*/
bool Keyboard::isValidKey(Qt::Key key) const
{
    return keysPressed_.count(key);
}
