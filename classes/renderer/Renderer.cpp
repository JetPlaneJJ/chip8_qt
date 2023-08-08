#include <array>
#include "Renderer.h"
#include <vector>

Renderer::Renderer(int scale) : 
    scale_(scale), 
    width_(kDefault_col_size * scale), 
    height_(kDefault_row_size * scale)
{
    display_ = std::vector<int>(kDefault_row_size * kDefault_col_size, 0);
}

Renderer::~Renderer(){}

/**
 * @brief Toggles a pixel at x, y location on display.
 * 
 * @param x column
 * @param y row
 * @return true Pixel at x, y was erased.
 * @return false Nothing was erased.
 */
bool Renderer::setPixel(int x, int y) 
{
    // Handle out of bounds pixel
    x > kDefault_col_size ? x -= kDefault_col_size : x += kDefault_col_size;
    y > kDefault_row_size ? y -= kDefault_row_size : y += kDefault_row_size;

    const int pixelLoc = x + (y * kDefault_col_size);
    display_[pixelLoc] ^= 1; // toggle pixel
    return !display_[pixelLoc];
}

/**
 * @brief Clears the display.
 * 
 */
void Renderer::clear() 
{
    std::fill(display_.begin(), display_.end(), 0);
}

/**
 * @brief Renders pixels in display at 60 times/second.
 * 
 */
void Renderer::render() 
{
    // TODO: Clear the display every render cycle.
    // this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);

    // Loop through our display array
    for (int i = 0; i < kDefault_col_size * kDefault_row_size; i++) {
        // Grabs the x position of the pixel based off of `i`
        int x = (i % kDefault_col_size) * scale_;

        // Grabs the y position of the pixel based off of `i`
        int y = std::floor(i / kDefault_col_size) * scale_;

        // If the value at this.display[i] == 1, then draw a pixel.
        if (display_[i]) {
            // TODO: Set the pixel color to black
            // this.ctx.fillStyle = '#000';

            // TODO: Place a pixel at position (x, y) with a width and height of scale
            // this.ctx.fillRect(x, y, this.scale, this.scale);
        }
    }
}

/**
 * @brief Test-draw a few pixels on the screen.
 * 
 */
void Renderer::testRender()
{
    Renderer::setPixel(0, 0);
    Renderer::setPixel(5, 2);
}