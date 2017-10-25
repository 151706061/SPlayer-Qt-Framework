#pragma once

#include "BaseWidget.h"

class SProgressBar : public BaseWidget
{
    Q_OBJECT

public:
    SProgressBar(QWidget *parent = Q_NULLPTR);
    virtual ~SProgressBar();

signals:
    void sliderMoved(int value);
    void rangeChanged(int min_value, int max_value);

public slots:
    void setMinimum(int value = 0);
    int minimum() const;
    void setMaximum(int value = 1000);
    int maximum() const;
    void setRange(int min_value = 0, int max_value = 1000);
    void setValue(int value = 0);
    int value() const;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    int m_currentProgress, min, max;
};
