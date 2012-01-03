#ifndef IPN_LAYOUTAPP_H
#define IPN_LAYOUTAPP_H

#include "App.h"

namespace ipn
{
    class BackgroundWidget;
    class TextWidget;
    class ScalableButtonWidget;
    class MarkingMenu;

    class LayoutApp : public App
        {
             Q_OBJECT

             public:
                LayoutApp(QWidget *parent = 0);
                TitleBarWidget *titleBar();


             inline bool isOpaque() {return false;}

             signals:
                void quitButtonClicked();

             private:
                BackgroundWidget *m_back;
                ScalableButtonWidget *m_quitButton, *m_someButton;
                MarkingMenu *m_markingMenu;
                QTimer *m_menuInvokeTimer;

             protected:
                virtual void mousePressEvent(QMouseEvent *event);
                virtual void mouseReleaseEvent(QMouseEvent *event);
                virtual void mouseMoveEvent(QMouseEvent *event);

            private slots:
                void handleSwipeGesture(qreal angle);
                void handleMenuClick(QString entryText);


};
} // namespace ipn

#endif /* end of include guard: IPN_LayoutApp_H */
