//
// Created by Jose Fiestas on 19/11/21.
//

#ifndef INC_2021_II_TEO3_SEM12_U6_S2_HIJO_H
#define INC_2021_II_TEO3_SEM12_U6_S2_HIJO_H
class Hijo: public Familia {
    string nombre=" ";
    int edad=0;
public:
    Hijo(){}
    Hijo(string l, string n, int e):Familia(l),nombre(n),edad(e){}
    string get_nombre()  {return this->nombre;}


    virtual ~Hijo(){cout<<"Destruye Hijo"<<endl;}
};
#endif //INC_2021_II_TEO3_SEM12_U6_S2_HIJO_H
