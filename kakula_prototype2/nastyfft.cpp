#include "nastyfft.h"
#include "scenepreset.h"


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <QTimer>



NastyFFT::NastyFFT() : QGLWidget(), obj(0), preset_index(0)
{
	printf("NastyFFT: CTOR ... \n");
	
    srand ( time(NULL) );

	obj = gluNewQuadric();
	
	gluQuadricNormals(obj, GLU_SMOOTH);

	for (int z=0;z<SCOPE_DEPTH;z++)
	{
		for (int a=0;a<NUM_BANDS;a++)
		{
			fftdata[z][a]=0.0f;
		}
	}


    presets << "Standar" << "Hero" <<  "Flame";

	printf("NastyFFT: creating new ScenePreset\n");

	loadPreset(preset_index);

    //tim.start();

    setAutoFillBackground(false);

	printf("NastyFFT: CTOR_Finished\n");

//        QTimer *timer = new QTimer(this);
//        connect(timer, SIGNAL(timeout()), this, SLOT(render()));
//        timer->start(30);
	
}
int NastyFFT::presetCount()
{
    return presets.count();
}
QString NastyFFT::presetName(int pos)
{
    return presets.value(pos);
}
void NastyFFT::loadPreset(int pos)
{
	
  cout << "NastyFFT: Loading PresetIndex: " << pos << endl;
  preset_index = 0;
  
  switch (pos)
  {
	case 1: //Hero
	initPreset();
    priv.scale = 12.0f;
	priv.cam_coords.y = 4.0f;
	priv.cam_coords.z = 15;
	priv.flatten = true;
	priv.step_z = 1.3f;
    priv.shiness = 1.0;
    priv.name = "Hero";
	preset_index = 1;
		break;
	case 2: //Flames

	  initPreset();
      priv.scale = 12.0f;
	  priv.cam_coords.y = 1.0f;
	  priv.cam_coords.z = 19;
	  priv.step_z = 0.1f;
      priv.shiness = 1;
      priv.name = "Flame";
	  preset_index = 2;
		break;
		
	default:
	  initPreset();
      priv.scale = 12.0f;
	  priv.cam_coords.y = 1.0f;
	  priv.cam_coords.z = 17;
	  priv.step_z = 1.3f;
      priv.shiness = 1.0;
      priv.name = "Standar";
      preset_index = 0;
	  
	
  }
  
  emit presetChanged();
   

  
}
void NastyFFT::initPreset()
{
  
		priv.fdist_z=-30.0f;

		priv.light_x=(NUM_BANDS/2);
		priv.light_dir=1;
		priv.shiness=0.1f;
		
// 		preset.cam_y=1.0f;
		priv.rot_x=0.0f;
		priv.step_z=1.3f;
		
		
        priv.scale=10.0f;
		priv.cinvert=false;
		priv.cammove=false;
        priv.tranzient=false;
		priv.flatten = false;
		

		
		
		priv.beat=0.0f;
		priv.step_x=1.15;
		priv.cam_coords.x=((NUM_BANDS*priv.step_x)/2.0f)-(priv.step_x/2.0f);
		priv.cam_coords.y=0;
		priv.cam_coords.z=0;
		

		   
		priv.cam_focus.x=((NUM_BANDS*priv.step_x)/2.0f)-(priv.step_x/2.0f);
		priv.cam_focus.y=0;
		priv.cam_focus.z=0;
		priv.cam_dir=+1;

        priv.use_magnitude = false;

}
int NastyFFT::presetIndex()
{
	return preset_index;
  
}
ScenePreset* NastyFFT::scenePreset()
{
	return &priv;
  
}
NastyFFT::~NastyFFT()
{

	printf("NastyFFT: DTOR_Finished\n");
	
	if (obj) {
	  gluDeleteQuadric(obj);
	  obj=0;
	}
	

}
void NastyFFT::render()
{
    repaint();
    qDebug("Time elapsed: %d ms", tim.elapsed());
    tim.restart();
      /* generate secret number: */


//        int y,a;

//    for (y=SCOPE_DEPTH-1;y>0;y--)
//    {
//        for (a=0;a<NUM_BANDS;a++)
//            fftdata[y][a]=fftdata[y-1][a];
//    }


//        for (int a=0;a<NUM_BANDS;a++)
//        {

//            fftdata[0][a]= rand() % 10 + 1;
//        }
//        updateGL();

//  initializeGL();
//  resizeGL(width, height);
//  paintGL();
  
}

