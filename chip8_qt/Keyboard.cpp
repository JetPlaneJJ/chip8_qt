#include "Keyboard.h"

Keyboard::Keyboard()
{
    // Some Chip-8 instructions require waiting for the next keypress.
    // We initialize this function elsewhere when needed.
    // this.onNextKeyPress = null;

    // window.addEventListener('keydown', this.onKeyDown.bind(this), false);
    // window.addEventListener('keyup', this.onKeyUp.bind(this), false);
}

Keyboard::~Keyboard() {}

/**
 * @param keyCode representing key pressed on keyboard
 * @return true if keyCode was pressed
 */
bool Keyboard::isKeyPressed(int keyCode)
{
    return keysPressed_[keyCode];
}

/**
 * @brief onKeyDown will be called upon key pressed event
 *
 */
void Keyboard::onKeyDown()
{
    // TODO: How to handle this in C++/Qt?
    // let key = this.KEYMAP[event.which];
    // this.keysPressed[key] = true;

    // // Make sure onNextKeyPress is initialized and the pressed key is actually mapped to a Chip-8 key
    // if (this.onNextKeyPress !== null && key) {
    //     this.onNextKeyPress(parseInt(key));
    //     this.onNextKeyPress = null;
    // }
}
