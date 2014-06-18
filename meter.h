#ifndef METER_H
#define METER_H

#include <QWidget>
#include <QtDesigner/QDesignerExportWidget>
#include <QPainter>
#include <QPen>
#include <math.h>

class QVUMeter : public QWidget
{
    Q_OBJECT

    QColor colorBg() const
    {
        return colBack;
    }
    QColor colorValue() const
    {
        return colValue;
    }
    QColor colorLow() const
    {
        return colLow;
    }
    QColor colorHigh() const
    {
        return colHigh;
    }
    double leftValue() const
    {
        return leftVal;
    }
    double rightValue() const
    {
        return rightVal;
    }
    double minValue() const
    {
        return min;
    }
    double maxValue() const
    {
        return max;
    }
    int valueDim() const
    {
        return dimVal;
    }


public:

    QVUMeter(QWidget *parent = 0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;


Q_SIGNALS:

    void valueLChanged(double);
    void valueRChanged(double);

public Q_SLOTS:

    void setColorBg(QColor);
    void setColorValue(QColor);
    void setColorHigh(QColor);
    void setColorLow(QColor);
    void setValueDim(int);
    void setLeftValue(double);
    void setRightValue(double);
    void setMinValue(double);
    void setMaxValue(double);


protected:

    void paintEvent(QPaintEvent *);
    void paintBorder();
    void paintBar();
    void paintValue();



private:

    double min;
    double max;
    double leftVal;
    double rightVal;
    int dimVal;
    QColor colBack;
    QColor colValue;
    QColor colHigh;
    QColor colLow;


};

#endif // METER_H
