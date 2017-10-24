/****************************************************
 * 这个类继承自QWidget                                *
 * 这个类使QWidget可以被鼠标左键按住拖动                 *
 ****************************************************/

#pragma once

#include <QWidget>

class DraggableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DraggableWidget(QWidget *parent = Q_NULLPTR);
    ~DraggableWidget();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
    //设置窗口是否可以被鼠标左键按住拖动（鼠标右键默认不能拖动）
    void setWindowMovable(bool m_movable = true);
    //返回窗口是否可以被鼠标左键按住拖动
    bool windowMovable() const;
    //返回窗口是否正被鼠标左键按住
    bool windowPressed() const;

private:
    bool m_bMovable;
    bool m_bPressed;
    QPoint m_pSourcePosition;
};
