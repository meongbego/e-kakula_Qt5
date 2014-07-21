#include <QApplication>
#include "pulseaudiomonitor.h"
#include "spectrumanalyser.h"
#include "menukakula.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<FrequencySpectrum>("FrequencySpectrum");
    qRegisterMetaType<WindowFunction>("WindowFunction");
    qRegisterMetaType<pa_sample_spec>("pa_sample_spec");

    PulseAudioMonitor monitor(&a);
    monitor.start();

    SpectrumAnalyser spectrum;
    QObject::connect(&monitor, SIGNAL(dataReady(const QByteArray&, const pa_sample_spec& )), &spectrum,SLOT(calculate(const QByteArray&, const pa_sample_spec&)));
    //QObject::connect(&a, SIGNAL(lastWindowClosed()), &monitor, SLOT(stop()));

    MenuKakula m;
    m.show();
    QObject::connect(&spectrum,SIGNAL(spectrumChanged(FrequencySpectrum)), m.glView(), SLOT(scopeEvent(FrequencySpectrum)));
    m.showMaximized();

    return a.exec();
}
