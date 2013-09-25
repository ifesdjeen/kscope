#pragma once

#include "ast/node.h"
#include "ast/prototype.h"
#include "ast/function.h"

#include "lexer.h"


class Parser {
    Lexer *lexer_;

    Parser(const Parser &other);
    Parser &operator =(const Parser &other);

    ASTNode *parse_expression();
    ASTNode *parse_if();
    ASTNode *parse_for();
    ASTNode *parse_unary();
    ASTNode *parse_number();
    ASTNode *parse_paren();
    ASTNode *parse_identifier();
    ASTNode *parse_var();
    ASTNode *parse_primary();
    ASTNode *parse_binary_op_rhs(int precedence, ASTNode *lhs);
    PrototypeNode *parse_prototype();

public:
    Parser();
    ~Parser();

    Lexer *lexer();

    PrototypeNode *parse_extern();
    FunctionNode *parse_definition();
    FunctionNode *parse_top_level_expression();
};
