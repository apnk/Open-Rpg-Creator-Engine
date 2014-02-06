#include "../Parser/ResourceParser.hpp"
#include "XMLParserPugi.hpp"

XMLParser* ResourceParser::getParser(){
    return new XMLParserPugi();
}