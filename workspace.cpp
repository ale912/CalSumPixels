#include "workspace.h"

WorkSpace::WorkSpace(QWidget *parent) :
    QWidget(parent), _maskPixmap(0), _isMaskCreate(false)
{
    _pixmap = new QPixmap;
}

WorkSpace::~WorkSpace()
{
    delete _pixmap;
    delete _maskPixmap;
}

void WorkSpace::setPixmap(const QStringList &paths)
{
    if(paths.isEmpty()) return;

    _images = paths;

    _pixmap->load(_images.takeFirst());

    _pixmapWidth = _pixmap->width();
    _pixmapHeight = _pixmap->height();

    _maskPixmap = new QPixmap(_pixmapWidth, _pixmapHeight);
    setFixedSize(_pixmapWidth, _pixmapHeight);
    setCircleCentre(QPointF(0,0));
    setCircleSize(100,100);
}

void WorkSpace::paintEvent(QPaintEvent *)
{
    if(_maskPixmap != 0){
        QPainter painter(this);

        painter.drawPixmap(0, 0, *_pixmap);

        painter.save();
        painter.setPen(Qt::white);
        painter.drawEllipse(_circleCenter, _circleW, _circleH);
        painter.restore();
    }
}

void WorkSpace::setCircleCentre(const QPointF &point)
{
    _circleCenter = QPointF((_pixmapWidth / 2) + point.x(),
                            (_pixmapHeight / 2) + point.y());
    repaint();
}

void WorkSpace::setCircleSize(qreal w, qreal h)
{
    _circleW = w;
    _circleH = h;
    repaint();
}

void WorkSpace::createMask()
{
    _maskPixmap->fill(Qt::black);
    QPainter painter(_maskPixmap);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawEllipse(_circleCenter, _circleW, _circleH);
    _mask = _maskPixmap->createMaskFromColor(Qt::black);
    _isMaskCreate = true;
    repaint();
}

void WorkSpace::start()
{
    if(!_isMaskCreate){
        QMessageBox::warning(0, tr("Предупреждение!"), tr("Нет маски!"));
    }
    else{
        QFile file("c:/LOVRIO-197001010000.rio");
        if(file.open(QIODevice::Append)){
            QTextStream in(&file);
            int index = 0;
            while(!_images.isEmpty()){
                _pixmap->setMask(_mask);
                QImage image = _pixmap->toImage();
                double sum = 0;
                for(int w = 0; w < _pixmapWidth; ++w){
                    for(int h = 0; h < _pixmapHeight; ++h){
                        QColor color(image.pixel(w,h));
                        sum += color.redF();
                    }
                }
                QString text(QString::number(index * 600));
                text.append(" ");
                text.append(QString::number(sum));
                text.append("\r\n");
                in << text;

                _pixmap->load(_images.takeFirst());
                ++index;
            }
        }
        file.close();
    }
}

