#include <iostream>
#include <iomanip>
using namespace std;

double futureVal (double monInv, double apr, double years);
double doubleMoneyCalc(double apr);
void outputReport(double monContrib, double rate, double term);;
void inputData(double &moni, double &interestRate, double &term);

int main() { // test driver
    double moni, interestRate, term;
    cout << "FUTURE VALUE CALCULATOR\n\n";
    inputData(moni, interestRate, term);
    outputReport(moni, interestRate, term);
    return 0;

}

void inputData(double &moni, double &interestRate, double &term) {
    cout << "Enter your monthly investment: $";
    cin >> moni;
    cout << "Enter APR for investment: %";
    cin >> interestRate;
    cout << "Enter term for investment: ";
    cin >> term;
}

void outputReport(double monContrib, double rate, double term) {
    cout << "\n------------------------------------\n";

    cout << fixed << setprecision(2);
    cout << "The future value will be $";
    cout << futureVal(monContrib, rate, term) << endl;
    cout << "The account balance would double every ";
    cout << doubleMoneyCalc(rate);
    cout << " years after.";

    //cout << doubleMoneyCalc(6.35) << endl;
}


double futureVal (double monInv, double apr, double years) {
    double fv=0; // future value to be returned
    int months = years * 12;
    double monRate = (apr / 100 / 12) + 1;
    for (int i = 1; i <= months; i++) {
        fv += monInv; // beginning of month
        fv = fv * monRate;
    }
    return fv;
}



double doubleMoneyCalc(double apr) {
    return 72/apr;
}