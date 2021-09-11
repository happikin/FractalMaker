#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace happikin {
    class mandelbrot {
        public:
            static const int MAX_ITERATIONS = 1000;
        public:
            mandelbrot();
            virtual ~mandelbrot();
            static int getIterations(double x, double y);
    };
}

#endif