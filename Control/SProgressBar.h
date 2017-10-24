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

public slots:
    void setMinimum(int value);
    int minimum() const;
    void setMaximum(int value);
    int maximum() const;
    void setValue(int value);
    int value() const;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    int m_currentProgress, min, max;
};
