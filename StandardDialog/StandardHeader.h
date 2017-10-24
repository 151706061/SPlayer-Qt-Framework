#pragma once

#include <QLabel>
#include <QWidget>

#include "Control/BaseWidget.h"
#include "Control/SButton.h"

class StandardHeader : public BaseWidget
{
    Q_OBJECT

public:
    explicit StandardHeader(QWidget *parent = Q_NULLPTR);
    virtual ~StandardHeader();

public:
    void SetLogoVisible(bool bVisible);
    void SetTitleText(const QString &str);
    void SetTitleCenter(bool bCenter);
    void SetSkinVisible(bool bVisible);
    void SetMinVisible(bool bVisible);
    void SetMaxVisible(bool bVisible);
    void SetCloseVisible(bool bVisible);
    void SetMaxImage();
    void SetRestoreImage();
    QWidget *getTitleBarLabel();

signals:
    void Signal_LogoClicked();
    void Signal_SkinClicked();
    void Signal_MinClicked();
    void Signal_MaxClicked();
    void Signal_CloseClicked();

private:
    void CreateLayout();

private:
    SButton *m_pLogo;
    QLabel *m_pTitle;
    SButton *m_pSkin;
    SButton *m_pMin;
    SButton *m_pMax;
    SButton *m_pClose;
    QColor m_backgroundColor;
};
