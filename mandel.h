#ifndef MANDEL_H_
#define MANDEL_H_

#include <complex>
typedef std::complex<double> complex;

class IPlotter {
 public:
  virtual void plot(int x, int y, int color) = 0;
};

class Mandel {
 public:
  Mandel( unsigned int iterations, int w, int h, IPlotter &plotter);
  virtual ~Mandel() { }
   
  void zoom(double minr, double maxr, double mini, double maxi);
  void zoom_back(); // zoom back one step
   
 protected:
  int width, height;
   
  // Array with colors. Should really be handled internally by the class.
  int m_palette[3][256]; // RGB

  bool havepainted; // Is set to True at start of plotting

  void calcmandel(); // plot/calc the mandelbrot set
   
  // zoom to pixel cords
  void zoom_cord(int fromx, int fromy, int tox, int toy); 

 private:
  IPlotter &m_plotter;

  // old coords (for zooming back one step)
  // implement stack of coords?
  double oldminre, oldmaxre, oldminim, oldmaxim;
  double minre, maxre, minim, maxim;
   
  unsigned int maxiter;
   
  // create palette called "cold fusion"
  void set_m_palette();
  unsigned int mandeliteration(complex &c, unsigned int maxiteration);
};

#endif /* MANDEL_H_ */
