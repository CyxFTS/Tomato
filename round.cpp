#include <round.h>
#include <tempcolor.h>
#include <QDebug>
CRoundProcesseBar::CRoundProcesseBar(QWidget *parent)
    : QProgressBar(parent)
{

    m_outerRadius=width()>height() ? height()/2 : width()/2;
    m_innerRadius=0.9*m_outerRadius;
    m_colorPieRadius=m_outerRadius*0.9;
    m_coverCircleRadius=0.9*m_colorPieRadius;
    m_center=rect().center();
    //m_longHand=(qreal)m_outerRadius/20;
    //m_okHand=0.7*m_longHand;
    //m_shortHand=0.5*m_longHand;
    //m_space=0.1*m_longHand;

    this->setFixedSize(420,420);
    setScanValue("10000");

}

CRoundProcesseBar::~CRoundProcesseBar()
{

}

void CRoundProcesseBar::setScanValue(QString strValue)
{
    m_strValue = strValue;
    this->repaint();
}

void CRoundProcesseBar::resetVariables(QPainter *painter)
{
    m_outerRadius=width()>height() ? height()/2 : width()/2;
    m_innerRadius=0.9*m_outerRadius;
    m_center=rect().center();
    m_colorPieRadius=m_outerRadius*0.9;
    m_coverCircleRadius=0.9*m_colorPieRadius;
}

void CRoundProcesseBar::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);

    resetVariables(&painter);
    drawInnerCircle(&painter);
    drawColorPies(&painter,m_strValue);
    drawTextRect(&painter);

    painter.end();
}

void CRoundProcesseBar::drawOuterCircle(QPainter* painter)
{
    painter->save();

    QPen pen;
    pen.setColor(Qt::gray);
    pen.setWidth(1);
    painter->setPen(pen);
    painter->setBrush(QColor(232,17,35));
    painter->drawEllipse(m_center,m_outerRadius,m_outerRadius);

    painter->restore();
}

void CRoundProcesseBar::drawInnerCircle(QPainter* painter)
{
    painter->save();

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(23,23,23));
    painter->drawEllipse(m_center,m_innerRadius,m_innerRadius);

    painter->restore();
}

void CRoundProcesseBar::drawColorPies(QPainter* painter, QString strValue)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    QPointF pieRectTopLeftPot(m_center.x()-m_colorPieRadius,m_center.y()-m_colorPieRadius);
    QPointF pieRectBottomRightPot(m_center.x()+m_colorPieRadius,m_center.y()+m_colorPieRadius);

    m_pieRect=QRectF(pieRectTopLeftPot,pieRectBottomRightPot);

    if(strValue.toInt()/100 >= 80)
    {
        painter->setBrush(lightgreen500);
    }
    else
    {
        painter->setBrush(lightgreen700);
    }

    float fAngle = strValue.toFloat();
    //qDebug()<<"str"<<strValue.toFloat();
    double nPieLenth = 360 *(fAngle/10000.0);
    painter->drawPie(m_pieRect,90*16, nPieLenth*16);
    painter->restore();
}

void CRoundProcesseBar::drawGraph(QPainter* painter)
{

    painter->save();
    painter->setPen(Qt::NoPen);

    painter->setPen(QColor(255,255,255));
    painter->drawPie(m_pieRect,90,360*16);

    painter->restore();
}

void CRoundProcesseBar::drawTextRect(QPainter* painter)
{
    painter->save();
    painter->setOpacity(1.0);
    QPointF topLeftPot(m_center.x()-m_coverCircleRadius,m_center.y()-m_coverCircleRadius);
    QPointF bottomRightPot(m_center.x()+m_coverCircleRadius,m_center.y()+m_coverCircleRadius);
    QRectF textRect(topLeftPot,bottomRightPot);
    painter->setPen(Qt::NoPen);

    QPen pen;
    pen.setColor(QColor(255,255,255,60));
    pen.setWidth(5);
    painter->setPen(pen);
    painter->setBrush(QColor(232,17,35));
    painter->drawEllipse(m_center, m_coverCircleRadius, m_coverCircleRadius);

    painter->setOpacity(1.0);
    painter->setPen(QColor(255,255,255));
    qreal fontSize=m_coverCircleRadius * 0.45;
    QFont font;
    font.setPointSize(fontSize);
    font.setBold(true);
    QFont font2("微软雅黑", fontSize, QFont::Normal);
    font2.setBold(true);

    painter->setFont(font2);
    painter->drawText(textRect,Qt::AlignVCenter|Qt::AlignHCenter, m_clockValue);
    painter->restore();
}
