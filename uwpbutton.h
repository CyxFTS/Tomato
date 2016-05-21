#ifndef UWPBUTTON_H
#define UWPBUTTON_H


#include <QWidget>
#include <QToolButton>
#include <QPushButton>
class UWPButton : public QPushButton
{
    Q_OBJECT
private:
    QIcon m_NormalIcon;
    QIcon m_FocusIcon;
    QIcon m_PressedIcon;

signals:
    void mName(const QString &name);

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    UWPButton(QWidget *parent = 0);
    virtual ~UWPButton();
    void SetButtonIcons(const QIcon &normal,
    const QIcon &focus = QIcon(),
    const QIcon &pressed = QIcon() );
    double res = 0.9;
    QString name;
    void send()
    {
        emit mName(name);
    }
};


#endif // UWPBUTTON_H
