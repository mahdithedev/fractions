#include <ostream>

#ifndef _FRACTIONS_
#define _FRACTIONS_

class Fraction {
    public:
    
      Fraction(int  , int  , bool simplfy_frac = 1 );
      Fraction(int  );
      Fraction(double );
      Fraction(const Fraction& _frac_b);
      Fraction();

      static int gcd(int a , int b) noexcept;
      static int lcm(int a , int b);

      static Fraction simplfy(const Fraction& _frac);
      static Fraction inverse(const Fraction& _frac);

      void set_numerator(int numerator) noexcept;
      void set_numerator_without_simplifying(int numerator) noexcept;
      void set_denominator_without_simplifying(int denominator) noexcept;

      int get_numerator() const;
      int get_denominator() const;
      double get_decimal() const;

      friend std::ostream& operator<<(std::ostream& stream , const Fraction& _fraction);
      
      Fraction operator+(const Fraction& _frac_b);
      Fraction& operator+=(const Fraction& _frac_b);
      Fraction operator-(const Fraction& _frac_b);
      Fraction& operator-=(const Fraction& _frac_b);
      Fraction operator*(const Fraction& _frac_b);
      Fraction& operator*=(const Fraction& _frac_b);
      Fraction operator/(const Fraction& _frac_b);
      friend Fraction operator/(int number , const Fraction& _frac);
      Fraction& operator/=(const Fraction& _frac_b);
      bool operator==(const Fraction& _frac_b);

    private:
      int _numerator;
      int _denominator;

};

#endif