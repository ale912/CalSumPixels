#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QBitmap>
#include <QImage>
#include <QRgb>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QDebug>

class WorkSpace : public QWidget
{
    Q_OBJECT
private:
    QPixmap* _pixmap;
    QStringList _images;
    int _step;
    int _pixmapWidth, _pixmapHeight;
    QPixmap* _maskPixmap;
    QBitmap _mask;
    bool _isMaskCreate;
    QPointF _circleCenter;
    qreal _circleW, _circleH;
public:
    explicit WorkSpace(QWidget *parent = 0);
    ~WorkSpace();

    void setPixmap(const QStringList &paths);
    void setStep(int step) { _step = step; }
    int getStep() const { return _step; }

protected:
    void paintEvent(QPaintEvent* /*event*/);

signals:

public slots:
    void setCircleCentre(const QPointF &point);
    void setCircleSize(qreal w, qreal h);
    void createMask();
    void start();
};

#endif // WORKSPACE_H
