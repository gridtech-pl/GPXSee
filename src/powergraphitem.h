#ifndef POWERGRAPHITEM_H
#define POWERGRAPHITEM_H

#include "graphitem.h"

class PowerGraphItem : public GraphItem
{
public:
	PowerGraphItem(const Graph &graph, QGraphicsItem *parent = 0);

	qreal max() const {return -bounds().top();}
	qreal avg() const {return _avg;}

private:
	QString toolTip() const;

	qreal _avg;
};

#endif // POWERGRAPHITEM_H