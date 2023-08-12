#include "Chip8.h"
#include "Renderer.h"
#include "Chip8.h"
#include "Keyboard.h"
#include "Speaker.h"
#include "Cpu.h"
#include <ctime>

Chip8::Chip8(){}
Chip8::~Chip8()
{

}

/**
 * @brief Initialize renderer at 60fps, use for testing.
 *
 */
void Chip8::initializeRenderer()
{
    fpsInterval_ = 1000 / fps_;
    start_ = std::chrono::steady_clock::now();

    // TODO: TESTING CODE. REMOVE WHEN DONE TESTING.
//    Renderer* r = new Renderer(1);
//    r->testRender();
//    r->render();
//    delete r;

//    Keyboard* k = new Keyboard();
//    k->isKeyPressed(50); // TODO: enum
//    delete k;

//    Speaker* s = new Speaker();
//    s->play(50);
//    s->stop();
//    delete s;

//    Cpu* c = new Cpu();
    // TODO: test, move the above to class members and move all deletes to deconstructor
//    delete c;
    // END TEST

    // loop = requestAnimationFrame(step); TODO: ???
}

/**
 * @brief Cycle the CPU
 *
 */
void Chip8::step()
{
    end_ = std::chrono::steady_clock::now();
    // if (std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_).count(); > fpsInterval_) {
    // Cycle the CPU. We'll come back to this later and fill it out.
    // }

    // loop = requestAnimationFrame(step); TODO: ???
}
