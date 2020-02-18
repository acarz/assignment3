// Zafer Acar
// Question 3

// We include necessary libraries
#include <iostream>
#include <cmath>
using namespace std;

// We define our class FourVector
class FourVector
{
    // We made all members and methods public
    public:
        // We define the members of the class:  the energy and three momentum (px, py, pz) of a given particle
        float E, Px, Py, Pz;

        // This is the constructor to force the user to initialize the members of the class 
        FourVector (float E, float Px, float Py, float Pz):
            E(E), Px(Px), Py(Py), Pz(Pz) {}

        // We define first method to replace the contents of the full four vector with the E, px, py, and pz
        void SetFourVector (float E, float Px, float Py, float Pz)
        {
            this->E = E;
            this->Px = Px;
            this->Py = Py;
            this->Pz = Pz;
        }

        // GetMass() method returns the invariant mass of the four vector (as a float)
        float GetMass()
        {
            // We used this equation to calculate invariant mass: m=SQRT (E^2 - Px^2 - Py^2 - Pz^2)
            float InvariantMass = sqrt(pow(E, 2) - pow(Px, 2) - pow(Py, 2) - pow(Pz, 2));
            return InvariantMass;


        }

        // GetEta method returnas the pseudorapity (η : Greek “eta”) of the four vector (as a float)
        float GetEta()
        {

            // p=sqrt(Px^2+Py^2+Pz^2)
            float p = sqrt(pow(Px, 2) + pow(Py, 2) + pow(Pz, 2));
            float theta = acos(Pz / p);
            float eta = -log(tan(theta / 2));
            return eta;
        }

        // DeltaPhi(FourVector v2) method takes second vector as an argument and 
        // returns the difference in the azimuthal angle (∆φ) between the two three-momenta of these vectors.
        float DeltaPhi(FourVector v2)
        {
            float p = sqrt(pow(Px, 2) + pow(Py, 2) + pow(Pz, 2));
            float p2 = sqrt(pow(v2.Px, 2) + pow(v2.Py, 2) + pow(v2.Pz, 2));
            float cosDeltaPhi = ((Px * v2.Px) + (Py * v2.Py) + (Pz * v2.Pz)) / (sqrt(pow(p, 2) * pow(p2,2)));

            float deltaPhi = acos(cosDeltaPhi);

            return deltaPhi;

        }

        float DeltaEta(FourVector v2)
        {
            return -log(tan(DeltaPhi(v2) / 2));
        }

};


int main(int argc, char const *argv[])
{
    cout << "Hello CERN" << endl;
    cout << "--------------" << endl;
    cout << " Assignment 3, Question 3 " << endl;

    // We create instance of two vectors and initialize the energy and three momentum (px, py, pz) of a given particle
    FourVector v1(45, 5, 6, 2);
    FourVector v2(25, 6, 7, 8);

    cout << " " << endl;

    cout << "________The results____________" << endl;

    cout << "The FourVector v1 has  E = " << v1.E << ", Px = " << v1.Px << ", Py = " << v1.Py << ", Pz = " << v1.Pz << endl;
    cout << "The Invariant Mass is: " << v1.GetMass() << endl;
    cout << "The pseudorapity is : " << v1.GetEta() << endl;

    cout << " " << endl; 

    cout << "The FourVector v2 has  E = " << v2.E << ", Px = " << v2.Px << ", Py = " << v2.Py << ", Pz = " << v2.Pz << endl;
    cout << "The Invariant Mass is: " << v2.GetMass() << endl;
    cout << "The pseudorapity is : " << v2.GetEta() << endl;

    cout << "____________________" << endl;
    cout << "The difference in the azimuthal angle (∆φ) between the two three-momenta of these vectors : " << v1.DeltaPhi(v2) << endl;
    cout << "the pseudorapity (η) of the two four-vectors : " << v1.DeltaEta(v2) << endl;

    cout << " " << endl; 

    return 99;
}