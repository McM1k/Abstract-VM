
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

    Token(std::string content, int type);

    std::string getContent() const;
    eTokenType getType() const;

    void setContent(std::string content);
    void setType(eTokenType type);

    typedef enum {command, separator, type, value, openBracket, closeBracket, comment} eTokenType;

private:
    std::string _content;
    eTokenType _type;

};

std::ostream &operator<<(std::ostream &o, Token const &i);


#endif