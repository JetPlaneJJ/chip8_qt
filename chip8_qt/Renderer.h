#ifndef Renderer_h
#define Renderer_h

#include <vector>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QMouseEvent>

/**
 * @brief Renderer handles emulator graphics rendering
 *
 */
class Renderer : public QWidget
{
public:
    explicit Renderer(QWidget *parent = nullptr, int scale = 10);
    ~Renderer();

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE
    {
        mouse_pos_ = event->pos();
        update();
    }

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

    /**
     * @brief Renders pixels in display at 60 times/second.
     * @param event
     */
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int width_; // canvas width
    int height_;
    int scale_;
    std::vector<int> display_; // 1D array representing pixels on screen
    QPoint mouse_pos_; // position of mouse
};

// Chip-8 has 64x32 display size.
static const int kDefault_row_size = 32; // height
static const int kDefault_col_size = 64; // width

#endif /* Renderer.h */
