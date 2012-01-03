#include "LayoutApp.h"
#include "widgets/BackgroundWidget.h"
#include "widgets/ImageWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "widgets/MarkingMenu.h"
#include "helpers.h"
#include <QTimer>

namespace ipn
{
LayoutApp::LayoutApp(QWidget *parent) : App(parent)
{
    m_back = new BackgroundWidget(this);
    m_back->setColor(BackgroundWidget::BG_WHITE);
    m_back->move(0, 0);

    //some message

    m_message = new TextWidget(this);
    m_message->setColor(Qt::white);
    m_message->resize(240, 180);
    m_message->setText("Hold your finger\non the screen or\npush the button to\ninvoke the menu.");

    //quit Button:

    m_quitButton = new ScalableButtonWidget(this);
    m_quitButton->move(148, 184);
    m_quitButton->resize(80, 48);
    m_quitButton->setImage(":/img/buttons/default");
    m_quitButton->setText("quit");
    connect(m_quitButton, SIGNAL(clicked()), this, SIGNAL(quitButtonClicked()));

    //some Button:

    m_someButton = new ScalableButtonWidget(this);
    m_someButton->move(2, 2);
    m_someButton->resize(136, 48);
    m_someButton->setImage(":/img/buttons/default");
    m_someButton->setText("menu");
 //   connect(m_someButton, SIGNAL(clicked()), );

    //Marking Menu:

    m_markingMenu = new MarkingMenu(this);
    m_markingMenu->hide();
    m_markingMenu->addEntry("Columns", Qt::white, Qt::black);
    m_markingMenu->addEntry("Date", Qt::gray, Qt::white);
    m_markingMenu->addEntry("Author", Qt::white, Qt::black);
    m_markingMenu->addEntry("Over-\nview", Qt::gray, Qt::white);

    m_menuInvokeTimer = new QTimer(this);
    m_menuInvokeTimer->setInterval(500);
    m_menuInvokeTimer->setSingleShot(true);

    // Grab swipe gesture:
    connect(this, SIGNAL(swipeTriggered(qreal)), this, SLOT(handleSwipeGesture(qreal)));

    connect(m_menuInvokeTimer, SIGNAL(timeout()), m_markingMenu, SLOT(show()));
    connect(m_menuInvokeTimer, SIGNAL(timeout()), m_markingMenu, SLOT(setFocus()));

    connect(m_markingMenu, SIGNAL(entryClicked(QString)), this, SLOT(handleMenuClick(QString)));

    }

    void LayoutApp::handleSwipeGesture(qreal angle)
    {
            m_markingMenu->hide();
            m_message->setText(m_markingMenu->entryText(angle));
            update();
    }

    void LayoutApp::handleMenuClick(QString entryText)
    {
            m_markingMenu->hide();
            m_message->setText(entryText);
            update();
    }

    void LayoutApp::mousePressEvent(QMouseEvent *event)
    {
            m_menuInvokeTimer->start();

            App::mousePressEvent(event);
            m_markingMenu->mousePressEvent(event);
    }

    void LayoutApp::mouseReleaseEvent(QMouseEvent *event)
    {
            m_markingMenu->deactivateAllEntries();

            if (!m_menuInvokeTimer->isActive())
                    m_markingMenu->mouseReleaseEvent(event);

            m_menuInvokeTimer->stop();

            App::mouseReleaseEvent(event);
    }

    void LayoutApp::mouseMoveEvent(QMouseEvent *event)
    {
            m_markingMenu->mouseMoveEvent(event);
    }

} // namespace ipn
