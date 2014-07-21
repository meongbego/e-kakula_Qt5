#include "pulseaudiomonitor.h"

#include <iostream>
#define BUFSIZE 1024
#include "nastyfft.h"

#include <QTime>



/* A simple routine calling UNIX write() in a loop */
static ssize_t loop_write(int fd, const void*data, size_t size) {
    ssize_t ret = 0;

    while (size > 0) {
        ssize_t r;

        if ((r = write(fd, data, size)) < 0)
            return r;

        if (r == 0)
            break;

        ret += r;
        data = (const uint8_t*) data + r;
        size -= (size_t) r;
    }

    return ret;
}

PulseAudioMonitor::PulseAudioMonitor(QObject *parent) :
    QThread(parent)
{



}
PulseAudioMonitor::~PulseAudioMonitor()
{



}



#include <QFile>

void PulseAudioMonitor::run()
{
    running=true;

    pa_sample_spec ss;

     ss.format = PA_SAMPLE_S16LE;
     ss.channels = 1;
     ss.rate = 44100;

    pa_simple *s = NULL;
    int ret = 1;
    int error;

    buffer.resize(BUFSIZE);

    char* buf = buffer.data();



         pa_buffer_attr ba;
             ba.tlength = pa_usec_to_bytes(50*1000, &ss);
             ba.minreq = pa_usec_to_bytes(50*1000, &ss);
             ba.maxlength = pa_usec_to_bytes(50*1000, &ss);
             ba.fragsize = sizeof(uint32_t) -1; //Adjust this value if it's glitchy

    /* Create the recording stream */
    if (!(s = pa_simple_new(NULL, "nastyfft", PA_STREAM_RECORD, "alsa_output.pci-0000_00_1b.0.analog-stereo.monitor", "record", &ss, NULL, &ba, &error))) {
        fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
        goto finish;
    }





    while (running) {


        /* Record some data ... */
        if (pa_simple_read(s, buf, BUFSIZE, &error) < 0) {
            fprintf(stderr, __FILE__": pa_simple_read() failed: %s\n", pa_strerror(error));
            goto finish;
        }

        emit dataReady(buffer, ss);

    }


    ret = 0;

finish:



    if (s)
        pa_simple_free(s);

    return ;
}

void PulseAudioMonitor::stop()
{
    running=false;
    this->wait();
}
