﻿#pragma once

#include <QString>

class SStyle
{

public:
    SStyle();
    ~SStyle();

public:
    QString GetStyle();

private:
    QString m_styleStr;
};
