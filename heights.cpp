#include "domains.hpp"

int nHeight(int_lit* e){
    return 0;
}

int nHeight(arg_expr* e){
    return 0;
}

int nHeight(arith_expr* e){
    return 1 + std::max(nHeight(e->lhs), nHeight(e->rhs));
}

int nHeight(if_expr* e){
    return 1 + std::max({nHeight(e->test), nHeight(e->pass), nHeight(e->fail)});
}


int nHeight(num_expr* e){
    switch (e->kind) {
        case 0:
            return nHeight(static_cast<int_lit*>(e));
        case 1:
            return nHeight(static_cast<arg_expr*>(e));
        case 2:
            return nHeight(static_cast<arith_expr*>(e));
        case 4:
            return nHeight(static_cast<if_expr*>(e));
    }
}

int bHeight(bool_lit* e){
    return 0;
}

//(RelationalOperator NE_lhs NE_rhs)
int bHeight(rel_expr* e){
    return 1 + std::max(bHeight(e->lhs), bHeight(e->rhs));
}

//(LogicalOperator NE_lhs NE_rhs)
int bHeight(logical_expr* e){
    return 1 + std::max(bHeight(e)->lhs, bHeight(e->rhs));
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
