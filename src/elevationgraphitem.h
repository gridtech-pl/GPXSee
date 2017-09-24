#ifndef ELEVATIONGRAPHITEM_H
#define ELEVATIONGRAPHITEM_H

#include "graphitem.h"

class ElevationGraphItem : public GraphItem
{
public:
	ElevationGraphItem(const Graph &graph, QGraphicsItem *parent = 0);

	qreal ascent() const {return _ascent;}
	qreal descent() const {return _descent;}
	qreal min() const {return -bounds().bottom();}
	qreal max() const {return -bounds().top();}

	void setUnits(Units units);

private:
	QString toolTip(Units units) const;

	qreal _ascent, _descent;
};

#endif // ELEVATIONGRAPHITEM_H