#ifndef CONVERTIMAGEEDGEDETECT_H
#define CONVERTIMAGEEDGEDETECT_H

#include <QStringList>
#include <QImage>
#include <QVector2D>
#include <QVector3D>
#include <QMatrix3x3>

class ConvertImageAlgorithms
{
public:
    static QStringList convertMultiLines(QImage img, bool* drawLines, bool mapToIntensity, int sampling, int threshold, QMatrix3x3 l2wTrans);

    static QStringList convertSquares(QImage img, int initialSize, int maxRecursion, QMatrix3x3 l2wTrans);

    static QStringList convertSin(QImage img, float maxAmplitude, int sampling, int frequency, QMatrix3x3 l2wTrans);

    static QMatrix3x3 computeLocalToWorldTransform(QVector2D imgPos, float scale);
private:
    static QVector2D convertLocalToWorld(QVector2D localPos, QMatrix3x3 l2wTrans);
    static QVector2D convertWorldToLocal(QVector2D worldPos, QMatrix3x3 w2lTrans);

    static QStringList convertLines(QImage& img, int angle, int threshold, int sampling, QMatrix3x3 l2wTrans);

    static QStringList createSquare(QVector2D center, float size, QMatrix3x3 l2wTrans);
    static QStringList createCross(QVector2D center, float size, QMatrix3x3 l2wTrans);
    static QStringList createSquaresRecursive(QImage& img, QVector2D center, float size, int maxLayer, int layer, uchar intensityBorder, QMatrix3x3 l2wTrans);
    static uchar getMinimalIntensity(QImage& img, QRectF roi);
};

#endif // CONVERTIMAGEEDGEDETECT_H
