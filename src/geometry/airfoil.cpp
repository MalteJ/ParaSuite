////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                   PARASUITE                                //
//                       Paraglider Engineering Framework                     //
//                       http://parasuite.geisterchor.com                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// Copyright 2014 Malte Janduda                                               //
//                                                                            //
// This file is part of ParaSuite.                                            //
//                                                                            //
// ParaSuite is free software: you can redistribute it and/or modify it under //
// the terms of the GNU General Public License as published by the Free       //
// Software Foundation, either version 3 of the License, or (at your option)  //
// any later version.                                                         //
//                                                                            //
// ParaSuite is distributed in the hope that it will be useful, but WITHOUT   //
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or      //
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   //
// more details.                                                              //
//                                                                            //
// You should have received a copy of the GNU General Public License along    //
// with ParaSuite. If not, see http://www.gnu.org/licenses/.                  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#include "airfoil.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace parasuite::geometry;

void Airfoil::readCsv(string filename, unsigned int startline) {
    ifstream f(filename.c_str());
    
    if(!f) {
        throw new runtime_error("Airfoil::readCsv - Cannot open file '"+filename+"'!");
    }
    
    string line, col;
    unsigned int i=0;
    unsigned int n;
    while(getline(f,line)) {
        if(++i > startline) {
            n=0;
            vec p(2);
            istringstream ss(line);
            while(getline(ss,col,',')) {
                p[n++] = boost::lexical_cast<double>(col);
            }
            if (n != 2) {
                throw new runtime_error("Airfoil CSV has an incorrect format");
            }
            points.push_back(p);
        }
    }
    
    f.close();
}
