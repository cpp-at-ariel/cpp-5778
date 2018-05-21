/**
 * Template for numerically calculating the n-th derivative.
 * 
 * Author: Peter Gottschling
 * Url: https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 */

#include <cmath>
#include <iostream>
#include <boost/mpl/bool.hpp>

double SinCos(double x) {
    return sin(x) + cos(x);
}

struct SinCosFunctor {
    double operator() (double x) const { 
	    return sin(x) + cos(x);
    }
};


class paramSinCosFunctor {
  public:
    paramSinCosFunctor(double alpha) : alpha(alpha) {}
    double operator() (double x) const { 
	    return sin(alpha * x) + cos(x);
    }
  private:
    double alpha;
};

#if 0 
// with function pointers
double fin_diff(double f(double), double x, double h) 
{
    return ( f(x+h) - f(x) ) / h;
}
#endif

template <typename Function, typename Number>
inline Number fin_diff(Function f, const Number& x, const Number& h) {
    return ( f(x+h) - f(x) ) / h;
}

template <typename Function, typename Number>
class derivative
{
  public:
    derivative(const Function& f, const Number& h) : f(f), h(h) {}

    Number operator()(const Number& x) const {
	    return ( f(x+h) - f(x) ) / h;
    }
  private:
    const Function& f;
    Number        h;
};

template<typename Function, typename Number> 
auto derive(const Function& f, const Number& h) {
    return derivative<Function,Number>(f,h);
}


template <typename Function, typename Number>
class second_derivative
{
  public:
    second_derivative(const Function& f, const Number& h): 
        h(h), fp(f, h) {}

    Number operator()(const Number& x) const
    {
	    return ( fp(x+h) - fp(x) ) / h;
    }    
  private:
    Number        h;
    derivative<Function, Number> fp;
};

#if 0
template <typename Function, typename Number, unsigned N>
class nth_derivative
{
    using prev_derivative= nth_derivative<Function, Number, N-1>;
  public:
    nth_derivative(const Function& f, const Number& h) : h(h), fp(f, h) {}

    Number operator()(const Number& x) const
    {
	return ( fp(x+h) - fp(x) ) / h;
    }    
  private:
    Number        h;
    prev_derivative fp;
};

#else

template <typename Function, typename Number, unsigned N>
class nth_derivative
{
    using prev_derivative = 
        nth_derivative<Function, Number, N-1>;
  public:
    nth_derivative(const Function& f, const Number& h) : h(h), fp(f, h) {}

    Number operator()(const Number& x) const {
        return N & 1 ? 
            ( fp(x+h) - fp(x) ) / h 
                    : 
            ( fp(x) - fp(x-h) ) / h;
    }
  private:
    Number          h;
    prev_derivative fp;
};


#if 0 // for meta-programming, maybe
template <typename Function, typename Number, unsigned N>
class nth_derivative
{
    using prev_derivative= nth_derivative<Function, Number, N-1>;
  public:
    nth_derivative(const Function& f, const Number& h) : h(h), fp(f, h) {}

    Number operator()(const Number& x) const
    {
	return diff(x, boost::mpl::bool_<N & 1>());
    }
	
  private:

    Number diff(const Number& x, boost::mpl::true_) const
    {
	return ( fp(x+h) - fp(x) ) / h;
    }    

    Number diff(const Number& x, boost::mpl::false_) const
    {
	return ( fp(x) - fp(x-h) ) / h;
    }    

    Number        h;
    prev_derivative fp;
};
#endif

#endif 

#if 0
template <typename Function, typename Number>
class nth_derivative<Function, Number, 1>
{
  public:
    nth_derivative(const Function& f, const Number& h): f(f), h(h) {}

    Number operator()(const Number& x) const
    {
	    return ( f(x+h) - f(x) ) / h;
    }   
  private:
    const Function& f;
    Number        h;
};
#else
template <typename Function, typename Number>
class nth_derivative<Function, Number, 1>
  : public derivative<Function, Number>
{
    using derivative<Function, Number>::derivative;

  // public:
  //   nth_derivative(const Function& f, const Number& h) : derivative<Function, Number>(f, h) {}
};
#endif 


#if 0
template <typename Function, typename Number, unsigned N> // Not clever
nth_derivative<Function, Number, N> 
make_nth_derivative(const Function& f, const Number& h)
{
    return nth_derivative<Function, Number, N>(f, h);
}
#endif




template <unsigned N, typename Function, typename Number>
nth_derivative<Function, Number, N> 
make_nth_derivative(const Function& f, const Number& h)
{
    return nth_derivative<Function, Number, N>(f, h);
}

struct et {};

template <typename Function>
void error(const Function& f)
{
    et e= f;
}
