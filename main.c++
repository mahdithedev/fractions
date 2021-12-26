#include<bits/stdc++.h>


class Fraction {
    public:
    
      Fraction(int numerator , int denominator , bool simplfy_frac = 1 ) : _numerator(numerator) , _denominator(denominator) {

          if(simplfy_frac)
            *this = simplfy(*this);

      };

      Fraction(int numerator ) : _numerator(numerator) , _denominator(1) {};

        //working on it i am trying to use regex      
    //   Fraction(double decimal) {

    //       decimal -= std::floor(decimal);
    //       std::string decimal_s = std::to_string(decimal);
    //       int digits_after_decimal = decimal_s.length()-2;

    //       std::cout<<decimal_s<<"\n";

    //       int power_of_ten = std::pow(10 , digits_after_decimal);

    //       _numerator = power_of_ten*decimal;
    //       _denominator = power_of_ten; 

    //   };

      Fraction() : _numerator(0) , _denominator(1) {};

      static int gcd(int a , int b) noexcept {

           a = std::abs(a);
           b = std::abs(b);

           if (a == 0)
            return b;

           if (b == 0)
            return a;

           if (a == b)
            return a;
  
           if (a > b)
            return gcd(a-b, b);

           return gcd(a, b-a);

      };

      static int lcm(int a , int b) {
          return (a*b)/gcd(a,b);
      }

      static Fraction simplfy(const Fraction& _frac) {

          int _numerator = _frac.get_numerator() , _denominator = _frac.get_denominator();

          int _gcd = gcd(_numerator , _denominator);

          _numerator = _numerator/_gcd;
          _denominator = _denominator/_gcd;

         if( _numerator < 0 && _denominator < 0 )
              _numerator = -_numerator , _denominator = -_denominator; 

          return Fraction(_numerator , _denominator , 0);

      };

      static Fraction inverse(const Fraction& _frac) {

          int _numerator = _frac.get_numerator();
          int _denominator = _frac.get_denominator();

          int temp = _numerator;
          _numerator = _denominator;
          _denominator = temp;

          return Fraction(_numerator , _denominator);

      }

      void set_numerator(int numerator) noexcept {
          _numerator = numerator;
          (*this) = simplfy(*this);
      };
      
      void set_numerator_without_simplifying(int numerator) noexcept {
          _numerator = numerator;
      };

      void set_denominator_without_simplifying(int denominator) noexcept {
          _denominator = denominator;
      };

      int get_numerator() const {
          return _numerator;
      }

      int get_denominator() const {
          return _denominator;
      }

      double get_decimal() const {
          return _numerator/_denominator;
      }

      friend std::ostream& operator<<(std::ostream& stream , const Fraction& _fraction);

      Fraction operator+(const Fraction& _frac_b) {

          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) + 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          return Fraction(final_numerator , final_denominator);
          
      }

      Fraction& operator+=(const Fraction& _frac_b) {
          
          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) + 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          (*this) = Fraction(final_numerator , final_denominator);

          return (*this);

      }

      Fraction operator-(const Fraction& _frac_b) {

          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) - 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          return Fraction(final_numerator , final_denominator);
          
      }

      Fraction& operator-=(const Fraction& _frac_b) {
          
          int _lcm = lcm(_denominator , _frac_b.get_denominator());

          int final_denominator = _lcm;

          int final_numerator = ( _numerator * ( _lcm / _denominator ) ) - 
          ( _frac_b.get_numerator() * ( _lcm / _frac_b.get_denominator() ) );

          (*this) = Fraction(final_numerator , final_denominator);

          return (*this);

      }

      Fraction operator*(const Fraction& _frac_b) {
          return Fraction(_numerator * _frac_b.get_numerator() , _denominator * _frac_b.get_denominator());
      };

      Fraction& operator*=(const Fraction& _frac_b) {
          (*this) = Fraction(_numerator * _frac_b.get_numerator() , _denominator * _frac_b.get_denominator());
          return (*this);
      };

      Fraction operator/(const Fraction& _frac_b) {
          auto _frac_c = inverse(_frac_b);
          return Fraction(_numerator * _frac_c.get_numerator() , _denominator * _frac_c.get_denominator());
      };

      Fraction& operator/=(const Fraction& _frac_b) {
          auto _frac_c = inverse(_frac_b);
          (*this) = Fraction(_numerator * _frac_c.get_numerator() , _denominator * _frac_c.get_denominator());
          return (*this);
      };


    private:
      int _numerator;
      int _denominator;
};


std::ostream& operator<<(std::ostream& stream , const Fraction& _fraction) {

    stream<<_fraction.get_numerator()<<"/"<<_fraction.get_denominator();

    return stream;

};



int main() {

    Fraction fraction1 = Fraction(1,2);

    std::cout<<fraction1/Fraction(3,2)/2<<"\n";

};