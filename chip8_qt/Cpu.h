/**
 * @file Cpu.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-08-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <vector>
#include <string>

//TODO fill out class
/**
 * @brief Emulates a CPU
 */
class Cpu
{
public:
    Cpu(/* args */);
    ~Cpu();

    /**
     * @brief
     *
     */
    void loadSpritesIntoMemory();

    /**
     * @brief
     *
     * @param program
     * @return true Program successfully loaded into memory.
     */
    bool loadProgramIntoMemory(std::vector<int> program); // TODO program variable type???

    /**
     * @brief Grabs ROM file from local filesystem.
     *
     * @param romName Local file name containing ROM.
     */
    void loadROM(std::string romName);

    /**
     * @brief Cycles the CPU.
     *
     */
    void cycle();

    /**
     * @brief Update delay and sound timers.
     *
     */
    void updateTimers();

    /**
     * @brief If sound timer is greater than zero, play a sound.
     *
     */
    void playSound();

    /**
     * @brief Handles all 36 of the Chip-8 instructions.
     *
     */
    void executeInstruction(int opcode);

private:
    // Array of hex values for each sprite. Each sprite is 5 bytes.
    const int sprites_[80] = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    bool isPaused_;
    int speed_;

    std::vector<int> stack_;
    unsigned long int program_counter_; // currently executing address
    int delay_timer_; // keeps track of when certain events occur
    int sound_timer_; // controls length of sound

    unsigned long int mem_address_;
    uint8_t registers_[16]; // 16 8-bit registers
    uint8_t memory_[4096]; // 4KB (4096 bytes) of memory
};
