#ifndef Renderer_h
#define Renderer_h

#include <iostream>
#include <ostream>
#include <vector>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>
#include "Keyboard.h"

/**
 * @brief Display represents the renderer window and handles emulator graphics rendering.
 *
 */
class Display : public QWidget
{
public:
    explicit Display(QWidget *parent = nullptr, int scale = 10);
    ~Display();

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
     * @brief Test-draw a few pixels on the screen.
     *
     */
    void testRender();

private:
    int width_; // canvas width
    int height_;
    int scale_;
    std::vector<int> pixels_; // 1D array representing pixels on screen
    QPoint mouse_pos_; // position of mouse
    Keyboard* keyboard_;

    /**
     * @brief Renders pixels in display at 60 times/second.
     * @param event
     */
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE
    {
        mouse_pos_ = event->pos();
        update();
    }

    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE
    {
        switch (event->key())
        {
            case Qt::Key_X:
                keyboard_->setKeyPressed(Qt::Key_X, true);
                std::cout << "Pressing X: " << keyboard_->isKeyPressed(Qt::Key_X) << std::endl;
                break;
            case Qt::Key_F:
                keyboard_->setKeyPressed(Qt::Key_F, true);
                std::cout << "Pressing F: " << keyboard_->isKeyPressed(Qt::Key_F) << std::endl;
                break;
            default:
                event->ignore();
                break;
        }
    }

    void keyReleaseEvent(QKeyEvent* event) Q_DECL_OVERRIDE
    {
        switch (event->key())
        {
        case Qt::Key_X:
                keyboard_->setKeyPressed(Qt::Key_X, false);
                std::cout << "KEY RELEASE X: " << keyboard_->isKeyPressed(Qt::Key_X) << std::endl;
                break;
        case Qt::Key_F:
                keyboard_->setKeyPressed(Qt::Key_F, false);
                std::cout << "KEY RELEASE F: " << keyboard_->isKeyPressed(Qt::Key_F) << std::endl;
                break;
        default:
                event->ignore();
                break;
        }
    }
};

// Chip-8 has 64x32 display size.
static const int kDefault_row_size = 32; // height
static const int kDefault_col_size = 64; // width

#endif /* Renderer.h */
