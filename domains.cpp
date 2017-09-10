#pragma once

//Integer Literals
//int

//Boolean Literals
//bool 


//Arithmatic Operator
enum arith_op {
    add_op,
    sub_op,
    mul_op,
    div_op,
    rem_op
};

//Relational Operator
enum rel_op {
    lt_op,
    gt_op,
    eq_op
};

//Logical Operator
enum logical_op {
    and_op,
    or_op
};

//Numeric and Boolean Expressions needed here

struct prog;
struct num_expr;
struct bool_expr;

struct prog {

    int args;
    num_expr* body;
};

struct num_expr {
    int kind;
};

struct int_lit : num_expr {
    int val;
};

struct arg_expr : num_expr {
    int arg;
};

struct arith_expr : num_expr {
    arith_op op;
    num_expr* lhs;
    num_expr* rhs;
};

struct if_exper : num_expr {
    bool_expr* test;
    num_expr* pass;
    num_expr* fail;
}

struct bool_expr {
    int kind;
};

struct bool_lit : bool_expr {
    bool  val;
};

struct rel_expr : bool_expr {
    rel_op op;
    num_expr* lhs;
    num_expr* rhs;
};

struct logical_expr : bool_expr {
    rel_op op;
    num_expr* lhs;
    num_expr* rhs;
};