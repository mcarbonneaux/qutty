/*
 * Copyright (C) 2012 Rajendran Thirupugalsamy
 * See LICENSE for full copyright and license information.
 * See COPYING for distribution information.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMdiArea>
#include <QMenu>
#include "GuiMainWindow.h"
#include "QtCommon.h"
#include "GuiSettingsWindow.h"

class GuiSettingsWindow;

class GuiMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    GuiMainWindow(QWidget *parent = 0);
    ~GuiMainWindow();
    GuiTerminalWindow *newTerminal();
    void createNewTab(Config *cfg);
    bool winEvent ( MSG * msg, long * result );
    void closeEvent ( QCloseEvent * event );
    GuiTerminalWindow *getCurrentTerminal();

    QTabWidget *tabArea;
private:
    GuiSettingsWindow *settingsWindow;
    QList<GuiTerminalWindow *> terminalList;
    QMenu *menu;

    void initializeMenuKeyboardShortcuts();

public slots:
    void on_openNewWindow();
    void on_openNewTab();
    void on_createNewTab(Config cfg);
    void on_settingsWindowClose();
    void on_changeSettingsTab(int tabIndex);
    void on_changeSettingsTabComplete(Config cfg, int tabIndex);
    void closeTerminal(int index);
    void closeTerminal(GuiTerminalWindow *termWnd);
    void tabCloseRequested (int index);
    void currentChanged(int index);
    void focusChanged ( QWidget * old, QWidget * now );

    void tabNext();
    void tabPrev();

};

#endif // MAINWINDOW_H
