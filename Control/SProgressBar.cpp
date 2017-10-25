#include "SProgressBar.h"

#include <QPainter>
#include <QMouseEvent>

SProgressBar::SProgressBar(QWidget *parent) : BaseWidget(parent)
  , m_currentProgress(0)
  , min(0)
  , max(1000)
{

}

SProgressBar::~SProgressBar()
{

}

void SProgressBar::setMinimum(int value)
{
    min = value;
    emit rangeChanged(min, max);
}

int SProgressBar::minimum() const
{
    return min;
}

void SProgressBar::setMaximum(int value)
{
    max = value;
    emit rangeChanged(min, max);
}

int SProgressBar::maximum() const
{
    return max;
}

void SProgressBar::setRange(int min_value, int max_value)
{
    if (min_value >= max_value)
    {
        return;
    }
    min = min_value;
    max = max_value;
    emit rangeChanged(min, max);
}

void SProgressBar::setValue(int value)
{
    if (value <= min)
    {
        m_currentProgress = min;
    }
    else if (value >= max)
    {
        m_currentProgress = max;
    }
    else
    {
        m_currentProgress = value;
    }
    update();
    emit sliderMoved(value);
}

int SProgressBar::value() const
{
    return m_currentProgress;
}

void SProgressBar::paintEvent(QPaintEvent *event)
{
    QPainter objPainter(this);
    objPainter.setRenderHint(QPainter::Antialiasing);
    //绘背景
    objPainter.fillRect(rect(),QColor(31,31,31));
    //绘内容区背景
    objPainter.fillRect(contentsRect(),QColor(78,78,78));
    int range = max - min;
    if (range <= 1)
    {
        range = 1;
    }
    int nWidth = static_cast<float>(contentsRect().width())
            * static_cast<float>(m_currentProgress) / static_cast<float>(range);
    //绘进度条背景;
    objPainter.fillRect(contentsRect().x(),contentsRect().y(),nWidth,contentsRect().height(),QColor(26,158,255));

    BaseWidget::paintEvent(event);
}

void SProgressBar::mousePressEvent(QMouseEvent *event)
{
    int range = max - min;
    if (range <= 1)
    {
        range = 1;
    }
    int value = (static_cast<float>(event->pos().x()) / static_cast<float>(width()))
            * static_cast<float>(range);
    setValue(value);
    BaseWidget::mousePressEvent(event);
}
