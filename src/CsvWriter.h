/*
 * CsvWriter.h
 *
 *  Created on: 4 de set de 2016
 *      Author: xbtse
 */

#ifndef CSVWRITER_H_
#define CSVWRITER_H_

#include <string>
#include <fstream>

using namespace std;

class CsvWriter {
public:
    CsvWriter(const string &csvPath);
    virtual ~CsvWriter();
    void nextLine();
    void addEntry(const string &s);
private:
    ofstream _fs;
    bool _isFirstEntry;
};

#endif /* CSVWRITER_H_ */
