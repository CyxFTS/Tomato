#include "uwpbutton.h"
#include <QDebug>
#define name_to_str(name_31415926)  (#name_31415926)
UWPButton::UWPButton(QWidget *parent)
: QPushButton(parent)
{
    setDown(false);
    setFocusPolicy(Qt::NoFocus);
    res = 0.9;
    //qDebug() << res;
}

UWPButton::~UWPButton()
{

}

void UWPButton::enterEvent(QEvent *)
{
    if( isEnabled() && !m_FocusIcon.isNull() )
        setIcon(m_FocusIcon);
}

void UWPButton::leaveEvent(QEvent *)
{
    if( isEnabled() )
        setIcon(m_NormalIcon);
}

void UWPButton::mousePressEvent(QMouseEvent *event)
{
    if( isEnabled() && !m_PressedIcon.isNull() )
        setIcon(m_PressedIcon);
    setIconSize(iconSize()*res);
    QPushButton::mousePressEvent(event);
}

void UWPButton::mouseReleaseEvent(QMouseEvent *event)
{
        setIcon(m_FocusIcon);
    setIconSize(iconSize()/res);
    QPushButton::mouseReleaseEvent(event);
    if(isCheckable())
    {
        QString r1 = ":/" + name + "_r";
        QString r2 = ":/" + name + "_r2";
        QString h1 = ":/" + name + "_h";
        QString h2 = ":/" + name + "_h2";
        QString p1 = ":/" + name + "_p";
        QString p2 = ":/" + name + "_p2";
        if(isChecked())
            SetButtonIcons(QIcon(r2), QIcon(h2), QIcon(p2));
        else
            SetButtonIcons(QIcon(r1), QIcon(h1), QIcon(p1));
    }
    send();
}

void UWPButton::SetButtonIcons(const QIcon &normal,
    const QIcon &focus, const QIcon &pressed)
{
    m_NormalIcon = normal;
    m_FocusIcon = focus;
    m_PressedIcon = pressed;
    setIcon(m_NormalIcon);
}


