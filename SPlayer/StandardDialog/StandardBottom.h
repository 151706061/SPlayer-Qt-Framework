#pragma once

#include <QHBoxLayout>

#include "Control/BaseWidget.h"

//界面底部基类
class StandardBottom : public BaseWidget
{
public:
    explicit StandardBottom(QWidget *parent = Q_NULLPTR);
    virtual ~StandardBottom();

public:
    void AddWidget(QWidget *pWidget);

public:
    QHBoxLayout *m_pHBoxLayout;
};
