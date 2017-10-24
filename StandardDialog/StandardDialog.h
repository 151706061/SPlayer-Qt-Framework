#pragma once

#include <QVBoxLayout>

#include "StandardHeader.h"
#include "StandardBottom.h"
#include "Control/framelesswindow.h"

class StandardDialog : public CFramelessWindow
{
    Q_OBJECT

public:
    explicit StandardDialog(QWidget *parent = Q_NULLPTR);
    virtual ~StandardDialog();

public:
    StandardHeader *GetHeader();
    StandardBottom *GetBottom();

protected slots:
    virtual void Slot_LogoClicked();
    virtual void Slot_SkinClicked();
    virtual void Slot_MinClicked();
    virtual void Slot_MaxClicked();
    virtual void Slot_CloseClicked();

protected:
    void SetCenterWidget(QWidget *pCenterWidget);
    void SetBottomWidget(QWidget *pBottomWidget);

private:
    StandardHeader *m_pHeader;
    StandardBottom *m_pBottom;
    QVBoxLayout *m_pVBoxLayout;
};
