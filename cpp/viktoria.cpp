
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#include "viktoria.h"
#include <stdio.h>


extern "C" {
     int initcd(char *path);
     int initcd(char *path);
     int read_toc_header(struct ioc_toc_header *);
     void * toc_entries_alloc(struct cd_toc_entry **, int);
     int read_toc_entries(int start, int len);

     void m_play();
     void m_stop();
     void m_pause();
     void m_next();
     void m_prev();
     void m_eject();
     void stats();
}

#ifdef DEBUG_OUT
#define DEBUG(format, args...) printf("%s: "format, __PRETTY_FUNCTION__ ,## args)
#else
#define DEBUG(format, args...)
#endif

int btncount = 8;
int width = 30;
int border = 4;
bool horizental = false;

Fl_Double_Window *main_window=(Fl_Double_Window *)0;

Fl_Button *last=(Fl_Button *)0;

static void cb_last(Fl_Button*, void*) {
     DEBUG("last song\n");
}												

Fl_Button *fastbackward=(Fl_Button *)0;
static void cb_fastbackward(Fl_Button*, void*) {
     DEBUG("fast backward\n");
     DEBUG("This option is only available in freeware version!!! ;-)");

}												

Fl_Button *pause=(Fl_Button *)0;
static void cb_pause(Fl_Button*, void*) {
     DEBUG("Pause\n");
     m_pause();
     
}												
Fl_Button *stop=(Fl_Button *)0;
static void cb_stop(Fl_Button*, void*) {
     DEBUG("Stop\n");	 
     m_stop();
     
}												
Fl_Button *play=(Fl_Button *)0;
static void cb_play(Fl_Button*, void*) {
     DEBUG("PLay\n");
     m_play();
}												

Fl_Button *fastforward=(Fl_Button *)0;
static void cb_fastforward(Fl_Button*, void*) {
     DEBUG("Fast Forward\n");
     DEBUG("This option is only available in freeware version!!! ;-)");
}
Fl_Button *next=(Fl_Button *)0;
static void cb_next(Fl_Button*, void*) {
     DEBUG("Next Song\n");	 
     m_next();
}												
Fl_Button *eject=(Fl_Button *)0;
static void cb_eject(Fl_Button*, void*) {
     DEBUG("eject\n");
     m_eject();
}												
											       
Fl_Double_Window* make_window() {								
     Fl_Double_Window* w;
     int window_W = width;
     int window_H = (btncount*(width-border))+border;
     int dynX = border, dynY = width;
     if (horizental) window_H ^= window_W ^= window_H ^= window_W;
  
     {Fl_Double_Window* o = main_window = new Fl_Double_Window(window_W, window_H, "Viktoria");
     w = o;
     o->box(FL_BORDER_BOX);
     o->color(40);
     o->labelcolor(63);

     int dynX = border, dynY = width;
     if (horizental) dynX ^= dynY ^= dynX ^= dynY; 

     { 
	  Fl_Button* o = last = new Fl_Button(dynX, dynX, width-2*border, width-2*border,"@|<" );
	  o->callback((Fl_Callback*)cb_last);
     }
     { 
	  Fl_Button* o = fastbackward = new Fl_Button(dynX, dynY, width-2*border, width-2*border,"@<<");
	  o->callback((Fl_Callback*)cb_fastbackward);
     }

     dynY += width-border;

     { 
	  Fl_Button* o = pause = new Fl_Button(dynX, dynY, width-2*border, width-2*border,"@||");
	  o->callback((Fl_Callback*)cb_pause);
     }

     dynY += width-border;

     { 
	  Fl_Button* o = stop = new Fl_Button(dynX, dynY, width-2*border, width-2*border, "@square");
	  o->callback((Fl_Callback*)cb_stop);
     }

     dynY += width-border;

     { 
	  Fl_Button* o = play = new Fl_Button(dynX, dynY, width-2*border, width-2*border, "@>");
	  o->callback((Fl_Callback*)cb_play);
     }

     dynY += width-border;

     { 
	  Fl_Button* o = fastforward = new Fl_Button(dynX, dynY, width-2*border, width-2*border, "@>>");
	  o->callback((Fl_Callback*)cb_fastforward);
     }

     dynY += width-border;

     { 
	  Fl_Button* o = next = new Fl_Button(dynX, dynY, width-2*border, width-2*border, "@>|");
	  o->callback((Fl_Callback*)cb_next);
     }

     dynY += width-border;

     { 
	  Fl_Button* o = eject = new Fl_Button(dynX, dynY, width-2*border, width-2*border, "@+");
	  o->callback((Fl_Callback*)cb_eject);
     }
     o->end();
     }
     return w;
}


int main(int argc, char **argv) {

     int i;
     char ch;
     
     if(initcd("/dev/acd0c") < 0) {
          fprintf(stderr, "Moin!\n");
     }


     Fl_Double_Window *w=make_window();

     Fl::visual(FL_DOUBLE|FL_INDEX);
     w->show();
     return Fl::run();
}
