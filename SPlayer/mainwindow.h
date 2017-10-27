#pragma once

#include <QWidget>
#include <QMenu>

#include "StandardDialog/StandardDialog.h"
#include "LogoWidget.h"
#include "Control/SProgressBar.h"
#include "Control/SButton.h"
#include "WindowBottom.h"
#include "ConfigDialog.h"

class MainWindow : public StandardDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private:
    //创建菜单
    void CreateMainMenu();
    //创建Logo视图
    void CreateLogoWidget(QWidget *parent);

protected slots:
    virtual void Slot_LogoClicked();
    void Slot_OptionActToggled(bool);

    //控件成员
private:
    QWidget *m_pCenterWidget;
    LogoWidget *m_pLogoWidget;
    SProgressBar *m_pProgressBar;
    WindowBottom *m_pWindowBottom;
    QMenu *m_pMainMenu;
    ConfigDialog *m_pConfigDialog;
};
