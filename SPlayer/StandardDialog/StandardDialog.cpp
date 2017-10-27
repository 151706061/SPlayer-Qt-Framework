#include "StandardDialog.h"

#include <QSizePolicy>
#include <QMouseEvent>

StandardDialog::StandardDialog(QWidget *parent) : CFramelessWindow(parent)
{
    m_pHeader = new StandardHeader(this);
    m_pBottom = new StandardBottom(this);

    m_pVBoxLayout = new QVBoxLayout(this);
    m_pVBoxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVBoxLayout->setSpacing(0);
    setLayout(m_pVBoxLayout);
    m_pVBoxLayout->addWidget(m_pHeader);
    m_pVBoxLayout->addWidget(m_pBottom);

    setTitleBar(m_pHeader);
    addIgnoreWidget(m_pHeader->getTitleBarLabel());

    connect(m_pHeader,SIGNAL(Signal_LogoClicked()),this,SLOT(Slot_LogoClicked()));
    connect(m_pHeader,SIGNAL(Signal_SkinClicked()),this,SLOT(Slot_SkinClicked()));
    connect(m_pHeader,SIGNAL(Signal_MinClicked()),this,SLOT(Slot_MinClicked()));
    connect(m_pHeader,SIGNAL(Signal_MaxClicked()),this,SLOT(Slot_MaxClicked()));
    connect(m_pHeader,SIGNAL(Signal_CloseClicked()),this,SLOT(Slot_CloseClicked()));
}

StandardDialog::~StandardDialog()
{

}

StandardHeader *StandardDialog::GetHeader()
{
    return m_pHeader;
}

StandardBottom *StandardDialog::GetBottom()
{
    return m_pBottom;
}

void StandardDialog::Slot_LogoClicked()
{

}

void StandardDialog::Slot_SkinClicked()
{

}

void StandardDialog::Slot_MinClicked()
{
    showMinimized();
}

//m_restoreGeometry：：保留用于还原显示的窗口几何信息
void StandardDialog::Slot_MaxClicked()
{
    if (isMaximized())//还原
    {
        showNormal();
        m_pHeader->SetMaxImage();
    }
    else    //最大化
    {
        showMaximized();
        m_pHeader->SetRestoreImage();
    }
}

void StandardDialog::Slot_CloseClicked()
{
    close();
}

void StandardDialog::SetCenterWidget(QWidget *pCenterWidget)
{
    if (pCenterWidget)
    {
        pCenterWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        int index = m_pVBoxLayout->indexOf(m_pHeader);
        m_pVBoxLayout->insertWidget(index+1, pCenterWidget);
    }
}

void StandardDialog::SetBottomWidget(QWidget *pBottomWidget)
{
    if (pBottomWidget)
    {
        pBottomWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_pBottom->AddWidget(pBottomWidget);
    }
}

