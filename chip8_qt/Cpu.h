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
    bool loadProgramIntoMemory(std::string program); // TODO program variable type???

    /**
     * @brief
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
    const int speed_ = 10;
    bool isPaused_;

    std::vector<int> stack_;
    unsigned long int program_counter_;
    int delay_timer_;
    int sound_timer_;

    unsigned long int mem_address_;
    std::vector<unsigned int> registers_; // 16 8-bit registers
    std::vector<unsigned int> memory_; // 4KB (4096 bytes) of memory
};
