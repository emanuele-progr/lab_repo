//
// Created by emanuele on 30/09/16.
//

#ifndef PROGRESSBAR_LISTEXCEPTION_H
#define PROGRESSBAR_LISTEXCEPTION_H

#include <stdexcept>

class NegativeOrNullBytesException : public std::out_of_range {
public:
    NegativeOrNullBytesException(const std::string &m = "") : out_of_range(m.c_str()) {
    }
};


class NegativeOrNullFilesException : public std::out_of_range {
public:
    NegativeOrNullFilesException(const std::string &n = "") : out_of_range(n.c_str()) {

    }
};

#endif //PROGRESSBAR_LISTEXCEPTION_H
