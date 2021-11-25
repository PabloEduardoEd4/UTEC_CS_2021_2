//
// Created by Jose Fiestas on 19/11/21.
//

#ifndef INC_2021_II_TEO3_SEM12_U6_S2_PADRE_H
#define INC_2021_II_TEO3_SEM12_U6_S2_PADRE_H
class Padre: public Familia{
    string nombre=" ";
    int edad=0;
public:
    Padre(){}
    Padre(string a, string n, int e):Familia(a),nombre(n),edad(e){}
    int get_edad(){return edad;};
    string get_nombre()  {return this->nombre;}

    virtual ~Padre(){cout<<"Destruye Padre"<<endl;};
};
#endif //INC_2021_II_TEO3_SEM12_U6_S2_PADRE_H
