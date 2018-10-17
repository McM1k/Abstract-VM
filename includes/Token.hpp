
#ifndef TOKEN_HPP
# define TOKEN_HPP
# include <iostream>
# include <string>

class Token {
public:
    Token(void);
    Token(Token const &src);
    virtual ~Token(void);
    Token &operator=(Token const &rhs); //equals

    typedef enum {command, separator, type, value, openBracket, closeBracket, comment} eTokenType;

    Token(std::string content, Token::eTokenType type);

    std::string getContent() const;
    Token::eTokenType getType() const;

    void setContent(std::string content);
    void setType(eTokenType type);



private:
    std::string _content;
    eTokenType _type;

};

std::ostream &operator<<(std::ostream &o, Token const &i);


#endif