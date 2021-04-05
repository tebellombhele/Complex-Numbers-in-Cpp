#include <iostream>

using namespace std;

class complexType
{
    //Overload the insertion and extraction strem operators
    friend ostream& operator<<(ostream&, const complexType&);
    friend istream& operator>>(istream&, complexType&);

public:
    //Function to set the complex numbers
    void setComplex(const double& realNum, const double& imagineNum);

    //Function to retrieve the complex number
    void getComplex(double& realNum, double& imagineNum) const;

    //Constructor; Initailize the complex number
    complexType(double realNum = 0, double imagineNum = 0);

    //Overload the operator +
    complexType operator+(const complexType& otherComplex) const;

    //Overload the operator *
    complexType operator*(const complexType& otherComplex) const;

    //Overload the operator ==
    bool operator == (const complexType& otherComplex) const;

private:
    double realPart; //variable to store real part numbers
    double imaginaryPart; //variable to store imaginary part numbers
};

//Function to overload stream insertion (<<) operator
ostream& operator<<(ostream& osObject, const complexType& complex)
{
    osObject << " (";
    osObject << complex.realPart;
    osObject << ", ";
    osObject << complex.imaginaryPart;
    osObject << ") ";

    return osObject; //return ostream object
}

//Function to overload stream extraction (>>) operator
istream& operator>>(istream& isObject, complexType& complex)
{
    char ch;

    isObject >> ch;
    isObject >> complex.realPart;
    isObject >> ch;
    isObject >> complex.imaginaryPart;
    isObject >> ch;

    return isObject; //return istream object
}

//overload the operator ==
bool complexType::operator ==(const complexType& otherComplex) const
{
    return(realPart == otherComplex.realPart && imaginaryPart == otherComplex.imaginaryPart);
}

//Constructor
complexType::complexType(double realNum, double imagineNum)
{
    realPart = realNum;
    imaginaryPart = imagineNum;
}

//Set and Get Functions after the object is declared
void complexType::setComplex(const double& realNum, const double& imagineNum)
{
    realPart = realNum;
    imaginaryPart = imagineNum;
}

void complexType::getComplex(double& realNum, double& imagineNum) const
{
    realNum = realPart;
    imagineNum = imaginaryPart;
}

//overload the operator +
complexType complexType::operator+(const complexType& otherComplex) const
{
    complexType temp;
    temp.realPart = realPart + otherComplex.realPart;
    temp.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;

    return temp;
}

//overload the operator *
complexType complexType::operator*(const complexType& otherComplex) const
{
    complexType temp;
    temp.realPart = (realPart * otherComplex.realPart) - (imaginaryPart * otherComplex.imaginaryPart);
    temp.imaginaryPart = (realPart * otherComplex.imaginaryPart) + (imaginaryPart * otherComplex.realPart);

    return temp;
}


int main()
{
    complexType num1;//(0, 0);
    complexType num2;
    complexType num3;

    cout << "Enter the first complex number pair " << "in the form (a, b): ";
    cin >> num1;
    cout << "Enter the second complex number pair " << "in the form (a, b): ";
    cin >> num2;
    cout << "First Ordered Pair (Num1) = " << num1 << endl;
    cout << "Second Ordered Pair (Num2) = " << num2 << endl;
    cout << endl;

    cout << "Adding Num1 and Num2.....\n";
    num3 = num1 + num2;
    cout << "Third Ordered Pair (Num3) = " << num3 << endl;
    cout << "Adding Complex Number: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << "Multiplying Complex Number: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;

    return 0;
}
