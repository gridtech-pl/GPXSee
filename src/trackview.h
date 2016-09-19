#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QGraphicsView>
#include <QVector>
#include <QHash>
#include <QList>
#include "units.h"
#include "palette.h"
#include "waypoint.h"

class GPX;
class POI;
class Map;
class Track;
class Route;
class TrackItem;
class RouteItem;
class WaypointItem;
class ScaleItem;
class PathItem;

class TrackView : public QGraphicsView
{
	Q_OBJECT

public:
	TrackView(QWidget *parent = 0);
	~TrackView();

	QList<PathItem*> loadGPX(const GPX &gpx);

	void loadPOI(const POI &poi);
	void clearPOI();
	void clear();

	void setMap(Map *map);
	void setUnits(enum Units units);

	void plot(QPainter *painter, const QRectF &target);

	int trackCount() const {return _tracks.count();}
	int routeCount() const {return _routes.count();}
	int waypointCount() const {return _waypoints.count();}

public slots:
	void redraw();

	void setPOIOverlap(bool overlap);
	void showWaypointLabels(bool show);
	void showPOILabels(bool show);
	void showTracks(bool show);
	void showRoutes(bool show);
	void showWaypoints(bool show);
	void showRouteWaypoints(bool show);

private:
	PathItem *addTrack(const Track &track);
	PathItem *addRoute(const Route &route);
	void addWaypoints(const QList<Waypoint> &waypoints);
	void addPOI(const QVector<Waypoint> &waypoints);

	QRectF trackBoundingRect() const;
	QRectF routeBoundingRect() const;
	QRectF waypointBoundingRect() const;
	qreal trackScale() const;
	qreal routeScale() const;
	qreal waypointScale() const;
	qreal mapScale(int zoom) const;
	void rescale(qreal scale);
	void rescale();
	void zoom(int z, const QPointF &pos);
	void checkPOIOverlap();

	void wheelEvent(QWheelEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void drawBackground(QPainter *painter, const QRectF &rect);
	void resizeEvent(QResizeEvent *e);
	void paintEvent(QPaintEvent *e);

	QGraphicsScene *_scene;
	QList<TrackItem*> _tracks;
	QList<RouteItem*> _routes;
	QList<WaypointItem*> _waypoints;
	QHash<Waypoint, WaypointItem*> _pois;

	Map *_map;
	ScaleItem *_mapScale;

	Palette _palette;

	qreal _scale;
	int _zoom;

	Units _units;

	bool _showTracks;
	bool _showRoutes;
	bool _showWaypoints;
	bool _showWaypointLabels;
	bool _showPOILabels;
	bool _overlapPOIs;
	bool _showRouteWaypoints;

	bool _plot;
};

#endif // TRACKVIEW_H
