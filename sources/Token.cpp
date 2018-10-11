
#include "Token.hpp"
#include <iostream>

/*
 * Constructors
 */
Token::Token(void) {
    //std::cout << "An instance of Token has been created" << std::endl;
}

Token::Token(Token const &src) {
    //std::cout << "An instance of Token has been created by copy" << std::endl;
    *this = src;
}

Token::Token(std::string content, eTokenType type) : _content(content), _type(type) {

}

/*
 * Destructors
 */
Token::~Token(void) {
    //std::cout << "An instance of Token has been destroyed" << std::endl;
}

/*
 * Getters
 */
std::string Token::getContent() const {
    return this->_content;
}

eTokenType Token::getType() const {
    return this->_type;
}

/*
 * Setters
 */
void Token::setContent(std::string content) {
    this->_content = content;
    return;
}

void Token::setType(eTokenType type) {
    this->_type = type;
    return;
}

/*
 * Equals
 */
Token &Token::operator=(Token const &rhs) {
    if (this != &rhs) {
        this->_content = rhs.getContent();
        this->_type = rhs.getType();
    }
    return *this;
}

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, Token const &i) {
    o << "no attributes" << std::endl;
    return o;
}

/*
 * Other
 */

/*
 * Exceptions
 */