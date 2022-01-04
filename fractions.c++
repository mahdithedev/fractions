#include<bits/stdc++.h>
#include "./fractions.h"
    
      Fraction::Fraction(int numerator , int denominator , bool simplfy_frac ) : _numerator(numerator) , _denominator(denominator) {

          if(simplfy_frac)
            *this = simplfy(*this);

      };

      Fraction::Fraction(int numerator ) : _numerator(numerator) , _denominator(1) {};

        //https://stackoverflow.com/questions/26643695/converting-a-floating-point-decimal-value-to-a-fraction
        //with some modifications

       Fraction::Fraction(double input) {

        int sign = input > 0 ? 1 : -1 ;
        input = std::abs(input);

        int integral = std::floor(input); //getting the number before the decimal point
        double frac = input - integral; //getting the number after the decimal point

        const long precision = 1000000000; // This is the accuracy.

        long gcd_ = gcd(round(frac * precision), precision);  //based on my interpretation bacuse the gcd
        //is an int and can't be a decimal we need to find the gcd of 
        //round(frac * precision) and precision

        long denominator = precision / gcd_;
        long numerator = round(frac * precision) / gcd_;

        _denominator = denominator;
        _numerator = numerator;

        if(sign == -1)
        _numerator *= -1;

        if(integral)
        (*this) = (*this) + integral;

      };

      Fraction::Fraction(const Fraction& _frac_b) : _numerator(_frac_b.get_numerator()) , _denominator(_frac_b.get_denominator()) {};

      Fraction::Fraction() : _numerator(0) , _denominator(1) {};

      int Fraction::gcd(int a , int b) noexcept {

           a = std::abs(a);
           b = std::abs(b);

           if (a == 0)
            return b;
           else if (b == 0)
            return a;

           if (a < b)
            return gcd(a, b % a);
           else
            return gcd(b, a % b);

      };

      int Fraction::lcm(int a , int b) {
          return (a*b)/gcd(a,b);
      }

      Fraction Fraction::simplfy(const Fraction& _frac) {

          int _numerator = _frac.get_numerator() , _denominator = _frac.get_denominator();

          int _gcd = gcd(_numerator , _denominator);

          _numerator = _numerator/_gcd;
          _denominator = _denominator/_gcd;

         if( _numerator < 0 && _denominator < 0 )
              _numerator = -_numerator , _denominator = -_denominator; 

          return Fraction(_numerator , _denominator , 0);

      };

      Fraction Fraction::inverse(const Fraction& _frac) {

          int _numerator = _frac.get_numerator();
          int _denominator = _frac.get_denominator();

          int temp = _numerator;
          _numerator = _denominator;
          _denominator = temp;

          return Fraction(_numerator , _denominator);

      }

      void Fraction::set_numerator(int numerator) noexcept {
          _numerator = numerator;
          (*this) = simplfy(*this);
      };
      
      void Fraction::set_numerator_without_simplifying(int numerator) noexcept {
          _numerator = numerator;
      };

      void Fraction::set_denominator_without_simplifying(int denominator) noexcept {
          _denominator = denominator;
      };

      int Fraction::get_numerator() const {
          return _numerator;
      }

      int Fraction::get_denominator() const {
          return _denominator;
      }

      double Fraction::get_decimal() const {
          return (double)_numerator/(double)_denominator;
      }

      Fraction Fraction::operator+(const Fraction& _frac_b) {

          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) + 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          return Fraction(final_numerator , final_denominator);
          
      }

      Fraction& Fraction::operator+=(const Fraction& _frac_b) {
          
          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) + 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          (*this) = Fraction(final_numerator , final_denominator);

          return (*this);

      }

      Fraction Fraction::operator-(const Fraction& _frac_b) {

          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) - 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          return Fraction(final_numerator , final_denominator);
          
      }

      Fraction& Fraction::operator-=(const Fraction& _frac_b) {
          
          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) - 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          (*this) = Fraction(final_numerator , final_denominator);

          return (*this);

      }

      Fraction Fraction::operator*(const Fraction& _frac_b) {
          return Fraction(_numerator * _frac_b.get_numerator() , _denominator * _frac_b.get_denominator());
      };

      Fraction& Fraction::operator*=(const Fraction& _frac_b) {
          (*this) = Fraction(_numerator * _frac_b.get_numerator() , _denominator * _frac_b.get_denominator());
          return (*this);
      };

      Fraction Fraction::operator/(const Fraction& _frac_b) {
          auto _frac_c = inverse(_frac_b);
          return Fraction(_numerator * _frac_c.get_numerator() , _denominator * _frac_c.get_denominator());
      };

      Fraction& Fraction::operator/=(const Fraction& _frac_b) {
          auto _frac_c = inverse(_frac_b);
          (*this) = Fraction(_numerator * _frac_c.get_numerator() , _denominator * _frac_c.get_denominator());
          return (*this);
      };

      bool Fraction::operator==(const Fraction& _frac_b) {

          auto f_a = simplfy(*this);
          auto f_b = simplfy(_frac_b);

          return (f_a.get_numerator() == f_b.get_numerator() && f_a.get_denominator() == f_b.get_denominator());

      }

     Fraction operator/(int number , const Fraction& _frac) {

         auto _frac_b = Fraction::inverse(_frac);

        int _numerator = number;
        int _denominator = 1;
        
        return Fraction(_numerator * _frac_b.get_numerator() , _denominator * _frac_b.get_denominator());

     } 

std::ostream& operator<<(std::ostream& stream , const Fraction& _fraction) {

    stream<<_fraction.get_numerator()<<"/"<<_fraction.get_denominator();
    return stream;

};