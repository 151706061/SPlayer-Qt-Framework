#include "DraggableWidget.h"

#include <QMouseEvent>
#include <QSizePolicy>

DraggableWidget::DraggableWidget(QWidget *parent) : QWidget(parent)
  , m_bMovable(true)
  , m_bPressed(false)
  , m_pSourcePosition(QPoint())
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setMouseTracking(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

DraggableWidget::~DraggableWidget()
{
}

void DraggableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        m_bPressed = false;
        QWidget::mousePressEvent(event);
        return;
    }
    m_bPressed = true;
    m_pSourcePosition = event->globalPos();
    QWidget::mousePressEvent(event);
}

void DraggableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isMaximized() || (windowState() == Qt::WindowFullScreen))
    {
        QWidget::mouseMoveEvent(event);
        return;
    }
    if (m_bPressed)
    {
        if (!m_pSourcePosition.isNull() && m_bMovable) //移动窗口
        {
            move(pos() + (event->globalPos() - m_pSourcePosition));
        }
        m_pSourcePosition = event->globalPos();
    }
    QWidget::mouseMoveEvent(event);
}

void DraggableWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_bPressed = false;
    m_pSourcePosition = QPoint();
    QWidget::mouseReleaseEvent(event);
}

void DraggableWidget::setWindowMovable(bool m_movable)
{
    m_bMovable = m_movable;
}

bool DraggableWidget::windowMovable() const
{
    return m_bMovable;
}

bool DraggableWidget::windowPressed() const
{
    return m_bPressed;
}