//void NastyFFT::setSize(int w, int h)
//{
//    width = w;
//    height = h;
//}

void NastyFFT::scopeEvent(const FrequencySpectrum &m_spectrum)
{


    register int i, c;

	register int index=0;
	register int y=0;
	register int a=0;

	float maxval=0;
	
  
	for (y=SCOPE_DEPTH-1;y>0;y--)
	{
		for (a=0;a<NUM_BANDS;a++)
			fftdata[y][a]=fftdata[y-1][a];
	}


 //   cout <<m_spectrum.count()<< endl;
//    float data[m_spectrum.count()];

//    FrequencySpectrum::const_iterator itr = m_spectrum.begin();
//    const FrequencySpectrum::const_iterator end = m_spectrum.end();
//    a=0;
//    for ( ; itr != end; ++itr) {
//        const FrequencySpectrum::Element e = *itr;
//        qreal mag = e.magnitude;
//        if (mag>0) {
//            fftdata[0][a] = mag * 10;
//        }
//        else {
//            fftdata[0][a] = 0;
//        }
//        //cout <<e.magnitude<< endl;
//        a++;

//        //if (e.frequency >= m_lowFreq && e.frequency < m_highFreq) {
//        //   Bar &bar = m_bars[barIndex(e.frequency)];
//        //    bar.value = qMax(bar.value, e.amplitude);
//        //    bar.clipped |= e.clipped;
//        //}
//    }


    int xscale[] = {0, 1, 2, 3, 5, 7, 10, 14, 20, 28, 40, 54, 74, 101, 137, 187, 255};

    GLdouble val = 0;

    for (i=0; i<NUM_BANDS; i++) {
	  
      for(c = (xscale[i]), val = 0; c < (xscale[i+1]); c++)
      {
        if (c<256)
        {
            qreal mag = priv.use_magnitude ? m_spectrum[c].magnitude : m_spectrum[c].amplitude;

            if(mag > val)val = mag;
        }
        else
          continue;
      }

      if(val > 0) {

          fftdata[0][i] =  (val * (priv.use_magnitude ? 1/priv.scale : priv.scale) ) > 10 ? 10 : (val * (priv.use_magnitude ? 1/priv.scale : priv.scale) );
          //fftdata[0][i] = val*16;
      }
      else {
		
        val=0;
        fftdata[0][i] =  0;
      }
  


	  
    }

	
	if (priv.light_x>NUM_BANDS)
		priv.light_dir=-1;
			
	if (priv.light_x<0)
		priv.light_dir=1;
			
	priv.light_x+=priv.light_dir;

    // repaint();
//     qDebug("Time elapsed: %d ms", tim.elapsed());
     tim.restart();

     updateGL();
}




void NastyFFT::initializeGL()
{
    //printf("NastyFFT: initializeGL\n");
	
	



    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_NORMALIZE);
	
	
    if (priv.cinvert==true)
    {
        glBlendFunc (GL_SRC_ALPHA, GL_SRC_ALPHA);
    }
    else
    {
        glBlendFunc (GL_SRC_ALPHA, GL_DST_ALPHA);
    }
	
	
	
    glShadeModel (GL_SMOOTH);
	
    //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat difuseMaterial[] = { .5, .5, .5, 1.0 };
    GLfloat mat_specular[] = { 0.2, 0.2, 0.2, 1.0 };
    //glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	
	
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	
    //glEnable(GL_CULL_FACE);
	
	
    //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_COLOR_MATERIAL);
    //GLfloat light_position1[] = { (NUM_BANDS/2), 12.0, 0, 4.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
		
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
}

void NastyFFT::resizeGL(int width, int height)
{

// 	printf("NastyFFT: resizeGL (%d,%d)\n", width, height);
	
	GLdouble defFOVY = 60.0; // field-of-view in degrees in up direction

	glViewport(0, 0, width, height);
	
	GLdouble aspect = (width > height) ? width/height : height/width;
	// field-of-view
	GLdouble fov = defFOVY/aspect;
	
	float nearDist = 0.1f;
	float farDist = 300.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(fov, aspect, nearDist, farDist);


}

