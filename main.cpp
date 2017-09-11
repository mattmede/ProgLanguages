#include "domains.hpp"

int main(args n) {
    
    //Height of Numeric AST
    auto* nheight = new int_lit {
        val = 1;
        val = new arith_expr(+,1,max(nheight(*lhs,*rhs)));
    }

    //Height of Boolean AST
    auto* bheight = new arith_expr {
        val = 1;
        val = new arith_expr(+,1,max(nheight(*lhs,*rhs)));
    }
}