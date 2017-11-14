#include "SStyle.h"

#include <QFile>
#include <QTextStream>

SStyle::SStyle()
{
    //读取皮肤样式文本
    QFile skinFile(":/QSS/Resource/default.qss");
    skinFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream ts(&skinFile);
    m_styleStr = ts.readAll();
    //qDebug() << "m_styleStr::" << m_styleStr;
}

SStyle::~SStyle()
{

}

QString SStyle::GetStyle()
{
    return m_styleStr;
}