void NastyFFT::setupCamera()
{
	GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f }; 	
	GLfloat LightDiffuse[]= { 1.0f, 0.8f, 0.8f, 1.0f };

	glLightfv(GL_LIGHT0,GL_AMBIENT,LightAmbient);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiffuse);
	
    GLfloat light_position0[] = {(NUM_BANDS*priv.step_x)/2, 30, (SCOPE_DEPTH*priv.step_z), 1 };
    GLfloat light_position1[] = {(NUM_BANDS*priv.step_x)/2, 30, (SCOPE_DEPTH*priv.step_z), 1 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	float center_x = ((NUM_BANDS*priv.step_x)/2.0f)-(priv.step_x/2.0f);
	
	if (priv.cam_coords.x < -(center_x/2)) 
	{
			priv.cam_dir=1;
	}
	if (priv.cam_coords.x> (center_x*2))
	{
			priv.cam_dir=-1;
	}
	
	if (priv.cammove)
	{
		priv.cam_coords.x=priv.cam_coords.x + (0.05*priv.cam_dir);	
	}
	
	gluLookAt(
	  priv.cam_coords.x,
	  priv.cam_coords.y,
	  priv.cam_coords.z,
	  
	  priv.cam_focus.x,
	  priv.cam_focus.y,
	  priv.cam_focus.z,
		   
		   0,1,0);
	
}

void NastyFFT::paintGL()
{
//    printf("paintGL\n");
//   glViewport(0, 0, width, height);
//   glLoadIdentity();
  
// glClearColor( 0.0, 0.0, 0.0, 0.0);
// 
// glColor3f(1.0, 1.0, 1.0);
// glDisable(GL_BLEND);
// 
// glTranslatef(0,150,-1.0);
// glBegin(GL_LINES);
// for (int a=16;a<NUM_BANDS-16;a++) {
//   glVertex2f(a,150);
//   GLdouble val = fftdata[0][a];
//   
//   if (val>0) {
// 	
// // 	  val /= fftdata[1][0];
// // 	  val *= 128;
// 	val/=10000000.0f;
// 	
// 	val*=128;
// 	if (val>128)val=128;
// 	
// 	glVertex2f(a,150 - val);
//   }
//   else {
// 	glVertex2f(a,150);
// 	
//   }
//   //glVertex2f(,50);
// }
// glEnd();
// glEnable(GL_BLEND);
// glPopMatrix();
// return;
  

// 	


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor( 0.0, 0.0, 0.0, 0.0);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    glEnable(GL_BLEND);
	
    glMaterialf(GL_FRONT, GL_SHININESS, priv.shiness);
	

	setupCamera();
    if (priv.cinvert==true)
    {
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHT0);
    }
	
	
	glRotatef(priv.rot_x,1,0,0);
    glTranslatef(0,-5,-(SCOPE_DEPTH*priv.step_z));
// 	glTranslatef(0,-5,0);
	
	GLdouble alpha=1.0;
	GLdouble s = 0.0;
	GLdouble xx=0.0;


	
	
	GLint a,z ;
	

	
    for (z=SCOPE_DEPTH-1;z>=0;z--)
	{
		
		xx=0.0;
		
        alpha=1.0-sqrt(z*(1.0f/SCOPE_DEPTH));
		
		for (a=0;a<NUM_BANDS;a++)
		{
		  

			s=fftdata[z][a] ;

			register GLdouble d = a/(NUM_BANDS-1.0);
				
			register GLdouble t_alpha = alpha;
			if (priv.tranzient||priv.flatten)t_alpha=alpha*s;	
			
			
			if (priv.flatten) {
				if (s>0.1)s=0.1;
				else s=0;
			}
			
			
			
			glPushMatrix();
				glColor4d(d,0.1,1.0-d,t_alpha);

				
				glRotatef(90,1,0,0);
				glTranslatef(0,0,-s);
				
				
				
				
// 				gluQuadricNormals(obj, GLU_FLAT);
  glRotatef(90,0,0,1);
				gluDisk(obj, 0,  0.5f , 12,  6);
  glRotatef(-90,0,0,1);
				
				if (!priv.flatten) {
					glScaled(1,1,s);
					glRotatef(90.0f,0,0,1);
	
					gluCylinder(obj, 0.5f, 0.5f, 1 , 6 ,1);
				}
				
			glPopMatrix();
			

			
			
			glTranslated(priv.step_x,0,0);
			xx+=priv.step_x;
		}
		glTranslated(-xx,0,0);
        glTranslated(0,0,priv.step_z);
		if (priv.step_z<1) {
            glClear(GL_DEPTH_BUFFER_BIT);
		}

  	}
  	
//    glDisable (GL_DEPTH_TEST);
//    glDisable (GL_BLEND);
//    glDisable (GL_COLOR_MATERIAL);
//    glDisable (GL_LIGHTING);
//    	glFlush();
// 	glFinish();

}


