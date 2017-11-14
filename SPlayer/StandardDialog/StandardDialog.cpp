#include "StandardDialog.h"

#include <QSizePolicy>
#include <QMouseEvent>

StandardDialog::StandardDialog(QWidget *parent) : CFramelessWindow(parent)
  , m_bPressed(false)
  , m_sourcePos(QPoint())
{
    setContentsMargins(0, 0, 0, 0);
    setResizeableAreaWidth(5);

    QWidget *centerContainer = new QWidget(this);
    centerContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setCentralWidget(centerContainer);

    m_pHeader = new StandardHeader(this);
    m_pBottom = new StandardBottom(this);

    m_pVBoxLayout = new QVBoxLayout(centerContainer);
    m_pVBoxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVBoxLayout->setSpacing(0);
    centerContainer->setLayout(m_pVBoxLayout);
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


void StandardDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bPressed = true;
        m_sourcePos = event->globalPos();
    }
    else
    {
        m_bPressed = false;
        m_sourcePos = QPoint();
    }
    CFramelessWindow::mousePressEvent(event);
}

void StandardDialog::mouseReleaseEvent(QMouseEvent *event)
{
    m_bPressed = false;
    m_sourcePos = QPoint();
    CFramelessWindow::mouseReleaseEvent(event);
}

//实现拖动窗口效果
void StandardDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bPressed)
    {
        if(!m_sourcePos.isNull())//移动窗口
        {
            move(pos()+(event->globalPos() - m_sourcePos));
        }

        m_sourcePos = event->globalPos();
    }

    CFramelessWindow::mouseMoveEvent(event);
}
