#ifndef Chip8_h
#define Chip8_h

#include <chrono>

/**
 * @brief Chip8 Initializes the Renderer
 *
 */
class Chip8
{
public:
    Chip8();
    ~Chip8();

    /**
     * @brief Initialize renderer at 60fps, use for testing.
     *
     */
    void initializeRenderer();

private:
    /**
     * @brief Cycle the CPU
     *
     */
    void step();
    const int fps_{60};
    int fpsInterval_;

    std::chrono::steady_clock::time_point start_; // Starting timestamp
    std::chrono::steady_clock::time_point end_;
};

#endif /* Chip8_h */
