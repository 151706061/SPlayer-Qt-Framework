#pragma execution_character_set("UTF-8")

#include "mainwindow.h"

#include <QVBoxLayout>
#include <QColor>

#define MAIN_HB_COLOR (QColor(56,58,66))

//构造函数
MainWindow::MainWindow(QWidget *parent) : StandardDialog(parent)
{
    //设置头部区域属性
    GetHeader()->SetTitleText(tr("SPlayer"));
    GetHeader()->SetTitleCenter(true);
    GetHeader()->GetBgColor().SetAllState(MAIN_HB_COLOR);
    GetHeader()->setFixedHeight(30);
    GetBottom()->GetBgColor().SetAllState(MAIN_HB_COLOR);
    GetBottom()->setFixedHeight(65);
    //设置内容区域属性
    BaseWidget *pCenterContainer = new BaseWidget(this);
    m_pCenterWidget = new QWidget(pCenterContainer);
    m_pCenterWidget->setMouseTracking(true);
    m_pProgressBar = new SProgressBar(pCenterContainer);
    m_pProgressBar->setValue(500);
    m_pProgressBar->setFixedHeight(12);
    m_pProgressBar->setContentsMargins(0,4,0,4);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout(pCenterContainer);
    pVBoxLayout->setContentsMargins(0,0,0,0);
    pVBoxLayout->setSpacing(0);
    pVBoxLayout->addWidget(m_pCenterWidget);
    pVBoxLayout->addWidget(m_pProgressBar);
    SetCenterWidget(pCenterContainer);

    CreateLogoWidget(m_pCenterWidget);
    //设置底部区域
    m_pWindowBottom = new WindowBottom(this);
    SetBottomWidget(m_pWindowBottom);

    CreateMainMenu();

    m_pConfigDialog = new ConfigDialog();
    m_pConfigDialog->setVisible(false);

    QSize size(860,500+30+65);
    setMinimumSize(size);//设置窗口最小大小
    resize(900, 650);
}

MainWindow::~MainWindow()
{

}

//创建菜单项
void MainWindow::CreateMainMenu()
{
    m_pMainMenu = new QMenu(this);
    m_pMainMenu->addAction(tr("File(&F)"));
    m_pMainMenu->addAction(tr("Play(&P)"));
    QAction *pOptionAct = m_pMainMenu->addAction(tr("Option"));
    connect(pOptionAct,SIGNAL(triggered(bool)),this,SLOT(Slot_OptionActToggled(bool)));
    m_pMainMenu->addAction(tr("Exit"));
}

void MainWindow::CreateLogoWidget(QWidget *parent)
{
    QHBoxLayout *pLogoLayout = new QHBoxLayout(parent);
    pLogoLayout->setContentsMargins(0,0,0,0);
    pLogoLayout->setSpacing(0);
    m_pLogoWidget = new LogoWidget(parent);
    m_pLogoWidget->SetLogoImage(":/Image/Resource/logo.png");
    pLogoLayout->addWidget(m_pLogoWidget);
}

//单击Logo图标，弹出菜单
void MainWindow::Slot_LogoClicked()
{
    QPoint pt = GetHeader()->rect().bottomLeft();
    m_pMainMenu->popup(GetHeader()->mapToGlobal(QPoint(pt.x(),pt.y()+1)));
}

//单击Option菜单项，弹出设置对话框
void MainWindow::Slot_OptionActToggled(bool)
{
    int nWidth = 560;
    int nHeight = 458;
    int nX= geometry().left()+(width()-nWidth)/2;
    int nY= geometry().top()+30+(height()-30-65-nHeight)/2;
    m_pConfigDialog->setGeometry(nX,nY,nWidth,nHeight);
    m_pConfigDialog->show();
}

