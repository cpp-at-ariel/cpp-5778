/**
 * Implementation of the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#include "Complex.hpp"

static std::istream& getAndCheckNextCharIs(std::istream& is, char ch) {
    char tmp;
    is >> tmp;
    if (!is) return is;
    // failbit is for format error
    if (tmp!=ch) is.setstate(std::ios::failbit);
    return is;
}

std::istream& operator>> (std::istream& is, Complex& c) {

    //---------------------------------------------
    // Does not check format
    //---------------------------------------------
    // char ch
    // return (is >> _re >> ch >> _im >> ch >> ch;
    //---------------------------------------------

    //---------------------------------------------
    // Checks format, with rewind on failure.
    //---------------------------------------------

    // remember place for rewinding
    std::ios::pos_type startPos= is.tellg();

    if ( (!(is >> c._re))||
         (!getAndCheckNextCharIs(is,'+'))||
         (!(is >> c._im))||
         (!(getAndCheckNextCharIs(is,'i'))) ) {

        // rewind on error
        std::ios::iostate errState= is.rdstate(); // remember error state
        is.clear(); // clear error so seekg will work
        is.seekg(startPos); // rewind
        is.clear(errState); // set back the error flag

    }

    return is;
    //---------------------------------------------
}
