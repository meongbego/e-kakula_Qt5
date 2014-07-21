#ifndef _PLUGIN_NASTYFFT_H_
#define _PLUGIN_NASTYFFT_H_

#include "scenepreset.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif
#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <QGLWidget>
#include <QTime>

#include "frequencyspectrum.h"

class NastyFFT  : public QGLWidget
{
Q_OBJECT

public:
    NastyFFT();
    ~NastyFFT();



    int presetCount();

    QString presetName(int pos);

	void loadPreset(int pos);
	int presetIndex();
//    void setSize(int width, int height);
	ScenePreset* scenePreset();
signals:
    void presetChanged();

public slots:
    void scopeEvent(const FrequencySpectrum &m_spectrum);
    void render();

protected:
	void initPreset();
	
	void setupCamera();
	
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
	
	GLUquadric *obj;
	
	ScenePreset priv;
	int preset_index;
	
	int width;
	int height;
	
	GLdouble fftdata[SCOPE_DEPTH][NUM_BANDS];

    QStringList presets;

    QTime tim;
};

#endif // _PLUGIN_NASTYFFT_H_


