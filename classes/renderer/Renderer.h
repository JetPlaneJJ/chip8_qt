#ifndef Renderer_h
#define Renderer_h

#include <vector>

/**
 * @brief Renderer handles emulator graphics rendering
 * 
 */
class Renderer
{
public:
    Renderer(int scale);
    ~Renderer();

    /**
     * @brief Toggles a pixel at x, y location on display.
     * 
     * @param x column
     * @param y row
     * @return true Pixel at x, y was erased.
     * @return false Nothing was erased.
     */
    bool setPixel(int x, int y);
    
    /**
     * @brief Clears the display.
     * 
     */
    void clear();

    /**
     * @brief Renders pixels in display at 60 times/second.
     * 
     */
    void render();

    /**
     * @brief Test-draw a few pixels on the screen.
     * 
     */
    void testRender();

private: 
    int width_; // canvas width
    int height_;
    int scale_;
    std::vector<int> display_; // 1D array representing pixels on screen
};

// Chip-8 has 64x32 display size.
static const int kDefault_row_size = 32;
static const int kDefault_col_size = 64;

#endif /* Renderer.h */