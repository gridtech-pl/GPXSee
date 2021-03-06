#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5, 4, 0)
#include <QGLWidget>
#include <QGLFormat>
#else
#include <QOpenGLWidget>
#include <QSurfaceFormat>
#endif

#if QT_VERSION < QT_VERSION_CHECK(5, 4, 0)
#define OPENGL_WIDGET QGLWidget
#else
#define OPENGL_WIDGET QOpenGLWidget
#endif

#if QT_VERSION < QT_VERSION_CHECK(5, 4, 0)
#define OPENGL_SET_FORMAT(samples, stencilBuffer) \
	{QGLFormat fmt; \
	fmt.setStencilBufferSize(stencilBuffer); \
	fmt.setSamples(samples); \
	QGLFormat::setDefaultFormat(fmt);}
#else
#define OPENGL_SET_FORMAT(samples, stencilBuffer) \
	{QSurfaceFormat fmt; \
	fmt.setStencilBufferSize(stencilBuffer); \
	fmt.setSamples(samples); \
	QSurfaceFormat::setDefaultFormat(fmt);}
#endif
