#include "Cpu.h"

Cpu::Cpu() :
    isPaused_(false),
    program_counter_(0x200),
    delay_timer_(0),
    sound_timer_(0),
    mem_address_(0),
    speed_(10)
{}

Cpu::~Cpu()
{
}

/**
* @brief Loads sprites into memory.
* Sprites are stored in the interpreter section of memory starting at hex 0x000.
*
*/
void Cpu::loadSpritesIntoMemory()
{
    int spriteArrLength = sizeof(sprites_) / sizeof(int);
    for (int i = 0; i < spriteArrLength; i++) {
        memory_[i] = sprites_[i];
    }
}

/**
* @brief
*
* @param program
* @return true Program successfully loaded into memory.
*/
bool Cpu::loadProgramIntoMemory(std::vector<int> program)
{
    if (program.size() <= 0)
    {
        return false;
    }
    for (int loc = 0; loc < program.size(); loc++) {
        memory_[0x200 + loc] = program[loc];
    }
    return true;
}

/**
* @brief Grabs ROM file from local filesystem.
*
* @param romName Local file name containing ROM.
*/
void Cpu::loadROM(std::string romName)
{
    // TODO: investigate Qt how to popup file selection UI window
}

/**
* @brief Cycles the CPU.
*
*/
void Cpu::cycle()
{
    // Execute instructions when emulator is running
    for (int i = 0; i < speed_; i++) {
        if (!isPaused_) {
            // Each instruction is 16 bits or 2 bytes long; however our memory is made up of 8 bit (1 byte) pieces
            // 2 pieces of memory = full opcode
            // 1) Shift first piece of memory 8 bits left -> mem << 8
            // 2) Perform bitwise or to add the second piece of memory -> mem + 1
            // Ex: PC = 0x10 --> 0x1000
            // PC + 1 = 0xF0, 0x1000 | 0xF0
            // Result: 0x10F0
            int opcode = (memory_[program_counter_] << 8 | memory_[program_counter_ + 1]);

            // TODO:
            executeInstruction(opcode);
        }
    }

    if (!isPaused_) {
        updateTimers();
    }

    playSound();
    //    renderer.render(); // TODO
}


/**
* @brief Update delay and sound timers.
*
*/
void Cpu::updateTimers()
{
    if (delay_timer_ > 0) {
        this->delay_timer_ -= 1;
    }
    if (sound_timer_ > 0) {
        sound_timer_ -= 1;
    }
}

/**
* @brief If sound timer is greater than zero, play a sound.
*
*/
void Cpu::playSound()
{
    // TODO: ... reference Speaker?
}

/**
* @brief Handles all 36 of the Chip-8 instructions.
*
*/
void Cpu::executeInstruction(int opcode)
{
    program_counter_ += 2; // instructions are 2 bytes long
    // We only need the 2nd nibble, so grab the value of the 2nd nibble
    // and shift it right 8 bits to get rid of everything but that 2nd nibble.
    int x = (opcode & 0x0F00) >> 8;

    // We only need the 3rd nibble, so grab the value of the 3rd nibble
    // and shift it right 4 bits to get rid of everything but that 3rd nibble.
    int y = (opcode & 0x00F0) >> 4;

    // TODO: switch case for each instruction?
}




