#include <bits/stdc++.h>
#include "../fractions.h"

//small testing (no need for any framwork or library)

int main() {
    
    Fraction frac(4,5);
    std::cout<<"\nbasic fraction: "<<frac<<"\n";

    frac = Fraction(-4,5);
    std::cout<<"negative fraction: "<<frac<<"\n";

    frac = Fraction(12,15);
    std::cout<<"12/15 should be reduced to 4/5: "<<(frac == Fraction(4,5))<<"\n";

    frac = Fraction(20,10);
    std::cout<<"20/10 is equal to 2: "<<(frac.get_decimal() == 2)<<"\n";

    frac = Fraction(1,3);
    std::cout<<"inverse of 1/3 is equal to 3: "<<(Fraction::inverse(frac).get_decimal() == 3)<<"\n";

    frac = Fraction(2,5);
    std::cout<<"2/5*5 is equal to 2: "<<( (frac*5).get_decimal() == 2 )<<"\n";

    frac = Fraction(1,2);
    std::cout<<"1/2*2/3 should be equal to 1/3: "<<( frac*Fraction(2,3) == Fraction(1,3) )<<"\n";

    frac = Fraction(1,3);
    std::cout<<"1/3 / 3 should be equalt to 1/9: "<<(frac/3 == Fraction(1,9))<<"\n";
    std::cout<<"3 / 1/3 should be equal to 9: "<<(3/frac == 9)<<"\n";

    frac = Fraction(1,2);
    std::cout<<"1/2 + 1 should be equal to 1.5: "<<(frac+1 == 1.5)<<"\n";

    frac = Fraction(1,2);
    std::cout<<"1/2 + 2/5 should be equal to 9/10: "<<(frac+Fraction(2,5) == 0.9)<<"\n";

    frac = Fraction(0.25);
    std::cout<<"0.25 should be equal to 1/4: "<<(frac == Fraction(1,4))<<"\n";

}