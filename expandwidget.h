#ifndef EXPANDWIDGET_H
#define EXPANDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTimerEvent>
class CExpandCollapseWidget : public QWidget {
    Q_OBJECT
public:
    CExpandCollapseWidget(QWidget *parent = NULL) : QWidget(parent, Qt::FramelessWindowHint)
    {
        timerId = 0;
        bExpand = true;
        ppbExpandCollapse = new QPushButton("Expand", this);
        connect(ppbExpandCollapse, SIGNAL(clicked()), this, SLOT(rxClicked()));
    }
protected:
    void timerEvent(QTimerEvent *event)
    {
        if (event->timerId() == timerId)
        {
            int x = geometry().x();
            int y = geometry().y();
            int w = geometry().width();
            int h = geometry().height();
            setGeometry(x, y, w, h + increment);
            if (bExpand)
            {
                if (h > 300)
                {
                    killTimer(timerId);
                    timerId = 0;
                }
            }
            else
            {
                if (h < 40)
                {
                    killTimer(timerId);
                    timerId = 0;
                }
            }
        }
    }

private slots:
    void rxClicked()
    {
        if (timerId == 0)
            timerId = startTimer(10);
        if (ppbExpandCollapse->text() == "Expand")
        {
            bExpand = true;
            ppbExpandCollapse->setText("Collapse");
            increment = 10;
            //setSizeIncrement(0, 10);
        }
        else
        {
            bExpand = false;
            ppbExpandCollapse->setText("Expand");
            increment = -10;
        }
    }
private:
    QPushButton *ppbExpandCollapse;
    bool bExpand;
    int timerId;
    int increment;
};

#endif // EXPANDWIDGET_H
