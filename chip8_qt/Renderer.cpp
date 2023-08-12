#include <array>
#include <vector>
#include <QWindow>
#include <QMainWindow>
#include <QRect>
#include <QPainterPath>
#include <QPainter>

#include "Renderer.h"

Renderer::Renderer(QWidget *parent, int scale) :
    QWidget(parent),
    scale_(scale),
    width_(kDefault_col_size * scale),
    height_(kDefault_row_size * scale)
{
    setFixedSize(width_, height_);
    display_ = std::vector<int>(kDefault_row_size * kDefault_col_size, 0);
}

Renderer::~Renderer(){}

/**
 * @brief Toggles a pixel at x, y location.
 *
 * @param x column
 * @param y row
 * @return true Pixel at x, y was set.
 * @return false Pixel at x, y was erased.
 */
bool Renderer::setPixel(int x, int y)
{
    // Handle out of bounds pixel
    x %= (kDefault_col_size);
    y %= (kDefault_row_size);

    const int pixelLoc = x + (y * kDefault_col_size);
    display_[pixelLoc] ^= 1; // toggle pixel
    return display_[pixelLoc];
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
void Renderer::paintEvent(QPaintEvent *event)
{
    // TODO: Clear the display every render cycle.

    QPainter painter(this);
    QBrush brush(Qt::black);
    painter.setPen(Qt::black);
    painter.setBrush(brush);

    for (int i = 0; i < kDefault_col_size * kDefault_row_size; i++) {
        int x = (i % kDefault_col_size) * scale_;
        int y = std::floor(i / kDefault_col_size) * scale_;
        if (display_[i]) {
            QRect rect(x, y, scale_, scale_);
            painter.drawRect(rect);
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
    Renderer::setPixel(60, 1);
    Renderer::setPixel(15, 3);
    Renderer::setPixel(2, 89);
}
