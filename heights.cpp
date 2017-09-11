#include "domains.hpp"

//Look in book to fix the somethings

int nHeight(int_lit* e){
    return e->val;
}

int nHeight(arg_expr* e){
    return 0;
}

int nHeight(arith_expr* e){
    return 1 + std::max(nHeight(num_expr* e1), nHeight(num_expr* e2));
}

//Still not quite sure how to do this one
//(if BE_test NE_then NE_else)
int nHeight(if_expr* e){
    return something;
}


int nHeight(num_expr* e){
    switch (e->kind) {
        case 0:
            return height(static_cast<int_lit*>(e));
        case 1:
            return height(static_cast<arg_expr*>(e));
        case 2:
            return height(static_cast<arith_expr*>(e));
        case 4:
            return height(static_cast<if_expr*>(e));
    }
}

//Look in book for bool expressions

int bHeight(bool_lit* e){
    return e->val;
}

//(RelationalOperator NE_lhs NE_rhs)
int bHeight(rel_expr* e){
    return something;
}

//(LogicalOperator NE_lhs NE_rhs)
int bHeight(logical_expr* e){
    return something;
}

int bHeight(bool_expr* e){
    switch (e->kind) {
        case 0:
            return bHeight(static_cast<bool_lit*>(e));
        case 1:
            return bHeight(static_cast<rel_expr*>(e));
        case 2:
            return bHeight(static_cast<logical_expr*>(e));
    }
}
