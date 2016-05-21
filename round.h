#ifndef ROUND_H
#define ROUND_H
#include <QProgressBar>
#include <QWidget>
#include <QString>
#include <QPainter>
#include <QMouseEvent>

class CRoundProcesseBar : public QProgressBar
{
Q_OBJECT


public:
    CRoundProcesseBar(QWidget *parent = 0);
    ~CRoundProcesseBar();

    void setScanValue(QString strValue);

    QString m_strValue;
    QString m_clockValue;


private:
    qreal m_value;
    qreal m_outerRadius;
    qreal m_innerRadius;
    qreal m_colorPieRadius;
    qreal m_coverCircleRadius;
    qreal m_space;
    QPointF m_center;
    QRectF m_pieRect;


private:
    void drawOuterCircle(QPainter* painter);
    void drawInnerCircle(QPainter* painter);
    void drawColorPies(QPainter* painter, QString strValue);
    void drawCoverLines(QPainter* painter);
    void drawCoverCircle(QPainter* painter);
    void drawMarkAndText(QPainter* painter);
    void drawGraph(QPainter* painter);
    void drawTextRect(QPainter* painter);
    void resetVariables(QPainter* painter);


protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ROUND_H
