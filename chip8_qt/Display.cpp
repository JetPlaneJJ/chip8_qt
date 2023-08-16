#include <array>
#include <vector>
#include <QWindow>
#include <QMainWindow>
#include <QRect>
#include <QPainterPath>
#include <QPainter>

#include "Display.h"

Display::Display(QWidget *parent, int scale) :
    QWidget(parent),
    scale_(scale),
    width_(kDefault_col_size * scale),
    height_(kDefault_row_size * scale)
{
    setFixedSize(width_, height_);
    pixels_ = std::vector<int>(kDefault_row_size * kDefault_col_size, 0);
    keyboard_ = new Keyboard();
}

Display::~Display()
{
    delete keyboard_;
}

/**
 * @brief Toggles a pixel at x, y location.
 *
 * @param x column
 * @param y row
 * @return true Pixel at x, y was set.
 * @return false Pixel at x, y was erased.
 */
bool Display::setPixel(int x, int y)
{
    // Handle out of bounds pixel
    x %= (kDefault_col_size);
    y %= (kDefault_row_size);

    const int pixelLoc = x + (y * kDefault_col_size);
    pixels_[pixelLoc] ^= 1; // toggle pixel
    return pixels_[pixelLoc];
}

/**
 * @brief Clears the display.
 *
 */
void Display::clear()
{
    std::fill(pixels_.begin(), pixels_.end(), 0);
}

/**
 * @brief Renders pixels in display at 60 times/second.
 *
 */
void Display::paintEvent(QPaintEvent *event)
{
    // TODO: Clear the display every render cycle.

    QPainter painter(this);
    QBrush brush(Qt::black);
    painter.setPen(Qt::black);
    painter.setBrush(brush);

    for (int i = 0; i < kDefault_col_size * kDefault_row_size; i++) {
        int x = (i % kDefault_col_size) * scale_;
        int y = std::floor(i / kDefault_col_size) * scale_;
        if (pixels_[i]) {
            QRect rect(x, y, scale_, scale_);
            painter.drawRect(rect);
        }
    }
}

/**
 * @brief Test-draw a few pixels on the screen.
 *
 */
void Display::testRender()
{
    Display::setPixel(0, 0);
    Display::setPixel(60, 1);
    Display::setPixel(15, 3);
    Display::setPixel(2, 89);
}
