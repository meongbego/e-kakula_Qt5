#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

class Bubble;
class QtLogo;

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize sizeHint() const;
    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

protected:
    void initializeGL();
    void paintEvent(QPaintEvent *event);
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);

private slots:
    void animate();

private:
    void createBubbles(int number);
    void drawInstructions(QPainter *painter);
    void setupViewport(int width, int height);

    //QColor qtGreen;
    QColor kuning;

    GLuint object;
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
    //QtLogo *logo;
    QList<Bubble*> bubbles;
    QTimer animationTimer;
};

#endif // GLWIDGET_H
